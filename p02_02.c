#include <stdio.h>

int main() {
    int n, i, targetKategori;
    int totalStok = 0;

    // 1. Input Jumlah Total Data (N)
    // User memasukkan berapa banyak jenis barang yang ada di gudang
    printf("Masukkan jumlah jenis barang (N): ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Input tidak valid.\n");
        return 1;
    }

    int stok[n];
    int kategori[n];

    // 2. Input Deret Stok dan Kode Kategori
    // Kita lakukan dalam satu perulangan agar lebih praktis saat simulasi
    printf("Masukkan data untuk %d barang (Format: [Stok] [Kode_Kategori]):\n", n);
    for (i = 0; i < n; i++) {
        printf("Barang ke-%d: ", i + 1);
        scanf("%d %d", &stok[i], &kategori[i]);
    }

    // 3. Input Kode Kategori yang Ingin Dihitung
    printf("\nMasukkan kode kategori yang ingin ditotal stoknya: ");
    scanf("%d", &targetKategori);

    // 4. Hitung Total Stok berdasarkan Kategori yang diminta
    for (i = 0; i < n; i++) {
        if (kategori[i] == targetKategori) {
            totalStok += stok[i];
        }
    }

    // 5. Tampilkan Hasil Akhir
    printf("--------------------------------------------\n");
    printf("Total stok untuk kategori %d adalah: %d pcs\n", targetKategori, totalStok);
    printf("--------------------------------------------\n");

    return 0;
}