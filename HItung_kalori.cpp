#include <stdio.h>

float hitungKaloriDasar(int gender, float bb, float tb, int umur) {
    if (gender == 1) {
        return 66 + (13.7 * bb) + (5 * tb) - (6.8 * umur);
    } else {
        return 655 + (9.6 * bb) + (1.8 * tb) - (4.7 * umur);
    }
}
float hitungTotalKalori(float kaloriDasar, int aktivitas) {
    switch (aktivitas) {
        case 1: 
            return kaloriDasar * 1.2;
        case 2: 
            return kaloriDasar * 1.375;
        case 3: 
            return kaloriDasar * 1.55;
        case 4: 
            return kaloriDasar * 1.725;
        default: 
            return kaloriDasar * 1.2;
    }
}
void tampilHasil(float kaloriDasar, float totalKalori) {
    printf("\n=== HASIL ===\n");
    printf("Kalori dasar        : %.2f kalori/hari\n", kaloriDasar);
    printf("Total kalori harian : %.2f kalori/hari\n", totalKalori);
    printf("Saran diet          : %.2f kalori/hari\n", totalKalori - 500);
}

int main() {
    int umur, gender, aktivitas;
    float tb, bb;

    printf("=== INPUT DATA ===\n");

    printf("Tinggi badan (cm): ");
    scanf("%f", &tb);

    printf("Berat badan (kg): ");
    scanf("%f", &bb);

    printf("Umur: ");
    scanf("%d", &umur);

    printf("Jenis kelamin (1=Laki-laki, 2=Perempuan): ");
    scanf("%d", &gender);

    printf("\nLevel aktivitas:\n");
    printf("1. Jarang olahraga\n");
    printf("2. Ringan\n");
    printf("3. Sedang\n");
    printf("4. Berat\n");
    printf("Pilih: ");
    scanf("%d", &aktivitas);

    float kaloriDasar = hitungKaloriDasar(gender, bb, tb, umur);
    float totalKalori = hitungTotalKalori(kaloriDasar, aktivitas);

    tampilHasil(kaloriDasar, totalKalori);

    return 0;
}