#include <bits/stdc++.h>
using namespace std;

// ===== BUKU =====
struct Buku {
    string judul, penulis;
    int tahun;
    int stok;
};

// ===== ARRAY =====
extern vector<Buku> daftarBuku;
extern string lokasi[45];

// ===== LINKED LIST (RIWAYAT) =====
struct Node {
    string nama, judul, sekolah;
    bool kembali; // false = belum, true = sudah
    Node* next;
};

void tambahRiwayat(string, string, string);
void tampilRiwayat();