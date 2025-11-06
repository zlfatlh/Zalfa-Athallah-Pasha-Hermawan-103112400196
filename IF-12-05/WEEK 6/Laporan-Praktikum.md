# Template Laporan Praktikum Struktur Data

## 1. Nama, NIM, Kelas
- **Nama**: Zalfa Athallah Pasha Hermawan
- **NIM**: 103112400196
- **Kelas**: S1IF-12-05

## 2. Motivasi Belajar Struktur Data
Struktur data penting dipelajari karena jadi dasar dalam bikin program supaya lebih teratur. Selain buat ngerjain tugas, materi ini juga sering kepakai di aplikasi sehari-hari dan bisa jadi bekal kalau nanti udah masuk dunia kerja.
## 3. Dasar Teori
Struktur data adalah cara untuk menyimpan dan mengorganisir data dalam komputer agar dapat digunakan secara efisien. Berikut adalah teori dasar :

- **Push:** Menambahkan elemen baru ke _bagian atas_ stack. Misalnya, menumpuk buku baru di atas tumpukan.
- **Pop:** Menghapus elemen di _puncak_ stack dan mengembalikan nilainya. Artinya, buku yang paling atas diambil keluar.
- **Peek/Top:** Melihat (mengintip) elemen teratas tanpa menghapusnya. Seperti mengintip buku paling atas tanpa mengambilnya.
- **IsEmpty:** Memeriksa apakah stack kosong atau tidak. Cocok seperti mengecek apakah masih ada piring di tumpukan.
- **Size:** Mengembalikan jumlah elemen dalam stack. Berguna untuk mengetahui seberapa tinggi tumpukan saat ini.
## 4. Guided
### 4.1 Guided 1
```cpp

#ifndef STACK_H

#define STACK_H

  

#include <iostream>

#define MaxEl 20

#define Nil -1

  

typedef int infotype;

  

struct Stack {

    infotype info[MaxEl];

    int top;

};

  

void CreateStack(Stack &S) ;

bool isEmpty(Stack S) ;

bool isFull(Stack S) ;

void push(Stack &S, infotype X) ;

infotype pop(Stack &S) ;

void printInfo(Stack S) ;

void balikStack(Stack &S) ;

  

#endif
```

**Penjelasan** : Kode di atas adalah file header **stack.h** yang mendefinisikan struktur data _stack_ dan fungsi-fungsi dasarnya. Bagian `#ifndef`, `#define`, dan `#endif` digunakan untuk mencegah file dimasukkan berulang. Nilai `MaxEl` menentukan kapasitas stack sebesar 20 elemen, sedangkan `Nil = -1` menandakan stack masih kosong. Struktur `Stack` terdiri dari array `info` untuk menyimpan data dan variabel `top` sebagai penanda posisi elemen teratas. Fungsi-fungsi seperti `CreateStack`, `push`, `pop`, `isEmpty`, dan `isFull` dideklarasikan untuk mengatur proses penyimpanan dan pengambilan data pada stack.

**Output** :
![](output/.png)

### 4.2 Guided 2
```cpp
#include "stack.h"

  

using namespace std;

  

//fungsi membuat stack baru udengan menginisialisasi top = Nil

void CreateStack(Stack &S) {

    S.top = Nil;

}

  

//fungsi untuk mengecek apakah stack kosong

bool isEmpty(Stack S) {

    return S.top == Nil;

}

  

//fungsi untuk mengecek apakah stack penuh

bool isFull(Stack S) {

    return S.top == MaxEl - 1;

}

  

//fungsi untuk menambahkan elemen ke stack

void push(Stack &S, infotype x) {

    if (! isFull(S)) {

        S.top++;

        S.info[S.top] = x;

    } else {

        cout << "stack penuh!" << endl;

    }

}

  

// fungsi untuk mengambil elemen teratas dari stack (pop)

infotype pop (Stack &S) {

    infotype X = -999;

    if (!isEmpty(S)) {

        X = S.info[S.top];

        S.top--;

    } else {

        cout << "Stack Kosong!" << endl;

    }

    return X;

}

  

// fungsi untuk menampilkan isi stack

void printInfo(Stack S) {

    if (isEmpty(S)){

        cout << "Stack kosong" << endl;

    } else {

        cout << "[TOP]" ;

        for (int i = S.top; i >= 0; i--) {

            cout << S.info[i] << " ";

        }

        cout << endl;

    }

}

  

//fungsi untuk membalikan urutan elemen dalam stack

void balikStack(Stack &S) {

    if (!isEmpty(S)) {

        Stack temp1, temp2;

        CreateStack(temp1); CreateStack(temp2);

  

        while (!isEmpty(S)) {push (temp1, pop(S));}

  

        while (!isEmpty(temp1)) {push (temp2, pop(temp1));}

  

        while (!isEmpty(temp2)) {push (S, pop(temp2));}

    }

}
```

**Penjelasan** : Kode di atas berisi implementasi fungsi-fungsi utama pada **stack**. Fungsi `CreateStack` menginisialisasi stack agar kosong, sedangkan `isEmpty` dan `isFull` digunakan untuk memeriksa kondisi stack. Fungsi `push` menambah elemen ke atas stack, dan `pop` menghapus serta mengambil elemen teratas. Fungsi `printInfo` menampilkan isi stack dari atas ke bawah, sementara `balikStack` membalik urutan elemen dengan bantuan dua stack sementara.

