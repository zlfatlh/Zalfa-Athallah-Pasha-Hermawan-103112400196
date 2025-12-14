# Template Laporan Praktikum Struktur Data

## 1. Nama, NIM, Kelas
- **Nama**: Zalfa Athallah Pasha Hermawan
- **NIM**: 103112400196
- **Kelas**: S1IF-12-05

## 2. Motivasi Belajar Struktur Data
Struktur data penting dipelajari karena jadi dasar dalam bikin program supaya lebih teratur. Selain buat ngerjain tugas, materi ini juga sering kepakai di aplikasi sehari-hari dan bisa jadi bekal kalau nanti udah masuk dunia kerja.
## 3. Dasar Teori
Queue atau dalam bahasa Indonesia yang berarti antrian adalah struktur data yang menyusun elemen-elemen data dalam urutan linier. Prinsip dasar dari struktur data ini adalah “First In, First Out” (FIFO) yang berarti elemen data yang pertama dimasukkan ke dalam antrean akan menjadi yang pertama pula untuk dikeluarkan.
## 4. Guided
### 4.1 Guided 1
```cpp
#ifndef QUEUE_H

#define QUEUE_H

  

#define MAX_QUEUE 5

  

struct Queue {

    int info [MAX_QUEUE];

    int head;

    int tail;

    int count;

};

  

void createQueue(Queue &Q);

  

bool isEmpty(Queue Q);

  

bool isFull(Queue Q);

  

void enqueue(Queue &Q, int x);

  

int dequeue(Queue &Q);

  

void printInfo(Queue Q);

  

#endif
```

**Penjelasan** : Kode ini mendefinisikan queue berbasis array dengan kapasitas lima elemen. Struct Queue menyimpan data, posisi depan dan belakang, serta jumlah elemen. Fungsi yang tersedia digunakan untuk inisialisasi, pengecekan kosong atau penuh, menambah data, mengambil data, dan menampilkan isi queue.
**Output** :
![](output/.png)

### 4.2 Guided 2
```cpp
#include "queue.h"

#include <iostream>

  

using namespace std;

  
  

void createQueue(Queue &Q){

    Q.head = 0;

    Q.tail = 0;

    Q.count = 0;

}

  
  

bool isEmpty(Queue Q) {

    return Q.count == 0;

}

  
  

bool isFull(Queue Q) {

    return Q.count == MAX_QUEUE;

}

  
  

void enqueue(Queue &Q, int x) {

    if(!isFull(Q)) {

        Q.info[Q.tail] = x;

  

        Q.tail = (Q.tail + 1) % MAX_QUEUE;

        Q.count++;

    } else {

        cout << "Antrean Penuh!" << endl;

    }

}

  
  

int dequeue(Queue &Q) {

    if(!isEmpty(Q)) {

        int x = Q.info[Q.head];

        Q.head = (Q.head + 1) % MAX_QUEUE;

        Q.count--;

        return x;

    } else {

        cout << "Antrean Kosong!" << endl;

        return -1;

    }

}

  
  

void printInfo(Queue Q) {

    cout << "Isi Queue : [";

    if(!isEmpty(Q)) {

        int i = Q.head;

        int n = 0;

        while (n < Q.count) {

            cout << Q.info[i] << " ";

            i = (i + 1) % MAX_QUEUE;

            n++;

        }

    }

    cout << "]" << endl;

}
```

**Penjelasan** : Kode ini berisi implementasi queue melingkar menggunakan array. Fungsi createQueue mengatur kondisi awal queue agar kosong. Fungsi isEmpty dan isFull digunakan untuk mengecek apakah queue kosong atau penuh berdasarkan nilai count. Fungsi enqueue menambahkan data ke posisi tail lalu menggeser tail secara melingkar. Fungsi dequeue mengambil data dari posisi head lalu menggeser head secara melingkar. Fungsi printInfo menampilkan seluruh isi queue dari head sampai jumlah data yang tersimpan.

**OUTPUT** :
![](output/.png)
### 4.3 Guided 3
```cpp
#include <iostream>

#include "queue.h"

  

using namespace std;

  
  

int main(){

    Queue Q;

  

    createQueue(Q);

    printInfo(Q);

  

    cout << "\n Enqueue 3 Elemen" << endl;

    enqueue(Q,5);

    printInfo(Q);

    enqueue(Q,2);

    printInfo(Q);

    enqueue(Q,7);

    printInfo(Q);

  

    cout << "\n Dequeue 1 Elemen" << endl;

    cout << "Elemen keluar : " << dequeue(Q) << endl;

    printInfo(Q);

  

    cout << "\n Enqueue 1 Elemen" << endl;

    enqueue(Q,4);

    printInfo(Q);

  

    cout << "\n Dequeue 2 Elemen" << endl;

    cout << "Elemen keluar : " << dequeue(Q) << endl;

    cout << "Elemen keluar : " << dequeue(Q) << endl;

    printInfo(Q);

  

    return 0;

}
```

