# Template Laporan Praktikum Struktur Data

## 1. Nama, NIM, Kelas
- **Nama**: Zalfa Athallah Pasha Hermawan
- **NIM**: 103112400196
- **Kelas**: S1IF-12-05

## 2. Motivasi Belajar Struktur Data
Struktur data penting dipelajari karena jadi dasar dalam bikin program supaya lebih teratur. Selain buat ngerjain tugas, materi ini juga sering kepakai di aplikasi sehari-hari dan bisa jadi bekal kalau nanti udah masuk dunia kerja.
## 3. Dasar Teori
Multi-linked list adalah jenis daftar khusus yang memiliki dua atau lebih urutan kunci logis. Sebelum memahami lebih jauh tentang multi-linked list, kita perlu melihat kembali apa itu linked list. Linked list adalah struktur data yang tidak memiliki batasan ukuran selama memori heap masih tersedia. Kita telah mengenal beberapa jenis linked list, seperti _Singly Linked List_, _Circular Linked List_, dan _Doubly Linked List_. Pada bagian ini, kita akan membahas mengenai multi-linked list.
## 4. Guided
### 4.1 Guided 1
```cpp
#ifndef MULTILIST_H_INCLUDED
#define MULTILIST_H_INCLUDED
#define Nil NULL

typedef int infotype;
typedef struct elemen_induk *address_induk;
typedef struct elemen_anak *address_anak;

struct elemen_anak {
    infotype info;
    address_anak next, prev;
};

struct list_anak {
    address_anak first, last;
};

struct elemen_induk {
    infotype info;
    list_anak anak;
    address_induk next, prev;
};

struct list_induk {
    address_induk first, last;
};

void createList(list_induk &L);
address_induk alokasi(infotype x);
void insertLastInduk(list_induk &L, address_induk P);
address_induk findInduk(list_induk L, infotype x);
void insertLastAnak(list_anak &LA, address_anak PA);
address_anak alokasiAnak(infotype x);
void printInfo(list_induk L);

#endif
```

**Penjelasan** : Kode ini mendefinisikan struktur multilist yang terdiri dari list induk dan list anak dengan data bertipe integer. Setiap elemen induk dan anak disusun menggunakan doubly linked list sehingga memiliki pointer next dan prev. Elemen induk menyimpan satu list anak yang memungkinkan satu data induk memiliki banyak data anak. Struktur list_induk dan list_anak berfungsi menyimpan alamat elemen pertama dan terakhir untuk mempermudah proses penambahan data. Fungsi createList digunakan untuk menginisialisasi list induk kosong, fungsi alokasi dan alokasiAnak digunakan untuk membuat elemen baru, fungsi insertLastInduk dan insertLastAnak menambahkan data di posisi terakhir, fungsi findInduk mencari data induk berdasarkan nilai info, dan fungsi printInfo menampilkan seluruh data induk beserta data anaknya.
**Output** :
![](output/.png)

### 4.2 Guided 2
```cpp
#include "multilist.h"
#include <iostream>
using namespace std;

void createList(list_induk &L) {
    L.first = Nil;
    L.last = Nil;
}

address_induk alokasi(infotype x) {
    address_induk P = new elemen_induk;
    P->info = x;
    P->next = Nil;
    P->prev = Nil;
    P->anak.first = Nil;
    P->anak.last = Nil;
    return P;
}

void insertLastInduk(list_induk &L, address_induk P) {
    if (L.first == Nil) {
        L.first = P;
        L.last = P;
    } else {
        L.last->next = P;
        P->prev = L.last;
        L.last = P;
    }
}

address_induk findInduk(list_induk L, infotype x) {
    address_induk P = L.first;
    while (P != Nil) {
        if (P->info == x) return P;
        P = P->next;
    }
    return Nil;
}
```

