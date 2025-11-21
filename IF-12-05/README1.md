[UTS PRAKTIKUM STRUKTUR DATA]

Identitas Pengumpul

Nama: [ZALFA ATHALLAH PASHA HERMAWAN]

NIM: [103112400196]

Kelas: [S1IF-12-05]

Soal : Genap

1. Kode Program

Berikut adalah kode program untuk mengimplementasikan Doubly Linked list


```File: main.cpp
 * Author: [Zalfa Athallah Pasha Hermawan]
 * NIM: [103112400196]
 * Deskripsi: Program untuk menentukan apakah sebuah bilangan
 * yang diinput oleh user adalah soal genap

#include <iostream>

using namespace std;

  

struct Node {

    int data;

    Node *prev, *next;

};

  

class DLL {

private:

    Node *head = nullptr, *tail = nullptr;

  

public:

    void insert(int v) {

        Node* n = new Node{v, tail, nullptr};

        if (!head) head = n;

        else tail->next = n;

        tail = n;

    }

  

    void deleteLast() {

        if (!tail) { cout << "List kosong.\n"; return; }

        Node* temp = tail;

        if (head == tail) head = tail = nullptr;

        else {

            tail = tail->prev;

            tail->next = nullptr;

        }

        delete temp;

    }

  

    void view() {

        for (Node* c = head; c; c = c->next) cout << c->data << " ";

        cout << endl;

    }

  

    void reverse() {

        Node* cur = head, *temp = nullptr;

        while (cur) {

            temp = cur->prev;

            cur->prev = cur->next;

            cur->next = temp;

            cur = cur->prev;

        }

        if (temp) head = temp->prev;

    }

};

  

int main() {

    DLL list;

    int c, v;

  

    do {

        cout << "1 insert, 2 delete, 3 view, 4 reverse+view, 0 exit\n";

        cin >> c;

  

        if (c == 1) cin >> v, list.insert(v);

        else if (c == 2) list.deleteLast();

        else if (c == 3) list.view();

        else if (c == 4) list.reverse(), list.view();

  

    } while (c != 0);

}
```

2. Penjelasan Kode

Program ini membuat struktur doubly linked list dengan node yang memiliki pointer ke depan dan ke belakang. Fungsi insert menambahkan data di bagian akhir, deleteLast menghapus node terakhir, view menampilkan seluruh isi list dari depan, dan reverse membalik urutan list dengan menukar pointer prev dan next pada setiap node. Bagian main menyediakan menu agar pengguna dapat mencoba semua fitur tersebut secara langsung.

3. Output Program

Berikut adalah hasil eksekusi program (output) ketika dijalankan.
![](output/soal2.png)

4. Penjelasan Lanjutan (Analisis Output)
Struktur dua arah pada doubly linked list membuat proses pembalikan data lebih efisien karena tidak perlu membuat node baru atau menyalin data. Proses reverse hanya mengubah arah pointer sehingga cepat dan hemat memori. Menu interaktif dalam program membantu pengguna melihat perubahan list setiap kali data ditambah, dihapus, atau dibalik.


5. Kesimpulan

Berdasarkan implementasi dan pengujian kode di atas, dapat disimpulkan bahwa:

Program ini berhasil mengimplementasikan operasi dasar pada doubly linked list seperti penambahan, penghapusan, penampilan, dan pembalikan urutan data.  dan sudah sesuai dengan soal yang diberikan asisten praktikum 