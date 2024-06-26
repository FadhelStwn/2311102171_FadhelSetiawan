# <h1 align="center">Laporan Praktikum Modul 4 - LINKED LIST CIRCULAR DAN NON CIRCULAR </h1>
<p align="center">Fadhel Setiawan - 2311102171</p>

# Tujuan Pratikum
a. Praktikan dapat mengetahui dan memahami linked list circular dan non circular.<br>
b. Praktikan dapat membuat linked list circular dan non circular.<br>
c. Praktikan dapat mengaplikasikan atau menerapkan linked list circular dan non 
circular pada program yang dibuat

# Dasar Teori 
<h2>1. Linked List Non Circular</h2>
<p style="text-indent: 45px;">Linked list non circular merupakan linked list dengan node pertama (head) dan node terakhir (tail) yang tidak saling terhubung. Pointer terakhir (tail) pada Linked List ini selalu bernilai ‘NULL’ sebagai pertanda data terakhir dalam list-nya. Linked list non circular dapat digambarkan sebagai berikut.</p></br>
    
<div style="display: block; margin-left: auto; margin-right: auto;">![alt text](<Screenshot 2024-04-02 144425.png>)</div></br>

# OPERASI PADA LINKED LIST NON CIRCULAR
1) Deklarasi Simpul (Node)

```C++
struct node
{
int data;
node *next;
};
```

2) Membuat dan Menginisialisasi Pointer Head dan Tail
```C++
node *head, *tail;
void init()
{
head = NULL;
tail = NULL;
};
```

3) Pengecekan Kondisi Linked List
```C++
bool isEmpty()
{
if (head == NULL && tail == NULL)
{
return true;
}
else
{
return false;
}
}
```

4) Penambahan Simpul (Node)
```C++
void insertBelakang(string dataUser)
{
if (isEmpty() == true)
{
node *baru = new node;
baru->data = dataUser;
head = baru;
tail = baru;
baru->next = NULL;
}
else
{
node *baru = new node;
baru->data = dataUser;
baru->next = NULL;
tail->next = baru;
tail = baru;
}
};
```

5) Penghapusan Simpul (Node)
```C++
void hapusDepan()
{
if (isEmpty() == true)
{
cout << "List kosong!" << endl;
}
else
{
node *helper;
helper = head;
if (head == tail)
{
head = NULL;
tail = NULL;
delete helper;
}
else
head = head->next;
helper->next = NULL;
delete helper;
}
}
```

<h2>2. Linked List Circular</h2>
<p style="text-indent: 45px;">Linked list circular merupakan linked list yang tidak memiliki akhir karena node terakhir (tail) tidak bernilai ‘NULL’, tetapi terhubung dengan node pertama (head). Saat menggunakan linked list circular kita membutuhkan dummy node atau node pengecoh yang biasanya dinamakan dengan node current supaya program dapat berhenti menghitung data ketika node current mencapai node pertama (head).Linked list circular dapat digunakan untuk menyimpan data yang perlu diakses secara berulang, seperti daftar putar lagu, daftar pesan dalam antrian, atau penggunaan memori berulang dalam suatu aplikasi. Linked list circular dapat digambarkan sebagai berikut.</p></br>

![alt text](<Screenshot 2024-04-02 145347.png>)</br>

1. Deklarasi Simpul (Node)
```c++
struct Node
{
string data;
Node *next;
};

```

2. Membuat dan Menginisialisasi Pointer Head dan Tail
```C++
Node *head, *tail, *baru, *bantu, *hapus;
void init()
{
head = NULL;
tail = head;
}
```

3. Pengecekan Kondisi Linked List
```c++
int isEmpty()
{
if (head == NULL)
return 1; // true
else
return 0; // false
}
```

4. Pembuatan Simpul (Node) 
```c++
void buatNode(string data)
{
baru = new Node;
baru->data = data;
baru->next = NULL;
}
```

5. Penambahan Simpul (Node)
```c++
// Tambah Depan
void insertDepan(string data)
{
// Buat Node baru
buatNode(data);
if (isEmpty() == 1)
{
head = baru;
tail = head;
baru->next = head;
}
else
{
while (tail->next != head)
{
tail = tail->next;
}
baru->next = head;
head = baru;
tail->next = head;
}
}
```

