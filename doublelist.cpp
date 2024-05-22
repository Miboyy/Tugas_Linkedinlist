#include <iostream>

using namespace std;

struct Datauser{
    string nama,  username, email, password;
    Datauser *prev;//sebelumnya
    Datauser *next;//selanjutnya
};

Datauser *sirah, *ekor, *cur, *newnode, *del;


void doublelinkedlist( string data [4]){

    sirah = new Datauser();
    sirah -> nama = data[0];
    sirah -> username = data[1];
    sirah -> email = data[2];
    sirah -> password = data[3];
    sirah->prev = NULL;
    sirah->next = NULL;
    ekor = sirah;
}

//Penambah awalan
void addfirst( string data[4]){
if(sirah == NULL){
    cout << "double-link list belum dibuat";
}else{
        newnode = new Datauser();
        newnode -> nama = data[0];
        newnode -> username = data[1];
        newnode -> email = data[2];
        newnode -> password = data[3];
        newnode->prev = NULL;
        newnode->next = ekor; 
        sirah ->prev = newnode;
        sirah = newnode;
     }
}

//Penambahan node diakhir
void addlast( string data[4]){
if(sirah == NULL){
    cout << "double-link list belum dibuat";
}else{
        newnode = new Datauser();
        newnode -> nama = data[0];
        newnode -> username = data[1];
        newnode -> email = data[2];
        newnode -> password = data[3];
        newnode->prev = ekor;
        newnode->next = NULL; 
        ekor ->prev = newnode;
        ekor = newnode;
     }
}

//Hapusawal
void removefirst(){
    if(sirah == NULL){
    cout << "double-link list belum dibuat";
    }else{
        del = sirah;
        sirah = sirah->next;
        sirah->prev = NULL;
        delete del;
    }
}
//Hapusakhir
void removelast(){
    if(sirah == NULL){
    cout << "double-link list belum dibuat";
}else{
    del = ekor;
    ekor = ekor ->prev;
    ekor -> next = NULL;
    delete del;
    }
}


//Mencetak double linked list
void cetakdouble(){
if(sirah == NULL){
    cout << "double-link list belum dibuat";
}else{
    cout << "isi data : " << endl;
cur = sirah;
while (cur != NULL){
//print
            cout << "nama user : " << cur->nama << endl;
            cout << "username : " << cur->username <<endl;
            cout << "email user : " << cur->email << endl;
            cout << "password : " << cur->password << " \n"<< endl; 
            cur=cur->next;
        }
    }
}


int main(){
    string newData[4]= {"Romlah with perdy ", "perdy", 
    "perdy@gmail.com","12345"};
    doublelinkedlist(newData);
    cetakdouble();

    string data2[4] = {"Zainun Hilmi", "hilmi",
    "hilmi@gmal.com", "987654321"};
    addfirst( data2);
    cetakdouble();

    string data3[4] = {"pablo eskobar", "pablo",
    "pablo@gmal.com", "123saja"};
    addlast( data3);
    cetakdouble();


    removefirst();
    cetakdouble();

    removelast();
    cetakdouble();


}