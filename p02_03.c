#include <stdio.h>

int main() {
    int N;
    int pilihan;
    int jumlah;
    int harga;
    int total = 0;
    int i;

    printf("=== Sistem Pembayaran Kafetaria IT Del ===\n");
    printf("Menu Makanan:\n");
    printf("1. Nasi Goreng  : Rp15000\n");
    printf("2. Mie Goreng   : Rp13000\n");
    printf("3. Ayam Geprek  : Rp17000\n");
    printf("4. Es Teh       : Rp5000\n");
    printf("5. Kopi         : Rp7000\n");

    printf("\nMasukkan jumlah item yang dibeli: ");
    scanf("%d", &N);

    for(i = 1; i <= N; i++) {
        printf("\nItem ke-%d\n", i);
        printf("Pilih menu (1-5): ");
        scanf("%d", &pilihan);

        if(pilihan == 1) {
            harga = 15000;
        } 
        else if(pilihan == 2) {
            harga = 13000;
        } 
        else if(pilihan == 3) {
            harga = 17000;
        } 
        else if(pilihan == 4) {
            harga = 5000;
        } 
        else if(pilihan == 5) {
            harga = 7000;
        } 
        else {
            printf("Pilihan tidak tersedia\n");
            harga = 0;
        }

        printf("Masukkan jumlah yang dibeli: ");
        scanf("%d", &jumlah);

        total = total + (harga * jumlah);
    }

    printf("\n==============================\n");
    printf("Total yang harus dibayar: Rp %d\n", total);
    printf("==============================\n");

    return 0;
}