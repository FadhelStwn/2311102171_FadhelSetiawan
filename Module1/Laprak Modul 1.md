# <h1 align="center">Laporan Praktikum Modul 1 - Tipe Data</h1>
<p align="center">Fadhel Setiawan - 2311102171</p>

# Dasar Teori

Tipe data adalah suatu memori atau media pada komputer yang digunakan untuk menampung informasi atau data sementara. Tipe data berfungsi untuk mempresentasikan jenis dari sebuah nilai yang terdapat dalam program. Berikut ini merupakan macam-macam tipe data serta penjelasannya yang terdapat pada C++:

1. Tipe Data Primitif<br/>
Tipe data primitif adalah tipe data yang sudah ditentukan oleh sistem dan disediakan oleh banyak bahasa pemrograman. Ini adalah blok bangunan fundamental untuk menyimpan nilai-nilai sederhana. Contoh tipe data primitif:
    - Int (Bilangan bulat)
    - Float (Bilangan desimal)
    - Char (Huruf)
    - Boolean (True/False)

2. Tipe Data Abstrak<br/>
Tipe data abstrak atau yang biasa disebut Abstrak Data Type merupakan tipe data yang dibentuk oleh programmer itu sendiri. Pada tipe data abstrak bisa berisi banyak tipe data, jadi nilainya bisa lebih dari satu dan beragam tipe data

3. Tipe Data Koleksi<br/>
Tipe data koleksi (Collection Data Type) adalah tipe data yang digunakan untuk mengelompokkan dan menyimpan beberapa nilai atau objek secara bersamaan. Tipe data koleksi memungkinkan Anda menyimpan, mengelola, dan mengakses sejumlah besar data dengan cara yang terstruktur. Contoh data koleksi:
    - Array (struktur data statis yang menyimpan elemen-elemen dengan
    tipe data yang sama)
    - Vector (vector mirip seperti array yang memiliki
    kemampuan untuk menyimpan data dalam bentuk elemen-elemen yang alokasi
    memorinya dilakukan otomatis dan bersebelahan)
    - Map (Map terasa mirip dengan array namun dengan index yang memungkinkan
    untuk berupa tipe data selain integer)

# Guided 

# 1. Tipe Data Primitif

```C++
#include <iostream>
#include <iomanip>

using namespace std;


int main(){
    char op;
    float num1, num2;

    cout << "Enter operator (+, -, *, /): ";
    cin >> op;

    cout << "Enter two operands: ";
    cin >> num1 >> num2;

    switch (op)
    {
    case '+':
        cout << "Result: " << num1 + num2 << endl;
        break;
    case '-':
        cout << "Result: " << num1 - num2 << endl;
        break;
    case '*':
        cout << "Result: " << num1 * num2 << endl;
        break;
    case '/':
        if (num2 == 0) {
            cout << "Result: " << fixed << setprecision(2) << num1 / num2 << endl;
        } else {
            cout << "Error!: Division by zero" << endl;
        }
        break;

    default:
        cout << "Error! operator is not correct" << endl;
        break;
    }
    return 0;
}
```
Kode di atas digunakan untuk memilih operasi penambahan (+), pengurangan (-), perkalian (*), dan pembagian (/). Keempat operasi ini akan jalan jika user sudah menginput dua angka pada saat penginputan cin. Terdapat juga dua tipe data primitif pada program ini, yaitu char dan float. Tipe data char digunakan pada saat pemilihan switch case dan float digunakan sebagai tipe data 2 angka yang diinput user.

# 2. Tipe Data Abstrak