**Penjelasan** : Kode ini berisi implementasi dasar pengelolaan list induk pada struktur multilist. Fungsi createList menginisialisasi list induk dengan kondisi kosong dengan mengatur pointer first dan last ke Nil. Fungsi alokasi digunakan untuk membuat node induk baru, mengisi data info, mengosongkan pointer next dan prev, serta menginisialisasi list anak agar masih kosong. Fungsi insertLastInduk berfungsi menambahkan node induk ke posisi terakhir list induk, baik saat list masih kosong maupun sudah berisi data. Fungsi findInduk digunakan untuk mencari elemen induk berdasarkan nilai info dengan cara menelusuri list dari awal hingga data ditemukan atau list berakhir.
**OUTPUT** :
![](output/.png)
### 4.3 Guided 3
```cpp
#include "multilist.h"
#include <iostream>
using namespace std;

address_anak alokasiAnak(infotype x) {
    address_anak P = new elemen_anak;
    P->info = x;
    P->next = Nil;
    P->prev = Nil;
    return P;
}

void insertLastAnak(list_anak &LA, address_anak PA) {
    if (LA.first == Nil) {
        LA.first = PA;
        LA.last = PA;
    } else {
        LA.last->next = PA;
        PA->prev = LA.last;
        LA.last = PA;
    }
}

void printInfo(list_induk L) {
    address_induk PI = L.first;
    while (PI != Nil) {
        cout << "Induk: " << PI->info << endl;
        address_anak PA = PI->anak.first;
        while (PA != Nil) {
            cout << "  Anak: " << PA->info << endl;
            PA = PA->next;
        }
        PI = PI->next;
    }
}
```

**PENJELASAN** : Kode ini mengatur operasi pada list anak dan proses penampilan data multilist. Fungsi alokasiAnak digunakan untuk membuat node anak baru dengan mengisi data dan mengosongkan pointer next dan prev. Fungsi insertLastAnak menambahkan node anak ke posisi terakhir pada list anak, baik saat list masih kosong maupun sudah berisi data. Fungsi printInfo berfungsi menampilkan seluruh isi multilist dengan cara menelusuri list induk dari awal hingga akhir, lalu untuk setiap induk menelusuri dan menampilkan seluruh data anak yang dimilikinya.

**OUTPUT** : 
![](output/G.PNG)

### 4.4 Guided 4
```cpp
#include "multilist.h"
#include <iostream>
using namespace std;

int main() {
    list_induk L;
    createList(L);

    address_induk P1 = alokasi(1);
    insertLastInduk(L, P1);

    address_anak PA1 = alokasiAnak(10);
    insertLastAnak(P1->anak, PA1);

    address_induk P2 = alokasi(2);
    insertLastInduk(L, P2);

    address_anak PA2 = alokasiAnak(20);
    insertLastAnak(P2->anak, PA2);

    printInfo(L);
    return 0;
}
```

***OUTPUT*** : 
![](output/GUIDED.png)

***PENJELASAN*** : Program utama ini menunjukkan cara penggunaan struktur multilist. Program membuat list induk kosong lalu menambahkan dua data induk dengan nilai 1 dan 2. Setiap induk diberi satu data anak, yaitu 10 untuk induk pertama dan 20 untuk induk kedua. Setelah proses penambahan selesai, fungsi printInfo dipanggil untuk menampilkan seluruh data induk beserta data anak yang terhubung, kemudian program diakhiri.
## 5. Unguided
### 5.1 Unguided 1
```cpp
#ifndef CIRCULARLIST_H_INCLUDED
#define CIRCULARLIST_H_INCLUDED

#include <iostream>
using namespace std;

#define Nil NULL

// TIPE DATA
typedef struct {
    string nama;
    string nim;
    char jenis_kelamin;
    float ipk;
} infotype;

typedef struct ElmList *address;

struct ElmList {
    infotype info;
    address next;
};

struct List {
    address first;
};

// FUNGSI / PROSEDUR
void createList(List &L);
address alokasi(infotype x);
void dealokasi(address P);

void insertFirst(List &L, address P);
void insertAfter(List &L, address Prec, address P);
void insertLast(List &L, address P);

void deleteFirst(List &L, address &P);
void deleteAfter(List &L, address Prec, address &P);
void deleteLast(List &L, address &P);

address findElm(List L, infotype x);
void printInfo(List L);

#endif

```

