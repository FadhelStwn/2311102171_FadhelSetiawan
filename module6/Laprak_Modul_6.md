# <h1 align="center">Laporan Praktikum Modul 6 - LINKED LIST CIRCULAR DAN NON CIRCULAR </h1>
<p align="center">Fadhel Setiawan - 2311102171</p>

# Tujuan Pratikum
a. Mampu memahami konsep stack pada struktur data dan algoritma
b. Mampu mengimplementasikan operasi-operasi pada stack
c. Mampu memecahkan permasalahan dengan solusi stack

# Dasar Teori 
<p align="justify">Stack adalah struktur data sederhana yang digunakan untuk menyimpan data (mirip dengan Linked Lists). Dalam tumpukan, urutan kedatangan data penting. Sebuah tumpukan piring di kafetaria adalah contoh bagus dari tumpukan. Piring ditambahkan ke tumpukan saat mereka dibersihkan dan ditempatkan di bagian atas. Ketika sebuah piring dibutuhkan, diambil dari bagian atas tumpukan. Piring pertama yang ditempatkan di tumpukan adalah yang terakhir digunakan. Definisi: Sebuah tumpukan adalah daftar terurut di mana penyisipan dan penghapusan dilakukan di satu ujung, disebut atas. Elemen terakhir yang dimasukkan adalah yang pertama dihapus. Oleh karena itu, disebut daftar Last in First out (LIFO).</p>

gambar

### Operasi pada stack melibatkan beberapa fungsi dasar yang dapat dilakukan pada
struktur data ini. Berikut adalah beberapa operasi umum pada stack:
- Push (Masukkan): Menambahkan elemen ke dalam tumpukan pada posisi paling
atas atau ujung.
- Pop (Keluarkan): Menghapus elemen dari posisi paling atas atau ujung tumpukan.
- Top (Atas): Mendapatkan nilai atau melihat elemen teratas pada tumpukan tanpa
menghapusnya.
- IsEmpty (Kosong): Memeriksa apakah tumpukan kosong atau tidak.
- IsFull (Penuh): Memeriksa apakah tumpukan penuh atau tidak (terutama pada
implementasi tumpukan dengan kapasitas terbatas).
- Size (Ukuran): Mengembalikan jumlah elemen yang ada dalam tumpukan.
- Peek (Lihat): Melihat nilai atau elemen pada posisi tertentu dalam tumpukan
tanpa menghapusnya.
- Clear (Hapus Semua): Mengosongkan atau menghapus semua elemen dari
tumpukan.
- Search (Cari): Mencari keberadaan elemen tertentu dalam tumpukan.

# Guided

```c++
#include <iostream>
using namespace std;

string arrayBuku[5];
int maksimal = 5, top = 0;

bool isFull()
{
    return (top == maksimal);
}

bool isEmpty()
{
    return (top == 0);
}

void pushArrayBuku(string data)
{
    if (isFull())
    {
        cout << "Data telah penuh" << endl;
    }
    else
    {
        arrayBuku[top] = data;
        top++;
    }
}

void popArrayBuku()
{
    if (isEmpty())
    {
        cout << "Tidak ada data yang dihapus" << endl;
    }
    else
    {
        arrayBuku[top - 1] = "";
        top--;
    }
}

void peekArrayBuku(int posisi)
{
    if (isEmpty())
    {
        cout << "Tidak ada data yang bisa dilihat" << endl;
    }
    else
    {
        int index = top;
        for (int i = 1; i <= posisi; i++)
        {
            index--;
        }
        cout << "Posisi ke " << posisi << " adalah " << arrayBuku[index] << endl;
    }
}

int countStack()
{
    return top;
}

void changeArrayBuku(int posisi, string data)
{
    if (posisi > top)
    {
        cout << "Posisi melebihi data yang ada" << endl;
    }
    else
    {
        int index = top;
        for (int i = 1; i <= posisi; i++)
        {
            index--;
        }
        arrayBuku[index] = data;
    }
}

void destroyArraybuku()
{
    for (int i = top; i >= 0; i--)
    {
        arrayBuku[i] = "";
    }
    top = 0;
}

void cetakArrayBuku()
{
    if (isEmpty())
    {
        cout << "Tidak ada data yang dicetak" << endl;
    }
    else
    {
        for (int i = top - 1; i >= 0; i--)
        {
            cout << arrayBuku[i] << endl;
        }
    }
}

int main()
{
    pushArrayBuku("Kalkulus");
    pushArrayBuku("Struktur Data");
    pushArrayBuku("Matematika Diskrit");
    pushArrayBuku("Dasar Multimedia");
    pushArrayBuku("Inggris");

    cetakArrayBuku();
    cout << "\n";

    cout << "Apakah data stack penuh? " << isFull() << endl;
    cout << "Apakah data stack kosong? " << isEmpty() << endl;

    peekArrayBuku(2);
    popArrayBuku();

    cout << "Banyaknya data = " << countStack() << endl;

    changeArrayBuku(2, "Bahasa Jerman");
    cetakArrayBuku();
    cout << "\n";

    destroyArraybuku();
    cout << "Jumlah data setelah dihapus: " << top << endl;
    cetakArrayBuku();

    return 0;
}
```
# Output
![alt text](<Screenshot 2024-05-08 155853.png>)</br>
# Penjelasan
 Program tersebut merupakan program untuk menyimpan dan mengelola sejumlah data (dalam hal ini, daftar buku) dengan prinsip LIFO (Last In First Out), di mana elemen terakhir yang dimasukkan akan menjadi yang pertama untuk dikeluarkan. Program ini memungkinkan pengguna untuk menambah, menghapus, melihat, mengubah, dan menghitung jumlah data yang disimpan dalam stack. Hal ini dapat diterapkan dalam berbagai konteks, seperti manajemen buku perpustakaan, pencatatan riwayat transaksi, atau bahkan dalam pemrosesan data pada aplikasi komputer.

