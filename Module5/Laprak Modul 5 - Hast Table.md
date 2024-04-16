# <h1 align="center">Laporan Praktikum Modul 5 - Hash Table</h1>
<p align="center">Fadhel Setiawan - 2311102171</p>

## Dasar Teori

![alt text](<Screenshot 2024-04-16 194814.png>)
### Pengertian Hash Table
<p align="justify">Hash table merupakan struktur data yang secara asosiatif menyimpan data. Dalam hal ini, data disimpan dalam format array, di mana setiap nilai data memiliki nilai indeks uniknya sendiri. Akses data akan menjadi sangat cepat jika user mengetahui indeks dari data yang diinginkan. Dengan demikian, hash table menjadi struktur data di mana operasi penyisipan dan pencarian data terjadi sangat cepat terlepas dari ukuran data tersebut. Hash table menggunakan array sebagai media penyimpanan dan tekniknya untuk menghasilkan indeks suatu elemen yang dimasukkan atau ditempatkan.</p>

### Fungsi Hash Table
<p align="justify">Fungsi utamanya pada data adalah mempercepat proses akses data. Hal ini berkaitan dengan peningkatan data dalam jumlah besar yang diproses oleh jaringan data global dan lokal. Hash table adalah solusi untuk membuat proses akses data lebih cepat dan memastikan bahwa data dapat dipertukarkan dengan aman. Di dalam banyak bidang, hash table dikembangkan dan digunakan karena menawarkan kelebihan dalam efisiensi waktu operasi, mulai dari pengarsipan hingga pencarian data. Contohnya adalah bidang jaringan komputer yang mengembangkannya menjadi hybrid open hash table, yang kemudian dipakai untuk memproses jaringan komputer.</p>

### Cara Membuat Hash Table
<p align="justify">Untuk membuat hash table, sepotong memori perlu diblokir dengan cara yang sama seperti saat membuat array. User perlu membuat indeks yang didasarkan pada kunci dengan menggunakan fungsi hash karena indeks yang dihasilkan harus sesuai dengan potongan memori. Ada dua pemeriksaan yang dibutuhkan saat menempatkan data baru pada hash table, yaitu nilai hash dari kunci dan bagaimana nilainya dibandingkan dengan objek lain. Pemeriksaan ini diperlukan saat membuatnya dengan Python karena saat data dimasukkan, kunci akan di-hash dan di-mask agar diubah menjadi larik atau indeks yang efisien.</p>

### Cara Kerja Hash Table
1. Insertion:
Memasukkan data baru ke dalam hash table dengan memanggil fungsi hash
untuk menentukan posisi bucket yang tepat, dan kemudian menambahkan
data ke bucket tersebut.
2. Deletion:
Menghapus data dari hash table dengan mencari data menggunakan fungsi
hash, dan kemudian menghapusnya dari bucket yang sesuai.
3. Searching:
Mencari data dalam hash table dengan memasukkan input kunci ke fungsi
hash untuk menentukan posisi bucket, dan kemudian mencari data di dalam
bucket yang sesuai.
4. Update:
Memperbarui data dalam hash table dengan mencari data menggunakan
fungsi hash, dan kemudian memperbarui data yang ditemukan.
5. Traversal:
Melalui seluruh hash table untuk memproses semua data yang ada dalam
tabel.

### D. Collision Resolution
Keterbatasan tabel hash adalah jika dua angka dimasukkan ke dalam fungsi
hash menghasilkan nilai yang sama. Hal ini disebut dengan collision. Ada dua
teknik untuk menyelesaikan masalah ini diantaranya :</br>
![alt text](<Screenshot 2024-04-16 202053.png>)

### 1. Open Hashing (Chaining)
Metode chaining mengatasi collision dengan cara menyimpan semua item data dengan nilai indeks yang sama ke dalam sebuah linked list. Setiap node pada linked list merepresentasikan satu item data. Ketika ada pencarian atau penambahan item data, pencarian atau penambahan dilakukan pada linked list yang sesuai dengan indeks yang telah dihitung dari kunci yang di hash. Ketika linked list memiliki banyak node, pencarian atau penambahan item data menjadi lambat, karena harus mencari di seluruh linked list.Namun, chaining dapat mengatasi jumlah item data yang besar dengan efektif, karena keterbatasan array dihindari.