***OUTPUT*** :
![](output/U1.png)

***PENJELASAN*** : Kode header ini mendefinisikan struktur dan operasi dasar circular linked list untuk menyimpan data mahasiswa. Tipe infotype berisi nama, NIM, jenis kelamin, dan IPK. Struktur ElmList menyimpan satu data dan pointer next yang terhubung secara melingkar, sedangkan struktur List hanya menyimpan alamat elemen pertama. Fungsi createList digunakan untuk menginisialisasi list kosong, fungsi alokasi dan dealokasi untuk membuat dan menghapus node. Fungsi insertFirst, insertAfter, dan insertLast digunakan untuk menambah data pada posisi tertentu di dalam list. Fungsi deleteFirst, deleteAfter, dan deleteLast digunakan untuk menghapus data dari list. Fungsi findElm digunakan untuk mencari data tertentu, dan fungsi printInfo digunakan untuk 
menampilkan seluruh isi circular linked list.

```cpp
#include "circularlist.h"

void createList(List &L){
    L.first = Nil;
}

address alokasi(infotype x){
    address P = new ElmList;
    P->info = x;
    P->next = Nil;
    return P;
}

void dealokasi(address P){
    delete P;
}

void insertFirst(List &L, address P){
    if(L.first == Nil){
        L.first = P;
        P->next = P;
    } else {
        address Q = L.first;
        while(Q->next != L.first){
            Q = Q->next;
        }
        Q->next = P;
        P->next = L.first;
        L.first = P;
    }
}

void insertAfter(List &L, address Prec, address P){
    if(Prec != Nil){
        P->next = Prec->next;
        Prec->next = P;
    }
}

void insertLast(List &L, address P){
    if(L.first == Nil){
        insertFirst(L, P);
    } else {
        address Q = L.first;
        while(Q->next != L.first){
            Q = Q->next;
        }
        Q->next = P;
        P->next = L.first;
    }
}

void deleteFirst(List &L, address &P){
    P = L.first;

    if(P->next == P){     // 1 elemen
        L.first = Nil;
    } else {
        address Q = L.first;
        while(Q->next != L.first){
            Q = Q->next;
        }
        L.first = P->next;
        Q->next = L.first;
    }
    P->next = Nil;
}

void deleteAfter(List &L, address Prec, address &P){
    P = Prec->next;

    if(P != Nil){
        Prec->next = P->next;
        P->next = Nil;
    }
}

void deleteLast(List &L, address &P){
    if(L.first->next == L.first){   // satu elemen
        deleteFirst(L, P);
    } else {
        address Q = L.first;
        while(Q->next->next != L.first){
            Q = Q->next;
        }
        P = Q->next;
        Q->next = L.first;
        P->next = Nil;
    }
}

address findElm(List L, infotype x){
    if(L.first == Nil) return Nil;

    address P = L.first;
    do{
        if(P->info.nim == x.nim){
            return P;
        }
        P = P->next;
    } while(P != L.first);

    return Nil;
}

void printInfo(List L){
    if(L.first == Nil){
        cout << "List kosong" << endl;
        return;
    }

    address P = L.first;

    do {
        cout << "Nama : " << P->info.nama << endl;
        cout << "NIM  : " << P->info.nim << endl;
        cout << "L/P  : " << P->info.jenis_kelamin << endl;
        cout << "IPK  : " << P->info.ipk << endl;
        cout << endl;
        P = P->next;
    } while(P != L.first);
}

```
**PENJELASAN** : Kode ini merupakan implementasi circular linked list untuk menyimpan data mahasiswa. Fungsi createList menginisialisasi list agar kosong. Fungsi alokasi dan dealokasi digunakan untuk membuat dan menghapus node. Fungsi insertFirst, insertAfter, dan insertLast digunakan untuk menambahkan data ke awal, setelah node tertentu, dan ke akhir list dengan menjaga sifat melingkar dimana node terakhir selalu menunjuk ke node pertama. Fungsi deleteFirst, deleteAfter, dan deleteLast digunakan untuk menghapus data dari posisi awal, setelah node tertentu, dan posisi terakhir dengan tetap mempertahankan struktur circular. Fungsi findElm digunakan untuk mencari data mahasiswa berdasarkan NIM dengan penelusuran melingkar. Fungsi printInfo digunakan untuk menampilkan seluruh data mahasiswa dari node pertama hingga kembali ke node pertama lagi.

