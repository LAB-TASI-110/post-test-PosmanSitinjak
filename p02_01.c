#include <stdio.h>
#include <string.h>

int main() {
    char kode[10];
    char kotaTujuan[50] = "";
    float beratInput, totalBerat = 0;
    float totalOngkos = 0;
    int isLuarPulau = 0;
    int adaLuarPulau = 0; // Penanda jika salah satu tujuan adalah luar pulau

    // Tampilan Papan Informasi
    printf("==================================================\n");
    printf("           SELAMAT DATANG DI DEL-EXPRESS          \n");
    printf("==================================================\n");
    printf(" DAFTAR ONGKIR PER KG:\n");
    printf(" MDN - Medan    : 8000  (Dalam Pulau)\n");
    printf(" BLG - Balige   : 5000  (Dalam Pulau)\n");
    printf(" JKT - Jakarta  : 12000 (Luar Pulau)\n");
    printf(" SBY - Surabaya : 13000 (Luar Pulau)\n");
    printf("--------------------------------------------------\n");
    printf(" PROMO:\n");
    printf(" 1. Berat > 10kg     -> Diskon 10%%\n");
    printf(" 2. Tujuan Luar Pulau -> Gratis Asuransi\n");
    printf("--------------------------------------------------\n");
    printf(" (Ketik 'END' pada kode kota untuk selesai)\n\n");

    // Proses Input Otomatis
    while (1) {
        printf("Masukkan Kode Kota: ");
        scanf("%s", kode);

        // Berhenti jika input adalah END
        if (strcmp(kode, "END") == 0 || strcmp(kode, "end") == 0) {
            break;
        }

        printf("Masukkan Berat Paket (kg): ");
        scanf("%f", &beratInput);

        // Logika Perhitungan per Kota
        if (strcmp(kode, "MDN") == 0) {
            totalOngkos += (beratInput * 8000);
            strcat(kotaTujuan, "Medan ");
        } else if (strcmp(kode, "BLG") == 0) {
            totalOngkos += (beratInput * 5000);
            strcat(kotaTujuan, "Balige ");
        } else if (strcmp(kode, "JKT") == 0) {
            totalOngkos += (beratInput * 12000);
            strcat(kotaTujuan, "Jakarta ");
            adaLuarPulau = 1; // Mendapat asuransi
        } else if (strcmp(kode, "SBY") == 0) {
            totalOngkos += (beratInput * 13000);
            strcat(kotaTujuan, "Surabaya ");
            adaLuarPulau = 1; // Mendapat asuransi
        } else {
            printf("Kode kota tidak dikenal, data diabaikan.\n");
            continue;
        }

        totalBerat += beratInput;
    }

    // Perhitungan Promo Diskon
    float diskon = 0;
    if (totalBerat > 10) {
        diskon = totalOngkos * 0.10;
    }

    float totalAkhir = totalOngkos - diskon;

    // Output Struk Pembayaran
    printf("\n\n==================================================\n");
    printf("               STRUK PEMBAYARAN                   \n");
    printf("==================================================\n");
    printf("Kota Tujuan    : %s\n", kotaTujuan);
    printf("Total Berat    : %.2f kg\n", totalBerat);
    printf("Total Ongkos   : Rp. %.0f\n", totalOngkos);
    printf("--------------------------------------------------\n");
    printf("Informasi Promo yang diperoleh:\n");
    
    if (totalBerat > 10) {
        printf("- Diskon 10%% (Berat > 10kg): -Rp. %.0f\n", diskon);
    }
    
    if (adaLuarPulau == 1) {
        printf("- Mendapatkan Asuransi Gratis (Tujuan Luar Pulau)\n");
    }

    if (totalBerat <= 10 && adaLuarPulau == 0) {
        printf("- Tidak ada promo yang didapat\n");
    }

    printf("--------------------------------------------------\n");
    printf("TOTAL BAYAR    : Rp. %.0f\n", totalAkhir);
    printf("==================================================\n");

    return 0;
}