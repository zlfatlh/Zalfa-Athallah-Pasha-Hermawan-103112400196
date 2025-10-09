//Pointer

#include <iostream>
using namespace std;

int main(){
    float hargaProduk = 50000.0f;
    //deklarasi pointer
    float* ptrHarga =& hargaProduk;

    cout << "harga awal produk" << hargaProduk << endl;
    cout << "alamat memori harga" << ptrHarga << endl;

    cout <<"\n...Memberikan diskon 10% melalui pointer..."<< endl;
    *ptrHarga= *ptrHarga*0.9;
    cout << "harga setelah diskon : Rp" << hargaProduk << endl;
    return 0;
}