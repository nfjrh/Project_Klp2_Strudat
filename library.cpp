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
