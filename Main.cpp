#include "library.h"

int main() {
    initGraph();
    initDataBuku();

    // masuk BST + sorting awal
    for (auto b : daftarBuku)
        root = insertBST(root, b.judul);

    mergeSort(daftarBuku, 0, daftarBuku.size()-1);

    int pilih;
    do {
        cout << endl;
        cout << "=== PERPUSTAKAAN KELILING ===" << endl;
        cout << "1. Tampil Buku" << endl;
        cout << "2. Cari Buku" << endl;
        cout << "3. Urutkan Buku" << endl;
        cout << "4. Pinjam Buku" << endl;
        cout << "5. Riwayat" << endl;
        cout << "6. Rute" << endl;
        cout << "0. Keluar" << endl;
        cout << "=============================" << endl;
        cout << "Masukkan Pilihan: ";
        cin >> pilih;

        if (pilih == 1) tampilBuku();

        else if (pilih == 2) {
            string j;
            cout << "Judul: " << endl;
            cin >> ws;
            getline(cin, j);

            if (linearSearch(j)!=-1) cout<<"Linear ditemukan"<<endl;
            if (binarySearch(j)!=-1) cout<<"Binary ditemukan"<<endl;
            if (cariBST(root,j)) cout<<"BST ditemukan"<<endl;
        }

        else if (pilih == 3) {
            insertionSort();
            cout<<"Sudah diurutkan"<<endl;
        }

        else if (pilih == 4) {
            string n,j;
            cout<<"Nama: "<<endl; cin>>n;
            cout<<"Judul: "<<endl; cin>>ws; getline(cin,j);
            tambahRiwayat(n,j);
        }

        else if (pilih == 5) tampilRiwayat();

        else if (pilih == 6) {
            tampilLokasi();
            int s,t;
            cout<<"Start: "<<endl; cin>>s;
            cout<<"Tujuan: "<<endl; cin>>t;
            dijkstra(s,t);
        }
    } while (pilih != 0);
}