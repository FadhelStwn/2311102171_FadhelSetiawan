# <h1 align="center">Laporan Praktikum Modul 3 - SINGLE AND DOUBLE LINKED LIST</h1>
<p align="center">Fadhel Setiawan - 2311102171</p>

# A.Dasar Teori 

1) Single Linked List</br>
Linked List merupakan suatu bentuk struktur data yang berisi kumpulan data yang disebut sebagai node yang tersusun secara sekuensial, saling sambung menyambung, dinamis, dan terbatas. Setiap elemen dalam linked list dihubungkan ke elemen lain melalui pointer. Masing-masing komponen sering disebut dengan simpul atau node atau verteks. Pointer adalah alamat elemen.
Setiap simpul pada dasarnya dibagi atas dua bagian pertama disebut bagian isi atau informasi atau data yang berisi nilai yang disimpan oleh simpul. Bagian kedua disebut bagian pointer yang berisi alamat dari node berikutnya atau sebelumnya. Dengan menggunakan struktur seperti ini, linked list dibentuk dengan cara menunjuk pointer next suatu elemen ke elemen yang mengikutinya. Pointer next pada elemen terakhir merupakan NULL, yang menunjukkan akhir dari suatu list. Elemen pada awal suatu list disebut head dan elemen terakhir dari suatu list disebut tail.</br>

![alt text](<Screenshot 2024-03-26 164241.png>)</br>

Dalam operasi Single Linked List, umumnya dilakukan operasi penambahan dan penghapusan simpul pada awal atau akhir daftar, serta pencarian dan pengambilan nilai pada simpul tertentu dalam daftar. Karena struktur data ini hanya memerlukan satu pointer untuk setiap simpul, maka Single Linked List umumnya lebih efisien dalam penggunaan memori dibandingkan dengan jenis
Linked List lainnya, seperti Double Linked List dan Circular Linked List. Single linked list yang kedua adalah circular linked list. Perbedaan circularlinked list dan non circular linked adalah penunjuk next pada node terakhir pada circular linked list akan selalu merujuk ke node pertama.</br>

![alt text](<Screenshot 2024-03-26 164300.png>)</br>

2) Double Linked List
Double Linked List adalah struktur data Linked List yang mirip dengan Single Linked List, namun dengan tambahan satu pointer tambahan pada setiap simpul yaitu pointer prev yang menunjuk ke simpul sebelumnya. Dengan adanya pointer prev, Double Linked List memungkinkan untuk melakukan operasi penghapusan dan penambahan pada simpul mana saja secara efisien. Setiap simpul pada Double Linked List memiliki tiga elemen penting, yaitu elemen data (biasanya berupa nilai), pointer next yang menunjuk ke simpul berikutnya, dan pointer prev yang menunjuk ke simpul sebelumnya.</br>

Keuntungan dari Double Linked List adalah memungkinkan untuk melakukan operasi penghapusan dan penambahan pada simpul dimana saja dengan efisien, sehingga sangat berguna dalam implementasi beberapa algoritma yang membutuhkan operasi tersebut. Selain itu, Double Linked List juga memungkinkan kita untuk melakukan traversal pada list baik dari depan (head) maupun dari belakang (tail) dengan mudah. Namun, kekurangan dari Double Linked List adalah penggunaan memori yang lebih besar dibandingkan dengan Single Linked List, karena setiap simpul membutuhkan satu pointer tambahan. Selain itu, Double Linked List juga membutuhkan waktu eksekusi yang lebih lama dalam operasi penambahan dan penghapusan jika dibandingkan dengan Single Linked List.</br>

Representasi sebuah double linked list dapat dilihat pada gambar berikut ini:</br>

![alt text](<Screenshot 2024-03-26 164332.png>)</br>

Di dalam sebuah linked list, ada 2 pointer yang menjadi penunjuk utama, yakni pointer HEAD yang menunjuk pada node pertama di dalam linked list itu sendiri dan pointer TAIL yang menunjuk pada node paling akhir di dalam linked list. Sebuah linked list dikatakan kosong apabila isi pointer head adalah NULL. Selain itu, nilai pointer prev dari HEAD selalu NULL, karena merupakan data pertama. Begitu pula dengan pointer next dari TAIL yang selalu bernilai NULL sebagai penanda data terakhir.

