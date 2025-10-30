# Template Laporan Praktikum Struktur Data

## 1. Nama, NIM, Kelas
- **Nama**: Zalfa Athallah Pasha Hermawan
- **NIM**: 103112400196
- **Kelas**: S1IF-12-05

## 2. Motivasi Belajar Struktur Data
Struktur data penting dipelajari karena jadi dasar dalam bikin program supaya lebih teratur. Selain buat ngerjain tugas, materi ini juga sering kepakai di aplikasi sehari-hari dan bisa jadi bekal kalau nanti udah masuk dunia kerja.
## 3. Dasar Teori
Struktur data adalah cara untuk menyimpan dan mengorganisir data dalam komputer agar dapat digunakan secara efisien. Berikut adalah teori dasar mengenai Array, Pointer, dan Fungsi:

- **Array**: Struktur data yang menyimpan elemen dengan tipe data sama dalam urutan tertentu dan diakses menggunakan indeks.
- **Linked List**: Kumpulan simpul (node) yang saling terhubung melalui pointer, di mana setiap simpul berisi data dan alamat simpul berikutnya.
- **Stack**: Struktur data dengan prinsip _Last In First Out (LIFO)_, di mana elemen yang terakhir dimasukkan akan dikeluarkan terlebih dahulu.
- **Queue**: Struktur data dengan prinsip _First In First Out (FIFO)_, di mana elemen yang pertama dimasukkan akan dikeluarkan terlebih dahulu.
- **Graf**: Struktur data yang digunakan untuk menggambarkan hubungan antar objek yang disebut simpul (vertex) dan hubungan antar simpul yang disebut busur (edge).
- **Pohon (Tree)**: Struktur data hierarkis yang terdiri dari simpul dan tepi, dengan satu simpul sebagai akar (root) dan simpul lainnya sebagai anak.

## 4. Guided
### 4.1 Guided 1
```cpp

#include <iostream>
#define Nil NULL
using namespace std;

typedef int infotype;
typedef struct elmlist *address;


struct elmlist{
    infotype info;
    address next;
    address prev;
};


struct List {
    address first;
    address last;
};


void insertFirst(List &L, address P) {
    P->next = L.first;
    P->prev = Nil;
    if (L.first != Nil) L.first->prev = P;
    else L.last = P ;
    L.first = P;
}


void insertLast(List &L, address P) {
    P->prev = L.last;
    P->next = Nil;
    if (L.last != Nil) L.last -> next = P;
    else L.first = P;
    L.last = P;
}


void insertAfter (List &L, address P, address R) {
    P->next = R->next;
    P->prev = R;
    if (R->next != Nil) R->next->prev = P;
    else L.last = P;
    R->next = P;
}


address alokasi(infotype x) {
    address P = new elmlist;
    P->info = x;
    P->next = Nil;
    P->prev = Nil;
    return P;
}


void printInfo(List L) {
    address P = L.first;
    while (P != Nil) {
        cout << P->info << " ";
        P = P-> next ;
    }
    cout << endl;
}


int main(){
    List L;
    L.first = Nil;
    L.last = Nil;
    address P1 = alokasi(1);
    insertFirst(L, P1);
    address P2 = alokasi(2);
    insertLast(L, P2);
    address P3 = alokasi(3);
    insertAfter(L, P3, P1);
    printInfo(L);
    return 0;
}
```

**Penjelasan** : Program ini menggunakan **doubly linked list** untuk menyimpan dan mengelola data secara berurutan. Setiap elemen terhubung ke elemen sebelumnya dan sesudahnya. Program memiliki fungsi untuk menambah data di awal, di akhir, dan setelah elemen tertentu, serta menampilkan seluruh isi list. Pada bagian utama, program menambahkan tiga data (1, 2, dan 3) lalu menampilkan hasil akhirnya yaitu **1 3 2**.

**Output** :
![](output/G1.png)

