#include<stdio.h>

int main(){
    int biaya_pasir, biaya_semen, biaya_batu_bata, biaya_tukang;
    int total_biaya;

    printf("Masukkan biaya pasir        : ");
    scanf("%d", &biaya_pasir);

    printf("Masukkan biaya semen        : ");
    scanf("%d", &biaya_semen);

    printf("Masukkan biaya batu bata    : ");
    scanf("%d", &biaya_batu_bata);

    printf("Masukkan biaya tukang       : ");
    scanf("%d", &biaya_tukang);

    total_biaya = biaya_pasir + biaya_semen + biaya_batu_bata + biaya_tukang;

    printf("RINCIAN BIAYA PEMBUATAN TEMBOK\n");
    printf("Biaya pasir     = %d\n", biaya_pasir);
    printf("Biaya semen     = %d\n", biaya_semen);
    printf("Biaya batu bata = %d\n", biaya_batu_bata);
    printf("Biaya tukang    = %d\n", biaya_tukang);
    printf("-------------------------\n");
    printf("TOTAL BIAYA     = %d\n", total_biaya);

    return 0;
}