# B. Guided

# 1. Latihan Single Linked List

```C++
#include <iostream>
using namespace std;

///PROGRAM SINGLE LINKED LIST NON-CIRCULAR
//Deklarasi Struct Node
struct Node{
//komponen/member
int data;
Node *next;
};
Node *head;
Node *tail;
//Inisialisasi Node
void init(){
head = NULL;
tail = NULL;
}
// Pengecekan
bool isEmpty(){
if (head == NULL)
return true;
else
return false;
}
//Tambah Depan
void insertDepan(int nilai){
//Buat Node baru
Node *baru = new Node;
baru->data = nilai;
baru->next = NULL;
if (isEmpty() == true){
head = tail = baru;
tail->next = NULL;

}
else{
baru->next = head;
head = baru;
}
}
//Tambah Belakang
void insertBelakang(int nilai){
//Buat Node baru
Node *baru = new Node;
baru->data = nilai;
baru->next = NULL;
if (isEmpty() == true){
head = tail = baru;
tail->next = NULL;
}
else{
tail->next = baru;
tail = baru;
}
}
//Hitung Jumlah List
int hitungList(){
Node *hitung;
hitung = head;
int jumlah = 0;
while( hitung != NULL ){
jumlah++;
hitung = hitung->next;
}
return jumlah;
}
//Tambah Tengah
void insertTengah(int data, int posisi){
if( posisi < 1 || posisi > hitungList() ){
cout << "Posisi diluar jangkauan" << endl;

}
else if( posisi == 1){
cout << "Posisi bukan posisi tengah" <<

endl;
}
else{
Node *baru, *bantu;
baru = new Node();
baru->data = data;
// tranversing
bantu = head;
int nomor = 1;
while( nomor < posisi - 1 ){
bantu = bantu->next;
nomor++;
}
baru->next = bantu->next;
bantu->next = baru;
}
}
//Hapus Depan
void hapusDepan() {
Node *hapus;
if (isEmpty() == false){
if (head->next != NULL){
hapus = head;
head = head->next;
delete hapus;
}
else{
head = tail = NULL;
}
}
else{
cout << "List kosong!" << endl;
}
}

//Hapus Belakang
void hapusBelakang() {
Node *hapus;
Node *bantu;
if (isEmpty() == false){
if (head != tail){
hapus = tail;
bantu = head;
while (bantu->next != tail){
bantu = bantu->next;
}
tail = bantu;
tail->next = NULL;
delete hapus;
}
else{
head = tail = NULL;
}
}
else{
cout << "List kosong!" << endl;
}
}
//Hapus Tengah
void hapusTengah(int posisi){
Node *hapus, *bantu, *bantu2;
if( posisi < 1 || posisi > hitungList() ){
cout << "Posisi di luar jangkauan" << endl;
}
else if( posisi == 1){
cout << "Posisi bukan posisi tengah" <<

endl;
}
else{
int nomor = 1;
bantu = head;
while( nomor <= posisi ){

if( nomor == posisi-1 ){
bantu2 = bantu;
}
if( nomor == posisi ){
hapus = bantu;
}
bantu = bantu->next;
nomor++;
}
bantu2->next = bantu;
delete hapus;
}
}
//Ubah Depan
void ubahDepan(int data){
if (isEmpty() == false){
head->data = data;
}
else{
cout << "List masih kosong!" << endl;
}
}
//Ubah Tengah
void ubahTengah(int data, int posisi){
Node *bantu;
if (isEmpty() == false){
if( posisi < 1 || posisi > hitungList() ){
cout << "Posisi di luar jangkauan" <<

endl;
}
else if( posisi == 1){
cout << "Posisi bukan posisi tengah" <<

endl;
}
else{
bantu = head;
int nomor = 1;

while (nomor < posisi){
bantu = bantu->next;nomor++;
}
bantu->data = data;
}
}
else{
cout << "List masih kosong!" << endl;
}
}
//Ubah Belakang
void ubahBelakang(int data){
if (isEmpty() == false){
tail->data = data;
}
else{
cout << "List masih kosong!" << endl;
}
}
//Hapus List
void clearList(){
Node *bantu, *hapus;
bantu = head;
while (bantu != NULL){
hapus = bantu;
bantu = bantu->next;
delete hapus;
}
head = tail = NULL;
cout << "List berhasil terhapus!" << endl;
}
//Tampilkan List
void tampil(){
Node *bantu;
bantu = head;
if (isEmpty() == false){

while (bantu != NULL){
cout << bantu->data << ends;
bantu = bantu->next;
}
cout << endl;
}
else{
cout << "List masih kosong!" << endl;
}
}
int main(){
init();
insertDepan(3);tampil();
insertBelakang(5);
tampil();
insertDepan(2);
tampil();
insertDepan(1);
tampil();
hapusDepan();
tampil();
hapusBelakang();
tampil();
insertTengah(7,2);
tampil();
hapusTengah(2);
tampil();
ubahDepan(1);
tampil();
ubahBelakang(8);
tampil();
ubahTengah(11, 2);
tampil();
return 0;
}
```
# Output
![alt text](<Screenshot 2024-03-26 215928.png>)</br>
Program ini memungkinkan pengguna untuk memahami konsep dasar pengelolaan Single Linked List melalui implementasi operasi dasar seperti penambahan, penghapusan, perubahan nilai, dan penampilan elemen.

