#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define ROWS 15
#define COLS 6

const char *namakursi = "ABCDEF";
const char *file_kursi = "Kursi.txt";
const char *file_harga = "Harga.txt";
const char *file_bag = "Bagasi.txt";

typedef struct { 
    long first, business, economy;
} Prices;

typedef struct {
    long A, B, C;
} bagasi;

static char seat[ROWS][COLS];
static Prices prices;
static bagasi Bagasi;
static long totalpendapatan = 0; // akumulasi runtime (bukan dari file)

int carihuruf(char c) {
    char *p = strchr((char*)namakursi, c);
    return (p ? (int)(p - namakursi) : -1);
}

int validrowperclass(int row, int classId) {
    // classId: 1=First, 2=Business, 3=Economy
    if (classId == 1) return (row >= 1 && row <= 2);
    if (classId == 2) return (row >= 3 && row <= 5);
    if (classId == 3) return (row >= 6 && row <= 15);
    return 0;
}

void seatMap() {
    FILE *f = fopen(file_kursi, "r");
    if (!f) {
        for (int i=0;i<ROWS;i++)
            for (int j=0;j<COLS;j++)
                seat[i][j] = '_';
        return;
    }
    char buf[64];
    for (int i=0;i<ROWS;i++) {
        if (fgets(buf, sizeof(buf), f)) {
            // harapannya 6 karakter status
            for (int j=0;j<COLS;j++) {
                if ((int)strlen(buf) > j && buf[j] != '\n' && buf[j] != '\r')
                    seat[i][j] = buf[j];
                else
                    seat[i][j] = '_';
            }
        } else {
            for (int j=0;j<COLS;j++) seat[i][j] = '_';
        }
    }
    fclose(f);
}

void saveSeatMap() {
    FILE *f = fopen(file_kursi, "w");
    if (!f) {
        printf("Gagal menulis %s\n", file_kursi);
        return;
    }
    for (int i=0;i<ROWS;i++) {
        for (int j=0;j<COLS;j++) fputc(seat[i][j], f);
        fputc('\n', f);
    }
    fclose(f);
}

void muatHarga() {
    // default (sesuai slide): 1.500.000, 1.000.000, 600.000
    prices.first   = 1500000;
    prices.business= 1000000;
    prices.economy = 600000;

    FILE *f = fopen(file_harga, "r");
    if (!f) return;
    long a,b,c;
    if (fscanf(f, "%ld %ld %ld", &a, &b, &c)==3) {
        prices.first=a; prices.business=b; prices.economy=c;
    }
    fclose(f);
}

void loadBaggagePrices() {
    // default: A=100k, B=175k, C=300k
    Bagasi.A=100000; Bagasi.B=175000; Bagasi.C=300000;

    FILE *f = fopen(file_bag, "r");
    if (!f) return;
    long A,B,C;
    if (fscanf(f, "%ld %ld %ld", &A, &B, &C)==3) {
        Bagasi.A=A; Bagasi.B=B; Bagasi.C=C;
    }
    fclose(f);
}

void printSeatMap() {
    printf("\n=== DENAH KURSI (15x6) ===\n    A B C D E F\n");
    for (int i=0;i<ROWS;i++) {
        printf("%2d: ", i+1);
        for (int j=0;j<COLS;j++) {
            printf("%c", seat[i][j]);
            if (j<COLS-1) printf(" ");
        }
        printf("\n");
    }
    printf("\nKeterangan:\n");
    printf("_ : Kosong\n");
    printf("X : Terisi (tanpa bagasi)\n");
    printf("A : Terisi (dengan bagasi 0-5kg)\n");
    printf("B : Terisi (dengan bagasi >5-10kg)\n");
    printf("C : Terisi (dengan bagasi >10-20kg)\n");
}

int seatToIndex(int row, char hurufkolom, int *ri, int *cj) {
    if (row < 1 || row > ROWS) return 0;
    int j = carihuruf(hurufkolom);
    if (j < 0) return 0;
    *ri = row-1;
    *cj = j;
    return 1;
}

char classNameBuf[16];
const char* className(int classId) {
    if (classId==1) return "First";
    if (classId==2) return "Business";
    if (classId==3) return "Economy";
    return "Unknown";
}

long priceByClass(int classId) {
    if (classId==1) return prices.first;
    if (classId==2) return prices.business;
    if (classId==3) return prices.economy;
    return 0;
}

long baggagePriceByCode(char code) {
    if (code=='A') return Bagasi.A;
    if (code=='B') return Bagasi.B;
    if (code=='C') return Bagasi.C;
    return 0;
}

