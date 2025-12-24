# Template Laporan Praktikum Struktur Data

## 1. Nama, NIM, Kelas
- **Nama**: Zalfa Athallah Pasha Hermawan
- **NIM**: 103112400196
- **Kelas**: S1IF-12-05

## 2. Motivasi Belajar Struktur Data
Struktur data penting dipelajari karena jadi dasar dalam bikin program supaya lebih teratur. Selain buat ngerjain tugas, materi ini juga sering kepakai di aplikasi sehari-hari dan bisa jadi bekal kalau nanti udah masuk dunia kerja.
## 3. Dasar Teori
Graph merupakan salah satu struktur data non-linear yang digunakan untuk merepresentasikan hubungan antar objek. Secara formal, graph didefinisikan sebagai **G = (V, E)**, di mana **V (vertex)** adalah himpunan simpul dan **E (edge)** adalah himpunan sisi yang menghubungkan antar simpul. Graph dapat bersifat berarah atau tidak berarah, serta dapat berbobot maupun tidak berbobot, tergantung pada jenis hubungan yang ingin dimodelkan. Struktur data graph banyak digunakan untuk menggambarkan permasalahan dunia nyata seperti jaringan komputer, peta jalan, dan hubungan antar pengguna dalam media sosial.

Dalam implementasinya, graph dapat direpresentasikan menggunakan **adjacency matrix** atau **adjacency list**. Adjacency matrix menggunakan matriks dua dimensi untuk menunjukkan hubungan antar simpul, sedangkan adjacency list menyimpan daftar simpul yang terhubung pada setiap simpul. Selain itu, graph memiliki algoritma penelusuran seperti **Breadth First Search (BFS)** dan **Depth First Search (DFS)** yang digunakan untuk mengunjungi seluruh simpul dalam graph secara sistematis.
## 4. Guided
### 4.1 Guided 1
```cpp
#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
using namespace std;

typedef char infoGraph;
typedef struct ElmNode *adrNode;
typedef struct ElmEdge *adrEdge;

struct ElmNode{
    infoGraph info;
    bool visited;
    adrEdge firstEdge;
    adrNode next;
};

struct ElmEdge{
    adrNode node;
    adrEdge next;
};

struct Graph{
    adrNode first;
};

// Prototypes
void createGraph(Graph &G);
adrNode allocateNode(infoGraph X);
void insertNode(Graph &G, infoGraph X);
void connectNode(Graph &G, infoGraph start, infoGraph end);
void printGraph(Graph G);

#endif
```

**Penjelasan** : Struktur ini merepresentasikan graph menggunakan adjacency list. Graph terdiri dari kumpulan node yang saling terhubung melalui edge. Setiap node menyimpan satu data bertipe char, penanda visited untuk proses traversal, serta pointer ke daftar edge yang dimilikinya. Edge menyimpan alamat node tujuan dan pointer ke edge berikutnya sehingga satu node bisa terhubung ke banyak node lain. Fungsi createGraph digunakan untuk menginisialisasi graph agar kosong. Fungsi allocateNode membuat node baru. Fungsi insertNode menambahkan node ke dalam graph. Fungsi connectNode menghubungkan dua node berdasarkan nilai awal dan tujuan. Fungsi printGraph digunakan untuk menampilkan hubungan antar node dalam graph. Struktur ini mendukung implementasi traversal seperti DFS dan BFS.

**Output** :
![](output/.png)

### 4.2 Guided 2
```cpp
#include "graph.h"

void createGraph(Graph &G) {
    G.first = NULL;
}

adrNode allocateNode(infoGraph X) {
    adrNode P = new ElmNode;
    P->info = X;
    P->visited = false;
    P->firstEdge = NULL;
    P->next = NULL;
    return P;
}

void insertNode(Graph &G, infoGraph X) {
    adrNode P = allocateNode(X);
    if (G.first == NULL) {
        G.first = P;
    } else {
        adrNode Q = G.first;
        while (Q->next != NULL) {
            Q = Q -> next;
        }
        Q->next = P;
    }
}
```

**Penjelasan** : Kode ini mengatur proses pembuatan dan penambahan node pada graph. Fungsi createGraph menginisialisasi graph dengan kondisi kosong dengan mengatur pointer first menjadi NULL. Fungsi allocateNode membuat satu node baru, mengisi data info sesuai input, mengatur visited menjadi false, serta mengosongkan pointer edge dan next. Fungsi insertNode menambahkan node ke dalam graph. Jika graph masih kosong, node langsung menjadi node pertama. Jika graph sudah memiliki node, proses penambahan dilakukan di akhir list dengan menelusuri node sampai pointer next bernilai NULL. Pendekatan ini memastikan setiap node tersimpan berurutan dalam struktur graph.

