# <h1 align="center">Laporan Praktikum Modul 8 - Algoritma Searching</h1>
<p align="center">Fadhel Setiawan - 2311102171</p>

## Dasar Teori

### Pengertian Searching
<p align="justify">Pencarian (Searching) yaitu proses menemukan suatu nilai tertentu pada kumpulan data. Hasil pencarian adalah salah satu dari tiga keadaan ini: data ditemukan, data ditemukan lebih dari satu, atau data tidak ditemukan. Searching juga dapat dianggap sebagai proses pencarian suatu data di dalam sebuah array dengan cara mengecek satu persatu pada setiap index baris atau setiap index kolomnya dengan menggunakan teknik perulangan untuk melakukan pencarian data. Terdapat 2 metode pada algoritma Searching, yaitu:</p>

### Sequential Search
![alt text](<Screenshot 2024-05-22 124348.png>)
<p align="justify">Algoritma sequential search adalah algoritma yang searching yang paling sederhana, dimana kita akan mencari sebuah nilai dari dalam list dengan cara membandingkannya satu per satu dari index ke 0 sampai index ke n. Algoritma ini merupakan algoritma dasar yang diajarkan oleh dosen/guru namun sering diterapkan dalam penggunaan sehari-hari. Untuk menjalankan algoritma ini kita hanya memerlukan 2 hal, yaitu Array target dan data key yang ingin dicari. Algoritma ini cukup fleksible, dimana kita tidak hanya bisa mencari angka (integer). namun kita bisa mencari integer, float, ataupun tipe data lainnya.</p>

#### Cara Kerja Sequential Search
1. Langkah pertama adalah menentukan data apa yang akan dicari, biasanya user akan menginputkan data yang akan dicari, dalam kasus ini, anggap saja kita ingin mencari angka 7. 
2. Setelah itu barulah kita memulai proses searching yang dimulai dari array index ke 0. 
3. Apakah value dari array index ke 0 (1) sama dengan 7? ternyata tidak, jadi kita akan lanjutkan ke index berikutnya. 
4. Apakah value dari array index ke 1 (9) sama dengan 7? teryata tidak, jadi kita lanjut kembali ke index berikutnya. 
5. Apakah value dari array index ke 2 (7) sama dengan 7? iya, maka sampai disini kamu bisa memilih untuk melanjutkan looping dan menghitung ada berapa angka 7 di dalam list atau keluar dari looping dan menyatakan bahwa angka 7 telah ditemukan.

### Binary Search
![Gambar Sequential Search](Pictures/Binary.png)
<p align="justify">Binary Search merupakan sebuah teknik pencarian data dengancara berulang kali membagi separuh dari jumlah data yang dicari sampai sehingga memperkecil lokasi pencarian menjadi satu data. Dengan teknik ini kita akanmembuang setengah dari jumlah data. Apabila ditemukan kecocokan data maka program akan mengembalikan output, jika tidak pencarian akan terus berlanjut hingga akhir dari pembagian jumlah data tersebut. Algotihma ini biasanya banyak digunakan untuk mencari di program dengan jumlah data yang banyak, dimana kompleksitas dari algorithma ini adalah Ο(log n) di mana n adalah jumlah item. Pada saat menggunakan binary search, data yang berada di dalam array harus diurutkan terlebih dahulu.</p>

#### Cara Kerja Binary Search
<p align="justify">Misalkan kita memiliki int arr[] = {70, 60, 30, 50, 40,20}, data para int arr harus diurutkan terlebih dahulu menggunakan teknik sorting seperti bubble sort. Sehingga array kita akan menjadi int arr[] = {20,30,40,50,60,70}. Apabila angka yang dicari adalah angka 40. Jika data ditemukan, maka program akan keluar dari looping. Jika kita ingin menampilkan index dari data yang dicari, kita tinggal menyimpan index dari array tersebut dan menampilkan nya.</br>

## Guided 

### 1. Sequential Search

