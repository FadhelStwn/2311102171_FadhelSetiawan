#include <iostream>
#include <cmath> // Library untuk fungsi pemangkatan dibawah

using namespace std;

char Pilih_234; // Data primitif char untuk pilihan menu Pilih_234
float data1, data2; // Data primitif float untuk bilangan pertama dan kedua supaya bisa menyimpan bilangan desimal

void FadhelSetiawan_321() { // Fungsi untuk menampilkan menu pilihan
    cout << "KALKULATOR FADHEL";
    cout << "\nA. Penjumlahan";
    cout << "\nB. Perkalian";
    cout << "\nC. Pembagian";
    cout << "\nD. Pengurangan";
    cout << "\nE. Pangkat" << endl;
    cout << "Masukkan Pilihan : ";
    cin >> Pilih_234;
}

float Penjumlahan() { // Fungsi Penjumlahan
    cout << "\n PENJUMLAHAN " << endl;
    cout << "Bilangan pertama : ";
    cin >> data1;
    cout << "Ditambah bilangan kedua : ";
    cin >> data2;
    cout << "Hasil penjumlahan : ";
    return data1 + data2; // Mengembalikan hasil penjumlahan
}

float Perkalian() { // Fungsi Perkalian
    cout << "\n PERKALIAN " << endl;
    cout << "Bilangan pertama : ";
    cin >> data1;
    cout << "Dikali bilangan kedua : ";
    cin >> data2;
    cout << "Hasil perkalian : ";
    return data1 * data2; // Mengembalikan hasil perkalian
}

float Pembagian() { // Fungsi Pembagian
    cout << "\n PEMBAGIAN " << endl;
    cout << "Bilangan pertama : ";
    cin >> data1;
    cout << "Dibagi bilangan kedua : ";
    cin >> data2;
    cout << "Hasil pembagian : ";
    return data1 / data2; // Mengembalikan hasil pembagian
}

float Pengurangan() { // Fungsi Pengurangan
    cout << "\n PENGURANGAN " << endl;
    cout << "Bilangan pertama : ";
    cin >> data1;
    cout << "Dikurangi bilangan kedua : ";
    cin >> data2;
    cout << "Hasil pengurangan : ";
    return data1 - data2; // Mengembalikan hasil pengurangan
}

float Pemangkatan() { // Fungsi Pemangkatan
    cout << "\n PEMANGKATAN " << endl;
    cout << "Bilangan pertama : ";
    cin >> data1;
    cout << "Dipangkati bilangan kedua : ";
    cin >> data2;
    cout << "Hasil pemangkatan : ";
    return pow(data1, data2); // Mengembalikan hasil pemangkatan dan pow itu fungsi dari library cmath diatas
}

int main() {
    do { // Looping menu pilihan
        FadhelSetiawan_321();
        switch (Pilih_234) { // Switch case untuk memilih menu
            case 'A':
            case 'a':
                cout << Penjumlahan() << "\n" << endl; // Jika user memilih A/a, maka akan menjalankan fungsi penjumlahan
                break;
            case 'B':
            case 'b':
                cout << Perkalian() << "\n" << endl; // Jika user memilih B/b, maka akan menjalankan fungsi perkalian
                break;
            case 'C':
            case 'c':
                cout << Pembagian() << "\n" << endl; // Jika user memilih C/c, maka akan menjalankan fungsi pembagian
                break;
            case 'D':
            case 'd':
                cout << Pengurangan() << "\n" << endl; // Jika user memilih D/d, maka akan menjalankan fungsi pengurangan
                break;
            case 'E':
            case 'e':
                cout << Pemangkatan() << "\n" << endl; // Jika user memilih E/e, maka akan menjalankan fungsi pemangkatan
                break;
            default:
                cout << "\nUhh.. not a valid number so yea goodbye" << endl;
                return 0;
        }
    } while (Pilih_234 != 0); // Looping akan terus berjalan selama user tidak memilih 0

    return 0;
}