### 2. Closed Hashing
- Linear Probing
Pada saat terjadi collision, maka akan mencari posisi yang kosong di
bawah tempat terjadinya collision, jika masih penuh terus ke bawah,
hingga ketemu tempat yang kosong. Jika tidak ada tempat yang kosong
berarti HashTable sudah penuh.
- Quadratic Probing
Penanganannya hampir sama dengan metode linear, hanya
lompatannya tidak satu-satu, tetapi quadratic ( 12, 22, 32, 42, ... )
- Double Hashing
Pada saat terjadi collision, terdapat fungsi hash yang kedua untuk
menentukan posisinya kembali.

## Guided 

### 1. Latihan Hash Table Sederhana

```C++
// Guided 1

#include <iostream>
using namespace std;

const int MAX_SIZE = 10;

// Fungsi hash sederhana
int hash_func(int key) {
    return key % MAX_SIZE;
}

// Struktur data untuk setiap node
struct Node {
    int key;
    int value;
    Node* next;
    Node(int key, int value) : key(key), value(value), next(nullptr) {}
};

// Class hash table
class HashTable {
private:
    Node** table;

public:
    HashTable() {
        table = new Node*[MAX_SIZE]();
    }

    ~HashTable() {
        for (int i = 0; i < MAX_SIZE; i++) {
            Node* current = table[i];
            while (current != nullptr) {
                Node* temp = current;
                current = current->next;
                delete temp;
            }
        }
        delete[] table;
    }

    // Insertion
    void insert(int key, int value) {
        int index = hash_func(key);
        Node* current = table[index];
        while (current != nullptr) {
            if (current->key == key) {
                current->value = value;
                return;
            }
            current = current->next;
        }
        Node* node = new Node(key, value);
        node->next = table[index];
        table[index] = node;
    }

    // Searching
    int get(int key) {
        int index = hash_func(key);
        Node* current = table[index];
        while (current != nullptr) {
            if (current->key == key) {
                return current->value;
            }
            current = current->next;
        }
        return -1;
    }

    // Deletion
    void remove(int key) {
        int index = hash_func(key);
        Node* current = table[index];
        Node* prev = nullptr;
        while (current != nullptr) {
            if (current->key == key) {
                if (prev == nullptr) {
                    table[index] = current->next;
                } else {
                    prev->next = current->next;
                }
                delete current;
                return;
            }
            prev = current;
            current = current->next;
        }
    }

    // Traversal
    void traverse() {
        for (int i = 0; i < MAX_SIZE; i++) {
            Node* current = table[i];
            while (current != nullptr) {
                cout << current->key << ": " << current->value << endl;
                current = current->next;
            }
        }
    }
};

int main() {
    HashTable ht;

    // Insertion
    ht.insert(1, 10);
    ht.insert(2, 20);
    ht.insert(3, 30);

    // Searching
    cout << "Get key 1: " << ht.get(1) << endl;
    cout << "Get key 4: " << ht.get(4) << endl;

    // Deletion
    ht.remove(4);

    // Traversal
    ht.traverse();

    return 0;
}
```
![alt text](<Screenshot 2024-04-16 190443.png>)
Kode di atas digunakan untuk menjalankan hash table sederhana. Pada struct Node terdapat key & value bertipe data integer, Node* next, dan deklarasi Node. Ada juga class HashTable di mana ada private class dan public class. Dalam private class, dideklarasikan Node** table dan di dalam public class dideklarasikan HashTable(), ~HashTable(), dan fungsi lainnya yang dapat dipakai di int main(). Program menambahkan tiga key dengan value 10, 20, dan 30 melalui ht.insert(). Lalu, dicari key 1 dan 4 dengan ht.get(). Selanjutnya, key 4 dihapus dengan ht.remove(). Pada akhirnya, program menampilkan key dan valuenya melalui ht.traverse() dengan outputnya adalah "1: 10, 2: 20, 3: 30".</p>

