#include <iostream>
using namespace std;

int main() {
    int n;
    string satuan[] = {"Nol","Satu","Dua","Tiga","Empat","Lima","Enam","Tujuh","Delapan","Sembilan"};
    string belasan[] = {"Sepuluh","Sebelas","Dua Belas","Tiga Belas","Empat Belas",
                        "Lima Belas","Enam Belas","Tujuh Belas","Delapan Belas","Sembilan Belas"};
    string puluhan[] = {"","","Dua Puluh","Tiga Puluh","Empat Puluh","Lima Puluh",
                        "Enam Puluh","Tujuh Puluh","Delapan Puluh","Sembilan Puluh"};

    cout << "Masukkan angka (0-100): ";
    cin >> n;

    if (n < 10) cout << satuan[n];
    else if (n < 20) cout << belasan[n-10];
    else if (n < 100) {
        if (n % 10 == 0) cout << puluhan[n/10];
        else cout << puluhan[n/10] << " " << satuan[n%10];
    }
    else if (n == 100) cout << "Seratus";
    else cout << "Diluar jangkauan";

    return 0;
}
