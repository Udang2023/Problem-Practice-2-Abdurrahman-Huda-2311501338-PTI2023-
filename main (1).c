#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_MAHASISWA 100

// Struktur data untuk menyimpan informasi kehadiran mahasiswa
struct Mahasiswa {
    char nim[15];
    char nama[50];
    bool hadir;
    // Anda dapat menambahkan informasi tanggal kehadiran jika diperlukan
};

// Fungsi untuk menambahkan kehadiran mahasiswa
void tambahKehadiran(struct Mahasiswa mahasiswa[], int *jumlahMahasiswa) {
    if (*jumlahMahasiswa < MAX_MAHASISWA) {
        printf("\nMasukkan NIM mahasiswa: ");
        scanf("%s", mahasiswa[*jumlahMahasiswa].nim);

        // Mengecek apakah mahasiswa sudah hadir sebelumnya
        for (int i = 0; i < *jumlahMahasiswa; i++) {
            if (strcmp(mahasiswa[i].nim, mahasiswa[*jumlahMahasiswa].nim) == 0) {
                printf("Mahasiswa dengan NIM tersebut sudah tercatat hadir sebelumnya.\n");
                return;
            }
        }

        printf("Masukkan nama mahasiswa: ");
        scanf("%s", mahasiswa[*jumlahMahasiswa].nama);

        mahasiswa[*jumlahMahasiswa].hadir = true;

        printf("Kehadiran mahasiswa berhasil dicatat.\n");
        (*jumlahMahasiswa)++;
    } else {
        printf("Kapasitas maksimum mahasiswa telah tercapai.\n");
    }
}

// Fungsi untuk melihat daftar kehadiran
void lihatDaftarKehadiran(struct Mahasiswa mahasiswa[], int jumlahMahasiswa) {
    if (jumlahMahasiswa > 0) {
        printf("\nDaftar Kehadiran Mahasiswa:\n");
        for (int i = 0; i < jumlahMahasiswa; i++) {
            printf("%s\t%s\t%s\n", mahasiswa[i].nim, mahasiswa[i].nama, mahasiswa[i].hadir ? "Hadir" : "Tidak Hadir");
        }
    } else {
        printf("Belum ada data kehadiran mahasiswa.\n");
    }
}

// Fungsi untuk menghitung presentase kehadiran
void hitungPresentaseKehadiran(struct Mahasiswa mahasiswa[], int jumlahMahasiswa) {
    if (jumlahMahasiswa > 0) {
        int jumlahHadir = 0;
        for (int i = 0; i < jumlahMahasiswa; i++) {
            if (mahasiswa[i].hadir) {
                jumlahHadir++;
            }
        }

        float presentase = (float)jumlahHadir / jumlahMahasiswa * 100;
        printf("\nPresentase Kehadiran: %.2f%%\n", presentase);
    } else {
        printf("Belum ada data kehadiran mahasiswa.\n");
    }
}

int main() {
    struct Mahasiswa daftarMahasiswa[MAX_MAHASISWA];
    int jumlahMahasiswa = 0;
    int pilihan;

    do {
        // Menampilkan menu
        printf("\nMenu:\n");
        printf("1. Tambah Kehadiran Mahasiswa\n");
        printf("2. Lihat Daftar Kehadiran\n");
        printf("3. Hitung Presentase Kehadiran\n");
        printf("4. Keluar\n");
        printf("Pilih operasi (1-4): ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                tambahKehadiran(daftarMahasiswa, &jumlahMahasiswa);
                break;
            case 2:
                lihatDaftarKehadiran(daftarMahasiswa, jumlahMahasiswa);
                break;
            case 3:
                hitungPresentaseKehadiran(daftarMahasiswa, jumlahMahasiswa);
                break;
            case 4:
                printf("Keluar dari program.\n");
                break;
            default:
                printf("Pilihan tidak valid. Masukkan nomor 1-4.\n");
        }
    } while (pilihan != 4);

    return 0;
}

