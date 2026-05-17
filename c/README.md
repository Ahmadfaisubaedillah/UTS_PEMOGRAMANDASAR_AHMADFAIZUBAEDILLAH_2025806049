# 🧠 UTS Pemrograman Dasar (C & Python)

## 👤 Identitas
| | |
|---|---|
| **Nama** | [Ahmad Faiz Ubaedillah] |
| **NIM** | [2025806049] |
| **Kelas** | TI 2 Pagi |
| **Dosen** | Rintis Mardika Sunarto |
| **Mata Kuliah** | Pemrograman Dasar |
| **Tahun Akademik** | 2025/2026 |

---

## 📚 Deskripsi Proyek
Proyek ini merupakan Ujian Tengah Semester (UTS) Pemrograman Dasar
yang menggabungkan bahasa **C** dan **Python**.
Tema besar: **"Data, Game, dan Analisis Otomatis"**

---

## 🧩 Struktur Folder
Soal_Data_mahasiswa/
├── docs/
│   ├── Screenshot_soal1_menu.png
│   └── Screenshot_soal1_output.png
├── linked_list.c
├── linked_list.h
├── main.c
├── data_mahasiswa.csv
└── README.md

---

## 🧠 Penjelasan Program

### 🗂️ Soal 1 — Sistem Data Mahasiswa (C)
Program manajemen data mahasiswa menggunakan **linked list dinamis**.
- Input: nama, NIM, nilai tugas, UTS, UAS
- Hitung nilai akhir: 40% UAS + 30% UTS + 30% Tugas
- Fitur: tambah, tampilkan, cari, hapus (dengan free()), simpan ke CSV
- Konsep: struct, pointer, dynamic memory, file I/O

---

## 🚀 Cara Menjalankan

### ▶️ Soal 1 — C
```bash
gcc main.c linked_list.c -o program
./program
```

---

## 📊 Contoh Output

### Tabel Data Mahasiswa

Nama            NIM          Tugas    UTS    UAS NilaiAkhir  Mutu
agung           2013           70.0   80.0   70.0      73.00     B
jajang          2014           80.0   90.0   80.0      83.00     B
### File data_mahasiswa.csv
Nama,NIM,Tugas,UTS,UAS,NilaiAkhir,Mutu
agung,2013,70.0,80.0,70.0,73.00,B
jajang,2014,80.0,90.0,80.0,83.00,B

---

## 🏁 Commit History
feat: inisiasi struktur repo dan file C soal 1
feat: soal 1 selesai - linked list, input, tampil, cari, hapus, simpan CSV
docs: tambah screenshot output dan README

