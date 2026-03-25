#include <stdio.h>
#include <string.h>

int BiayaParkir(char JenisKendaraan[], int Jam){
    int Tarif_Dasar = 5000;
    int tarif;
    int total;

    if (strcmp(JenisKendaraan, "mobil") == 0){
        tarif = Tarif_Dasar;
    }
    else if (strcmp(JenisKendaraan, "motor") == 0){
        tarif = 0.5 * Tarif_Dasar;
    }
    else if (strcmp(JenisKendaraan, "truk") == 0){
        tarif = 2 * Tarif_Dasar;
    }
    else{
        printf("Jenis kendaraan tidak ada.\n");
        return 0;
    }

    total = tarif * Jam;

    if (Jam > 5){
        total = total - (0.10 * total);
    }

    return total;
}

int TotalBiayaParkir(int JumlahKendaraan, int biaya[]){
    int total = 0;
    for (int i = 0; i < JumlahKendaraan; i++){
        total += biaya[i];
    }
    return total;
}

void CetakStruk(char Nama[], int Jumlah, char Jenis[][20], int Lama[], int Biaya[], int Total){

    FILE *file = fopen("struk.txt", "a");

    if (file == NULL){
        printf("Gagal membuka file\n");
        return;
    }

    printf("\n==== STRUK PARKIR ====\n");
    printf("Nama Pemilik: %s\n\n", Nama);

    fprintf(file, "\n==== STRUK PARKIR ====\n");
    fprintf(file, "Nama Pemilik: %s\n\n", Nama);

    for (int i = 0; i < Jumlah; i++){

        printf("Kendaraan ke-%d\n", i + 1);
        printf("Jenis : %s\n", Jenis[i]);
        printf("Lama  : %d jam\n", Lama[i]);
        printf("Biaya : %d\n\n", Biaya[i]);

        fprintf(file, "Kendaraan ke-%d\n", i + 1);
        fprintf(file, "Jenis : %s\n", Jenis[i]);
        fprintf(file, "Lama  : %d jam\n", Lama[i]);
        fprintf(file, "Biaya : %d\n\n", Biaya[i]);
    }

    printf("Total Bayar: %d\n", Total);
    fprintf(file, "Total Bayar: %d\n", Total);

    fclose(file);
}

int main(){

    char Nama[30];
    char Jenis[3][20];
    int Jumlah, Lama[3], Biaya[3], Total;

    printf("Masukkan nama pelanggan : ");
    scanf("%s", Nama);

    printf("Masukkan jumlah kendaraan (maks 3): ");
    scanf("%d", &Jumlah);

    if (Jumlah > 3){
        printf("Maksimal hanya 3 kendaraan.\n");
        return 1;
    }

    for (int i = 0; i < Jumlah; i++) {
        printf("\nKendaraan ke-%d\n", i + 1);

        printf("Jenis kendaraan (mobil/motor/truk): ");
        scanf("%s", Jenis[i]);

        printf("Lama Parkir (jam): ");
        scanf("%d", &Lama[i]);

        Biaya[i] = BiayaParkir(Jenis[i], Lama[i]);
    }

    Total = TotalBiayaParkir(Jumlah, Biaya);

    CetakStruk(Nama, Jumlah, Jenis, Lama, Biaya, Total);

    return 0;
}