**OUTPUT** :
![](output/.png)
### 4.3 Guided 3
```cpp
#include "stack.h"

#include <iostream>

  

using namespace std ;

  

int main() {

    Stack S;

    CreateStack(S);

  

    push(S, 3);

    push(S, 4);

    push(S, 8);

    pop(S);

    push(S, 2);

    push(S, 3);

    pop(S);

    push(S, 9);

  

    cout << "Stack Awal:" << endl;

    printInfo(S);

  

    cout << "balik Stack" << endl;

    balikStack(S);

  

    cout << "stack Setelah dibalik:" << endl;

    printInfo(S);

  

    return 0;

}
```

**PENJELASAN** : Kode di atas merupakan **program utama** untuk menguji fungsi-fungsi pada struktur data _stack_. Pada awal program, sebuah stack `S` dibuat menggunakan `CreateStack`. Selanjutnya dilakukan beberapa operasi seperti `push` untuk menambah elemen dan `pop` untuk menghapus elemen teratas. Setelah itu, isi stack ditampilkan melalui `printInfo`, kemudian fungsi `balikStack` dijalankan untuk membalik urutan elemen dalam stack. Terakhir, isi stack yang sudah dibalik ditampilkan kembali sebagai hasil akhir program.

**OUTPUT** : 
![](output/1.jpg)

### 4.4 Guided 4
```cpp
```

***OUTPUT*** :
![](output/suhu.png)

***PENJELASAN*** : 
## 5. Unguided
### 5.1 Unguided 1
```cpp
#include "stack.h"

#include <iostream>

using namespace std;

  

int main() {

    cout << "Hello World!" << endl;

    Stack S;

    CreateStack(S);

  

    // Operasi stack

    push(S, 3);

    push(S, 4);

    push(S, 8);

    pop(S);

    push(S, 2);

    push(S, 3);

    pop(S);

    push(S, 9);

  

    cout << "Stack sebelum dibalik:" << endl;

    printInfo(S);

  

    balikStack(S);

  

    cout << "Stack sesudah dibalik:" << endl;

    printInfo(S);

  

    return 0;

}
```

***OUTPUT*** :
![](output/U1.png)

***PENJELASAN*** : Kode di atas merupakan program utama yang berfungsi untuk **mendemonstrasikan operasi dasar pada stack**. Program diawali dengan menampilkan teks “Hello World!” lalu membuat sebuah stack `S` menggunakan `CreateStack`. Selanjutnya dilakukan beberapa operasi `push` untuk menambahkan data dan `pop` untuk menghapus elemen teratas. Setelah beberapa proses tersebut, isi stack ditampilkan melalui `printInfo` sebelum dan sesudah dibalik menggunakan fungsi `balikStack`. Hasil akhirnya menunjukkan perbedaan urutan elemen sebelum dan setelah proses pembalikan dilakukan.
### 5.2 Unguided 2
```cpp
#include "stack.h"

#include <iostream>

using namespace std;

  

int main() {

    cout << "Hello world!" << endl;

    Stack S;

    CreateStack(S);

    pushAscending(S,3);

    pushAscending(S,4);

    pushAscending(S,8);

    pushAscending(S,2);

    pushAscending(S,3);

    pushAscending(S,9);

    printInfo(S);

    cout<<"balik stack"<<endl;

    balikStack(S);

    printInfo(S);

    return 0;

  

}
```

***OUTPUT*** : 
![](output/U2.png)

***PENJELASAN*** : Kode di atas merupakan program utama untuk menguji fungsi `pushAscending` pada struktur data *stack*. Program membuat stack baru, menambahkan beberapa elemen secara berurutan menggunakan `pushAscending`, lalu menampilkan isinya dengan `printInfo`. Setelah itu, fungsi `balikStack` digunakan untuk membalik urutan elemen dalam stack dan hasilnya kembali ditampilkan.
### 5.3 Unguided 3
```cpp
#include "stack.h"

#include <iostream>

using namespace std;

  

int main() {

    cout << "Hello world!" << endl;

    Stack S;

    CreateStack(S);

  

    // gunakan fungsi getInputStream untuk membaca input angka dari user

    getInputStream(S);

  

    // tampilkan isi stack hasil input

    printInfo(S);

  

    cout << "balik stack" << endl;

    balikStack(S);

  

    // tampilkan hasil setelah dibalik

    printInfo(S);

  

    return 0;

}
```

***OUTPUT*** : 
![](output/U3.png)

***PENJELASAN*** : Kode di atas merupakan **program utama** yang berfungsi untuk membaca data dari pengguna menggunakan fungsi `getInputStream`, lalu menyimpannya ke dalam struktur data _stack_. Setelah data dimasukkan, isi stack ditampilkan dengan `printInfo`. Program kemudian memanggil fungsi `balikStack` untuk membalik urutan elemen di dalam stack, dan hasil akhirnya kembali ditampilkan. Program ini menunjukkan penggunaan input dinamis dari pengguna serta proses pembalikan isi stack.
## 6. Kesimpulan
Kesimpulannya, program ini menunjukkan cara kerja stack dalam C++ mulai dari membuat tumpukan data, menambah dan menghapus elemen, sampai menampilkan serta membalik urutannya. Ada juga tambahan fitur seperti `pushAscending` untuk menyusun data secara menaik dan `getInputStream` supaya pengguna bisa langsung memasukkan data lewat input. Intinya, kode ini dibuat untuk memperlihatkan bagaimana konsep **LIFO (Last In, First Out)** diterapkan dalam pengelolaan data menggunakan stack.
## 7. Referensi
1.  [https://dte.telkomuniversity.ac.id/struktur-data-dasar-array-linked-list-stack-dan-queue/](https://dte.telkomuniversity.ac.id/struktur-data-dasar-array-linked-list-stack-dan-queue/)
2.  [https://www.trivusi.web.id/2022/06/mengenal-struktur-data.html](https://www.trivusi.web.id/2022/06/mengenal-struktur-data.html)