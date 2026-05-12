#include "library.h"
#include <iomanip>

// ===== ARRAY =====
vector<Buku> daftarBuku;
BST* root=NULL;
Node* head=NULL;

// ===== DATA SEKOLAH =====
string lokasi[45]={
    "SDN Inpres Perintis Kemerdekaan","SMPN 30 Makassar","SMAN 21 Makassar",
    "SD Inpres Karampuang 1","SMP Kartika XX-1","SMA Kartika XX-1",
    "SD Inpres Pettarani","SMP Muhammadiyah 12","SMKN 3 Makassar",
    "SD Inpres Pa'baeng-baeng","SMP Muhammadiyah 1","SMAN 11 Makassar",
    "SDN Nusantara","SMP Wahyu Makassar","SMK Dharma Nusantara",
    "SD Katolik Karya","SMP Frater","SMA Katolik Rajawali",
    "SDN Sudirman 1","SMPN 2 Makassar","SMAN 1 Makassar",
    "SD Inpres Maradekaya","SMP Nasional Makassar","SMA Nasional Makassar",
    "SD Inpres Mamajang 1","SMP Hang Tuah","SMA Kristen Makassar",
    "SDIT Al-Fityan","SMPN 13 Makassar","SMAN 9 Makassar",
    "SD Islam Cikal Harapan","SMP Al-Azhar 21","SMA Al-Azhar 12",
    "SD Katolik Mamajang","SMPN 3 Makassar","SMAN 14 Makassar",
    "SDN Antang 1","SMPN 19 Makassar","SMAN 10 Makassar",
    "SDN Borong","SMPN 17 Makassar","SMA LPP UMI",
    "SDN Malengkeri 1","SMPN 18 Makassar","SMAN 4 Makassar"
};

// ===== BUKU =====
void initDataBuku(){
    daftarBuku={
    {"Laskar Pelangi","Andrea Hirata",2005,5},
    {"Sang Pemimpi","Andrea Hirata",2006,4},
    {"Edensor","Andrea Hirata",2007,3},
    {"Maryamah Karpov","Andrea Hirata",2008,2},
    {"Bumi","Tere Liye",2014,6},
    {"Bulan","Tere Liye",2015,5},
    {"Matahari","Tere Liye",2016,4},
    {"Bintang","Tere Liye",2017,3},
    {"Negeri 5 Menara","Ahmad Fuadi",2009,5},
    {"Ranah 3 Warna","Ahmad Fuadi",2011,4},
    {"Rantau 1 Muara","Ahmad Fuadi",2013,3},
    {"Ayat-Ayat Cinta","Habiburrahman",2004,6},
    {"Ketika Cinta Bertasbih","Habiburrahman",2007,4},
    {"Dilan 1990","Pidi Baiq",2014,7},
    {"Dilan 1991","Pidi Baiq",2015,6},
    {"Milea","Pidi Baiq",2016,5},
    {"Perahu Kertas","Dee Lestari",2009,4},
    {"Rectoverso","Dee Lestari",2008,3},
    {"Supernova","Dee Lestari",2001,2},
    {"5 cm","Donny Dhirgantoro",2005,5},
    {"Hujan","Tere Liye",2016,6},
    {"Filosofi Teras","Henry Manampiring",2018,4},
    {"Atomic Habits","James Clear",2018,5},
    {"Rich Dad Poor Dad","Robert Kiyosaki",1997,4},
    {"The Alchemist","Paulo Coelho",1988,3},
    {"Harry Potter","J.K. Rowling",1997,8},
    {"1984","George Orwell",1949,0},
    {"The Great Gatsby","F. Scott Fitzgerald",1925,2},
    {"To Kill a Mockingbird","Harper Lee",1960,3},
    {"Thinking Fast and Slow","Daniel Kahneman",2011,4}
    };
}

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
// ===== BST =====
BST* insertBST(BST* n,string j){
    if(!n) return new BST{j,NULL,NULL};
    if(j<n->judul)
        n->kiri=insertBST(n->kiri,j);
    else
        n->kanan=insertBST(n->kanan,j);
    return n;
}

bool cariBST(BST* n,string j){
    if(!n) return false;
    if(n->judul==j)
        return true;
    if(j<n->judul)
        return cariBST(n->kiri,j);
    return cariBST(n->kanan,j);
}
// ===== LINEAR SEARCH =====
int linearSearchPenulis(string key){
    for(int i=0;i<daftarBuku.size();i++)
        if(daftarBuku[i].penulis==key)
            return i;
    return -1;
}

