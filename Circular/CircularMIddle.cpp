#include <iostream>
#include <string>  // Menambahkan header untuk tipe data string

using namespace std;

// Struktur linked list
struct lagu{
  string JudulLagu, ArtisLagu;
  float DurasiLagu;

  // Pointer
  lagu *prev;
  lagu *next;
};

lagu *head, *tail, *cur, *del, *newNode, *afterNode;

// Fungsi membuat circular double Linked list
void createlagu(string JudulLagu, string ArtisLagu, float DurasiLagu) {
  head = new lagu();
  head->JudulLagu = JudulLagu;
  head->ArtisLagu = ArtisLagu;
  head->DurasiLagu = DurasiLagu;
  head->prev = head;
  head->next = head;
  tail = head;
}

// Add First
void addFirst(string JudulLagu, string ArtisLagu, float DurasiLagu) {
  if (head == NULL) {
    cout << "Buat Linked List dahulu!!" << endl;
  } else {
    newNode = new lagu();
    newNode->JudulLagu = JudulLagu;
    newNode->ArtisLagu = ArtisLagu;
    newNode->DurasiLagu = DurasiLagu;
    newNode->prev = tail;
    newNode->next = head;
    head->prev = newNode;
    tail->next = newNode;
    head = newNode;
  }
}

// Add Last
void addLast(string JudulLagu, string ArtisLagu, float DurasiLagu) {
  if (head == NULL) {
    cout << "Buat Linked List dahulu!!" << endl;
  } else {
    newNode = new lagu();
    newNode->JudulLagu = JudulLagu;
    newNode->ArtisLagu = ArtisLagu;
    newNode->DurasiLagu = DurasiLagu;
    newNode->prev = tail;
    newNode->next = head;
    head->prev = newNode;
    tail->next = newNode;
    tail = newNode;
  }
}

// Add Middle
void addMiddle(string JudulLagu, string ArtisLagu, float DurasiLagu, int posisi) {
  if (head == NULL) {
    cout << "Buat Linked List dahulu!!" << endl;
  } else {
    if (posisi == 1) {
      cout << "Posisi 1 bukan posisi tengah" << endl;
    } else if (posisi < 1) {
      cout << "Posisi diluar jangkauan" << endl;
    } else {
      newNode = new lagu();
      newNode->JudulLagu = JudulLagu;
      newNode->ArtisLagu = ArtisLagu;
      newNode->DurasiLagu = DurasiLagu;

      // Travesing
      cur = head;
      int nomor = 1;
      while (nomor < posisi - 1) {
        cur = cur->next;
        nomor++;
      }
      afterNode = cur->next;
      cur->next = newNode;
      afterNode->prev = newNode;
      newNode->prev = cur;
      newNode->next = afterNode;
    }
  }
}

// Remove First
void removeFirst() {
  if (head == NULL) {
    cout << "Buat Linked List dahulu!!" << endl;
  } else {
    del = head;
    head = head->next;
    tail->next = head;
    head->prev = tail;
    delete del;
  }
}

// Remove Last
void removeLast() {
  if (head == NULL) {
    cout << "Buat Linked List dahulu!!" << endl;
  } else {
    del = tail;
    tail = tail->prev;
    tail->next = head;
    head->prev = tail;
    delete del;
  }
}

// Remove Middle
void removeMiddle(int posisi) {
  if (head == NULL) {
    cout << "Buat Linked List dahulu!!" << endl;
  } else {
    if (posisi == 1) {
      cout << "Posisi 1 bukan posisi tengah" << endl;
    } else if (posisi < 1) {
      cout << "Posisi diluar jangkauan" << endl;
    } else {
      // Travesing
      cur = head;
      int nomor = 1;
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

// Edit Node
void editNode(int posisi, string newJudul, string newArtis, float newDurasi) {
  if (head == NULL) {
    cout << "Buat Linked List dahulu!!" << endl;
  } else {
    cur = head;
    int nomor = 1;
    while (nomor < posisi) {
      cur = cur->next;
      nomor++;
    }
    cur->JudulLagu = newJudul;
    cur->ArtisLagu = newArtis;
    cur->DurasiLagu = newDurasi;
  }
}

// Fungsi print
void printlagu() {
  if (head == NULL) {
    cout << "Buat Linked List dahulu!!" << endl;
  } else {
    cout << "Data Lagu : " << endl;
    cur = head;
    while (cur->next != head) {
      // Print
      cout << "Judul Lagu : " << cur->JudulLagu << endl;
      cout << "Artis Lagu : " << cur->ArtisLagu << endl;
      cout << "Durasi Lagu : " << cur->DurasiLagu << " Menit.." << endl;

      // Step
      cur = cur->next;
    }
    // Print last node
    cout << "Judul Lagu : " << cur->JudulLagu << endl;
    cout << "Artis Lagu : " << cur->ArtisLagu << endl;
    cout << "Durasi Lagu : " << cur->DurasiLagu << " Menit.." << endl;
  }
}

int main() {
  createlagu("Cantik Tak Menarik", "Dyo Haw", 4.33);
//   printlagu();

  addFirst("Answer", "Don't not artist", 3.33);
//   printlagu();

  addLast("Lamunan", "Dinda Teratu", 5.34);
//   printlagu();

  addMiddle("Ibu Kota", "Eva Vernanda", 4.34, 2);
//   printlagu();

  editNode(2, "Bunga Desa", "Tasya Rosmala", 4.50);
  printlagu();

  removeMiddle(2);
//   printlagu();

  return 0;
}
