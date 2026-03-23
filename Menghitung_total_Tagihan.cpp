#include<stdio.h>

int main(){
    int tagihan_awal, pajak_pemerintah, biaya_layanan, total;

    printf("PROGRAM MENGHITUNG TOTAL TAGIHAN\n");

    printf("Masukkan biaya tagihan awal (Rp) : ");
    scanf("%d", &tagihan_awal);

    pajak_pemerintah = tagihan_awal * 11 / 100;   
    biaya_layanan = tagihan_awal * 5 / 100;  
    total = tagihan_awal + pajak_pemerintah + biaya_layanan;

    printf("TOTAL TAGIHAN\n");
    printf("Tagihan awal              : Rp %d\n", tagihan_awal);
    printf("Pajak pemerintah 11%%     : Rp %d\n", pajak_pemerintah);
    printf("Biaya layanan     5%%     : Rp %d\n", biaya_layanan);
    printf("------------------------------------------\n");
    printf("Total tagihan             : Rp %d\n", total);

    return 0;
}   