#include "library.h"

int main(){
    initGraph();
    initDataBuku();

    for(auto b:daftarBuku)
        root=insertBST(root,b.judul);
    int p;
    do{
        cout<<"==================================="<<endl;
        cout<<"   === PERPUSTAKAAN KELILING ==="<<endl;
        cout<<"1. Tampil Buku"<<endl;
        cout<<"2. Cari Buku"<<endl;
        cout<<"3. Pinjam Buku"<<endl;
        cout<<"4. Riwayat"<<endl;
        cout<<"5. Rute Sekolah"<<endl;
        cout<<"6. Urutkan Buku"<<endl;
        cout<<"7. Tambah Buku"<<endl;
        cout<<"8. Kembalikan Buku"<<endl;
        cout<<"0. Keluar"<<endl;
        cout<<"==================================="<<endl;
        cout<<"Pilihan : ";
        cin>>p;
    
        if(p==1){
            tampilBuku();
        }

        // ===== SEARCHING =====
        else if(p==2){
            int pilih;
            cout<<"===== METODE PENCARIAN ====="<<endl;
            cout<<"1. Linear Search (Penulis)"<<endl;
            cout<<"2. Binary Search (Stok)"<<endl;
            cout<<"3. Binary Search Tree (Judul)"<<endl;
            cout<<"Pilih : ";
            cin>>pilih;

            // ===== LINEAR SEARCH =====
            if(pilih==1){
                string penulis;
                cout<<"Nama Penulis : ";
                cin>>ws;
                getline(cin,penulis);
                int idx=linearSearchPenulis(penulis);
                if(idx!=-1){
                    cout<<"Buku ditemukan!"<<endl;
                    cout<<"Judul   : "<<daftarBuku[idx].judul<<endl;
                    cout<<"Penulis : "<<daftarBuku[idx].penulis<<endl;
                    cout<<"Tahun   : "<<daftarBuku[idx].tahun<<endl;
                    cout<<"Stok    : "<<daftarBuku[idx].stok<<endl;
                } else {
                    cout<<"Penulis tidak ditemukan"<<endl;
                }
            }

            // ===== BINARY SEARCH =====
            else if(pilih==2){
                int stok;
                cout<<"Cari Stok : ";
                cin>>stok;
                int idx=binarySearchStok(stok);
                if(idx!=-1){
                    cout<<"Buku dengan stok "<<stok<<" ditemukan"<<endl;
                    cout<<"===================================="<<endl;
                    for(auto b:daftarBuku){
                        if(b.stok==stok){
                            cout<<"Judul   : "<<b.judul<<endl;
                            cout<<"Penulis : "<<b.penulis<<endl;
                            cout<<"Tahun   : "<<b.tahun<<endl;
                            cout<<"Stok    : "<<b.stok<<endl;
                            cout<<"------------------------------------"<<endl;
                        }
                    }
                } else {
                    cout<<"Stok tidak ditemukan"<<endl;
                }
            }

            // ===== BST SEARCH =====
            else if(pilih==3){
                string judul;
                cout<<"Judul Buku : ";
                cin>>ws;
                getline(cin,judul);
                if(cariBST(root,judul)){
                    cout<<"Buku ditemukan"<<endl;
                } else {
                    cout<<"Buku tidak ditemukan"<<endl;
                }
            }
        }

        // ===== PINJAM =====
        else if(p==3){
            string n,s,j;
            cout<<"Nama     : ";
            getline(cin>>ws,n);
            cout<<"Sekolah  : ";
            getline(cin,s);
            cout<<"Judul    : ";
            getline(cin,j);
            if(pinjamBuku(j))
                tambahRiwayat(n,j,s);
        }

        // ===== RIWAYAT =====
        else if(p==4){
            tampilRiwayat();
        }

        // ===== GRAPH =====
        else if(p==5){
            tampilLokasi();
            int s,t;
            cout<<"Lokasi Awal   : ";
            cin>>s;
            cout<<"Lokasi Tujuan : ";
            cin>>t;
            dijkstra(s,t);
        }

        // ===== SORT =====
        else if(p==6){
            int mode;
            cout<<"1. Lama -> Baru"<<endl;
            cout<<"2. Baru -> Lama"<<endl;
            cout<<"Pilih Mode : ";
            cin>>mode;
            autoSort(mode);
        }

        // ===== TAMBAH BUKU =====
        else if(p==7){
            tambahBuku();
        }

        // ===== KEMBALIKAN =====
        else if(p==8){
            string j;
            cout<<"Judul Buku : ";
            cin>>ws;
            getline(cin,j);
            kembalikanBuku(j);
        }
    }while(p!=0);
}