### 2. Latihan Hash Table dengan Node

```C++
// Guided 2

#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int TABLE_SIZE = 11;

class HashNode {
public:
    string name;
    string phone_number;

    HashNode(string name, string phone_number) {
        this->name = name;
        this->phone_number = phone_number;
    }
};

class HashMap {
private:
    vector<HashNode*> table[TABLE_SIZE];

public:
    int hashFunc(string key) {
        int hash_val = 0;
        for (char c : key) {
            hash_val += c;
        }
        return hash_val % TABLE_SIZE;
    }

    void insert(string name, string phone_number) {
        int hash_val = hashFunc(name);
        for (auto node : table[hash_val]) {
            if (node->name == name) {
                node->phone_number = phone_number;
                return;
            }
        }
        table[hash_val].push_back(new HashNode(name, phone_number));
    }

    void remove(string name) {
        int hash_val = hashFunc(name);
        for (auto it = table[hash_val].begin(); it != table[hash_val].end(); it++) {
            if ((*it)->name == name) {
                table[hash_val].erase(it);
                return;
            }
        }
    }

    string searchByName(string name) {
        int hash_val = hashFunc(name);
        for (auto node : table[hash_val]) {
            if (node->name == name) {
                return node->phone_number;
            }
        }
        return "";
    }

    void print() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << i << ": ";
            for (auto pair : table[i]) {
                if (pair != nullptr) {
                    cout << "[" << pair->name << ", " << pair->phone_number << "]";
                }
            }
            cout << endl;
        }
    }
};

int main() {
    HashMap employee_map;
    employee_map.insert("Mistah", "1234");
    employee_map.insert("Pastah", "5678");
    employee_map.insert("Ghana", "91011");

    cout << "Nomer Hp Mistah: " << employee_map.searchByName("Mistah") << endl;
    cout << "Phone Hp Pastah: " << employee_map.searchByName("Pastah") << endl;

    employee_map.remove("Mistah");

    cout << "Nomer Hp Mistah setelah dihapus: " << employee_map.searchByName("Mistah") << endl << endl;

    cout << "Hash Table: " << endl;
    employee_map.print();

    return 0;
}
```
![alt text](<Screenshot 2024-04-16 190906.png>)
Kode di atas digunakan untuk menjalankan hash table dengan node. Pada class HashNode, terdapat class public di mana class public ini memiliki string name dan phone_number. Lalu, di dalam class HashMap, terdapat class private dan public. Dalam class privatenya, dideklarasikan vector<HashNode*> table[TABLE_SIZE]. Dalam class publicnya, dideklarasikan int hashFunc(string key) beserta fungsi lainnya yang dapat dipakai di int main(). Program menambahkan tiga data, yaitu name Mistah dan phone_number 1234, Pastah dan 5678, Ghana dan 91011 dengan employee_map.insert(). Lalu, program mencari data nomor hp milik Mistah dan Pastah melalui employee_map.searchByName(). Selanjutnya, program menghapus data milik Mistah melalui employee_map.remove(). Setelah dihapus, ditampilkan nomor hp Mistah yang telah dihapus melalui employee_map.searchByName(). Pada akhirnya, program menampilkan Hash Table dengan employee_map.print().</p>

## Unguided

### 1. Implementasikan hash table untuk menyimpan data mahasiswa. Setiap mahasiswa memiliki NIM dan nilai. Implementasikan fungsi untuk menambahkan data baru, menghapus data, mencari data berdasarkan NIM, dan mencari data berdasarkan nilai. Dengan ketentuan:</br> a. Setiap mahasiswa memiliki NIM dan nilai.</br> b. Program memiliki tampilan pilihan menu berisi poin C.</br> c. Implementasikan fungsi untuk menambahkan data baru, menghapus data, mencari data berdasarkan NIM, dan mencari data berdasarkan rentang nilai (80 – 90).