6. Penghapusan Simpul (Node)
```c++
void hapusBelakang()
{
if (isEmpty() == 0)
{
hapus = head;
tail = head;
if (hapus->next == head)
{
head = NULL;
tail = NULL;
delete hapus;
}
else
{
while (hapus->next != head)
{
hapus = hapus->next;
}
while (tail->next != hapus)
{
tail = tail->next;
}
tail->next = head;
hapus->next = NULL;
delete hapus;
}
}
}
```

7. Menampilkan Data Linked List
```C++
void tampil()
{
if (isEmpty() == 0)
{
tail = head;
do
{
cout << tail->data << ends;
tail = tail->next;
} while (tail != head);
cout << endl;
}
}
```

# Guided

1) Linked List Non Circular
```c++
#include <iostream>
using namespace std;
// PROGRAM SINGLE LINK LIST NON CIRCULAR
// DEKLARASI STRUCT NODE

struct node
{
    int data;
    node *next;
};
node *head;
node *tail;

// INSTALASI NODE
void init()
{
    head = NULL;
    tail = NULL;
}

//PENGECEKAN
bool isEmpty()
{
    if(head == NULL)
        return true;

    else
        return false;
}

// TAMBAH DEPAN
void insertDepan(int nilai)
{
    //BUAT NODE BARU
    node *baru = new node;
    baru -> data = nilai;
    baru -> next = NULL;
    if(isEmpty() == true)
    {
        head = tail = baru;
        tail -> next = NULL;
    }
    else
    {
        baru -> next = head;
        head = baru;
    }
}

// TAMBAH BELAKANG
void insertBelakang(int nilai)
{
    // BUAT NODE BARU
    node *baru = new node;
    baru -> data = nilai;
    baru -> next = NULL;
    if(isEmpty() == true)
    {
        head = tail = baru;
        tail -> next = NULL;
    }
    else
    {
        tail -> next = baru;
        tail = baru;
    }
}

// HITUNG JUMLAH LIST
int hitungList()
{
    node *hitung;
    hitung = head;
    int jumlah = 0;
    while(hitung != NULL)
    {
        jumlah++;
        hitung = hitung -> next;
    }
    return jumlah;
}

// TAMBAH TENGAH
void insertTengah(int data, int posisi)
{
    if(posisi < 1 || posisi > hitungList())
    {
        cout << "posisi di liar jangkauan" << endl;
    }
    else if(posisi == 1)
    {
        cout << "posisi buan posisi tengah" << endl;
    }
    else
    {
        node *baru, *bantu;
        baru = new node();
        baru -> data = data;

        // TRANSVERSING
        bantu = head;
        int nomor = 1;
        while(nomor < posisi -1)
        {
            bantu =bantu -> next;
            nomor++;
        }
    
    baru -> next = bantu -> next;
    bantu -> next = baru;
    }
}

//HAPUS DEPAN
void hapusDepan()
{
    node *hapus;
    if(isEmpty() == false)
    {
        if(head -> next != NULL)
        {
            hapus = head;
            head = head -> next;
            delete hapus;
        }
    
    else
    {
        head = tail = NULL;
    }
    }
    else
    {
        cout <<"list kosong" << endl;
    }
}

// HAPUS BELAKNG
void hapusBelakng()
{
    node *hapus;
    node *bantu;
    if(isEmpty() == false)
    {
        if(head != tail)
        {
            hapus = tail;
            bantu = head;
            while(bantu -> next != tail)
            {
                bantu = bantu -> next;
            }
            tail = bantu;
            tail -> next = NULL;
            delete hapus;
        }
        else
        {
            head = tail = NULL;
        }
    }
    else
    {
        cout <<"list kosiing"<< endl;
    }
}

// HAPUS TENGAH
void hapusTengah(int posisi)
{
    node *bantu, *hapus, *sebelum;
    if( posisi < 1 || posisi > hitungList())
    {
        cout <<"posisi di liar jangkauan"<< endl;
    }
    else if(posisi == 1)
    {
        cout <<"posisi bukan posisi tengah"<< endl;
    }
    else 
    {
        int nomor = 1;
        bantu = head;
        while(nomor <= posisi)
        {
            if(nomor == posisi - 1)
            {
                sebelum = bantu;
            }
            if(nomor == posisi)
            {
                hapus = bantu;
            }
            bantu = bantu -> next;
            nomor++;
        }
        sebelum  -> next = bantu;
        delete hapus;
    }

}

// Ubah Depan
void ubahDepan(int data)
{
if (isEmpty() == 0)
{
head->data = data;
}
else
{
cout << "List masih kosong!" << endl;
}
}

// Ubah Tengah
void ubahTengah(int data, int posisi)
{
node *bantu;
if (isEmpty() == 0)
{
    if (posisi < 1 || posisi > hitungList())
{
cout << "Posisi di luar jangkauan" << endl;
}
else if (posisi == 1)
{

}
else
{
cout << "Posisi bukan posisi tengah" << endl;

bantu = head;
int nomor = 1;
while (nomor < posisi)
{
bantu = bantu->next;
nomor++;
}
bantu->data = data;
}
}
else
{
cout << "List masih kosong!" << endl;
}
}

// Ubah Belakang
void ubahBelakang(int data)
{
if (isEmpty() == 0)
{
tail->data = data;
}
else
{
cout << "List masih kosong!" << endl;
}
}

// Hapus List
void clearList()
{
node *bantu, *hapus;
bantu = head;
while (bantu != NULL)
{
hapus = bantu;
bantu = bantu->next;
delete hapus;
}
head = tail = NULL;
cout << "List berhasil terhapus!" << endl;
}

// Tampilkan List
void tampil()
{
node *bantu;
bantu = head;
if (isEmpty() == false)
{
while (bantu != NULL)
{
cout << bantu->data << ends;
bantu = bantu->next;
}
cout << endl;
}
else
{
cout << "List masih kosong!" << endl;
}
}

int main()
{
init();
insertDepan(3);
tampil();
insertBelakang(5);
tampil();
insertDepan(2);
tampil();
insertDepan(1);
tampil();
hapusDepan();
tampil();
hapusBelakng();
tampil();
insertTengah(7, 2);
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
![alt text](image.png)</br>
Single linked list adalah struktur data linear yang terdiri dari sejumlah simpul atau node yang saling terhubung melalui pointer, dimana setiap node memiliki data dan pointer yang menunjuk ke node berikutnya. Program ini digunakan untuk membuat, mengelola, dan memanipulasi daftar data secara dinamis, dimana setiap elemen data dihubungkan oleh satu arah, yaitu dari depan ke belakang. Program ini memberikan kemampuan untuk menambah, menghapus, dan mengubah data pada posisi tertentu dalam daftar tersebut.

2) Linked List Circular 
```C++
#include <iostream>