// ===== BINARY SEARCH =====
int binarySearchStok(int key){
    vector<Buku> t=daftarBuku;
    sort(t.begin(),t.end(),[](Buku a,Buku b){
        return a.stok<b.stok;
    });
    int l=0,r=t.size()-1;
    while(l<=r){
        int m=(l+r)/2;
        if(t[m].stok==key)
            return m;
        else if(t[m].stok<key)
            l=m+1;
        else
            r=m-1;
    }
    return -1;
}

// ===== INSERTION SORT =====
void insertionSort(int mode){
    for(int i=1;i<daftarBuku.size();i++){
        Buku k=daftarBuku[i];
        int j=i-1;
        while(j>=0 && (
            (mode==1 && daftarBuku[j].tahun>k.tahun) ||
            (mode==2 && daftarBuku[j].tahun<k.tahun)
        )){
            daftarBuku[j+1]=daftarBuku[j];
            j--;
        }
        daftarBuku[j+1]=k;
    }
}
// ===== MERGE SORT =====
void merge(vector<Buku>&a,int l,int m,int r,int mode){
    vector<Buku> t;
    int i=l,j=m+1;
    while(i<=m && j<=r){
        if((mode==1 && a[i].tahun<a[j].tahun) ||
           (mode==2 && a[i].tahun>a[j].tahun))
            t.push_back(a[i++]);
        else
            t.push_back(a[j++]);
    }
    while(i<=m) t.push_back(a[i++]);
    while(j<=r) t.push_back(a[j++]);
    for(int k=0;k<t.size();k++)
        a[l+k]=t[k];
}

void mergeSort(vector<Buku>&a,int l,int r,int mode){
    if(l>=r) return;
    int m=(l+r)/2;
    mergeSort(a,l,m,mode);
    mergeSort(a,m+1,r,mode);
    merge(a,l,m,r,mode);
}

// ===== AUTO SORT =====
void autoSort(int mode){
    if(daftarBuku.size()<=20){
        insertionSort(mode);
        cout<<"Menggunakan Insertion Sort"<<endl;
    } else{
        mergeSort(daftarBuku,0,daftarBuku.size()-1,mode);
        cout<<"Menggunakan Merge Sort"<<endl;
    }
    cout<<(mode==1?
    "Diurutkan: Lama -> Baru":
    "Diurutkan: Baru -> Lama")<<endl;
}

// ===== GRAPH =====
typedef pair<int,int> pii;
const int V=45;
vector<pii> g[V];

void addEdge(int u,int v,int w){
    g[u].push_back({v,w});
    g[v].push_back({u,w});
}

// ===== INIT GRAPH =====
void initGraph(){
    for(int i=0;i<45;i+=3){
        addEdge(i,i+1,1);
        addEdge(i+1,i+2,1);
    }
    for(int i=0;i<42;i+=3)
        addEdge(i+2,i+3,3);
}

// ===== TAMPIL LOKASI =====
void tampilLokasi(){
    for(int i=0;i<V;i++)
        cout<<"["<<i<<"] "<<lokasi[i]<<endl;
}

// ===== DIJKSTRA =====
void dijkstra(int s,int t){
    vector<int>d(V,INT_MAX),p(V,-1);
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    d[s]=0;
    pq.push({0,s});
    while(!pq.empty()){
        int u=pq.top().second;
        pq.pop();
        for(auto e:g[u]){
            int v=e.first,w=e.second;
            if(d[u]+w<d[v]){
                d[v]=d[u]+w;
                p[v]=u;
                pq.push({d[v],v});
            }
        }
    }
    vector<int> path;

    for(int v=t;v!=-1;v=p[v])
        path.push_back(v);
    reverse(path.begin(),path.end());
    cout<<"========== RUTE =========="<<endl;
    for(int i=0;i<path.size();i++)
        cout<<" -> "<<lokasi[path[i]]<<endl;
    int jarak=d[t];
    int waktu=(jarak*60)/30;
    
    cout<<"=========================="<<endl;
    cout<<"Jumlah Sekolah : "<<path.size()<<endl;
    cout<<"Total Jarak    : "<<jarak<<" km"<<endl;
    cout<<"Estimasi Waktu : "<<waktu<<" menit"<<endl;
}