# Unguided

1) Unguided 1 

```c++
#include <iostream>
using namespace std;

string arrayBuku[5];
int maksimal = 5, top = 0;

bool isFull()
{
    return (top == maksimal);
}

bool isEmpty()
{
    return (top == 0);
}

void pushArrayBuku(string data)
{
    if (isFull())
    {
        cout << "Data telah penuh" << endl;
    }
    else
    {
        arrayBuku[top] = data;
        top++;
    }
}

void popArrayBuku()
{
    if (isEmpty())
    {
        cout << "Tidak ada data yang dihapus" << endl;
    }
    else
    {
        arrayBuku[top - 1] = "";
        top--;
    }
}

void peekArrayBuku(int posisi)
{
    if (isEmpty())
    {
        cout << "Tidak ada data yang bisa dilihat" << endl;
    }
    else
    {
        int index = top;
        for (int i = 1; i <= posisi; i++)
        {
            index--;
        }
        cout << "Posisi ke " << posisi << " adalah " << arrayBuku[index] << endl;
    }
}

int countStack()
{
    return top;
}

void changeArrayBuku(int posisi, string data)
{
    if (posisi > top)
    {
        cout << "Posisi melebihi data yang ada" << endl;
    }
    else
    {
        int index = top;
        for (int i = 1; i <= posisi; i++)
        {
            index--;
        }
        arrayBuku[index] = data;
    }
}

void destroyArraybuku()
{
    for (int i = top; i >= 0; i--)
    {
        arrayBuku[i] = "";
    }
    top = 0;
}

void cetakArrayBuku()
{
    if (isEmpty())
    {
        cout << "Tidak ada data yang dicetak" << endl;
    }
    else
    {
        for (int i = top - 1; i >= 0; i--)
        {
            cout << arrayBuku[i] << endl;
        }
    }
}

int main()
{
    pushArrayBuku("Kalkulus");
    pushArrayBuku("Struktur Data");
    pushArrayBuku("Matematika Diskrit");
    pushArrayBuku("Dasar Multimedia");
    pushArrayBuku("Inggris");

    cetakArrayBuku();
    cout << "\n";

    cout << "Apakah data stack penuh? " << isFull() << endl;
    cout << "Apakah data stack kosong? " << isEmpty() << endl;

    peekArrayBuku(2);
    popArrayBuku();

    cout << "Banyaknya data = " << countStack() << endl;

    changeArrayBuku(2, "Bahasa Jerman");
    cetakArrayBuku();
    cout << "\n";

    destroyArraybuku();
    cout << "Jumlah data setelah dihapus: " << top << endl;
    cetakArrayBuku();

    return 0;
}
```
# Output 
![alt text](<Screenshot 2024-05-08 160552.png>)
# Penjelasan 
Program ini berfungsi untuk memeriksa apakah sebuah kalimat yang dimasukkan pengguna adalah palindrom atau bukan. Itu dilakukan dengan memasukkan setiap karakter dari kalimat ke dalam stack, lalu membandingkan karakter tersebut dengan karakter-karakter di depan kalimat. Jika kalimat tersebut dapat dibaca dari depan dan belakang dengan hasil yang sama, maka kalimat itu adalah palindrom. 

2) Unguided 2 
```c++
#include <iostream>
#include <stack>

using namespace std;

string pengulang171(string kalimat171) {
  stack<char> s; // Buat stack untuk menyimpan karakter kalimat

  for (int i = 0; i < kalimat171.length(); i++) { // Masukkan karakter kalimat ke stack
    s.push(kalimat171[i]);
  }

  string setelahmengulangi171; // Membalik kalimat dengan mengeluarkan karakter dari stack
  while (!s.empty()) {
    setelahmengulangi171 += s.top();
    s.pop();
  }

  return setelahmengulangi171;
}

int main() {
  string kalimat171;
  cout << "-=-=- Membalik Kata -=-=-" << endl;

  do {
  cout << "\n Masukkan kalimat yang ingin dibalikkan: ";  // Input kalimat dari pengguna
  getline(cin, kalimat171);

  string setelahmengulangi171 = pengulang171(kalimat171);  // Membalik kalimat

  cout << " Kalimat yang dibalik: " << setelahmengulangi171 << endl; // Menampilkan kalimat yang dibalik

  } while (kalimat171 != "exit");
  return 0;
}
```
# Output
![alt text](<Screenshot 2024-05-08 154628.png>)
# Penjelasan 
Program tersebut merupakan program yang meminta pengguna memasukkan sebuah kalimat dan kemudian membalikkan kalimat tersebut. Ini dilakukan dengan menggunakan struktur data stack untuk membalikkan urutan karakter dalam kalimat. Program akan terus berjalan dan membalikkan setiap kalimat yang dimasukkan oleh pengguna. 

# Referensi
[1] Stroustrup, B., A Tour of C++ Third Edition. United States: Pearson Education, Inc., 2023.<br/>
[2]Y. Wu,S.Wang,C.-P.Bezemerand K.Inoue,"How do developers utilize source code from stack overflow?", Empir. Softw. Eng.,vol.24,no.2,pp.637-673,2019.</br>
[3]Muhammad Nugraha, Dasar Pemrograman Dengan C++, Materi Paling Dasar untuk Menjadi Programmer Berbagai Platform. Yogyakarta: Deepublish, 2021.