# 2. Latihan Double Linked List Source
```C++
#include <iostream>
using namespace std;
class Node {
public:int data;
Node* prev;
Node* next;
};
class DoublyLinkedList {

public:
Node* head;
Node* tail;
DoublyLinkedList() {
head = nullptr;
tail = nullptr;

}
void push(int data) {
Node* newNode = new Node;
newNode->data = data;
newNode->prev = nullptr;
newNode->next = head;
if (head != nullptr) {
head->prev = newNode;
}
else {
tail = newNode;
}
head = newNode;
}
void pop() {
if (head == nullptr) {
return;
}
Node* temp = head;
head = head->next;
if (head != nullptr) {
head->prev = nullptr;
}
else {
tail = nullptr;
}
delete temp;
}
bool update(int oldData, int newData) {
Node* current = head;while (current != nullptr) {
if (current->data == oldData) {
current->data = newData;
return true;
}
current = current->next;
}

return false;
}
void deleteAll() {
Node* current = head;
while (current != nullptr) {
Node* temp = current;
current = current->next;
delete temp;
}
head = nullptr;
tail = nullptr;
}
void display() {
Node* current = head;
while (current != nullptr) {
cout << current->data << " ";
current = current->next;
}
cout << endl;
}
};
int main() {
DoublyLinkedList list;
while (true) {
cout << "1. Add data" << endl;
cout << "2. Delete data" << endl;
cout << "3. Update data" << endl;
cout << "4. Clear data" << endl;
cout << "5. Display data" << endl;
cout << "6. Exit" << endl;int choice;
cout << "Enter your choice: ";
cin >> choice;
switch (choice) {
case 1: {
int data;
cout << "Enter data to add: ";
cin >> data;
list.push(data);
break;
}
case 2: {
list.pop();
break;
}
case 3: {
int oldData, newData;
cout << "Enter old data: ";
cin >> oldData;
cout << "Enter new data: ";
cin >> newData;
bool updated = list.update(oldData,

newData);

if (!updated) {
cout << "Data not found" << endl;
}
break;

}
case 4: {
list.deleteAll();
break;
}
case 5: {
list.display();
break;
}
case 6: {
return 0;
}
default: {
cout << "Invalid choice" << endl;
break;
}
}
}
return 0;
}
```
# Output
![alt text](<Screenshot 2024-03-26 215540.png>)</br>
Doubly Linked List adalah struktur data di mana setiap node memiliki dua pointer: satu pointer ke node sebelumnya dan satu pointer ke node selanjutnya. Program ini memungkinkan pengguna untuk menambah, menghapus, mengupdate, dan menampilkan data dalam Doubly Linked List melalui menu interaktif.

