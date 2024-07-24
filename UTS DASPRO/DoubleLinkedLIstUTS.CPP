#include <iostream>
using namespace std;

// Struktur data untuk node double linked list
struct DataUser {
    string playlist, Artis, Judul, Durasi;
    DataUser *prev;
    DataUser *next;
};

DataUser *kepala, *buntut, *cur, *newNode, *del, *afterNode;

// Fungsi untuk membuat double linked list
void buatdoublelinklist(string data[4]) {
    kepala = new DataUser();
    kepala->playlist = data[0];
    kepala->Artis = data[1];
    kepala->Judul = data[2];
    kepala->Durasi = data[3];
    kepala->prev = NULL;
    kepala->next = NULL;
    buntut = kepala;
}

// Fungsi untuk menghitung jumlah node dalam double linked list
int hitungDoubleLinkedList() {
    if (kepala == NULL) {
        cout << "Double Linked List belum dibuat!!!";
        return 0;
    } else {
        cur = kepala;
        int jumlah = 0;
        while (cur != NULL) {
            jumlah++;
            cur = cur->next;
        }
        return jumlah;
    }
}

// Fungsi untuk menambahkan node di awal
void addFirst(string data[4]) {
    if (kepala == NULL) {
        cout << "Double Linked List belum dibuat!!!";
    } else {
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

// Fungsi untuk menambahkan node di akhir
void addLast(string data[4]) {
    if (kepala == NULL) {
        cout << "Double Linked List belum dibuat";
    } else {
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

// Fungsi untuk menambahkan node di tengah
void addmidle(string data[4], int posisi) {
    if (kepala == NULL) {
        cout << "Double Linked List belum dibuat!!!";
    } else {
        if (posisi == 1) {
            cout << "Posisi 1 itu bukan posisi tengah!!!" << endl;
        } else if (posisi < 1 || posisi > hitungDoubleLinkedList()) {
            cout << "Posisi diluar jangkauan!" << endl;
        } else {
            newNode = new DataUser();
            newNode->playlist = data[0];
            newNode->Artis = data[1];
            newNode->Judul = data[2];
            newNode->Durasi = data[3];

            // Traversing
            cur = kepala;
            int nomor = 1;
            while (nomor < posisi - 1) {
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

// Fungsi untuk menghapus node berdasarkan data
void removeByData(string data[4]) {
    if (kepala == NULL) {
        cout << "Double Linked List belum dibuat" << endl;
        return;
    }

    // Cari node yang akan dihapus
    cur = kepala;
    while (cur != NULL) {
        if (cur->playlist == data[0] && cur->Artis == data[1] && cur->Judul == data[2] && cur->Durasi == data[3]) {
            // Node ditemukan, lakukan penghapusan
            if (cur == kepala) {
                // Hapus node di awal
                removeFirst();
            } else if (cur == buntut) {
                // Hapus node di akhir
                removeLast();
            } else {
                // Hapus node di tengah
                del = cur;
                cur->prev->next = cur->next;
                cur->next->prev = cur->prev;
                delete del;
            }
            return;
        }
        cur = cur->next;
    }

    cout << "Data tidak ditemukan dalam Double Linked List" << endl;
}

// Fungsi untuk menghapus node di awal
void removeFirst() {
    if (kepala == NULL) {
        cout << "Double Linked List belum dibuat";
    } else {
        del = kepala;
        kepala = kepala->next;
        kepala->prev = NULL;
        delete del;
    }
}

// Fungsi untuk menghapus node di akhir
void removeLast() {
    if (kepala == NULL) {
        cout << "Double Linked List belum dibuat";
    } else {
        del = buntut;
        buntut = buntut->prev;
        buntut->next = NULL;
        delete del;
    }
}

// Fungsi untuk menghapus node di tengah
void removeMiddle(int posisi) {
    if (kepala == NULL) {
        cout << "Double Linked List belum dibuat";
    } else {
        if (posisi == 1 || posisi == hitungDoubleLinkedList()) {
            cout << "Posisi bukan posisi tegah!!" << endl;
        } else if (posisi < 1 || posisi > hitungDoubleLinkedList()) {
            cout << "Posisi diluar jangkauan!!" << endl;
        } else {
            int nomor = 1;
            cur = kepala;
            while (nomor < posisi - 1) {
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

// Fungsi untuk mencetak isi double linked list
void cetakDoubleLinkedList() {
    if (kepala == NULL) {
        cout << "Double Linked List belum dibuat!!!" << endl;
    } else {
        cout << "Jumlah Data : " << hitungDoubleLinkedList() << endl;
        cout << "Isi Data : " << endl;
        cur = kepala;
        while (cur != NULL) {
            // Cetak
            cout << "playlist Lagu : " << cur->playlist << endl;
            cout << "Artis Lagu : " << cur->Artis << endl;
            cout << "Judul Lagu : " << cur->Judul << endl;
            cout << "Durasi Lagu : " << cur->Durasi << "\n" << endl;
            cur = cur->next;
        }
    }
}

int main() {
    string newData[4] = {"Velozta Music", "Riza Ainul Faroh", "Denting", "04.35"};
    buatdoublelinklist(newData);

    string data2[4] = {"GG Music", "Siska Amanda", "Dinding Pemisah", "04.23"};
    addFirst(data2);

    string data3[4] = {"Zariden Music", "Yesa Octavia", "Laut", "04.45"};
    addLast(data3);

}