```C++
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
```
<p align="justify">Dalam program ini, sebuah array dengan panjang 10 elemen diinisialisasi dengan data tertentu. Nilai yang ingin dicari, yaitu 10, juga dideklarasikan. Program kemudian menggunakan loop for untuk memeriksa setiap elemen dalam array, dimulai dari indeks 0 hingga 9. Jika elemen yang diperiksa sama dengan nilai yang dicari, variabel boolean ketemu diatur menjadi true, dan loop dihentikan menggunakan perintah break untuk menghindari pemeriksaan elemen yang tidak perlu.</p>

<p align="justify">Setelah loop selesai, program menampilkan hasil pencarian. Jika nilai ditemukan, program mencetak pesan yang menunjukkan nilai yang dicari dan indeks di mana nilai tersebut ditemukan. Jika nilai tidak ditemukan setelah memeriksa semua elemen dalam array, program mencetak pesan bahwa nilai tidak ditemukan dalam array. Selain itu, program juga mencetak array data awal untuk referensi pengguna. Program ini adalah contoh sederhana namun efektif untuk memahami konsep dasar pencarian linear dalam pemrograman.</p>

### 2. Binary Search

```C++
#include <iostream>
#include <iomanip>
using namespace std;
// Deklarasi array dan variabel untuk pencarian
int arrayData[7] = {1, 8, 2, 5, 4, 9, 7};
int cari;
void selection_sort(int arr[], int n)
{
    int temp, min;
    for (int i = 0; i < n - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        // Tukar elemen
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}
void binary_search(int arr[], int n, int target)
{
    int awal = 0, akhir = n - 1, tengah, b_flag = 0;
    while (b_flag == 0 && awal <= akhir)
    {
        tengah = (awal + akhir) / 2;
        if (arr[tengah] == target)
        {
            b_flag = 1;
            break;
        }
        else if (arr[tengah] < target)
        {
            awal = tengah + 1;
        }
        else
        {
            akhir = tengah - 1;
        }
    }
    if (b_flag == 1)
        cout << "\nData ditemukan pada index ke-" << tengah << endl;
    else
        cout << "\nData tidak ditemukan\n";
}
int main()
{
    cout << "\tBINARY SEARCH" << endl;
    cout << "\nData awal: ";
    // Tampilkan data awal
    for (int x = 0; x < 7; x++)
    {
        cout << setw(3) << arrayData[x];
    }
    cout << endl;
    cout << "\nMasukkan data yang ingin Anda cari: ";
    cin >> cari;
    // Urutkan data dengan selection sort
    selection_sort(arrayData, 7);
    cout << "\nData diurutkan: ";
    // Tampilkan data setelah diurutkan
    for (int x = 0; x < 7; x++)
    {
        cout << setw(3) << arrayData[x];
    }
    cout << endl;
    // Lakukan binary search
    binary_search(arrayData, 7, cari);
    return 0;
}
```
<p align="justify">program ini berfungsi mencari sebuah nilai dalam sebuah array menggunakan metode pencarian biner (binary search) setelah array tersebut diurutkan terlebih dahulu dengan menggunakan algoritma selection sort. Program dimulai dengan mendeklarasikan sebuah array arrayData yang berisi 7 elemen integer dan sebuah variabel cari untuk menyimpan nilai yang akan dicari.</p>

## Unguided

### 1. Buatlah sebuah program untuk mencari sebuah huruf pada sebuah kalimat yang sudah diinput dengan menggunakan Binary Search!

