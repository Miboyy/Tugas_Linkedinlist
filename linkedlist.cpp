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
 ngisiLinkedlist("Bohong", "bagus", 2029);
 tambahAwal("Mancing", "Romlah", 2033);
 tambahGuri("Sekolah", "suteno", 2021);
//  hapusAwal();
//  hapusLast();


 ubahAwal("Melihat pemandangan senja", "uden", 1921);
 ubahLast("Aku Pada Mu", "hilmi", 2005);
 cetakLinkedlist();

 return 0;
}