### 4.2 Guided 2
```cpp
#include <iostream>

using namespace std;

#define Nil NULL

  

typedef int infotype;

typedef struct elmlist *address;

  

struct elmlist {

    infotype info;

    address next;

    address prev;

};

  

struct List {

    address first;

    address last;

};

  

address alokasi(infotype x) {

    address P = new elmlist;

    P->info = x ; P->next = Nil; P->prev = Nil; return P;

}

void dealokasi(address &P) {delete P; P = Nil;}

void insertFirst(List &L, address P) {

    P->next = L.first; P->prev = Nil;

    if (L.first != Nil) L.first->prev = P; else L.last = P;

    L.first = P;

}

  

void printInfo(List L) {

    address P = L.first; while (P != Nil) {cout << P->info << " "; P = P-> next;} cout;

}

void deleteFirst(List &L, address &P) {

    P = L.first; L.first = L.first->next;

    if (L.first != Nil) L.first->prev = Nil; else L.last = Nil;

    P->next = Nil; P->prev = Nil;

}

  

void deleteLast (List &L, address &P) {

    P = L.last; L.last = L.last->prev;

    if (L.last != Nil) L.last->next = Nil; else L.first = Nil;

    P->prev = Nil; P->next = Nil;

}

  

void deleteAfter (List &L, address &P, address R) {

    P = R->next; R->next = P->next;

    if (P->next != Nil) P->next->prev = R; else L.last = R;

    P->prev = Nil; P->next = Nil;

}

  

int main() {

    List L; L.first = Nil; L.last = Nil;

    insertFirst(L, alokasi (1)); insertFirst(L, alokasi(2)); insertFirst (L, alokasi(3));

    printInfo(L);

    address P; deleteFirst(L, P); dealokasi (P);

    deleteAfter (L, P, L.first); dealokasi (P);

    printInfo(L);

    return 0;

}
```

**Penjelasan** : Program ini merupakan implementasi **doubly linked list** dengan fitur penambahan dan penghapusan elemen. Program dapat menambah data di awal list, menampilkan isi list, serta menghapus data di awal, akhir, atau setelah elemen tertentu. Pada fungsi utama, data 3, 2, dan 1 dimasukkan ke dalam list, kemudian beberapa elemen dihapus, dan hasil akhirnya ditampilkan di layar.

**OUTPUT** :
![](output/G2.png)
### 4.3 Guided 3
```cpp

```

**PENJELASAN** : 

**OUTPUT** : 
![](output/3.png)

### 4.4 Guided 4
```cpp
```

***OUTPUT*** :
![](output/suhu.png)

***PENJELASAN*** : 
## 5. Unguided
### 5.1 Unguided 1
```cpp
#include <iostream>

#define Nil NULL

using namespace std;

  

typedef int infotype;

typedef struct elmlist *address;

  
  

struct elmlist{

    infotype info;

    address next;

    address prev;

};

  
  

struct List {

    address first;

    address last;

};

  
  

void insertFirst(List &L, address P) {

    P->next = L.first;

    P->prev = Nil;

    if (L.first != Nil) L.first->prev = P;

    else L.last = P ;

    L.first = P;

}

  
  

void insertLast(List &L, address P) {

    P->prev = L.last;

    P->next = Nil;

    if (L.last != Nil) L.last -> next = P;

    else L.first = P;

    L.last = P;

}

  
  

void insertAfter (List &L, address P, address R) {

    P->next = R->next;

    P->prev = R;

    if (R->next != Nil) R->next->prev = P;

    else L.last = P;

    R->next = P;

}

  
  

address alokasi(infotype x) {

    address P = new elmlist;

    P->info = x;

    P->next = Nil;

    P->prev = Nil;

    return P;

}

  
  

void printInfo(List L) {

    address P = L.first;

    while (P != Nil) {

        cout << P->info << " ";

        P = P-> next ;

    }

    cout << endl;

}

  

void insertBefore(List &L, address P, address R) {

    P->next = R;

    P->prev = R->prev;

    if (R->prev != Nil)

        R->prev->next = P;

    else

        L.first = P;

    R->prev = P;

}

  

void printReverse(List L) {

    address P = L.last;

    while (P != Nil) {

        cout << P->info << " ";

        P = P->prev;

    }

    cout << endl;

}

  
  

int main() {

    List L;

    L.first = Nil;

    L.last = Nil;

  

    cout << "TASK 1: INSERT OPERATIONS" << endl;

  

    // Membuat list awal: 1 3 2

    address P1 = alokasi(1);

    insertFirst(L, P1);

    address P2 = alokasi(2);

    insertLast(L, P2);

    address P3 = alokasi(3);

    insertAfter(L, P3, P1);

  

    cout << "List awal:" << endl;

    cout << "Forward: ";

    printInfo(L);

    cout << "Backward: ";

    printReverse(L);

  

    // InsertBefore: 4 sebelum 2

    address P4 = alokasi(4);

    insertBefore(L, P4, P2);

    cout << "Berhasil insert 4 sebelum 2" << endl;

  

    // InsertBefore: 5 sebelum 1

    address P5 = alokasi(5);

    insertBefore(L, P5, P1);

    cout << "Berhasil insert 5 sebelum 1" << endl;

  

    cout << "List setelah insertBefore:" << endl;

    cout << "Forward: ";

    printInfo(L);

    cout << "Backward: ";

    printReverse(L);

  

    return 0;

}
```