```cpp
#include <iostream>
#include "circularlist.h"
using namespace std;

address createData(string nama, string nim, char jenis_kelamin, float ipk)
{
    infotype x;
    address P;

    x.nama = nama;
    x.nim = nim;
    x.jenis_kelamin = jenis_kelamin;
    x.ipk = ipk;

    P = alokasi(x);
    return P;
}

int main(){
    List L;
    address P1, P2;
    infotype x;

    createList(L);

    cout << "coba insert first, last, dan after" << endl << endl;

    // dasar: tambah beberapa elemen dengan insertFirst / insertLast
    P1 = createData("Danu", "04", 'l', 4.0);
    insertFirst(L, P1);

    P1 = createData("Fahmi", "06", 'l', 3.45);
    insertLast(L, P1);

    P1 = createData("Bobi", "02", 'l', 3.71);
    insertFirst(L, P1);

    P1 = createData("Ali", "01", 'l', 3.3);
    insertFirst(L, P1);

    P1 = createData("Gita", "07", 'p', 3.75);
    insertLast(L, P1);

    // 1) masukkan Cindi (03) setelah NIM "02" (Bobi)
    x.nim = "02";
    P1 = findElm(L, x);            // cari Bobi
    P2 = createData("Cindi", "03", 'p', 3.5);
    insertAfter(L, P1, P2);

    // 2) masukkan Hilmi (08) setelah NIM "07" (Gita)  -> jadi berada di akhir sesuai gambar
    x.nim = "07";
    P1 = findElm(L, x);            // cari Gita
    P2 = createData("Hilmi", "08", 'p', 3.3);
    insertAfter(L, P1, P2);

    // 3) masukkan Eli (05) setelah NIM "04" (Danu)
    x.nim = "04";
    P1 = findElm(L, x);            // cari Danu
    P2 = createData("Eli", "05", 'p', 3.4);
    insertAfter(L, P1, P2);

    printInfo(L);
    return 0;
}

```
**PENJELASAN** : Program utama ini digunakan untuk menguji operasi circular linked list dengan data mahasiswa. Program membuat list kosong lalu menambahkan beberapa data mahasiswa menggunakan insertFirst dan insertLast untuk membentuk struktur awal. Setelah itu, program melakukan pencarian data berdasarkan NIM menggunakan findElm, kemudian menambahkan data baru di posisi tertentu dengan insertAfter sesuai skenario yang ditentukan. Setiap data mahasiswa berisi nama, NIM, jenis kelamin, dan IPK yang dibuat melalui fungsi createData. Terakhir, fungsi printInfo dipanggil untuk menampilkan seluruh isi list secara melingkar dari elemen pertama hingga kembali ke elemen awal.

***OUTPUT*** : 
![](output/UNGUIDED.png)
## 6. Kesimpulan
Praktikum ini menunjukkan cara membangun dan mengelola struktur circular linked list dan multilist secara terstruktur. Kamu membuat node, menambah data di awal, tengah, dan akhir, mencari data berdasarkan kunci tertentu, serta menghapus dan menampilkan data dengan benar. Setiap operasi menjaga hubungan antar node agar struktur list tetap konsisten. Hasil program membuktikan bahwa data dapat disimpan, diakses, dan ditampilkan sesuai urutan yang diinginkan dengan memanfaatkan pointer dan traversal list.
## 7. Referensi
1.  [https://dte.telkomuniversity.ac.id/struktur-data-dasar-array-linked-list-stack-dan-queue/](https://dte.telkomuniversity.ac.id/struktur-data-dasar-array-linked-list-stack-dan-queue/)
2.  [https://www.trivusi.web.id/2022/06/mengenal-struktur-data.html](https://www.trivusi.web.id/2022/06/mengenal-struktur-data.html)