```C++
#include <stdio.h>
#include <string.h>

// Struct
struct Mahasiswa
{
    char name[50];
    char address[50];
    int age;
};

int main() {
    // Menggunakan Struct
    struct Mahasiswa mhs1, mhs2;

    // Mengisi nilai ke struct
    strcpy(mhs1.name, "Dian");
    strcpy(mhs1.address, "Mataram");
    mhs1.age = 22;
    strcpy(mhs2.name, "Bambang");
    strcpy(mhs2.address, "Surabaya");
    mhs2.age = 23;

    // Mencetak isi dari struct
    printf("## Mahasiswa 1 ##\n");
    printf("Nama: %s\n", mhs1.name);
    printf("Alamat: %s\n", mhs1.address);
    printf("Umur: %d\n", mhs1.age);
    printf("\n");
    printf("## Mahasiswa 2 ##\n");
    printf("Nama: %s\n", mhs2.name);
    printf("Alamat: %s\n", mhs2.address);
    printf("Umur: %d\n", mhs2.age);

    return 0;
}
```
Kode di atas digunakan untuk mencetak isi dari struct. Struct merupakan salah satu contoh dari tipe data abstrak. Pada kode di atas terdapat sebuah struct Mahasiswa. Pada struct Mahasiswa ini, terdapat 3 nilai, yaitu char name dengan ukuran 50, char address dengan ukuran 50 juga, dan int age. Lalu pada int main, diisi nilai dan dideklarasikan struct Mahasiswa dengan 2 objek, yaitu mhs1 dengan nama Dian dan mhs2 dengan nama Bambang.

# 3. Tipe Data Koleksi

```C++
#include <iostream>
#include <array>
using namespace std;

int main() {
    // Deklarasi dan inisialisasi array
    int nilai[5];
    nilai[0] = 23;
    nilai[1] = 50;
    nilai[2] = 34;
    nilai[3] = 78;
    nilai[4] = 90;

    // Mencetak array dengan tab
    cout << "Isi array pertama : " << nilai[0] << endl;
    cout << "Isi array kedua : " << nilai[1] << endl;
    cout << "Isi array ketiga : " << nilai[2] << endl;
    cout << "Isi array keempat : " << nilai[3] << endl;
    cout << "Isi array kelima : " << nilai[4] << endl;

    return 0;
}
```
Kode di atas digunakan untuk mencetak isi dari sebuah array. Array merupakan salah satu contoh dari tipe data koleksi. Pada kode di atas, terdapat library array yang membantu proses pemrogramannya. Terdapat array nilai yang dapat menampung 5 nilai, yaitu 23, 50, 34, 78, dan 90. Lalu dideklarasikan di bawahnya.

# Unguided 

# 1. Buatlah program menggunakan tipe data primitif minimal dua fungsi dan bebas. Menampilkan program, jelaskan program tersebut dan ambil kesimpulan dari materi tipe data primitif!

```C++
#include <iostream>
#include <cmath> 
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
```
# Output:
![alt text](Fadhelimg_111.png) <br/>
Program tersebut adalah kalkulator sederhana yang memungkinkan pengguna untuk melakukan beberapa operasi aritmatika dasar seperti penjumlahan, perkalian, pembagian, pengurangan, dan pemangkatan.Program dimulai dengan mendefinisikan beberapa fungsi:
FadhelSetiawan_321(): Menampilkan menu pilihan untuk pengguna. Fungsi-fungsi aritmatika seperti Penjumlahan(), Perkalian()Pembagian(), Pengurangan(), dan Pemangkatan(): Menerima input bilangan dari pengguna dan mengembalikan hasil operasi aritmatika sesuai dengan pilihan pengguna. Di dalam fungsi main(), terdapat loop do-while yang akan terus berjalan selama pengguna tidak memilih untuk keluar (memilih 0). Pengguna diminta untuk memilih menu pilihan. Program akan menjalankan fungsi yang sesuai dengan pilihan pengguna menggunakan pernyataan switch-case.Setelah menjalankan fungsi, hasil operasi aritmatika akan dicetak ke layar.Jika pengguna memilih untuk keluar (memilih 0), loop akan berhenti dan program akan selesai.Program menggunakan variabel global untuk menyimpan pilihan menu yang dimasukkan oleh pengguna (Pilih_234) dan variabel global data1 dan data2 untuk menyimpan bilangan yang dimasukkan oleh pengguna. Program menggunakan library <cmath> untuk memangkatkan bilangan (pow()).