void searchSeat() {
    int row; char col;
    printf("Masukkan baris (1-15): "); scanf("%d", &row);
    printf("Masukkan kolom (A-F): "); scanf(" %c", &col);
    int r,c;
    if (!seatToIndex(row, col, &r, &c)) {
        printf("Input kursi tidak valid.\n");
        return;
    }
    char s = seat[r][c];
    if (s=='_') printf("Kursi %d%c: KOSONG\n", row, col);
    else if (s=='X') printf("Kursi %d%c: TERISI (tanpa bagasi)\n", row, col);
    else if (s=='A' || s=='B' || s=='C') printf("Kursi %d%c: TERISI (bagasi %c)\n", row, col, s);
    else printf("Kursi %d%c: Status tidak dikenal '%c'\n", row, col, s);
}

int countEmptyInClass(int classId) {
    int cnt=0;
    for (int i=0;i<ROWS;i++) {
        int row = i+1;
        if (!validrowperclass(row, classId)) continue;
        for (int j=0;j<COLS;j++) if (seat[i][j]=='_') cnt++;
    }
    return cnt;
}

void printReceipt(const char *nama, int n, int classId, char kursi[][6], char *bagCodes, long hargaKursi, long total) {
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    char ts[32];
    strftime(ts, sizeof(ts), "%Y-%m-%d %H:%M:%S", tm);

    printf("\n=== STRUK PEMBELIAN ===\n");
    printf("Nama                : %s\n", nama);
    printf("Banyak Pemesanan    : %d\n", n);
    printf("Kelas Penerbangan   : %s\n", className(classId));
    printf("Nomor Kursi         : ");
    for (int i=0;i<n;i++) {
        printf("%s", kursi[i]);
        if (i<n-1) printf(", ");
    }
    printf("\nTambahan Bagasi     : ");
    for (int i=0;i<n;i++) {
        if (bagCodes[i]=='X') printf("Tidak");
        else printf("%c", bagCodes[i]);
        if (i<n-1) printf(", ");
    }
    printf("\nHarga per Kursi     : Rp %ld\n", hargaKursi);
    printf("Waktu Pemesanan     : %s\n", ts);
    printf("Total Pembayaran    : Rp %ld\n", total);
    printf("Terima kasih telah memesan!\n");
}

void bookSeat() {
    int classId, n;
    char nama[50];
    printf("\n=== PEMESANAN KURSI ===\n");
    printf("Harga: First=Rp%ld, Business=Rp%ld, Economy=Rp%ld\n", prices.first, prices.business, prices.economy);
    printf("Pilih kelas (1=First, 2=Business, 3=Economy): ");
    scanf("%d", &classId);
    if (classId<1 || classId>3) { printf("Kelas tidak valid.\n"); return; }

    int available = countEmptyInClass(classId);
    printf("Kursi kosong di kelas %s: %d\n", className(classId), available);
    if (available<=0) { printf("Tidak ada kursi kosong.\n"); return; }

    printf("Banyak tiket yang dipesan: "); scanf("%d", &n);
    if (n<=0) { printf("Jumlah tidak valid.\n"); return; }
    if (n>available) { printf("Jumlah tiket > kursi kosong. Batal.\n"); return; }

    printf("Nama pemesan: "); scanf(" %49[^\n]", nama);

    char booked[20][6];
    char bagCodes[20];
    int bookedCount=0;
    long hargaKursi = priceByClass(classId);
    long total=0;

    for (int k=0;k<n;k++) {
        int row; char col;
        printf("\nTiket #%d\n", k+1);
        printf("Baris (sesuai kelas %s): ", className(classId)); scanf("%d", &row);
        printf("Kolom (A-F): "); scanf(" %c", &col);

        if (!validrowperclass(row, classId)) {
            printf("Baris tidak sesuai kelas. Ulangi tiket ini.\n"); k--; continue;
        }
        int r,c;
        if (!seatToIndex(row, col, &r, &c)) {
            printf("Kursi tidak valid. Ulangi tiket ini.\n"); k--; continue;
        }
        if (seat[r][c] != '_') {
            printf("Kursi %d%c sudah terisi. Pilih yang lain.\n", row, col);
            k--; continue;
        }

        // tanya bagasi
        printf("Tambah bagasi? (N=Tidak, A=0-5kg, B=>5-10kg, C=>10-20kg): ");
        char bg; scanf(" %c", &bg);
        if (bg=='A' || bg=='B' || bg=='C') {
            seat[r][c] = bg; // terisi + bagasi
            bagCodes[k] = bg;
            total += hargaKursi + baggagePriceByCode(bg);
        } else {
            seat[r][c] = 'X'; // terisi tanpa bagasi
            bagCodes[k] = 'X';
            total += hargaKursi;
        }

        snprintf(booked[k], sizeof(booked[k]), "%d%c", row, col);
        bookedCount++;
    }

    saveSeatMap();
    totalpendapatan += total;

    printSeatMap();
    printReceipt(nama, bookedCount, classId, booked, bagCodes, hargaKursi, total);
}

