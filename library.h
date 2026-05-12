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

// ===== BST =====
struct BST{
    string judul;
    BST *kiri,*kanan;
};

extern BST* root;

BST* insertBST(BST*,string);
bool cariBST(BST*,string);

// ===== LINEAR SEARCH =====
int linearSearchPenulis(string);

// ===== BINARY SEARCH =====
int binarySearchStok(int);

// ===== BUKU =====
void initDataBuku();
void tampilBuku();
void tambahBuku();
bool pinjamBuku(const string&);
bool kembalikanBuku(const string&);

// ===== SORT =====
void insertionSort(int);
void mergeSort(vector<Buku>&,int,int,int);
void autoSort(int);

// ===== GRAPH =====
void initGraph();
void tampilLokasi();
void dijkstra(int,int);
