#include <bits/stdc++.h>
using namespace std;

// ===== BUKU =====
struct Buku{
    string judul,penulis;
    int tahun,stok;
};

// ===== ARRAY =====
extern vector<Buku> daftarBuku;
extern string lokasi[45];

// ===== LINKED LIST =====
struct Node{
    string nama,judul,sekolah;
    bool kembali;
    Node* next;
};

void tambahRiwayat(string,string,string);
void tampilRiwayat();