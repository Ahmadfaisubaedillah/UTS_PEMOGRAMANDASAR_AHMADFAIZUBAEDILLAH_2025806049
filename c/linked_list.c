#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked_list.h"

char hitung_mutu(float nilai) {
    if (nilai >= 85) return 'A';
    if (nilai >= 70) return 'B';
    if (nilai >= 60) return 'C';
    if (nilai >= 50) return 'D';
    return 'E';
}

Mahasiswa* buat_node(char *nama, char *nim, float tugas, float uts, float uas) {
    Mahasiswa *baru = (Mahasiswa*)malloc(sizeof(Mahasiswa));
    strcpy(baru->nama, nama);
    strcpy(baru->nim, nim);
    baru->tugas = tugas;
    baru->uts   = uts;
    baru->uas   = uas;
    baru->nilai_akhir = (0.30 * tugas) + (0.30 * uts) + (0.40 * uas);
    baru->mutu  = hitung_mutu(baru->nilai_akhir);
    baru->next  = NULL;
    return baru;
}

void tambah(Mahasiswa **head, char *nama, char *nim, float tugas, float uts, float uas) {
    Mahasiswa *baru = buat_node(nama, nim, tugas, uts, uas);
    if (*head == NULL) { *head = baru; return; }
    Mahasiswa *tmp = *head;
    while (tmp->next != NULL) tmp = tmp->next;
    tmp->next = baru;
}

void hapus(Mahasiswa **head, char *nim) {
    Mahasiswa *tmp = *head, *prev = NULL;
    while (tmp != NULL && strcmp(tmp->nim, nim) != 0) {
        prev = tmp; tmp = tmp->next;
    }
    if (tmp == NULL) { printf("NIM tidak ditemukan.\n"); return; }
    if (prev == NULL) *head = tmp->next;
    else prev->next = tmp->next;
    free(tmp);
    printf("Data berhasil dihapus.\n");
}

Mahasiswa* cari(Mahasiswa *head, char *nim) {
    while (head != NULL) {
        if (strcmp(head->nim, nim) == 0) return head;
        head = head->next;
    }
    return NULL;
}

void tampilkan(Mahasiswa *head) {
    printf("%-15s %-12s %6s %6s %6s %10s %5s\n",
           "Nama","NIM","Tugas","UTS","UAS","NilaiAkhir","Mutu");
    printf("------------------------------------------------------------------\n");
    while (head != NULL) {
        printf("%-15s %-12s %6.1f %6.1f %6.1f %10.2f %5c\n",
               head->nama, head->nim, head->tugas, head->uts,
               head->uas, head->nilai_akhir, head->mutu);
        head = head->next;
    }
}

void simpan_csv(Mahasiswa *head, const char *filename) {
    FILE *f = fopen(filename, "w");
    if (!f) { printf("Gagal membuka file.\n"); return; }
    fprintf(f, "Nama,NIM,Tugas,UTS,UAS,NilaiAkhir,Mutu\n");
    while (head != NULL) {
        fprintf(f, "%s,%s,%.1f,%.1f,%.1f,%.2f,%c\n",
                head->nama, head->nim, head->tugas, head->uts,
                head->uas, head->nilai_akhir, head->mutu);
        head = head->next;
    }
    fclose(f);
    printf("Data disimpan ke %s\n", filename);
}

void bebaskan_memori(Mahasiswa **head) {
    Mahasiswa *tmp;
    while (*head != NULL) {
        tmp = *head;
        *head = (*head)->next;
        free(tmp);
    }
}