***OUTPUT*** :
![](output/U1.png)

***PENJELASAN*** : Program ini merupakan implementasi **doubly linked list** dengan berbagai operasi penyisipan dan penelusuran data. Program dapat menambah elemen di awal, akhir, setelah, maupun sebelum elemen tertentu, serta menampilkan isi list dari depan maupun dari belakang. Pada bagian utama, program membuat list dengan data **1, 3, 2**, lalu menambahkan **4 sebelum 2** dan **5 sebelum 1**. Hasil akhirnya ditampilkan secara berurutan (forward) dan terbalik (backward).
### 5.2 Unguided 2
```cpp
#include <iostream>

using namespace std;

#define Nil NULL

  

typedef int infotype;

typedef struct elmlist *address;

  

struct elmlist {

    infotype info;

    address next;

    address prev;

};

  

struct List {

    address first;

    address last;

};

  

address alokasi(infotype x) {

    address P = new elmlist;

    P->info = x;

    P->next = Nil;

    P->prev = Nil;

    return P;

}

  

void dealokasi(address &P) {

    delete P;

    P = Nil;

}

  

void insertFirst(List &L, address P) {

    P->next = L.first;

    P->prev = Nil;

    if (L.first != Nil)

        L.first->prev = P;

    else

        L.last = P;

    L.first = P;

}

  

void printInfo(List L) {

    address P = L.first;

    while (P != Nil) {

        cout << P->info << " ";

        P = P->next;

    }

    cout << endl;

}

  

void deleteFirst(List &L, address &P) {

    P = L.first; L.first = L.first->next;

    if (L.first != Nil) L.first->prev = Nil; else L.last = Nil;

    P->next = Nil; P->prev = Nil;

}

  

void deleteLast (List &L, address &P) {

    P = L.last; L.last = L.last->prev;

    if (L.last != Nil) L.last->next = Nil; else L.first = Nil;

    P->prev = Nil; P->next = Nil;

}

  

void deleteAfter (List &L, address &P, address R) {

    P = R->next; R->next = P->next;

    if (P->next != Nil) P->next->prev = R; else L.last = R;

    P->prev = Nil; P->next = Nil;

}

  

bool deleteByValue(List &L, infotype x) {

    address P = L.first;

  

    while (P != Nil && P->info != x) {

        P = P->next;

    }

  

    if (P == Nil) {

        cout << "Nilai " << x << " tidak ditemukan" << endl;

        return false;

    }

  

    if (P == L.first) {

        L.first = P->next;

        if (L.first != Nil)

            L.first->prev = Nil;

        else

            L.last = Nil;

    } else if (P == L.last) {

        L.last = P->prev;

        if (L.last != Nil)

            L.last->next = Nil;

        else

            L.first = Nil;

    } else {

        P->prev->next = P->next;

        P->next->prev = P->prev;

    }

  

    cout << "Nilai " << x << " berhasil dihapus" << endl;

    dealokasi(P);

    return true;

}

  

void deleteAll(List &L) {

    address P = L.first;

    int count = 0;

    while (P != Nil) {

        address temp = P;

        P = P->next;

        dealokasi(temp);

        count++;

    }

    L.first = Nil;

    L.last = Nil;

    cout << "Semua elemen (" << count << ") berhasil dihapus" << endl;

}

  

int main() {

    List L;

    L.first = Nil;

    L.last = Nil;

  

    cout << "TASK 1: DELETE OPERATIONS" << endl;

  

    // List awal: 2 3 2 1

    insertFirst(L, alokasi(1));

    insertFirst(L, alokasi(2));

    insertFirst(L, alokasi(3));

    insertFirst(L, alokasi(2));

  

    cout << "List awal: ";

    printInfo(L);

  

    // Delete by value 2

    deleteByValue(L, 2);

    cout << "Setelah deleteByValue(2): ";

    printInfo(L);

  

    // Delete value yang tidak ada

    deleteByValue(L, 5);

    cout << "List tetap: ";

    printInfo(L);

  

    // Tambah data baru

    insertFirst(L, alokasi(5));

    cout << "List setelah tambah data: ";

    printInfo(L);

  

    // Delete semua elemen

    deleteAll(L);

  

    return 0;

}
```