# Unguided 

# 1. Soal mengenai Single Linked List
Buatlah program menu Single Linked List Non-Circular untuk menyimpan Nama dan usia mahasiswa, dengan menggunakan inputan dari user. Lakukan operasi berikut:
a.	Masukkan data sesuai urutan berikut. (Gunakan insert depan, belakang atau tengah). Data pertama yang dimasukkan adalah nama dan usia anda.
[Nama_anda]	[Usia_anda]
John	        19
Jane	        20
Michael	        18
Yusuke	        19
Akechi	        20
Hoshino	        18
Karin	        18
b.	Hapus data Akechi
c.	Tambahkan data berikut diantara John dan Jane : Futaba	18
d.	Tambahkan data berikut diawal : Igor	20
e.	Ubah data Michael menjadi : Reyn	18
f.	Tampilkan seluruh data
```C++
// LAPRAK 3 : UNGUIDED 1
// FADHEL SETIAWAN
// 2311102171
// S1 IF-11-E
#include <iostream>
using namespace std;

struct Node {
    string nama_171;
    int usia_171;
    Node* next_171;
};

Node* head_171 = nullptr;

void tampilkanList_171() {
    cout << "[ Nama ]" << "\t" << "[ Usia ]" << endl;
    Node* saatIni_171 = head_171;
    while (saatIni_171 != nullptr) {
        cout << saatIni_171->nama_171 << "\t\t" << saatIni_171->usia_171 << endl;
        saatIni_171 = saatIni_171->next_171;
    }
}

void insertDepan_171(string nama_171, int usia_171) {
    Node* baru_171 = new Node;
    baru_171->nama_171 = nama_171;
    baru_171->usia_171 = usia_171;
    baru_171->next_171 = head_171;
    head_171 = baru_171;
}

void insertBelakang_171(string nama_171, int usia_171) {
    Node* baru_171 = new Node;
    baru_171->nama_171 = nama_171;
    baru_171->usia_171 = usia_171;
    baru_171->next_171 = nullptr;
    if (head_171 == nullptr) {
        head_171 = baru_171;
    }
    else {
        Node* temp_171 = head_171;
        while (temp_171->next_171 != nullptr) {
            temp_171 = temp_171->next_171;
        }
        temp_171->next_171 = baru_171;
    }
}

void insertTengah_171(string nama_171, int usia_171, int posisi_171) {
    Node* baru_171 = new Node;
    baru_171->nama_171 = nama_171;
    baru_171->usia_171 = usia_171;
    Node* bantu_171 = head_171;
    for (int i_171 = 1; i_171 < posisi_171 - 1; i_171++) {
        if (bantu_171 != nullptr) {
            bantu_171 = bantu_171->next_171;
        }
    }
    if (bantu_171 != nullptr) {
        baru_171->next_171 = bantu_171->next_171;
        bantu_171->next_171 = baru_171;
    }
}

void hapusData_171(string nama_171) {
    Node* hapus_171 = head_171;
    Node* prev_171 = nullptr;
    while (hapus_171 != nullptr && hapus_171->nama_171 != nama_171) {
        prev_171 = hapus_171;
        hapus_171 = hapus_171->next_171;
    }
    if (hapus_171 == nullptr) {
        cout << "Data tidak ditemukan" << endl;
        return;
    }
    if (prev_171 == nullptr) {
        head_171 = hapus_171->next_171;
    }
    else {
        prev_171->next_171 = hapus_171->next_171;
    }
    delete hapus_171;
}

void ubahData_171(string nama_171, string newnama_171, int newusia_171) {
    Node* temp_171 = head_171;
    while (temp_171 != nullptr && temp_171->nama_171 != nama_171) {
        temp_171 = temp_171->next_171;
    }
    if (temp_171 != nullptr) {
        temp_171->nama_171 = newnama_171;
        temp_171->usia_171 = newusia_171;
    }
}

void tampilkanData() {
    Node* temp_171 = head_171;
    while (temp_171 != nullptr) {
        cout << temp_171->nama_171 << " " << temp_171->usia_171 << endl;
        temp_171 = temp_171->next_171;
    }
}

int main() {
    insertBelakang_171("Rico", 19);
    insertBelakang_171("John", 19);
    insertBelakang_171("Jane", 20);
    insertBelakang_171("Michael", 18);
    insertBelakang_171("Yusuke", 19);
    insertBelakang_171("Akechi", 20);
    insertBelakang_171("Hoshino", 18);
    insertBelakang_171("Karin", 18);

    char pilihan_171;
    do {
        cout << "\nMenu:\n";
        cout << "a. Tampilkan data sesuai urutan tersedia (Data pertama adalah nama dan usia pengguna)\n";
        cout << "b. Hapus data Akechi\n";
        cout << "c. Tambahkan data berikut diantara John dan Jane : Futaba 18\n";
        cout << "d. Tambahkan data berikut diawal : igor 20\n";
        cout << "e. Ubah data Michael menjadi : Reyn 18\n";
        cout << "f. Tampilkan seluruh data\n";
        cout << "g. Keluar\n";
        cout << "Pilihan Anda: ";
        cin >> pilihan_171;

        switch (pilihan_171) {
            case 'a':
                cout << "\nData yang tersedia:\n";
                tampilkanList_171();
                break;
            case 'b':
                hapusData_171("Akechi");
                cout << "Data Akechi berhasil dihapus.\n";
                cout << "\nData yang tersedia setelah penghapusan:\n";
                tampilkanList_171();
                break;
            case 'c':
                insertTengah_171("Futaba", 18, 3); 
                cout << "Data Futaba berhasil ditambahkan.\n";
                cout << "\nData yang tersedia setelah penambahan:\n";
                tampilkanList_171();
                break;
            case 'd':
                insertDepan_171("Igor", 20);
                cout << "Data Igor berhasil ditambahkan di awal.\n";
                cout << "\nData yang tersedia setelah penambahan:\n";
                tampilkanList_171();
                break;
            case 'e':
                ubahData_171("Michael", "Reyn", 18);
                cout << "Data Michael berhasil diubah menjadi Reyn 18.\n";
                cout << "\nData yang tersedia setelah perubahan:\n";
                tampilkanList_171();
                break;
            case 'f':
                cout << "\nTampilan seluruh data sekarang:\n";
                tampilkanList_171();
                break;
            case 'g':
                cout << "Terima kasih, program selesai.\n";
                break;
            default:
                cout << "Pilihan tidak valid, silakan coba lagi.\n";
                break;
        }
    } while (pilihan_171 != 'g');

    return 0;
}
```
# Output
![alt text](<Screenshot 2024-03-26 205325.png>)</br>
![alt text](<Screenshot 2024-03-26 205426.png>)</br>
![alt text](<Screenshot 2024-03-26 205456.png>)</br>
Dalam program ini, kita memiliki sebuah struktur (struct) yang disebut Node, yang merepresentasikan simpul dalam linked list. Setiap simpul memiliki dua data: nama_171 yang bertipe string untuk menyimpan nama, dan usia_171 yang bertipe int untuk menyimpan usia. Selain itu, setiap simpul memiliki pointer (next_171) yang menunjuk ke simpul berikutnya dalam linked list. Di dalamnya, terdapat menu pilihan untuk melakukan operasi-operasi tertentu pada linked list, seperti menampilkan data, menghapus data, menambah data, mengubah data, dan keluar dari program.Program ini menawarkan pengguna berbagai opsi melalui menu, dan terus meminta input dari pengguna sampai mereka memilih untuk keluar dari program.

