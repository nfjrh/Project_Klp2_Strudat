#include <bits/stdc++.h>
using namespace std;

// ===== DATA BUKU =====
struct Buku {
    string judul;
    string penulis;
    int tahun;
};
extern vector<Buku> daftarBuku;

// ===== LINKED LIST =====
struct Node {
    string nama;
    string judul;
    Node* next;
};

void tambahRiwayat(string nama, string judul);
void tampilRiwayat();

// ===== BST =====
struct BST {
    string judul;
    BST* kiri;
    BST* kanan;
};

extern BST* root;

BST* insertBST(BST* node, string judul);
bool cariBST(BST* node, string judul);

// ===== BUKU =====
void tambahBuku();
void tampilBuku();
void initDataBuku();

// ===== SEARCH =====
int linearSearch(string judul);
int binarySearch(string judul);

// ===== SORT =====
void insertionSort();
void mergeSort(vector<Buku>& arr, int l, int r);

// ===== GRAPH =====
void initGraph();
void dijkstra(int start, int tujuan);
void tampilLokasi();