**OUTPUT** :
![](output/.png)
### 4.3 Guided 3
```cpp
#include "graph.h"

adrNode findNode(Graph G, infoGraph X) {
    adrNode P = G.first;
    while (P != NULL) {
        if (P->info == X) return P;
        P = P->next;
    }
    return NULL;
}

void connectNode(Graph &G, infoGraph start, infoGraph end) {
    adrNode pStart = findNode(G, start);
    adrNode pEnd = findNode(G, end);

    if (pStart != NULL && pEnd != NULL) {
        adrEdge newEdge = new ElmEdge;
        newEdge->node = pEnd;
        newEdge->next = pStart->firstEdge; // Insert First di list edge
        pStart->firstEdge = newEdge;
    }
}
```

**PENJELASAN** : Kode ini mengatur pencarian node dan pembentukan edge pada graph. Fungsi findNode menelusuri daftar node dari awal sampai akhir untuk mencari node dengan nilai info tertentu. Proses berhenti saat data ditemukan atau saat daftar node habis. Fungsi connectNode menghubungkan dua node berdasarkan nilai start dan end. Program mencari alamat node awal dan node tujuan terlebih dahulu. Jika keduanya ditemukan, program membuat edge baru yang menunjuk ke node tujuan. Edge kemudian ditambahkan ke awal daftar edge milik node awal. Cara ini membuat proses penambahan edge lebih cepat karena tidak perlu menelusuri seluruh daftar edge.

**OUTPUT** : 
![](output/G.PNG)

### 4.4 Guided 4
```cpp
#include "graph.h"

void printGraph(Graph G) {
    adrNode P = G.first;
    while (P != NULL) {
        cout << "Node " << P->info << " terhubung ke: ";
        adrEdge E = P->firstEdge;
        while (E != NULL) {
            cout << E->node->info << " ";
            E = E->next;
        }
        cout << endl;
        P = P->next;
    }
}
```

***PENJELASAN*** : Kode ini menampilkan struktur graph ke layar. Program menelusuri setiap node dari awal hingga akhir. Untuk setiap node, program mencetak data node tersebut. Program lalu menelusuri daftar edge milik node tersebut. Setiap edge menampilkan node tujuan yang terhubung. Proses ini menunjukkan hubungan antar node secara jelas sesuai adjacency list. Output memudahkan Kamu melihat arah dan koneksi antar node dalam graph.

***OUTPUT*** :
![](output/.png)

### 4.5 Guided 5
```cpp
#include "graph.h"
#include <iostream>

using namespace std;

int main() {
    Graph G;
    createGraph(G);

    // Menambahkan Node A, B, C, D
    insertNode(G, 'A');
    insertNode(G, 'B');
    insertNode(G, 'C');
    insertNode(G, 'D');

    // Menghubungkan Node (Sesuai contoh materi)
    connectNode(G, 'A', 'B'); // A ke B
    connectNode(G, 'A', 'C'); // A ke C
    connectNode(G, 'B', 'D'); // B ke D
    connectNode(G, 'C', 'D'); // C ke D

    cout << "Isi Graph:" << endl;
    printGraph(G);

    return 0;
}
```
***PENJELASAN*** : Program utama ini menunjukkan cara penggunaan graph secara utuh. Program membuat sebuah graph kosong lalu menambahkan empat node yaitu A, B, C, dan D. Setelah node tersedia, program menghubungkan node sesuai arah yang ditentukan, yaitu A ke B, A ke C, B ke D, dan C ke D. Hubungan ini membentuk graph berarah dengan satu titik tujuan yang sama pada node D. Fungsi printGraph kemudian menampilkan seluruh node beserta koneksi edge yang dimilikinya. Hasil output memperlihatkan struktur graph sesuai adjacency list sehingga Kamu dapat melihat relasi antar node secara langsung dan jelas.

***OUTPUT*** : 
![](output/.png)

## 5. Unguided