**PENJELASAN** : Program ini digunakan untuk menguji operasi queue. Pada awalnya queue dibuat kosong lalu isinya ditampilkan. Program kemudian menambahkan tiga elemen ke dalam queue dan menampilkan isinya setiap kali enqueue. Setelah itu satu elemen dikeluarkan dengan dequeue dan hasilnya ditampilkan. Program menambahkan satu elemen lagi, lalu mengeluarkan dua elemen sekaligus dan menampilkan kondisi akhir queue.

**OUTPUT** : 
![](output/G.PNG)

### 4.4 Guided 4
```cpp
```

***OUTPUT*** :
![](output/.png)

***PENJELASAN*** : 
## 5. Unguided

queue.h
```cpp
#ifndef QUEUE_H

#define QUEUE_H

  

#include <iostream>

using namespace std;

  

#define MAX_QUEUE 5

typedef int infotype;

  

struct Queue {

    infotype info[MAX_QUEUE];

    int head;

    int tail;

    int count;

};

  

void createQueue(Queue &Q);

bool isEmptyQueue(Queue Q);

bool isFullQueue(Queue Q);

void enqueue(Queue &Q, infotype x);

infotype dequeue(Queue &Q);

void printInfo(Queue Q);

  

#endif
```

main.cpp
```cpp
#include <iostream>

#include "queue.h"

using namespace std;

  

int main() {

    cout << "Hello world!" << endl;

    Queue Q;

    cout << "------------------" << endl;

    cout << "H - T : Queue Info" << endl;

    cout << "------------------" << endl;

  

    createQueue(Q); printInfo(Q);

  

    enqueue(Q, 5); printInfo(Q);  

  

    enqueue(Q, 2); printInfo(Q);  

  

    enqueue(Q, 7); printInfo(Q);  

  

    dequeue(Q); printInfo(Q);

  

    dequeue(Q); printInfo(Q);

  

    enqueue(Q, 4); printInfo(Q);  

  

    dequeue(Q); printInfo(Q);

  

    dequeue(Q); printInfo(Q);

  

    return 0;

}
```
### 5.1 Unguided 1
```cpp
#include "queue.h"

  

void createQueue(Queue &Q) {

    Q.head = -1;

    Q.tail = -1;

}

  

bool isEmptyQueue(Queue Q) {

    return Q.tail == -1;

}

  

bool isFullQueue(Queue Q) {

    return Q.tail == MAX_QUEUE - 1;

}

  

void enqueue(Queue &Q, infotype x) {

    if (isFullQueue(Q)) {

        cout << "Antrean Penuh!" << endl;

    } else {

        if (isEmptyQueue(Q)) {

            Q.head = 0;

        }

        Q.tail++;

        Q.info[Q.tail] = x;

    }

}

  

infotype dequeue(Queue &Q) {

    if (isEmptyQueue(Q)) {

        cout << "Antrean Kosong!" << endl;

        return -1;

    } else {

        infotype x = Q.info[Q.head];

        for (int i = Q.head; i < Q.tail; i++) {

            Q.info[i] = Q.info[i + 1];

        }

        Q.tail--;

        if (Q.tail == -1) {

            Q.head = -1;    

        }

        return x;

    }

}

  

void printInfo(Queue Q) {

    cout << Q.head << " - " << Q.tail << " : ";

    if (isEmptyQueue(Q)) {

        cout << "empty queue" << endl;

    } else {

        for (int i = Q.head; i <= Q.tail; i++) {

            cout << Q.info[i];

            if (i < Q.tail) {

                cout << " ";

            }

        }

        cout << endl;

    }

}
```

***OUTPUT*** :
![](output/U1.png)