using namespace std;

// Program SINGLE LINGKED LIST SIRCULAR

// Deklarasi Struct Node
struct  Node
{
    string data;
    Node*next;
};

Node *head, *tail, *baru, *bantu, *hapus;

void init()
{
    head = NULL;
    tail = head;
}

// Pengecekan
int isEmpty()
{
    if (head == NULL)
    return 1; // true
    else
    return 0; // false
}

// Buat Node baru
void buatNode(string data)
{
    baru = new Node;
    baru->data = data;
    baru->next = NULL;
}

//hitung list
int hitunglist()
{
    bantu = head;
    int jumlah = 0;

    while (bantu != NULL)
    {
        jumlah++;
        bantu = bantu->next;
    }
    return jumlah;
}

// Tambah Depan

void insertDepan(string data)
{
    // buat Node Baru
    buatNode(data);

    if (isEmpty() == 1)
    {
        head = baru;
        tail = head;
        baru->next = head;
    }
    else 
    {
        while (tail->next != head)
        {
            tail = tail->next;
        }
        baru->next = head;
        head = baru;
        tail->next = head;
    }
}

// Tambah Belakang
void insertBelakang(string data)
{
    // Buat Node baru
    buatNode(data);

    if(isEmpty() == 1)
    {
        head = baru;
        tail = head;
        baru->next = head;
    }
    else
    {
        while (tail->next != head)
        {
            tail = tail->next;
        }

        tail->next = baru; 
        baru->next = head;
        tail = baru;
    }
}
// Tambah Tengah
void insertTengah(string data, int posisi)
{
    if(isEmpty() == 1)
    {
        head = baru;
        tail = head;
        baru->next = head;
    }
    else
    {
        baru->data = data;
        //Transvering
        int nomor = 1;
        bantu = head;
        while(nomor < posisi - 1)
        {
            bantu = bantu->next;
            nomor++;
        }
        baru->next = bantu->next;
        bantu->next = baru;
    }
}
// Hapus Depan
void hapusDepan()
{
    if (isEmpty() == 0)
    {
        hapus = head;
        tail = NULL;

        delete hapus;
    }
    else 
    {
        while(tail->next != hapus)
        {
            tail = tail->next;
        }
        head = head->next;
        tail->next = head;
        hapus->next = NULL;

        delete hapus;
    }
}
// hapus belakang
void hapusBelakang()
{
    if(isEmpty() == 0)
    {
        hapus = head;
        tail = head;
        if(hapus->next == head)
        {
            head = NULL;
            tail = NULL;

            delete hapus;
        }
        else
        {
            while (hapus->next != head)
            {
                hapus = hapus->next;
            }
            while (tail->next != hapus)
            {
                tail = tail->next;
            }
            tail->next = head;
            hapus->next = NULL;

            delete hapus;
        }
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}
// Hapus tengah
void hapusTengah(int posisi)
{
    if (isEmpty() == 0)
    {
        //Transvering
        int nomor = 1;
        bantu = head;

        while (nomor < posisi -1)
        {
            bantu = bantu->next;
            nomor++;
        }
        hapus = bantu->next;
        bantu->next = hapus->next;

        delete hapus;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}

// Hapus list
void clearlist()
{
    if (head != NULL)
    {
        hapus = head->next;

        while (hapus != head)
        {
            bantu = hapus->next;
            delete hapus;
            hapus = bantu;
        }
        delete head;
        head = NULL;
    }
    cout << "List berhasil terhapus!" << endl;
}

// Tampilkan list
void tampil()
{
    if(isEmpty() == 0)
    {
        tail = head;
        do
        {
            cout << tail->data << ends;
            tail = tail->next;
        } 
        while (tail != head);
        cout << endl;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}

int main()
{
init();
insertDepan("Ayam");
tampil();
insertDepan("Bebek");
tampil();
insertBelakang("Cicak");
tampil();
insertBelakang("Domba");
tampil();
hapusBelakang();
tampil();
hapusDepan();
tampil();
insertTengah("keboo", 3);
tampil();
hapusTengah(2);
tampil();

return 0;
}
```
# Output 
![alt text](<Screenshot 2024-04-02 151641.png>)</br>
Single linked list circular adalah struktur data linear yang terdiri dari sejumlah simpul atau node yang saling terhubung melalui pointer, dimana node terakhir terhubung kembali ke node pertama, membentuk lingkaran. Secara singkat, program ini digunakan untuk membuat, mengelola, dan memanipulasi daftar data secara dinamis dalam bentuk lingkaran, dimana setiap elemen data dihubungkan dari awal ke akhir dan kembali ke awal, membentuk suatu lingkaran.

# Unguided

1) Buatlah menu untuk menambahkan, mengubah, menghapus, dan melihat Nama dan NIM mahasiswa
# Tampilkan Menu

![alt text](<Screenshot 2024-04-03 103622.png>)<br>

# Tampilkan Oprasi Tambah

- Tambah Depan<br>
![alt text](<Screenshot 2024-04-03 103817.png>)<br>
- Tambah Tengah <br>
![alt text](<Screenshot 2024-04-03 103912.png>)<br>
- Tambah Belakang<br>
![alt text](<Screenshot 2024-04-03 104001.png>)<br>

# Tampilakan Oprasi Hapus

- Hapus Belakang<br>
![alt text](<Screenshot 2024-04-03 104001-1.png>)<br>
- Hapus Tengah <br>
![alt text](<Screenshot 2024-04-03 104045.png>)<br>

# Tampilkan Oprasi Ubah

- Ubah Belakang<br>
![alt text](<Screenshot 2024-04-03 104329.png>)<br>
- Ubah Tengah<br>
![alt text](<Screenshot 2024-04-03 104501.png>)<br>
- Tampilan Operasi Tampil Data<br>
![alt text](<Screenshot 2024-04-03 104552.png>)<br>

2) Setelah membuat menu tersebut, masukkan data sesuai urutan berikut, lalu tampilkan data yang telah dimasukkan. (Gunakan insert depan, belakang atau tengah)<br>
![alt text](<Screenshot 2024-04-03 105855.png>)<br>

3) Lakukan perintah berkut:<br>
a. Tambahkan data berikut diantara Farrel dan Denis:<br>
![alt text](<Screenshot 2024-04-03 110116.png>)<br>
b. Hapus data Denis<br>
![alt text](<Screenshot 2024-04-03 110157.png>)<br>
c. Tambahkan data di awal<br>
![alt text](<Screenshot 2024-04-03 110247.png>)<br>
d. Tambahkan data akhir<br>
![alt text](<Screenshot 2024-04-03 110324.png>)<br>
e. Ubah data Udin<br>
![alt text](<Screenshot 2024-04-03 110437.png>)<br>
f. Ubah data terkahir<br> 
![alt text](<Screenshot 2024-04-03 110524.png>)<br>
g. Hapus data awal<br>
![alt text](<Screenshot 2024-04-03 110630.png>)<br>
h. Ubah data awal <br>
![alt text](<Screenshot 2024-04-03 110725.png>)<br>
i. Hapus data akhir<br>
![alt text](<Screenshot 2024-04-03 110814.png>)<br>
j. Tampilkan seluruh data<br>
![alt text](<Screenshot 2024-04-03 110814-1.png>)<br>
<br>
Program diatas adalah program sederhana yang memungkinkan pengguna untuk melakukan operasi dasar pada linked list, seperti menambahkan, mengubah, menghapus, dan menampilkan data. Pada program diatas terdapat beberapa komponen utama dalam program yaitu :

1. Struct Node: Digunakan untuk merepresentasikan sebuah node dalam linked list. Setiap node memiliki dua string yang menyimpan informasi nama dan NIM mahasiswa, serta pointer next yang menunjukkan ke node berikutnya dalam linked list.
2. Variabel Head dan Tail: Variabel global head dan tail digunakan untuk menandai awal dan akhir dari linked list.
3. Inisialisasi Linked List (init): Fungsi init() digunakan untuk menginisialisasi linked list dengan mengatur head dan tail menjadi NULL.
4. Fungsi-fungsi untuk Modifikasi Linked List: Program menyediakan fungsi-fungsi seperti insertdepan(), insertbelakang(), inserttengah(), ubahdepan(), ubahbelakang(), ubahtengah(), hapusdepan(), hapusbelakang(), hapustengah(), dan hapuslist() untuk menambah, mengubah, dan menghapus data dalam linked list.
5. Fungsi-fungsi Bantu: Terdapat beberapa fungsi bantu seperti hitunglist() yang digunakan untuk menghitung jumlah node dalam linked list, dan isempty() yang digunakan untuk memeriksa apakah linked list kosong.
6. Fungsi Tampilkan: Fungsi tampilkan() digunakan untuk menampilkan seluruh data mahasiswa yang ada dalam linked list.
7. Menu Utama (main): Program utama menggunakan perulangan do-while untuk menampilkan menu utama yang memberikan opsi untuk melakukan operasi-operasi pada linked list seperti tambah data, ubah data, hapus data, dan tampilkan data. Setiap opsi diimplementasikan melalui pemanggilan fungsi-fungsi yang telah didefinisikan sebelumnya.
<br>
Jadi dengan menggunakan fungsi-fungsi dasar seperti penambahan, penghapusan, dan pencarian, program memungkinkan pengguna untuk mengelola data mahasiswa melalui linked list. Melalui menu interaktif, pengguna dapat dengan mudah melakukan operasi-operasi tersebut, memberikan pemahaman yang baik tentang cara kerja struktur data linked list dan kemungkinan aplikasinya dalam pengembangan perangkat lunak yang lebih kompleks.


# Kesimpulan 
Linked list adalah struktur data linear yang terdiri dari node-node yang terhubung. Single linked list memiliki pointer next untuk menghubungkan node, sedangkan double linked list memiliki pointer prev dan next untuk navigasi dua arah.

Single Linked List</br>
- Non-circular: Pointer next pada node terakhir menunjuk ke NULL.</br>
- Circular: Pointer next pada node terakhir menunjuk kembali ke node pertama.</br>

Double Linked List</br>
- Non-circular: Pointer prev dan next pada node terakhir menunjuk ke NULL.</br>
- Circular: Pointer next pada node terakhir menunjuk kembali ke node pertama, dan pointer prev pada node pertama menunjuk ke node terakhir.</br>

Pemilihan jenis linked list tergantung pada kebutuhan operasi yang akan dilakukan pada data.</br>
- Circular linked list: Cocok untuk navigasi data maju dan mundur terus menerus, serta lebih fleksibel dalam hal navigasi.</br>
- Non-circular linked list: Lebih sederhana dan efisien dalam hal memori.</br>

# Referensi
[1] Muhammad Nugraha, Dasar Pemrograman Dengan C++, Materi Paling Dasar untuk Menjadi Programmer Berbagai Platform Yogyakarta: Deepublish, 2021.<br>
[2]Istvan Haller, Asia Slowinska, Herbert Bos Empirical Software Engineering 21, 778-810, 2016.<br>
[3]Wisam Abed Shukur, Ahmed Badrulddin, Mohammed Kamal Nsaif, A proposed encryption technique of different texts using circular link lists, Vol 9, No 2 (2021)<br>


