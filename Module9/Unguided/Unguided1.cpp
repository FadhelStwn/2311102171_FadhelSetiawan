#include <iostream>
#include <vector> 
#include <iomanip> 

using namespace std;

int main() {
    int Fadhel_171;
    cout << "===== Program Membuat Menghitung Sebuah Jarak Kota Ke Kota Lain =====\n";

    do {
    cout << "\nMasukan Jumalah Simpul : "; cin >> Fadhel_171;

    vector<string> kota(Fadhel_171); 
    cout << "\nMasukan Nama Simpul" << endl;
    for (int i = 0; i < Fadhel_171; ++i) {
        cout << "Simpul " << i + 1 << " : ";
        cin >> kota[i]; 
    }

    vector<vector<int>> kota2(Fadhel_171, vector<int>(Fadhel_171)); 
    cout << "\nJarak Masing - Masing Kota\n";
    for (int i = 0; i < Fadhel_171; ++i) {
        for (int j = 0; j < Fadhel_171; ++j) { 
            cout << kota[i] << " --> " << kota[j] << " = ";
            cin >> kota2[i][j];
        }
    }

    cout << "\n====== Grafik Jarak Kota ======";
    cout << "\n           ";
    for (const auto& city : kota) { 
        cout << setw(10) << city;
    }
    cout << '\n';

    for (int i = 0; i < Fadhel_171; ++i) { 
        cout << setw(10) << kota[i];
        for (int j = 0; j < Fadhel_171; ++j) {
            cout << setw(10) << kota2[i][j]; 
        }
        cout << '\n';
    }
    } while (Fadhel_171 != 0); 
    cout << "Semoga Bisa Membantu";
    return 0;
}