```C++
#include <iostream>
#include <string>

using namespace std;


bool binarySearch(string kalimat171, char carikalimat171) {
 
  int low171 = 0;
  int high171 = kalimat171.length() - 1;

  
  while (low171 <= high171) {
    
    int mid = (low171 + high171) / 2;

   
    if (kalimat171[mid] == carikalimat171) {
      
      return true;
    } else if (kalimat171[mid] < carikalimat171) {
      
      low171 = mid + 1;
    } else {
     
      high171 = mid - 1;
    }
  }


  return false;
}

int main() {
  
  string kalimat171;
  char carikalimat171;


  cout << "Masukkan kalimat171: ";
  getline(cin, kalimat171);

 
  cout << "Masukkan huruf yang ingin dicari: ";
  cin >> carikalimat171;

  
  bool ditemukan = binarySearch(kalimat171, carikalimat171);

 
  if (ditemukan) {
    cout << "Huruf '" << carikalimat171 << "' ditemukan dalam kalimat." << endl;
  } else {
    cout << "Huruf '" << carikalimat171 << "' tidak ditemukan dalam kalimat." << endl;
  }

  return 0;
}
```
## Output Unguided 1:
![alt text](<Screenshot 2024-05-22 125701.png>)
<p align="justify">Program ini digunakan untuk mencari sebuah karakter dalam sebuah string menggunakan metode pencarian biner (binary search). Namun, agar pencarian biner dapat berfungsi dengan benar, string harus diurutkan terlebih dahulu. Dalam program ini, pengguna diminta untuk memasukkan sebuah kalimat (string) dan sebuah karakter yang ingin dicari dalam kalimat tersebut. Program kemudian menggunakan fungsi binarySearch untuk mencari karakter tersebut dalam kalimat.</p>\

### 2. Buatlah sebuah program yang dapat menghitung banyaknya huruf vokal dalam sebuah kalimat!

```C++
#include <iostream>
#include <cctype>

using namespace std;

bool isVowel(char karakter171) { 
    karakter171 = tolower(karakter171); 
    return (karakter171 == 'a' || karakter171 == 'e' || karakter171 == 'i' || karakter171 == 'o' || karakter171 == 'u'); 
}

void countVowels(const string &kata171, int vocal171[5]) { 
   
    for (char karakter171 : kata171) {
        if (isVowel(karakter171)) {  
            switch (tolower(karakter171)) { 
                case 'a': 
                    vocal171[0]++; 
                    break;
                case 'e':
                    vocal171[1]++; 
                    break;
                case 'i':
                    vocal171[2]++; 
                    break;
                case 'o':
                    vocal171[3]++; 
                    break;
                case 'u':
                    vocal171[4]++; 
                    break;
            }
        }
    }
}

int main() {
    string kata171;
    cout << "\n Menghitung Banyak Huruf Vokal" << endl;

    do
    {
    cout << "\n------------------------------" << endl;
    cout << "\nMasukan Sebuah Kalimat :"; getline(cin, kata171);

    int vocal171[5] = {0}; 

    countVowels(kata171, vocal171); 

    cout << "\nKalimat yang kamu masukan terdiri dari huruf vokal ini:\n";
    cout << "a: " << vocal171[0] << endl;
    cout << "e: " << vocal171[1] << endl;
    cout << "i: " << vocal171[2] << endl;
    cout << "o: " << vocal171[3] << endl;
    cout << "u: " << vocal171[4] << endl;
    
    } while (kata171 != "!");
    
}
```
## Output Unguided 2:
![alt text](<Screenshot 2024-05-22 130741.png>)
<p align="justify">Program ini digunakan untuk menghitung jumlah masing-masing huruf vokal ('a', 'e', 'i', 'o', 'u') dalam sebuah kalimat yang dimasukkan oleh pengguna. Program dimulai dengan meminta pengguna untuk memasukkan sebuah kalimat. Kemudian, fungsi countVowels memproses kalimat tersebut dengan memeriksa setiap karakter apakah termasuk vokal menggunakan fungsi isVowel. Jika karakter adalah vokal, program akan meningkatkan jumlah hitungan vokal yang sesuai dalam array vocal171. Setelah selesai memproses kalimat, program mencetak jumlah masing-masing vokal yang ditemukan. Proses ini diulang terus menerus hingga pengguna memasukkan kalimat "!". Setiap kali pengguna memasukkan kalimat baru, hasil perhitungan vokal akan ditampilkan.</p>

### 3. Diketahui data = 9, 4, 1, 4, 7, 10, 5, 4, 12, 4. Hitunglah berapa banyak angka 4 dengan menggunakan algoritma Sequential Search!