Kesimpulan Tipe Data Primitif:<br/>
Tipe data primitif merupakan sebuah tipe data yang sudah ditentukan oleh sistem, disediakan oleh banyak bahasa pemrograman, dan merupakan blok bangunan fundamental untuk menyimpan nilai-nilai yang bersifat sederhana.

# 2. Jelaskan fungsi dari class dan struct secara detail dan berikan contoh programnya!

```C++

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
```
# Output:
![alt text](Fadhelimg_112.png)<br/>
Program ini bertujuan untuk menunjukkan bagaimana menggunakan struct untuk menyimpan dan mengelola informasi tentang seseorang dalam satu kesatuan yang terorganisir. Dengan menggunakan struct, informasi tentang nama, umur, dan tinggi badan seseorang dapat dengan mudah dikelola dan diakses melalui satu variabel.

A. Fungsi dari Class<br/>
Class adalah salah satu dari konsep OOP yang digunakan untuk membungkus data abstraksi procedural sebagai deskripsi tergeneralisir atau rancangan dari sebuah object untuk mendefinisikan atau menggambarkan isi dan tingkah laku sebagai entitas dari object. Fitur class adalah fitur Object Oriented Program pada bahasa C++.

B. Fungsi dari Struct<br/>
Struct dalam pemrograman C++, adalah sekumpulan data yang dikelompokkan ke dalam sebuah “tabel” yang memiliki elemen-elemenyang saling terkait.Struct digunakan apabila data yang ingin dikelompokkan memiliki tipe data yang berbeda atau membuat struktur dari suatu record.

# 3. Buat dan jelaskan program menggunakan fungsi map dan jelaskan perbedaan dari array dengan map!

```C++


// Contoh Program Fungsi Map
#include <iostream>
#include <map> // Library supaya bisa menggunakan fungsi map dibawah

using namespace std;

int main() {
    
    // Deklarasi map dengan key int dan value string
    map<int, string> wisata112;
  
    // Menambahkan elemen-elemen ke dalam map
    wisata112[1] = "taman";
    wisata112[2] = "curug";
    wisata112[3] = "pemandian air panas";
    wisata112[4] = "rumah hantu";
    wisata112[5] = "museum";

    cout << "-=-= Wisata Fadhel! =-=-" << endl;
    for (int i = 1; i <= wisata112.size(); ++i) { // Looping untuk menampilkan semua elemen map
        cout << "No." << i << " " << wisata112[i] << endl; // Menampilkan elemen map
    }

    return 0;
}
```
# Output:
![alt text](Fadhelimg_113.png)
Kode di atas digunakan untuk mencetak isi dari sebuah map. Pada kode di atas, terdapat sebuah map wisata112 dengan key yang bersifat int dan nilai-nilainya yang bersifat string. Lalu, isi dari map wisata112 dideklarasikan dengan perulangan for supaya semua elemen dapat ditampilkan.

Perbedaan Array dengan Map
    - Array harus bilangan bulat non-negatif & mulai berurutan dari 0
    - Map dapat berupa nilai berapa pun & tidak harus berurutan
    - Array harus dideklarasikan dengan ukuran yang tetap
    - Map dapat dideklarasikan dengan ukuran yang dinamis
    - Array hanya dapat menggunakan tipe data primitif
    - Map dapat menggunakan tipe data apapun
    - Array digunakan untuk menyimpan data yang berurutan


# Kesimpulan
Dengan memahami konsep dan penggunaan tipe data primitif, class, struct, array, dan map, programmer dapat membuat program-program yang lebih kompleks dan efisien untuk memenuhi kebutuhan pengembangan perangkat lunak.

# Referensi
[1]Khoirudin, Algoritma & Struktur Data dengan Python 3. Semarang: Universitas Semarang Press, 2019.<br/>
[2]Zenda,A.D.(2018, July 13).PENGERTIAN ARRAY.<br/>
[3]Wahyuni, Zelfi. “Makalah Dasar-dasar Pemograman Komputer.” OSF Preprints, 27 Feb. 2023. Web.