# 2. Soal mengenai Double Linked List
Modifikasi Guided Double Linked List dilakukan dengan penambahan operasi untuk menambah data, menghapus, dan update di tengah / di urutan tertentu yang diminta. Selain itu, buatlah agar tampilannya menampilkan Nama produk dan harga.<br>
Nama           |    Produk	Harga
---------------|-----------------
Originote	   |        60.000
Somethinc	   |        150.000
Skintific	   |        100.000
Wardah	       |        50.000
Hanasui	       |        30.000</br>
Case:</br>
1.	Tambahkan produk Azarine dengan harga 65000 diantara
Somethinc dan Skintific
2.	Hapus produk wardah
3.	Update produk Hanasui menjadi Cleora dengan harga 55.000
4.	Tampilkan menu seperti dibawah ini
Toko Skincare Purwokerto
1.	Tambah Data
2.	Hapus Data
3.	Update Data
4.	Tambah Data Urutan Tertentu
5.	Hapus Data Urutan Tertentu
6.	Hapus Seluruh Data
7.	Tampilkan Data
8.	Exit
Pada menu 7, tampilan akhirnya akan menjadi seperti dibawah
ini :</br>
Nama           |    Produk	Harga
---------------|-----------------
Originote	   |        60.000
Somethinc	   |        150.000
Azarine	       |        65.000
Skintific      |        100.000
Cleora         |        55.000</br>
```C++
// LAPRAK 3 : UNGUIDED 2
// FADHEL SETIAWAN
// 2311102171
// S1 IF-11-E
#include <iostream>
#include <iomanip> 
using namespace std;

// Deklarasi Struct Node
class Node {
public:
    string produk_171;
    int harga_171;
    Node* prev_171;
    Node* next_171;
};

// Deklarasi Class DoublyLinkedList
class DoublyLinkedList {
public:
    Node* head_171;
    Node* tail_171;

    // Constructor
    DoublyLinkedList() {
        head_171 = nullptr;
        tail_171 = nullptr;
    }

    // Prosedur untuk menambahkan data di depan
    void Push(int harga_171, string produk_171) {
        Node* newNode_171 = new Node;
        newNode_171->harga_171 = harga_171;
        newNode_171->produk_171 = produk_171;
        newNode_171->prev_171 = nullptr;
        newNode_171->next_171 = head_171;

        if (head_171 != nullptr) {
            head_171->prev_171 = newNode_171;
        }
        else {
            tail_171 = newNode_171;
        }

        head_171 = newNode_171;
    }

    // Prosedur untuk menambahkan data pada posisi tertentu
    void PushPosition(int posisi_171, int harga_171, string produk_171) {
        if (posisi_171 < 1) {
            cout << "Posisi tidak valid!" << endl;
            return;
        }

        Node* newNode_171 = new Node;
        newNode_171->harga_171 = harga_171;
        newNode_171->produk_171 = produk_171;
        newNode_171->prev_171 = nullptr;
        newNode_171->next_171 = nullptr;

        if (posisi_171 == 1) {
            newNode_171->next_171 = head_171;
            if (head_171 != nullptr)
                head_171->prev_171 = newNode_171;
            else
                tail_171 = newNode_171;
            head_171 = newNode_171;
            return;
        }

        Node* saatIni_171 = head_171;
        for (int i = 1; i < posisi_171 - 1 && saatIni_171 != nullptr; ++i)
            saatIni_171 = saatIni_171->next_171;

        if (saatIni_171 == nullptr) {
            cout << "Posisi tidak valid!" << endl;
            delete newNode_171;
            return;
        }

        newNode_171->next_171 = saatIni_171->next_171;
        newNode_171->prev_171 = saatIni_171;
        if (saatIni_171->next_171 != nullptr)
            saatIni_171->next_171->prev_171 = newNode_171;
        else
            tail_171 = newNode_171;
        saatIni_171->next_171 = newNode_171;
    }

    // Prosedur untuk menghapus data di depan
    void Pop() {
        if (head_171 == nullptr) {
            cout << "Tidak ada data yang bisa dihapus!" << endl;
            return;
        }

        Node* temp_171 = head_171;
        head_171 = head_171->next_171;

        if (head_171 != nullptr) {
            head_171->prev_171 = nullptr;
        }
        else {
            tail_171 = nullptr;
        }

        delete temp_171;
    }

    // Prosedur untuk menghapus data pada posisi tertentu
    void PopPosition(int posisi_171) {
        if (head_171 == nullptr) {
            cout << "Tidak ada data yang bisa dihapus!" << endl;
            return;
        }

        Node* temp_171 = head_171;
        for (int i = 1; i < posisi_171 && temp_171 != nullptr; ++i) {
            temp_171 = temp_171->next_171;
        }

        if (temp_171 == nullptr) {
            cout << "Posisi tidak valid!" << endl;
            return;
        }

        if (temp_171->prev_171 != nullptr) {
            temp_171->prev_171->next_171 = temp_171->next_171;
        } else {
            head_171 = temp_171->next_171;
        }

        if (temp_171->next_171 != nullptr) {
            temp_171->next_171->prev_171 = temp_171->prev_171;
        } else {
            tail_171 = temp_171->prev_171;
        }

        delete temp_171;
    }

    // Fungsi untuk mengupdate data
    bool Update(string oldProduk_171, string newProduk_171, int newharga_171) {
        Node* saatIni_171 = head_171;

        while (saatIni_171 != nullptr) {
            if (saatIni_171->produk_171 == oldProduk_171) {
                saatIni_171->produk_171 = newProduk_171;
                saatIni_171->harga_171 = newharga_171;
                return true;
            }
            saatIni_171 = saatIni_171->next_171;
        }

        return false;
    }

    // Prosedur untuk menghapus semua data
    void DeleteAll() {
        Node* saatIni_171 = head_171;

        while (saatIni_171 != nullptr) {
            Node* temp_171 = saatIni_171;
            saatIni_171 = saatIni_171->next_171;
            delete temp_171;
        }

        head_171 = nullptr;
        tail_171 = nullptr;
    }

    // Prosedur untuk menampilkan data
    void Display_171() {
        Node* saatIni_171 = head_171;

        cout << left << setw(20) << "[ Nama Produk ]" << setw(10) << "[ Harga ]" << endl;

        while (saatIni_171 != nullptr) {
            cout << setw(20) << saatIni_171->produk_171 << setw(10) << saatIni_171->harga_171 << endl;
            saatIni_171 = saatIni_171->next_171;
        }

        cout << endl;
    }
};

int main() {
    DoublyLinkedList list;

    cout << "\n== MENU TOKO SKINCARE PURWOKERTO BY RICO ADE PRATAMA ==" << endl;

    // Inisialisasi data awal
    list.Push(30000, "Hanasui");
    list.Push(50000, "Wardah");
    list.Push(100000, "Skintific");
    list.Push(150000, "Somethinc");
    list.Push(60000, "Originote");
    list.Display_171(); 

    // Loop untuk menu interaktif
    while (true) {
        cout << "\nToko Skincare Purwokerto" << endl;
        cout << "   1. Tambah Data" << endl;
        cout << "   2. Hapus Data" << endl;
        cout << "   3. Update Data" << endl;
        cout << "   4. Tambah Data pada Posisi Tertentu" << endl;
        cout << "   5. Hapus Data pada Posisi Tertentu" << endl;
        cout << "   6. Hapus Semua Data" << endl;
        cout << "   7. Tampilkan Data" << endl;
        cout << "   8. Exit" << endl;

        int pilihan_171;
        cout << "Pilih Nomor: ";
        cin >> pilihan_171;

        switch (pilihan_171) {
            case 1: {
                int harga_171;
                string produk_171;

                cout << "\nTAMBAH PRODUK SKINCARE" << endl;
                cout << "Nama produk: ";
                cin.ignore();
                getline(cin, produk_171);
                cout << "Harga produk: ";
                cin >> harga_171;
                list.Push(harga_171, produk_171);
                cout << "Produk berhasil ditambahkan!" << endl;
                list.Display_171(); 
                break;
            }

            case 2: {
                list.Pop();
                cout << "PRODUK PALING ATAS BERHASIL DIHAPUS!" << endl;
                list.Display_171(); 
                break;
            }

            case 3: {
                string oldProduk_171, newProduk_171;
                int newharga_171;

                cout << "\nUPDATE DATA PRODUK SKINCARE" << endl;
                cout << "Masukkan nama produk yang ingin diubah: ";
                cin.ignore();
                getline(cin, oldProduk_171);
                cout << "Masukkan nama produk baru: ";
                getline(cin, newProduk_171);
                cout << "Masukkan harga baru: ";
                cin >> newharga_171;

                bool update_171 = list.Update(oldProduk_171, newProduk_171, newharga_171);
                if (update_171) {
                    cout << "Data berhasil diperbarui!" << endl;
                } else {
                    cout << "Data tidak ditemukan!" << endl;
                }
                list.Display_171(); 
                break;
            }

            case 4: {
                int posisi_171, harga_171;
                string produk_171;

                cout << "\nTAMBAH PRODUK SKINCARE PADA POSISI TERTENTU" << endl;
                cout << "Masukkan posisi untuk produk baru: ";
                cin >> posisi_171;
                cout << "Nama produk: ";
                cin.ignore();
                getline(cin, produk_171);
                cout << "Harga produk: ";
                cin >> harga_171;
                list.PushPosition(posisi_171, harga_171, produk_171);
                cout << "Produk berhasil ditambahkan pada posisi ke-" << posisi_171 << "!" << endl;
                list.Display_171(); 
                break;
            }

            case 5: {
                int posisi_171;

                cout << "\nHAPUS PRODUK SKINCARE PADA POSISI TERTENTU" << endl;
                cout << "Masukkan posisi untuk menghapus data: ";
                cin >> posisi_171;
                list.PopPosition(posisi_171);
                cout << "Data berhasil dihapus pada posisi ke-" << posisi_171 << "!" << endl;
                list.Display_171(); 
                break;
            }

            case 6: {
                list.DeleteAll();
                cout << "SEMUA DATA BERHASIL DI HAPUS!" << endl;
                list.Display_171(); 
                break;
            }

            case 7: {
                cout << "\nTAMPILAN DATA PRODUK TOKO SKINCARE PURWOKERTO SEKARANG" << endl;
                list.Display_171(); 
                break;
            }

            case 8: {
                cout << "Terimakasih telah menggunakan program ini!" << endl;
                return 0;
            }

            default: {
                cout << "Pilihan anda tidak valid!" << endl;
                break;
            }
        }
    }

    return 0;
}
```
# Output
![alt text](<Screenshot 2024-03-26 213422.png>)</br>
![alt text](<Screenshot 2024-03-26 212819.png>)</br>
![alt text](<Screenshot 2024-03-26 212931.png>)</br>
![alt text](<Screenshot 2024-03-26 213027-1.png>)</br>
Di awal program, kita mendefinisikan sebuah class Node yang merepresentasikan satu elemen dalam linked list. Setiap elemen (Node) memiliki dua bagian: nama produk dan harganya. Kemudian, kita juga mendefinisikan sebuah class DoublyLinkedList yang berisi berbagai operasi yang dapat dilakukan pada linked list ganda, seperti menambah data, menghapus data, mengupdate data, dan lain-lain. Semua operasi yang dilakukan pada linked list diimplementasikan menggunakan konsep linked list ganda. Misalnya, untuk menambah data pada posisi tertentu, program akan mencari elemen pada posisi yang ditentukan, lalu menautkan elemen baru di antara elemen-elemen lainnya. Program ini memberikan pengalaman interaktif yang memungkinkan pengguna untuk mengelola data produk toko skincare dengan mudah.

# Kesimpulan 
Dari materi dan tugas diatas, dapat disimpulkan bahwa single linked list dan double linked list kedua jenis linked list ini merupakan struktur data yang kuat dan fleksibel untuk menyimpan dan mengelola data dalam berbagai aplikasi.

# Referensi
[1] Nick Parlante. (2001, january 25). Stanford CS Education Library.</br>
[2] Putra, A. k. (2019, April 25). Single linked list.