```C++
#include <iostream>
#include <iomanip>
using namespace std;

const int MAX_SIZE = 10;

// Fungsi hash sederhana
int hash_func(long long key) {
    return key % MAX_SIZE;
}

// Struktur data untuk setiap node
struct Mahasiswa_2171 {
    long long NIM_2171;
    string Nama_2171; 
    int Nilai_2171;
    Mahasiswa_2171* next;
    Mahasiswa_2171(long long NIM_2171, string Nama_2171, int Nilai_2171) : NIM_2171(NIM_2171), Nama_2171(Nama_2171), Nilai_2171(Nilai_2171), next(nullptr) {} // Constructor
};

// Class hash table
class HashTable {
private:
    Mahasiswa_2171** table;

public:
    HashTable() { // Constructor
        table = new Mahasiswa_2171*[MAX_SIZE]();
    }

    ~HashTable() { // Destructor
        for (int i = 0; i < MAX_SIZE; i++) { // Menghapus semua node yang ada
            Mahasiswa_2171* current = table[i]; // Menunjuk ke index yang sudah ditentukan
            while (current != nullptr) {
                Mahasiswa_2171* temp = current;
                current = current->next;
                delete temp;
            }
        }
        delete[] table;
    }

    // Insertion
    void Insert_2139(long long NIM_2171, string Nama_2171, int Nilai_2171) {
        int index = hash_func(NIM_2171); // Menggunakan fungsi hash untuk menentukan index
        Mahasiswa_2171* current = table[index]; // Menunjuk ke index yang sudah ditentukan
        while (current != nullptr) {
            if (current->NIM_2171 == NIM_2171) {
                current->Nilai_2171 = Nilai_2171;
                return;
            }
            current = current->next;
        }
        Mahasiswa_2171* mahasiswa = new Mahasiswa_2171(NIM_2171, Nama_2171, Nilai_2171);
        mahasiswa->next = table[index]; // Menunjuk ke node selanjutnya
        table[index] = mahasiswa; // Menunjuk ke node yang baru dibuat
    }

    // Searching by NIM_2171
    Mahasiswa_2171* SearchNIM_2171(long long NIM_2171) {
        int index = hash_func(NIM_2171); // Menggunakan fungsi hash untuk menentukan index
        Mahasiswa_2171* current = table[index]; // Menunjuk ke index yang sudah ditentukan
        while (current != nullptr) {
            if (current->NIM_2171 == NIM_2171) {
                return current;
            }
            current = current->next;
        }
        return nullptr;
    }

    // Searching by value range (80 - 90)
    void SearchNilai_2171(int StartScoreRange, int EndScoreRange) {
        cout << left << setw(15) << "-NAME-" << setw(20) << "-NIM-" << right << setw(2) << "-SCORE-" << endl;
        for (int i = 0; i < MAX_SIZE; i++) { // Untuk setiap index yang ada di tabel hash table ini, akan diiterasi satu per satu untuk mencari data yang sesuai dengan range yang diinginkan
            Mahasiswa_2171* current = table[i];
            while (current != nullptr) {
                if (current->Nilai_2171 >= StartScoreRange && current->Nilai_2171 <= EndScoreRange) { // Jika nilai mahasiswa berada di dalam range yang diinginkan
                    cout << left << setw(15) << current->Nama_2171 << setw(20) << current->NIM_2171 << right << setw(6) << current->Nilai_2171 << endl; // Maka data mahasiswa tersebut akan ditampilkan
                }
                current = current->next;
            }
        }
    }

    // Deletion
    void Remove_2139(long long NIM_2171) {
    int index = hash_func(NIM_2171); // Menggunakan fungsi hash untuk menentukan index
    Mahasiswa_2171* current = table[index]; // Menunjuk ke index yang sudah ditentukan
    Mahasiswa_2171* prev = nullptr;
    
    while (current != nullptr) { // Iterasi untuk mencari data yang akan dihapus
        if (current->NIM_2171 == NIM_2171) { // Jika data ditemukan
            if (prev == nullptr) { // Jika data yang akan dihapus berada di awal index
                table[index] = current->next; // Maka index akan menunjuk ke node selanjutnya
            } else {
                prev->next = current->next; // Jika data yang akan dihapus berada di tengah atau akhir index, maka node sebelumnya akan menunjuk ke node setelahnya
            }
            delete current; // Menghapus node yang diinginkan
            cout << "\nCongrats! NIM " << NIM_2171 << " has been erased from existence!" << endl;
            return;
        }
        prev = current;
        current = current->next;
    }
    
    // Jika NIM tidak ditemukan
    cout << "\nHuh? NIM " << NIM_2171 << " is nowhere to be found." << endl;
}


    // Traversal
    void Traverse_2139() {
        cout << left << setw(17) << "-NAME-" << setw(17) << "-NIM-" << setw(12) << "-SCORE-" << endl;
        for (int i = 0; i < MAX_SIZE; i++) { // Diiterasi untuk setiap index yang ada di tabel hash table ini
            Mahasiswa_2171* current = table[i]; // Menunjuk ke index yang sudah ditentukan
            while (current != nullptr) { // Iterasi untuk menampilkan data mahasiswa
                cout << left << setw(17) << current->Nama_2171 << setw(19) << current->NIM_2171 << setw(12) << current->Nilai_2171 << endl;
                current = current->next;
        }
    }
}
};

int main() {
    HashTable ht; // Membuat objek hash table

    cout << "\n-=-=-=- PROGRAM HASH TABLE DATA MAHASISWA -=-=-=-" << endl;

    while (true) {
        cout << "\n-=- MENU -=-";
        cout << "\n1. Add Data Mahasiswa";
        cout << "\n2. Delete Data Mahasiswa";
        cout << "\n3. Search Data by NIM Mahasiswa";
        cout << "\n4. Search Score by Range";
        cout << "\n5. Show Data Mahasiswa";
        cout << "\n6. Exit";
        cout << "\nChoose your choice: ";
        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "\n-=-= ADD DATA MAHASISWA =-=-" << endl;
                long long NIM_2171;
                string Nama_2171;
                int Nilai_2171;
                cout << "Enter the student's name: ";
                cin.ignore(); // Untuk menghindari bug cin getline
                getline(cin, Nama_2171); // Menggunakan getline untuk input string yang mengandung spasi
                cout << "Enter the NIM: ";
                cin >> NIM_2171;
                cout << "Input the score: ";
                cin >> Nilai_2171;
                ht.Insert_2139(NIM_2171, Nama_2171, Nilai_2171); // Memasukkan data mahasiswa ke dalam hash table
                cout << "\nSuccess! You have added the student data of " << Nama_2171 << " with the NIM " << NIM_2171 << " and the score " << Nilai_2171 << endl;
                break;
            }
            case 2: {
                cout << "\n-=-= DELETE DATA MAHASISWA =-=-" << endl;
                long long NIM_2171;
                cout << "Input which NIM to delete: ";
                cin >> NIM_2171;
                ht.Remove_2139(NIM_2171); // Menghapus data mahasiswa dari hash table
                break;
            }
            case 3: {
                cout << "\n-=-= SEARCH DATA BY NIM MAHASISWA =-=-" << endl;
                long long NIM_2171;
                cout << "Input NIM to search for their data: ";
                cin >> NIM_2171;
                Mahasiswa_2171* mahasiswa = ht.SearchNIM_2171(NIM_2171); // Mencari data mahasiswa berdasarkan NIM
                if (mahasiswa != nullptr) // Jika data ditemukan
                    cout << "\nThe NIM " << NIM_2171 << " belongs to " << mahasiswa->Nama_2171 << " and has the score of " << mahasiswa->NIM_2171 << endl; // Maka data mahasiswa tersebut akan ditampilkan
                else
                    cout << "\nWhoops! Data not found!" << endl;
                break;
            }
            case 4: {
                cout << "\n-=-= SEARCH SCORE BY RANGE =-=-" << endl;
                int StartScoreRange, EndScoreRange;
                cout << "Range starts from Score: ";
                cin >> StartScoreRange;
                cout << "to Score: ";
                cin >> EndScoreRange;
                cout << "\nStudent(s) with the score between " << StartScoreRange << "-" << EndScoreRange << " are:\n";
                ht.SearchNilai_2171(StartScoreRange, EndScoreRange); // Mencari data mahasiswa berdasarkan range nilai
                break;
            }
            case 5: {
                cout << "\n" << right << setw(8) << "" << "-=-= MAHASISWA DATA =-=-" << endl;
                ht.Traverse_2139(); // Menampilkan data mahasiswa yang ada di hash table
                break;
            }
            case 6:
                cout << "\nThank you for using program!";
                return 0;
            default:
                cout << "\nWhat did you just type..?" << endl;
        }
    }
}
```
#### Output Unguided 1:
![alt text](<Screenshot 2024-04-16 194654.png>)
![alt text](<Screenshot 2024-04-16 194729.png>)
Program tersebut merupakan program sederhana dari hash table untuk menyimpan data mahasiswa. Berikut adalah penjelasan fungsi-fungsi utama dalam program:</br>
1. Fungsi Hash (hash_func):
- Digunakan untuk menghasilkan indeks (index) dari sebuah kunci (key) yang diberikan.
- Fungsi ini menggunakan modulus untuk mengonversi kunci menjadi indeks, sehingga menghasilkan angka antara 0 hingga MAX_SIZE 