void cancelSeat() {
    int row; char col;
    printf("\n=== BATALKAN PEMESANAN ===\n");
    printf("Baris (1-15): "); scanf("%d", &row);
    printf("Kolom (A-F): "); scanf(" %c", &col);
    int r,c;
    if (!seatToIndex(row, col, &r, &c)) { printf("Kursi tidak valid.\n"); return; }
    if (seat[r][c]=='_') {
        printf("Kursi %d%c sudah kosong.\n", row, col);
        return;
    }
    seat[r][c] = '_';
    saveSeatMap();
    printSeatMap();
    printf("Kursi %d%c berhasil dibatalkan.\n", row, col);
}

void recommendSeat() {
    int classId;
    printf("\n=== REKOMENDASI KURSI TERBAIK ===\n");
    printf("Pilih kelas (1=First, 2=Business, 3=Economy): ");
    scanf("%d", &classId);
    if (classId<1 || classId>3) { printf("Kelas tidak valid.\n"); return; }

    for (int i=0;i<ROWS;i++) {
        int row = i+1;
        if (!validrowperclass(row, classId)) continue;
        for (int j=0;j<COLS;j++) {
            if (seat[i][j]=='_') {
                printf("Rekomendasi: %d%c\n", row, namakursi[j]);
                return;
            }
        }
    }
    printf("Tidak ada kursi kosong di kelas %s.\n", className(classId));
}

void showStats() {
    int totalSeats = ROWS * COLS;
    int filled=0, empty=0;
    int fFill=0, fTotal=0, bFill=0, bTotal=0, eFill=0, eTotal=0;

    for (int i=0;i<ROWS;i++) {
        int row=i+1;
        for (int j=0;j<COLS;j++) {
            int isFill = (seat[i][j] != '_');
            filled += isFill;
            empty  += !isFill;

            if (validrowperclass(row,1)) { fTotal++; if (isFill) fFill++; }
            else if (validrowperclass(row,2)) { bTotal++; if (isFill) bFill++; }
            else if (validrowperclass(row,3)) { eTotal++; if (isFill) eFill++; }
        }
    }

    double pf = fTotal? (100.0*fFill/fTotal):0.0;
    double pb = bTotal? (100.0*bFill/bTotal):0.0;
    double pe = eTotal? (100.0*eFill/eTotal):0.0;

    printf("\n=== STATISTIK & PENDAPATAN ===\n");
    printf("Jumlah kursi total : %d\n", totalSeats);
    printf("Kursi kosong       : %d\n", empty);
    printf("Kursi terisi       : %d\n", filled);
    printf("%% keterisian First : %.2f%%\n", pf);
    printf("%% keterisian Busns : %.2f%%\n", pb);
    printf("%% keterisian Econ  : %.2f%%\n", pe);
    printf("Total pendapatan   : Rp %ld\n", totalpendapatan);
}

int loginAdmin() {
    char u[32], p[32];
    printf("=== LOGIN ADMIN ===\n");
    printf("Username: "); scanf(" %31s", u);
    printf("Password: "); scanf(" %31s", p);
    if (strcmp(u,"admin")==0 && strcmp(p,"12345")==0) return 1;
    printf("Login gagal.\n");
    return 0;
}

void resetData() {
    if (!loginAdmin()) return;
    // tampilkan pendapatan saat ini sebelum reset peta
    printf("Pendapatan saat ini: Rp %ld\n", totalpendapatan);
    for (int i=0;i<ROWS;i++)
        for (int j=0;j<COLS;j++)
            seat[i][j] = '_';
    saveSeatMap();
    printSeatMap();
    printf("Semua kursi direset menjadi kosong.\n");
}

int main() {
    muatHarga();
    loadBaggagePrices();
    seatMap();

    int pilihan;
    do {
        printf("\n=== MENU MASKAPAI ===\n");
        printf("1. Cari info kursi\n");
        printf("2. Pemesanan kursi\n");
        printf("3. Batalkan pemesanan\n");
        printf("4. Rekomendasi kursi terbaik\n");
        printf("5. Statistik & total pendapatan\n");
        printf("6. Reset data (admin)\n");
        printf("7. Tampilkan denah kursi\n");
        printf("8. Keluar\n");
        printf("Pilih: ");
        if (scanf("%d", &pilihan)!=1) { fflush(stdin); continue; }

        switch(pilihan) {
            case 1: searchSeat(); break;
            case 2: bookSeat(); break;
            case 3: cancelSeat(); break;
            case 4: recommendSeat(); break;
            case 5: showStats(); break;
            case 6: resetData(); break;
            case 7: printSeatMap(); break;
            case 8: printf("Terima kasih.\n"); break;
            default: printf("Pilihan tidak valid.\n");
        }
    } while (pilihan != 8);

    return 0;
}