***PENJELASAN*** : Kode ini merupakan implementasi queue sederhana berbasis array tanpa konsep melingkar. Queue dianggap kosong saat head dan tail bernilai -1. Fungsi enqueue menambahkan data ke belakang queue dengan menaikkan tail, dan jika data pertama masuk maka head diatur ke nol. Fungsi dequeue mengambil data dari depan lalu menggeser seluruh elemen ke kiri agar head tetap di posisi awal. Fungsi isEmptyQueue dan isFullQueue digunakan untuk mengecek kondisi queue, sedangkan printInfo menampilkan indeks head, tail, dan isi queue saat ini.
### 5.2 Unguided 2
```cpp
#include "queue.h"

  

void createQueue(Queue &Q) {

    Q.head = -1;

    Q.tail = -1;

    Q.count = 0;

}

  

bool isEmptyQueue(Queue Q) {

    return Q.count == 0;

}

  

bool isFullQueue(Queue Q) {

    return Q.count == MAX_QUEUE;

}

  

void enqueue(Queue &Q, infotype x) {

    if (isFullQueue(Q)) {

        cout << "Antrean Penuh!" << endl;

    } else {

        if (isEmptyQueue(Q)) {

            Q.head = 0;

            Q.tail = 0;

        } else {

            Q.tail = (Q.tail + 1) % MAX_QUEUE;

        }

        Q.info[Q.tail] = x;

        Q.count++;

    }

}

  

infotype dequeue(Queue &Q) {

    if (isEmptyQueue(Q)) {

        cout << "Antrean Kosong!" << endl;

        return -1;

    } else {

        infotype x = Q.info[Q.head];

        Q.head = (Q.head + 1) % MAX_QUEUE;

        Q.count--;

        if (Q.count == 0) {

            Q.head = -1;

            Q.tail = -1;

        }

        return x;

    }

}

  

void printInfo(Queue Q) {

    cout << Q.head << " - " << Q.tail << " : ";

    if (isEmptyQueue(Q)) {

        cout << "empty queue" << endl;

    } else {

        int i = Q.head;

        for (int c = 0; c < Q.count; c++) {

            cout << Q.info[i];

            if (c < Q.count - 1) cout << " ";

            i = (i + 1) % MAX_QUEUE;

        }

        cout << endl;

    }

}
```

***OUTPUT*** : 
![](output/U2.png)

***PENJELASAN*** : Kode ini menerapkan queue melingkar berbasis array dengan pencatatan jumlah elemen. Queue dianggap kosong saat count bernilai nol dan penuh saat count sama dengan kapasitas maksimum. Fungsi enqueue menambahkan data ke posisi tail secara melingkar, sedangkan dequeue mengambil data dari posisi head dan menggesernya secara melingkar. Variabel count menjaga jumlah data agar kondisi kosong dan penuh dapat dicek dengan tepat.
### 5.3 Unguided 3
```cpp
#include "queue.h"

  

void createQueue(Queue &Q) {

    Q.head = 0;

    Q.tail = 0;

}

  

bool isEmptyQueue(Queue Q) {

    return Q.head == Q.tail;

}

  

bool isFullQueue(Queue Q) {

    return (Q.tail + 1) % MAX_QUEUE == Q.head;

}

  

void enqueue(Queue &Q, infotype x) {

    if (isFullQueue(Q)) {

        cout << "Antrean Penuh!" << endl;

    } else {

        Q.info[Q.tail] = x;

        Q.tail = (Q.tail + 1) % MAX_QUEUE;

    }

}

  

infotype dequeue(Queue &Q) {

    if (isEmptyQueue(Q)) {

        cout << "Antrean Kosong!" << endl;

        return -1;

    } else {

        infotype x = Q.info[Q.head];

        Q.head = (Q.head + 1) % MAX_QUEUE;

        return x;

    }

}

  

void printInfo(Queue Q) {

    cout << Q.head << " - " << Q.tail << " | ";

    if (isEmptyQueue(Q)) {

        cout << "empty queue" << endl;

    } else {

        int i = Q.head;

        while (i != Q.tail) {

            cout << Q.info[i] << " ";

            i = (i + 1) % MAX_QUEUE;

        }

        cout << endl;

    }

}
```

***OUTPUT*** : 
![](output/U3.png)

***PENJELASAN*** : Kode ini mengimplementasikan queue melingkar tanpa variabel count. Queue kosong saat head sama dengan tail, dan penuh saat posisi tail berikutnya bertemu head. Fungsi enqueue menyimpan data di tail lalu menggeser tail secara melingkar. Fungsi dequeue mengambil data dari head lalu menggeser head. Fungsi printInfo menampilkan indeks head, tail, dan isi queue dari depan sampai belakang.
## 6. Kesimpulan
Praktikum ini menunjukkan bahwa struktur data queue dapat diimplementasikan dengan beberapa cara menggunakan array. Pengaturan nilai head dan tail menjadi kunci utama dalam menentukan kondisi kosong, penuh, serta alur masuk dan keluarnya data. Queue tanpa sistem melingkar membutuhkan pergeseran elemen saat dequeue sehingga kurang efisien. Queue melingkar lebih efektif karena indeks array dapat digunakan kembali. Penambahan variabel count mempermudah pengelolaan jumlah data di dalam queue.
## 7. Referensi
1.  [https://dte.telkomuniversity.ac.id/struktur-data-dasar-array-linked-list-stack-dan-queue/](https://dte.telkomuniversity.ac.id/struktur-data-dasar-array-linked-list-stack-dan-queue/)
2.  [https://www.trivusi.web.id/2022/06/mengenal-struktur-data.html](https://www.trivusi.web.id/2022/06/mengenal-struktur-data.html)
