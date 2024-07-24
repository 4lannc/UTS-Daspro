#include <iostream>
using namespace std;

// deklarasi 
struct DataUser{
  string playlist, Artis, Judul, Durasi;
  DataUser *prev;
  DataUser *next;
};

DataUser *kepala, *buntut, *cur, *newNode, *del, *afterNode;


// Create Double Linked List
void buatdoublelinklist( string data[4] ){
  kepala = new DataUser();
  kepala->playlist = data[0];
  kepala->Artis = data[1];
  kepala->Judul = data[2];
  kepala->Durasi = data[3];
  kepala->prev = NULL;
  kepala->next = NULL;
  buntut = kepala;
}


// hitung Double Linked List
int hitungDoubleLinkedList()
{
  if( kepala == NULL ){
    cout << "Double Linked List belum dibuat!!!";
  }else{
    cur = kepala;
    int jumlah = 0;
    while( cur != NULL ){
      jumlah++;      
      //step
      cur = cur->next;
    }
    return jumlah;
  }
}


// Add First
void addFirst( string data[4] ){
  if( kepala == NULL ){
    cout << "Double Linked List belum dibuat!!!";
  }else{
    newNode = new DataUser();
    newNode->playlist = data[0];
    newNode->Artis = data[1];
    newNode->Judul = data[2];
    newNode->Durasi = data[3];
    newNode->prev = NULL;
    newNode->next = kepala;
    kepala->prev = newNode;
    kepala = newNode;
  }
}

// Add Last
void addLast( string data[4] ){
  if( kepala == NULL ){
    cout << "Double Linked List belum dibuat";
  }else{
    newNode = new DataUser();
    newNode->playlist = data[0];
    newNode->Artis = data[1];
    newNode->Judul = data[2];
    newNode->Durasi = data[3];
    newNode->prev = buntut;
    newNode->next = NULL;
    buntut->next = newNode;
    buntut = newNode;
  }
}

// Add Middle
void addmidle( string data[4], int posisi ){
  if( kepala == NULL ){
    cout << "Double Linked List belum dibuat!!!";
  }else{

    if( posisi == 1 ){
      cout << "Posisi 1 itu bukan posisi tengah!!!" << endl;
    }else if( posisi < 1 || posisi > hitungDoubleLinkedList() ){
      cout << "Posisi diluar jangkauan!" << endl;
    }else{
      newNode = new DataUser();
      newNode->playlist = data[0];
      newNode->Artis = data[1];
      newNode->Judul = data[2];
      newNode->Durasi = data[3];

      // tranversing
      cur = kepala;
      int nomor = 1;
      while( nomor <  posisi - 1){
        cur = cur->next;
        nomor++;
      }

      afterNode = cur->next;
      newNode->prev = cur;
      newNode->next = afterNode;
      cur->next = newNode;
      afterNode->prev = newNode;
    }

  }
}

// remove First
void removeFirst()
{
  if( kepala == NULL ){
    cout << "Double Linked List belum dibuat";
  }else{
    del = kepala;
    kepala = kepala->next;
    kepala->prev = NULL;
    delete del;
  }
}



// remove Last
void removeLast()
{
  if( kepala == NULL ){
    cout << "Double Linked List belum dibuat";
  }else{
    del = buntut;
    buntut = buntut->prev;
    buntut->next = NULL;
    delete del;
  }
}

// remove Middle
void removeMiddle(int posisi){
  if( kepala == NULL ){
    cout << "Double Linked List belum dibuat";
  }else{
    if( posisi == 1 || posisi == hitungDoubleLinkedList() ){
      cout << "Posisi bukan posisi tegah!!" << endl;
    }else if( posisi < 1 || posisi > hitungDoubleLinkedList() ){
      cout << "Posisi diluar jangkauan!!" << endl;
    }else{
      int nomor = 1;
      cur = kepala;
      while( nomor < posisi - 1 ){
        cur = cur->next;
        nomor++;
      }
      del = cur->next;
      afterNode = del->next;
      cur->next = afterNode;
      afterNode->prev = cur;
      delete del;
    }
  }
}

// cetak Double Linked List
void cetakDoubleLinkedList()
{
  if( kepala == NULL ){
    cout << "Double Linked List belum dibuat!!!";
  }else{
    cout << "Jumlah Data : " << hitungDoubleLinkedList() << endl;
    cout << "Isi Data : " << endl;
    cur = kepala;
    while( cur != NULL ){
      // cetak
      cout << "playlist Lagu : " << cur->playlist << endl;
      cout << "Artis Lagu : " << cur->Artis << endl;
      cout << "Judul Lagu : " << cur->Judul << endl;
      cout << "Durasi Lagu : " << cur->Durasi << "\n" << endl;

      cur = cur->next;
    }
  }
}

int main(){

  string newData[4] = {"Velozta Music", "Riza Ainul Faroh", "Denting", "04.35"};
  buatdoublelinklist(newData);
  // cetakDoubleLinkedList();
  string data2[4] = {"GG Music", "Siska Amanda", "Dinding Pemisah", "04.23"};

  addFirst( data2 );
  // cetakDoubleLinkedList();

  string data3[4] = {"Zariden Music", "Yesa Octavia", "Laut", "04.45"};
  addLast( data3 );
  // cetakDoubleLinkedList();

  string data4[4] = {"MH Music", "Din Anesia", "Anak Lanang", "04.36"};
  addmidle(data4, 3);
  // cetakDoubleLinkedList();
  removeMiddle(3);
  cetakDoubleLinkedList();


}