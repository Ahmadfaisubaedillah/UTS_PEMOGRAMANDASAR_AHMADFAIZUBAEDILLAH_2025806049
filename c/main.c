#include <stdio.h>
#include <string.h>
#include "linked_list.h"

int main() {
    Mahasiswa *head = NULL;
    int pilihan;
    char nama[50], nim[15];
    float tugas, uts, uas;

    do {
        printf("\n=== SISTEM DATA MAHASISWA ===\n");
        printf("1. Tambah mahasiswa\n2. Tampilkan semua\n");
        printf("3. Cari mahasiswa\n4. Hapus mahasiswa\n");
        printf("5. Simpan ke CSV\n0. Keluar\nPilihan: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                printf("Nama: "); scanf("%s", nama);
                printf("NIM: ");  scanf("%s", nim);
                printf("Nilai Tugas: "); scanf("%f", &tugas);
                printf("Nilai UTS: ");   scanf("%f", &uts);
                printf("Nilai UAS: ");   scanf("%f", &uas);
                tambah(&head, nama, nim, tugas, uts, uas);
                break;
            case 2:
                tampilkan(head);
                break;
            case 3:
                printf("Masukkan NIM: "); scanf("%s", nim);
                Mahasiswa *m = cari(head, nim);
                if (m) printf("Ditemukan: %s | Nilai Akhir: %.2f | Mutu: %c\n",
                              m->nama, m->nilai_akhir, m->mutu);
                else printf("Tidak ditemukan.\n");
                break;
            case 4:
                printf("Masukkan NIM yang dihapus: "); scanf("%s", nim);
                hapus(&head, nim);
                break;
            case 5:
                simpan_csv(head, "data_mahasiswa.csv");
                break;
        }
    } while (pilihan != 0);

    bebaskan_memori(&head);
    return 0;
}