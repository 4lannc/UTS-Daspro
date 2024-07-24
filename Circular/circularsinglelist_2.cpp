#include <iostream>
using namespace std;

// Deklarasi struktur untuk Circular Single Linked List
struct lagu {
    string judulLagu, Artis;
    float Durasi;

    lagu *next;
};

lagu *kepala, *buntut, *newNode, *cur, *del;

// create Circular Single Linked List
void createCircularSingleLinkedList(string dataBaru[3], float ukuran) {
    kepala = new lagu();
    kepala->judulLagu = dataBaru[0];
    kepala->Artis = dataBaru[1];
    kepala->Durasi = ukuran;
    buntut = kepala;
    buntut->next = kepala;
}

// add first
void addFirst(string data[3], float ukuran) {
    if (kepala == NULL) {
        cout << "Buat Linked List dulu!!" << endl;
    } else {
        newNode = new lagu();
        newNode->judulLagu = data[0];
        newNode->Artis = data[1];
        newNode->Durasi = ukuran;
        newNode->next = kepala;
        buntut->next = newNode;
        kepala = newNode;
    }
}

// add Last
void addLast(string data[3], float ukuran) {
    if (kepala == NULL) {
        cout << "Buat Linked List dulu!!" << endl;
    } else {
        newNode = new lagu();
        newNode->judulLagu = data[0];
        newNode->Artis = data[1];
        newNode->Durasi = ukuran;
        newNode->next = kepala;
        buntut->next = newNode;
        buntut = newNode;
    }
}

// add Middle
void addMiddle(string data[3], float ukuran, int posisi) {
    if (kepala == NULL) {
        cout << "Buat Linked List dulu!!" << endl;
    } else {
        if (posisi == 1) {
            cout << "Posisi satu bukan posisi tengah!!!" << endl;
        } else {
            newNode = new lagu();
            newNode->judulLagu = data[0];
            newNode->Artis = data[1];
            newNode->Durasi = ukuran;

            // transversing
            int nomor = 1;
            cur = kepala;
            while (nomor < posisi - 1) {
                cur = cur->next;
                nomor++;
            }
            newNode->next = cur->next;
            cur->next = newNode;
        }
    }
}

// remove First
void removeFirst() {
    if (kepala == NULL) {
        cout << "Buat Linked List dulu!!" << endl;
    } else {
        del = kepala;
        kepala = kepala->next;
        buntut->next = kepala;
        delete del;
    }
}

// remove Last
void removeLast() {
    if (kepala == NULL) {
        cout << "Buat Linked List dulu!!" << endl;
    } else {
        del = buntut;
        cur = kepala;
        while (cur->next != buntut) {
            cur = cur->next;
        }
        buntut = cur;
        buntut->next = kepala;
        delete del;
    }
}

// remove Middle
void removeMiddle(int posisi) {
    if (kepala == NULL) {
        cout << "Buat Linked List dulu!!" << endl;
    } else {
        // transversing
        int nomor = 1;
        cur = kepala;
        while (nomor < posisi - 1) {
            cur = cur->next;
            nomor++;
        }
        del = cur->next;
        cur->next = del->next;
        delete del;
    }
}

// Edit Node
void editNode(int posisi, string newJudul, string newArtis, float newDurasi) {
    if (kepala == NULL) {
        cout << "Buat Linked List dulu!!" << endl;
    } else {
        cur = kepala;
        int nomor = 1;
        while (nomor < posisi) {
            cur = cur->next;
            nomor++;
        }
        cur->judulLagu = newJudul;
        cur->Artis = newArtis;
        cur->Durasi = newDurasi;
    }
}

void printCircular() {
    if (kepala == NULL) {
        cout << "Buat Linked List dulu!!" << endl;
    } else {
        cout << "Data lagu" << endl;
        cout << "_________________________________________________" << endl;
        cout << "| Nama lagu\t| Artis Lagu\t| Durasi lagu\t|" << endl;
        cout << "_________________________________________________" << endl;
        cur = kepala;
        while (cur->next != kepala) {
            // print
            cout << "| " << cur->judulLagu << "\t| " << cur->Artis << "\t| " << cur->Durasi << "\t\t|" << endl;
            cur = cur->next;
        }
        cout << "| " << cur->judulLagu << "\t| " << cur->Artis << "\t| " << cur->Durasi << "\t\t|" << endl;
        cout << "_________________________________________________" << endl;
    }
}

int main() {
    string dataBaru[3] = {"Haning", "Evis Renata"};
    createCircularSingleLinkedList(dataBaru, 4.23);

    printCircular();

    string data[3] = {"Mari Bercinta", "Bunga Permata"};
    addFirst(data, 6.45);

    printCircular();

    string data2[3] = {"Empat Mata", "Adinda Rahel"};
    addLast(data2, 4.45);

    printCircular();

    string data3[3] = {"Kerinduan", "Ayu Cantika"};
    addMiddle(data3, 5.36, 2);

    printCircular();

    editNode(2, "Bunga Desa", "Dinda Teratu", 4.50);
    printCircular();

    removeMiddle(2);

    printCircular();

    removeFirst();

    printCircular();

    removeLast();

    printCircular();

    return 0;
}