***OUTPUT*** : 
![](output/U2.png)

***PENJELASAN*** : Program ini merupakan implementasi **doubly linked list** dengan fokus pada operasi penghapusan data. Program dapat menghapus elemen pertama, terakhir, setelah elemen tertentu, berdasarkan nilai tertentu, maupun seluruh elemen dalam list. Selain itu, terdapat fungsi untuk menambah elemen di awal dan menampilkan isi list. Pada bagian utama, program membuat list awal berisi data **2, 3, 2, 1**, kemudian melakukan penghapusan berdasarkan nilai, menambah data baru, dan menghapus semua elemen hingga list kosong.
### 5.3 Unguided 3
```cpp
#include <iostream>

using namespace std;

#define Nil NULL

  

typedef int infotype;

typedef struct elmlist *address;

  

struct elmlist {

    infotype info;

    address next;

    address prev;

};

  

struct List {

    address first;

    address last;

};

  

address alokasi(infotype x) {

    address P = new elmlist;

    P->info = x;

    P->next = Nil;

    P->prev = Nil;

    return P;

}

  

void dealokasi(address &P) {

    delete P;

    P = Nil;

}

  

void insertFirst(List &L, address P) {

    P->next = L.first;

    P->prev = Nil;

    if (L.first != Nil)

        L.first->prev = P;

    else

        L.last = P;

    L.first = P;

}

  

void insertLast(List &L, address P) {

    P->prev = L.last;

    P->next = Nil;

    if (L.last != Nil)

        L.last->next = P;

    else

        L.first = P;

    L.last = P;

}

  

void insertAfter(List &L, address P, address R) {

    P->next = R->next;

    P->prev = R;

    if (R->next != Nil)

        R->next->prev = P;

    else

        L.last = P;

    R->next = P;

}

  

void printForward(List L) {

    address P = L.first;

    while (P != Nil) {

        cout << P->info << " ";

        P = P->next;

    }

    cout << endl;

}

  

void printBackward(List L) {

    address P = L.last;

    while (P != Nil) {

        cout << P->info << " ";

        P = P->prev;

    }

    cout << endl;

}

  

// SMART INSERT

void smartInsert(List &L, infotype x) {

    address P = alokasi(x);

    cout << "Smart Insert: ";

  

    // 1) List kosong

    if (L.first == Nil) {

        insertFirst(L, P);

        cout << "List kosong, insert " << x << " di first" << endl;

        return;

    }

  

    // 2) Nilai lebih kecil dari elemen pertama

    if (x < L.first->info) {

        insertFirst(L, P);

        cout << x << " < first, insert di first" << endl;

        return;

    }

  

    // 3) Nilai genap

    if (x % 2 == 0) {

        insertLast(L, P);

        cout << x << " genap, insert di last" << endl;

        return;

    }

  

    // 4) Nilai ganjil (di antara dua nilai)

    address Q = L.first;

    bool inserted = false;

    while (Q->next != Nil) {

        if (Q->info < x && x < Q->next->info) {

            insertAfter(L, P, Q);

            cout << x << " di antara " << Q->info << " dan " << Q->next->info << endl;

            inserted = true;

            break;

        }

        Q = Q->next;

    }

  

    // Jika tidak menemukan posisi di tengah

    if (!inserted) {

        insertLast(L, P);

        cout << x << " insert di last (tidak menemukan posisi tengah)" << endl;

    }

}

  

// CONDITIONAL DELETE (hapus semua bilangan ganjil)

void conditionalDelete(List &L) {

    cout << "Sebelum Conditional Delete: ";

    printForward(L);

  

    address P = L.first;

    int count = 0;

  

    while (P != Nil) {

        address next = P->next;

        if (P->info % 2 != 0) { // hapus ganjil

            if (P == L.first) {

                L.first = P->next;

                if (L.first != Nil) L.first->prev = Nil;

                else L.last = Nil;

            } else if (P == L.last) {

                L.last = P->prev;

                if (L.last != Nil) L.last->next = Nil;

                else L.first = Nil;

            } else {

                P->prev->next = P->next;

                P->next->prev = P->prev;

            }

            dealokasi(P);

            count++;

        }

        P = next;

    }

  

    cout << "Conditional Delete: " << count << " elemen ganjil dihapus" << endl;

    cout << "Setelah Conditional Delete: ";

    printForward(L);

}

  

// MAIN PROGRAM

int main() {

    List L;

    L.first = Nil;

    L.last = Nil;

  

    cout << "ADVANCED OPERATIONS" << endl;

    cout << "SMART INSERT DEMO" << endl;

  

    smartInsert(L, 5);

    smartInsert(L, 3);

    smartInsert(L, 8);

    smartInsert(L, 6);

    smartInsert(L, 4);

    smartInsert(L, 7);

  

    cout << "\nHasil Smart Insert:" << endl;

    cout << "Forward: ";

    printForward(L);

    cout << "Backward: ";

    printBackward(L);

    cout << endl;

  

    cout << "CONDITIONAL DELETE" << endl;

    conditionalDelete(L);

    cout << endl;

  

    cout << "DELETE BY VALUE DEMO" << endl;

    // hapus nilai 6

    int x = 6;

    address P = L.first;

    while (P != Nil && P->info != x) P = P->next;

    if (P != Nil) {

        if (P == L.first) {

            L.first = P->next;

            if (L.first != Nil) L.first->prev = Nil;

        } else if (P == L.last) {

            L.last = P->prev;

            if (L.last != Nil) L.last->next = Nil;

        } else {

            P->prev->next = P->next;

            P->next->prev = P->prev;

        }

        cout << "Nilai " << x << " berhasil dihapus" << endl;

        dealokasi(P);

    } else {

        cout << "Nilai " << x << " tidak ditemukan" << endl;

    }

  

    // hapus nilai 10

    x = 10;

    P = L.first;

    while (P != Nil && P->info != x) P = P->next;

    if (P != Nil) {

        if (P == L.first) {

            L.first = P->next;

            if (L.first != Nil) L.first->prev = Nil;

        } else if (P == L.last) {

            L.last = P->prev;

            if (L.last != Nil) L.last->next = Nil;

        } else {

            P->prev->next = P->next;

            P->next->prev = P->prev;

        }

        cout << "Nilai " << x << " berhasil dihapus" << endl;

        dealokasi(P);

    } else {

        cout << "Nilai " << x << " tidak ditemukan" << endl;

    }

  

    cout << "List akhir: ";

    printForward(L);

    cout << endl;

  

    cout << "DELETE ALL DEMO" << endl;

    int count = 0;

    while (L.first != Nil) {

        address temp = L.first;

        L.first = L.first->next;

        dealokasi(temp);

        count++;

    }

    L.last = Nil;

    cout << "Semua elemen (" << count << ") berhasil dihapus" << endl;

  

    return 0;

}
```

