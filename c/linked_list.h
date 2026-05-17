#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct Mahasiswa {
    char nama[50];
    char nim[15];
    float tugas, uts, uas;
    float nilai_akhir;
    char mutu;
    struct Mahasiswa *next;
} Mahasiswa;

Mahasiswa* buat_node(char *nama, char *nim, float tugas, float uts, float uas);
void tambah(Mahasiswa **head, char *nama, char *nim, float tugas, float uts, float uas);
void hapus(Mahasiswa **head, char *nim);
Mahasiswa* cari(Mahasiswa *head, char *nim);
void tampilkan(Mahasiswa *head);
void simpan_csv(Mahasiswa *head, const char *filename);
void bebaskan_memori(Mahasiswa **head);

#endif