### 5.1 Unguided 1
```cpp
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
using namespace std;

typedef char infoGraph;
typedef struct ElmNode *adrNode;
typedef struct ElmEdge *adrEdge;

struct ElmNode {
    infoGraph info;
    int visited;
    adrEdge firstEdge;
    adrNode next;
};

struct ElmEdge {
    adrNode node;
    adrEdge next;
};

struct Graph {
    adrNode first;
};

// Prototype
void CreateGraph(Graph &G);
adrNode AllocateNode(infoGraph X);
void InsertNode(Graph &G, infoGraph X);
adrNode FindNode(Graph G, infoGraph X);
void ConnectNode(Graph &G, infoGraph X, infoGraph Y);
void PrintInfoGraph(Graph G);

#endif

```

***OUTPUT*** :
![](output/U1.png)

***PENJELASAN*** : Kode ini mendefinisikan graph menggunakan adjacency list yang terdiri dari node dan edge. Setiap node menyimpan data bertipe char, penanda visited untuk keperluan penelusuran, pointer ke edge pertama, dan pointer ke node berikutnya, sedangkan edge menyimpan pointer ke node tujuan dan edge selanjutnya. Struktur Graph menyimpan pointer ke node pertama sebagai awal graph. Fungsi yang disediakan digunakan untuk menginisialisasi graph, membuat dan menambahkan node, mencari node tertentu, menghubungkan dua node dengan edge, serta menampilkan seluruh isi dan hubungan dalam graph.
### 5.2 Unguided 2
```cpp
#include "graph_unguided.h"

void CreateGraph(Graph &G) {
    G.first = NULL;
}

adrNode AllocateNode(infoGraph X) {
    adrNode P = new ElmNode;
    P->info = X;
    P->visited = 0;
    P->firstEdge = NULL;
    P->next = NULL;
    return P;
}

void InsertNode(Graph &G, infoGraph X) {
    adrNode P = AllocateNode(X);
    if (G.first == NULL) {
        G.first = P;
    } else {
        adrNode Q = G.first;
        while (Q->next != NULL) {
            Q = Q->next;
        }
        Q->next = P;
    }
}

adrNode FindNode(Graph G, infoGraph X) {
    adrNode P = G.first;
    while (P != NULL) {
        if (P->info == X)
            return P;
        P = P->next;
    }
    return NULL;
}

void ConnectNode(Graph &G, infoGraph X, infoGraph Y) {
    adrNode N1 = FindNode(G, X);
    adrNode N2 = FindNode(G, Y);

    if (N1 != NULL && N2 != NULL) {
        // Edge dari X ke Y
        adrEdge E1 = new ElmEdge;
        E1->node = N2;
        E1->next = N1->firstEdge;
        N1->firstEdge = E1;

        // Edge dari Y ke X (karena tidak berarah)
        adrEdge E2 = new ElmEdge;
        E2->node = N1;
        E2->next = N2->firstEdge;
        N2->firstEdge = E2;
    }
}

void PrintInfoGraph(Graph G) {
    adrNode P = G.first;
    while (P != NULL) {
        cout << P->info << " terhubung ke: ";
        adrEdge E = P->firstEdge;
        while (E != NULL) {
            cout << E->node->info << " ";
            E = E->next;
        }
        cout << endl;
        P = P->next;
    }
}

```

***OUTPUT*** : 
![](output/U2.png)

***PENJELASAN*** : Kode ini mengimplementasikan graph tidak berarah menggunakan adjacency list. Program menginisialisasi graph kosong, membuat node baru, lalu menambahkan node ke dalam graph secara berurutan. Fungsi pencarian digunakan untuk menemukan node tertentu sebelum membuat koneksi. Proses penghubungan node menambahkan dua edge agar relasi bersifat dua arah. Fungsi cetak menampilkan setiap node beserta daftar node yang terhubung, sehingga struktur dan hubungan graph dapat dilihat dengan jelas.
### 5.3 Unguided 3
```cpp
#include "graph_unguided.h"

int main() {
    Graph G;
    CreateGraph(G);

    // Insert node A sampai H
    InsertNode(G, 'A');
    InsertNode(G, 'B');
    InsertNode(G, 'C');
    InsertNode(G, 'D');
    InsertNode(G, 'E');
    InsertNode(G, 'F');
    InsertNode(G, 'G');
    InsertNode(G, 'H');

    // Hubungan sesuai ilustrasi graph
    ConnectNode(G, 'A', 'B');
    ConnectNode(G, 'A', 'C');
    ConnectNode(G, 'B', 'D');
    ConnectNode(G, 'B', 'E');
    ConnectNode(G, 'C', 'F');
    ConnectNode(G, 'C', 'G');
    ConnectNode(G, 'D', 'H');
    ConnectNode(G, 'E', 'H');
    ConnectNode(G, 'F', 'H');
    ConnectNode(G, 'G', 'H');

    cout << "Isi Graph Tidak Berarah:" << endl;
    PrintInfoGraph(G);

    return 0;
}

```