***OUTPUT*** : 
![](output/U3.png)

***PENJELASAN*** : Program ini merupakan implementasi lanjutan dari **doubly linked list** dengan fitur penyisipan dan penghapusan data berdasarkan kondisi tertentu. Fungsi **smartInsert()** menambahkan elemen secara otomatis sesuai aturan: jika list kosong atau nilai lebih kecil dari elemen pertama maka disisipkan di awal, jika genap dimasukkan di akhir, dan jika ganjil ditempatkan di antara dua nilai yang sesuai. Fungsi **conditionalDelete()** menghapus semua elemen ganjil dari list. Program juga menampilkan proses penghapusan berdasarkan nilai tertentu serta penghapusan seluruh elemen. Hasil akhir menunjukkan urutan list setelah setiap operasi dilakukan.
## 6. Kesimpulan
Kesimpulannya, program yang dibuat menunjukkan penerapan struktur data **doubly linked list** dengan berbagai operasi, seperti menambah, menghapus, dan menampilkan data dari dua arah. Program juga dilengkapi dengan fitur tambahan seperti **smart insert** dan **conditional delete** yang membuat proses pengolahan data lebih fleksibel. Secara keseluruhan, program ini berhasil menggambarkan cara kerja list ganda dalam mengelola data secara terurut dan efisien.

## 7. Referensi
1.  [https://dte.telkomuniversity.ac.id/struktur-data-dasar-array-linked-list-stack-dan-queue/](https://dte.telkomuniversity.ac.id/struktur-data-dasar-array-linked-list-stack-dan-queue/)
2.  [https://www.trivusi.web.id/2022/06/mengenal-struktur-data.html](https://www.trivusi.web.id/2022/06/mengenal-struktur-data.html)