2. Struktur Data Mahasiswa (Mahasiswa_2171):
- Merupakan struktur data yang menyimpan informasi tentang seorang mahasiswa, termasuk NIM, nama, dan nilai.
- Setiap elemen dalam tabel hash akan menunjuk ke linked list dari struktur ini, sehingga memungkinkan untuk menangani collision (tabrakan indeks).

3. Kelas Hash Table (HashTable):
- Menyediakan operasi-operasi dasar untuk tabel hash, seperti Insert_2139, Remove_2139, SearchNIM_2171, SearchNilai_2171, dan Traverse_2139.
- Dalam implementasi ini, collision handling dilakukan dengan chaining, yaitu setiap elemen di tabel hash menunjuk ke linked list yang berisi semua elemen yang memiliki indeks yang sama.

4. Fungsi-fungsi Utama:
- Insert_2139: Memasukkan data mahasiswa baru ke dalam tabel hash.
- Remove_2139: Menghapus data mahasiswa dari tabel hash berdasarkan NIM.
- SearchNIM_2171: Mencari data mahasiswa berdasarkan NIM.
- SearchNilai_2171: Mencari data mahasiswa berdasarkan rentang nilai.
- Traverse_2139: Menampilkan semua data mahasiswa yang ada dalam tabel hash.
- main(): Berisi loop utama untuk menampilkan menu dan memproses input pengguna. User dapat memilih untuk menambahkan data mahasiswa, menghapusnya, mencari berdasarkan NIM, mencari berdasarkan rentang nilai, atau menampilkan semua data mahasiswa.
- Selain itu, program ini juga melakukan alokasi memori dinamis untuk tabel hash dan setiap node dalam linked list, serta mengimplementasikan dealokasi memori melalui destruktor.

## Kesimpulan
<p align="justify">Hash table adalah struktur data yang digunakan untuk menyimpan data secara asosiatif dengan menggunakan teknik hash untuk memetakan nilai kunci ke indeks dalam array. Fungsi hash digunakan untuk menghasilkan indeks unik untuk setiap kunci, memungkinkan akses data dalam waktu konstan terlepas dari ukuran data. Hash table sangat efisien untuk operasi penyisipan, pencarian, dan penghapusan data. Cara membuat hash table melibatkan inisialisasi sepotong memori yang diblokir dengan ukuran tertentu dan penggunaan fungsi hash untuk menentukan indeks tempat data disimpan. Hash table harus memiliki mekanisme untuk menangani bentrokan yang mungkin terjadi saat dua kunci menghasilkan nilai hash yang sama.</p>

## Referensi
[1] Mailund, T. (2019). The Joys of Hashing: Hash Table Programming with C. Apress.<br/>
[2] Tobias Heer and Co., 2006, Adapting Distributed Hash Tables for Mo- bile Ad Hoc Networks.
