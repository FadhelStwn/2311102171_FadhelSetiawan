#include <iostream>
using namespace std;

int main()
{
    // Deklarasi variabel
    int n = 10; // Panjang array
    int data[n] = {9, 4, 1, 7, 5, 12, 4, 13, 4, 10}; // Array yang berisi data
    int cari = 10; // Nilai yang akan dicari dalam array
    bool ketemu = false; // Penanda apakah nilai ditemukan atau tidak
    int i; // Variabel untuk iterasi

    // Proses pencarian
    for (i = 0; i < n; i++)
    {
        if (data[i] == cari) // Jika elemen array pada indeks ke-i sama dengan nilai yang dicari
        {
            ketemu = true; // Set penanda bahwa nilai telah ditemukan
            break; // Keluar dari loop
        }
    }

    // Menampilkan hasil pencarian
    cout << "\t Program Sequential Search Sederhana\n " << endl;
    cout << "data: {9, 4, 1, 7, 5, 12, 4, 13, 4, 10}" << endl;
    if (ketemu) // Jika nilai ditemukan
    {
        cout << "\n angka " << cari << " ditemukan pada indeks ke-" << i << endl;
    }
    else // Jika nilai tidak ditemukan
    {
        cout << cari << " tidak dapat ditemukan pada data." << endl;
    }
    return 0; // Mengakhiri program
}