***OUTPUT*** : 
![](output/2.png)

***PENJELASAN*** : Program utama ini membuat dan menguji graph tidak berarah. Graph diinisialisasi dalam keadaan kosong, lalu node A sampai H dimasukkan ke dalam graph. Setelah itu, setiap node dihubungkan sesuai struktur graph yang ditentukan sehingga membentuk relasi dua arah. Program kemudian menampilkan isi graph untuk memperlihatkan setiap node beserta node lain yang terhubung dengannya.

### 5.4 Unguided 4
```cpp
void ResetVisited(Graph &G);
void PrintDFS(Graph &G, adrNode N);
void PrintBFS(Graph &G, adrNode N);
```
***Penjelasan*** : Prototype fungsi ini digunakan untuk proses penelusuran graph. ResetVisited berfungsi mengatur ulang status visited pada seluruh node agar siap digunakan kembali. PrintDFS melakukan penelusuran graph dengan metode Depth First Search mulai dari node tertentu dan menampilkan urutan kunjungan. PrintBFS melakukan penelusuran graph dengan metode Breadth First Search mulai dari node tertentu dan menampilkan hasil penelusuran secara melebar.

```cpp
void ResetVisited(Graph &G) {
    adrNode P = G.first;
    while (P != NULL) {
        P->visited = 0;
        P = P->next;
    }
}

void PrintDFS(Graph &G, adrNode N) {
    if (N == NULL || N->visited == 1)
        return;

    cout << N->info << " ";
    N->visited = 1;

    adrEdge E = N->firstEdge;
    while (E != NULL) {
        PrintDFS(G, E->node);
        E = E->next;
    }
}

#include <queue>

void PrintBFS(Graph &G, adrNode N) {
    if (N == NULL)
        return;

    queue<adrNode> Q;
    N->visited = 1;
    Q.push(N);

    while (!Q.empty()) {
        adrNode P = Q.front();
        Q.pop();
        cout << P->info << " ";

        adrEdge E = P->firstEdge;
        while (E != NULL) {
            if (E->node->visited == 0) {
                E->node->visited = 1;
                Q.push(E->node);
            }
            E = E->next;
        }
    }
}


```

***Penjelasan*** : Kode ini mengatur dan menampilkan proses penelusuran graph. Fungsi ResetVisited mengatur ulang nilai visited pada seluruh node agar traversal bisa dijalankan kembali. PrintDFS menelusuri graph secara mendalam dari satu node awal dengan memanggil dirinya sendiri pada setiap node yang terhubung. PrintBFS menelusuri graph secara melebar menggunakan queue, dimulai dari node awal lalu mengunjungi node tetangga terlebih dahulu sebelum berpindah ke level berikutnya.

```cpp
cout << "DFS dari node A: ";
ResetVisited(G);
PrintDFS(G, FindNode(G, 'A'));
cout << endl;

cout << "BFS dari node A: ";
ResetVisited(G);
PrintBFS(G, FindNode(G, 'A'));
cout << endl;
```
***Penjelasan*** : Potongan kode ini menampilkan hasil penelusuran graph dari node A. Program mencetak urutan DFS dengan mengatur ulang status visited terlebih dahulu agar semua node bisa dikunjungi. Setelah itu, program mencetak urutan BFS dari node yang sama dengan kondisi visited yang sudah direset kembali. Cara ini memastikan hasil DFS dan BFS tampil secara benar dan terpisah.

***OUTPUT*** : 
![](output/3.png)
## 6. Kesimpulan
Praktikum ini menunjukkan penerapan struktur data graph tidak berarah menggunakan adjacency list. Program berhasil membangun node, menghubungkan antar node, dan menampilkan relasi graph dengan benar. Proses DFS dan BFS berjalan sesuai konsep penelusuran graph setelah status visited diatur ulang. Hasil keluaran membuktikan bahwa struktur graph dan algoritma traversal telah diimplementasikan dengan baik.
## 7. Referensi
1.  [https://dte.telkomuniversity.ac.id/struktur-data-dasar-array-linked-list-stack-dan-queue/](https://dte.telkomuniversity.ac.id/struktur-data-dasar-array-linked-list-stack-dan-queue/)
2.  [https://www.trivusi.web.id/2022/06/mengenal-struktur-data.html](https://www.trivusi.web.id/2022/06/mengenal-struktur-data.html)
