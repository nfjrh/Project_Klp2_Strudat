#include "library.h"
#include <iomanip>

// ===== SEKOLAH =====
string lokasi[45] = {
"SDN Inpres Perintis Kemerdekaan", "SMPN 30 Makassar", "SMAN 21 Makassar",
"SD Inpres Karampuang 1", "SMP Kartika XX-1", "SMA Kartika XX-1",
"SD Inpres Pettarani", "SMP Muhammadiyah 12", "SMKN 3 Makassar",
"SD Inpres Pa'baeng-baeng", "SMP Muhammadiyah 1", "SMAN 11 Makassar",
"SDN Nusantara", "SMP Wahyu Makassar", "SMK Dharma Nusantara",
"SD Katolik Karya", "SMP Frater", "SMA Katolik Rajawali",
"SDN Sudirman 1", "SMPN 2 Makassar", "SMAN 1 Makassar",
"SD Inpres Maradekaya", "SMP Nasional Makassar", "SMA Nasional Makassar",
"SD Inpres Mamajang 1", "SMP Hang Tuah", "SMA Kristen Makassar",
"SDIT Al-Fityan", "SMPN 13 Makassar", "SMAN 9 Makassar",
"SD Islam Cikal Harapan", "SMP Al-Azhar 21", "SMA Al-Azhar 12",
"SD Katolik Mamajang", "SMPN 3 Makassar", "SMAN 14 Makassar",
"SDN Antang 1", "SMPN 19 Makassar", "SMAN 10 Makassar",
"SDN Borong", "SMPN 17 Makassar", "SMA LPP UMI",
"SDN Malengkeri 1", "SMPN 18 Makassar", "SMAN 4 Makassar"
};

//====== TAMBAH BUKU ========
void tambahBuku(){
    Buku b;
    cout<<"Judul :"; cin>>ws; getline(cin,b.judul);
    cout<<"Penulis : "; getline(cin,b.penulis);
    cout<<"Tahun   : "; cin>>b.tahun;
    cout<<"Stok    : "; cin>>b.stok;

    daftarBuku.push_back(b);
    root=insertBST(root,b.judul);
    cout<<"Buku berhasil ditambahkan!"<<endl;
}
// ===== PINJAM BUKU =====
bool pinjamBuku(const string& j){
    for(auto &b:daftarBuku)
        if(b.judul==j){
            if(b.stok>0){
                b.stok--;
                cout<<"Buku berhasil dipinjam!"<<endl;
                cout<<"Sisa stok \""<<b.judul<<"\" : "<<b.stok<<endl;
                return true;
            }
            cout<<"Stok buku habis!"<<endl;
            return false;
        }
        cout<<"Buku tidak ditemukan!"<<endl;
    return false;
}
// ===== KEMBALIKAN BUKU =====
bool kembalikanBuku(const string& j){
    for(auto &b:daftarBuku)
        if(b.judul==j){
            b.stok++;
            for(Node* t=head;t;t=t->next)
                if(t->judul==j && !t->kembali){
                    t->kembali=true;
                    break;
                }
                 cout<<"Buku berhasil dikembalikan!"<<endl;
            return true;
        }
         cout<<"Buku tidak ditemukan!"<<endl;
    return false;
}

// ===== LINKED LIST =====
void tambahRiwayat(string n,string j,string s){
    Node* baru=new Node{n,j,s,false,NULL};
    if(!head) head=baru;
    else{
        Node* t=head;
        while(t->next)
            t=t->next;
        t->next=baru;
    }
}
void tampilRiwayat(){
    cout<<"================ RIWAYAT ================"<<endl;
    for(Node* t=head;t;t=t->next){
        cout<<"Nama     : "<<t->nama<<endl;
        cout<<"Sekolah  : "<<t->sekolah<<endl;
        cout<<"Buku     : "<<t->judul<<endl;
        cout<<"Status   : "
            <<(t->kembali?"Sudah dikembalikan":"Belum dikembalikan")
            <<endl;
        cout<<"----------------------------------------"<<endl;
    }
}