```C++
#include <iostream>

using namespace std;

int main() {
    int n = 10;
    int data171[n] = {9, 4, 1, 4, 7, 10, 5, 4, 12, 4};
    int cari171 = 4;
    int count171 = 0;  
    int indeks[n]; 
    int i;

   
    for (i = 0; i < n; i++) {
        if (data171[i] == cari171) {
            indeks[count171] = i; 
            count171++;
        }
    }

    cout << "\nHitunglah berapa banyak angka 4 dengan menggunakan algoritma Sequential Search!" << endl;
    cout << "\n-------------------------------------------------------------------------------" << endl;
    cout << "\nData : {9, 4, 1, 4, 7, 10, 5, 4, 12, 4}" << endl;

    cout << "\nNomor " << cari171 << " berjumlah " << count171 << " pada data tersebut " << endl;

    
    if (count171 > 0) {
        cout << "\nnomor " << cari171 << " ditemukan pada indeks berikut : ";
        for (i = 0; i < count171; i++) {
            cout << indeks[i];
            if (i != count171 - 1) {
                cout << ", ";
            }
        }
        cout << endl;
    } else {
        cout << "\nnomor" << cari171 << " tidak ditemukan di mana pun!" << endl;
    }
    return 0;
}
```
## Output Unguided 3:
![alt text](<Screenshot 2024-05-22 131809.png>)
<p align="justify">Program ini digunakan untuk menghitung jumlah kemunculan angka tertentu, dalam hal ini angka 4, dalam sebuah array menggunakan algoritma pencarian sekuensial. Program dimulai dengan mendeklarasikan sebuah array data171 yang berisi 10 elemen. Program kemudian mendeklarasikan variabel cari171 yang menyimpan nilai yang akan dicari, serta variabel count171 untuk menghitung jumlah kemunculan angka tersebut dan array indeks untuk menyimpan indeks di mana angka tersebut ditemukan. Dengan menggunakan loop for, program memeriksa setiap elemen dalam array dan jika elemen tersebut sama dengan nilai yang dicari, indeks elemen tersebut disimpan dalam array indeks dan count171 ditingkatkan. Setelah loop selesai, program menampilkan jumlah kemunculan angka yang dicari serta indeks-indeks di mana angka tersebut ditemukan. Jika angka tidak ditemukan, program mencetak pesan bahwa angka tersebut tidak ditemukan di mana pun.</p>

## Kesimpulan
Dari hasil analisis perbandingan antara algoritma Binary Search dan Regular Search Expression dalam pencarian data, dapat diambil dari Kedua algoritma memiliki kelebihan dan kekurangan masing-masing, binary Search cocok untuk pencarian data besar dan terurut, sementara Regular Search Expression lebih fleksibel dalam pencarian berdasarkan pola. Pemilihan algoritma pencarian harus disesuaikan dengan karakteristik data dan kebutuhan pencarian yang spesifik. Dari perbandingan antara algoritma Binary Search dan Regular Search Expression, dapat disimpulkan bahwa Binary Search efisien untuk pencarian data besar dan terurut, sementara Regular Search Expression lebih fleksibel dalam pencarian berdasarkan pola. Pemilihan algoritma pencarian harus disesuaikan dengan karakteristik data dan kebutuhan pencarian yang spesifik 

## Referensi
[1] Quinn, R., Advanced C++ Programming Cookbook. United Kingdoms: Packt Publishing Ltd., 2020.<br/>
[2] Budiman, A. & Rusdi, A. (2020). Penerapan Algoritma Pencarian Binary Search pada Sistem Basis Data untuk Meningkatkan Kecepatan Pencarian Data. Jurnal Sains dan Teknologi Komputer, 11(2), 123-130.<br/>
[3] Fenina Adline Twince Tobing, Rena Nainggolan, ANALISIS PERBANDINGAN PENGGUNAAN METODE BINARY SEARCH DENGAN REGULAR SEARCH EXPRESSION, Vol. 4, No. 2, 168-172, Oktober 2020.<br/>
