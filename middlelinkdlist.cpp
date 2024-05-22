#include <iostream>

using namespace std;

struct Buku
{
    string judul, pengarang;
    int thn;

    Buku *next;
};

Buku *sirah, *bt, *ini, *nodeBaru, *hapuspokoke;

void ngisiLinkedlist (string judul, string pengarang, int thn) {
    sirah = new Buku();
    sirah->judul = judul;
    sirah->pengarang = pengarang;
    sirah->thn = thn;
    sirah->next = NULL;
    bt = sirah;    
}

void tambahAwal (string judul, string pengarang, int thn) {
    nodeBaru = new Buku();
    nodeBaru->judul = judul;
    nodeBaru->pengarang = pengarang;
    nodeBaru->thn = thn;
    nodeBaru->next = sirah;
    sirah = nodeBaru;
}

void tambahGuri (string judul, string pengarang, int thn) {
    nodeBaru = new Buku();
    nodeBaru->judul = judul;
    nodeBaru->pengarang = pengarang;
    nodeBaru->thn = thn;
    nodeBaru->next = NULL;
    bt->next = nodeBaru;
    bt = nodeBaru;
}
// Tambah tengah single list

void tambahtengah (string judul, string pengarang, int thn,int posisi) {
    nodeBaru = new Buku();
    nodeBaru->judul = judul;
    nodeBaru->pengarang = pengarang;
    nodeBaru->thn = thn;
    
    //transversing
    ini = sirah;
    int nomer = 1;
    while(nomer < posisi - 1){
        ini = ini->next;
        nomer++;
    }
    nodeBaru->next = ini->next;
    ini->next = nodeBaru;
}

void ubahAwal(string judul, string pengarang, int thn){
    sirah->judul = judul;
    sirah->pengarang = pengarang;
    sirah->thn = thn;
}


void ubahLast(string judul, string pengarang, int thn){
    bt->judul = judul;
    bt->pengarang = pengarang;
    bt->thn = thn;
}

void hapusAwal () {
    hapuspokoke = sirah;
    sirah = sirah->next;
    delete hapuspokoke;
}

void hapusLast () {
    hapuspokoke = bt;
    ini = sirah;
    while (ini->next != bt)
    {
        ini = ini->next;
    }
    bt = ini;
    bt->next = NULL;
    delete hapuspokoke;  
}

void cetakLinkedlist(){
    ini = sirah;
    while (ini != NULL)
    {
        cout << "Judul Buku : " << ini->judul << endl;
        cout << "Pengarang Buku : " << ini->pengarang << endl;
        cout << "Tahun terbit Buku : " << ini->thn << endl;
        cout << endl;
    ini = ini->next;
    }
    
}

int main () {
 ngisiLinkedlist("Ngoding", "Nuha", 2025);
 tambahAwal("Mancing", "eko", 2033);
 tambahGuri("Sekolah", "wijayanto", 2021);
 tambahtengah();

//  hapusAwal();

//  hapusLast();


 ubahAwal("Senja pagi buta", "uden", 1923);
 ubahLast("Fajar sore itu", "gamblok", 2000);
 cetakLinkedlist();

 return 0;
}