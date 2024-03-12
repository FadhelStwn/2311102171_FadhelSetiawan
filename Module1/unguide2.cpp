#include <iostream>
#include <string>

// Definisikan sebuah struct bernama 'Orang'
struct Person {
    std::string nama;
    int umur;
    float tinggi;
};

int main() {
    // Membuat instance dari struct 'Orang'
    Person fadhel;

    // Menetapkan nilai pada anggota struct
    fadhel.nama = "Fadhel Setiawan";
    fadhel.umur = 18;
    fadhel.tinggi = 175;

   // Cetak nilainya
    std::cout << "Nama: " << fadhel.nama << std::endl;
    std::cout << "Umur: " << fadhel.umur << std::endl;
    std::cout << "Tinggi: " << fadhel.tinggi << std::endl;

    return 0;
}