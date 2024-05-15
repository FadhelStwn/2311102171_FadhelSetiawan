# <h1 align="center">Laporan Praktikum Modul 7 - QUEUE </h1>
<p align="center">Fadhel Setiawan - 2311102171</p>

# TUJUAN PRAKTIKUM
1. Mahasiswa mampu menjelaskan definisi dan konsep dari double queue
2. Mahasiswa mampu menerapkan operasi tambah, menghapus pada queue
3. Mahasiswa mampu menerapkan operasi tampil data pada queue

# DASAR TEORI
Queue adalah struktur data yang digunakan untuk menyimpan data dengan metode FIFO (First-In First-Out). Data yang pertama dimasukkan ke dalam queue akan menjadi data yang pertama pula untuk dikeluarkan dari queue. Queue mirip dengan konsep antrian pada kehidupan sehari-hari, dimana konsumen yang datang lebih dulu akan dilayani terlebih dahulu.</br>

Implementasi queue dapat dilakukan dengan menggunakan array atau linked list. Struktur data queue terdiri dari dua pointer yaitu front dan rear. Front/head adalah pointer ke elemen pertama dalam queue dan rear/tail/back adalah pointer ke elemen terakhir dalam queue.</br>

![alt text](<Screenshot 2024-05-15 232532.png>)</br>

Perbedaan antara stack dan queue terdapat pada aturan penambahan dan penghapusan elemen. Pada stack, operasi penambahan dan penghapusan elemen dilakukan di satu ujung. Elemen yang terakhir diinputkan akan berada paling dengan dengan ujung atau dianggap paling atas sehingga pada operasi penghapusan, elemen teratas tersebut akan dihapus paling awal, sifat demikian dikenal dengan LIFO.</br>

maupun delete. Prosedur ini sering disebut Enqueue dan Dequeue pada kasus Queue. Untuk Enqueue, cukup tambahkan elemen setelah elemen terakhir Queue, dan untuk Dequeue, cukup "geser"kan Head menjadi elemen selanjutnya.</br>

# Operasi pada Queue
- enqueue() : menambahkan data ke dalam queue.
- dequeue() : mengeluarkan data dari queue.
- peek() : mengambil data dari queue tanpa menghapusnya.
- isEmpty() : mengecek apakah queue kosong atau tidak.
- isFull() : mengecek apakah queue penuh atau tidak.
- size() : menghitung jumlah elemen dalam queue.

# GUIDED

```C++
#include <iostream>
using namespace std;

const int maksimalQueue = 5; 
int front = 0; 
int back = 0; 
string queueTeller[5]; 

bool isFull() { 
    if (back == maksimalQueue) {
        return true; 
    } else {
        return false;
    }
}

bool isEmpty() { 
    if (back == 0) {
        return true;
    } else {
        return false;
    }
}

void enqueueAntrian(string data) { 
    if (isFull()) {
        cout << "Antrian penuh" << endl;
    } else {
        if (isEmpty()) { 
            queueTeller[0] = data;
            front++;
            back++;
        } else {
            queueTeller[back] = data;
            back++;
        }
    }
}

void dequeueAntrian() { 
    if (isEmpty()) {
        cout << "Antrian kosong" << endl;
    } else {
        for (int i = 0; i < back; i++) {
            queueTeller[i] = queueTeller[i + 1];
        }
        back--;
    }
}

int countQueue() { 
    return back;
}

void clearQueue() { 
    if (isEmpty()) {
        cout << "Antrian kosong" << endl;
    } else {
        for (int i = 0; i < back; i++) {
            queueTeller[i] = "";
        }
        back = 0;
        front = 0;
    }
}

void viewQueue() { 
    cout << "Data antrian teller:" << endl;
    for (int i = 0; i < maksimalQueue; i++) {
        if (queueTeller[i] != "") {
            cout << i + 1 << ". " << queueTeller[i] << endl;
        } else {
            cout << i + 1 << ". (kosong)" << endl;
        }
    }
}

int main() {
    enqueueAntrian("Andi");
    enqueueAntrian("Maya");
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    dequeueAntrian();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    clearQueue();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    return 0;
}
```
# Output
![alt text](<Screenshot 2024-05-15 231823.png>)</br>

# Penjelasan Guided 1 
Program ini berfungsi untuk mensimulasikan operasi dasar pada antrian (queue) menggunakan array dengan kapasitas maksimal 5 elemen. Mengimplementasikan dan memahami operasi dasar pada antrian seperti penambahan, penghapusan, dan pengecekan status antrian. Menggunakan antrian dalam aplikasi yang membutuhkan struktur data FIFO.

# UNGUIDED 1 
```c++
#include <iostream>
using namespace std;


struct Node {
  string dat171;
  Node* next;
};


Node* head = NULL;
Node* tail = NULL; 


bool isEmpty() {
  return head == NULL;
}


void enqueueAntrian(string dat171) {
  Node* newNode = new Node; 
  newNode->dat171 = dat171; 
  newNode->next = NULL; 

  if (isEmpty()) { 
    head = newNode;
    tail = newNode;
  } else { 
    tail->next = newNode;
    tail = newNode;
  }
}


void dequeueAntrian() {
  if (isEmpty()) {
    cout << "Huh, this queue is empty! Nothing to dequeue!" << endl;
    return;
  }

  Node* temp = head; 
  head = head->next; 
  delete temp; 

  if (head == NULL) { 
    tail = NULL;
  }
}


int countQueue() {
  int count = 0;
  Node* current = head;
  while (current != NULL) {
    count++;
    current = current->next;
  }
  return count;
}


void clearQueue() {
  while (!isEmpty()) {
    dequeueAntrian();
  }
}


void viewQueue() {
  if (isEmpty()) {
    cout << "The queue is empty!" << endl;
    return;
  }

  cout << "Data antrian teller:" << endl;
  Node* current = head;
  int i = 1;
  while (current != NULL) {
    cout << i << ". " << current->dat171 << endl;
    i++;
    current = current->next;
  }
}

int main() {
    cout << "\n TELLER QUEUE \n" << endl;
    cout << "-=- Enqueue/Add Tellers -=-" << endl;
    enqueueAntrian("Andi");
    enqueueAntrian("Maya");
    viewQueue();
    cout << "Jumlah antrian: " << countQueue() << endl;

    cout << "\n-=- Dequeue/Remove Tellers -=-" << endl;
    dequeueAntrian();
    viewQueue();
    cout << "Jumlah antrian: " << countQueue() << endl;

    cout << "\n-=- Remove All Tellers -=-" << endl;
    clearQueue();
    viewQueue();
    cout << "Jumlah antrian: " << countQueue() << endl;

    return 0;
}
```
# Output
![alt text](<Screenshot 2024-05-15 231639.png>)

# Penjelasan Program 
Program ini berfungsi untuk mengimplementasikan antrian (queue) menggunakan struktur data linked list untuk menyimpan data teller Program ini memiliki fungsi untuk menambahkan data ke antrian (enqueueAntrian), menghapus data dari antrian (dequeueAntrian), memeriksa apakah antrian kosong (isEmpty), menghitung jumlah elemen dalam antrian (countQueue), menghapus semua elemen dari antrian (clearQueue), dan menampilkan semua elemen dalam antrian (viewQueue). Pada fungsi main, program menambahkan data teller ke antrian, menghapus data dari antrian, dan mengosongkan antrian, sambil menampilkan kondisi antrian setelah setiap operasi untuk mendemonstrasikan cara kerja fungsi-fungsi tersebut.

# UNGUIDED 2
```c++
#include <iostream>

using namespace std;


struct Node {
  string NamaMahasiswa171;
  long long int NIMMahasiswa171;
  Node* next;
};


Node* head = NULL; 
Node* tail = NULL; 


bool isEmpty() {
  return head == NULL;
}


void enqueueAntrian(string nama, long long int NIM) {
  Node* newNode = new Node; // Buat node baru
  newNode->NamaMahasiswa171 = nama;
  newNode->NIMMahasiswa171 = NIM;
  newNode->next = NULL; 

  if (isEmpty()) { 
    head = newNode;
    tail = newNode;
  } else { 
    tail->next = newNode;
    tail = newNode;
  }
}


void dequeueAntrian() {
  if (isEmpty()) {
    cout << "Yo! The queue is empty! There's nothing to dequeue!" << endl;
    return;
  }

  Node* temp = head; 
  head = head->next; 
  delete temp; 

  if (head == NULL) { 
    tail = NULL;
  }
}


int countQueue() {
  int count = 0;
  Node* current = head;
  while (current != NULL) {
    count++;
    current = current->next;
  }
  return count;
}


void clearQueue() {
  while (!isEmpty()) {
    dequeueAntrian();
  }
}


void viewQueue() {
  if (isEmpty()) {
    cout << "Hey, the queue is empty!" << endl;
    return;
  }

  cout << "Mahasiswa Queue Data:" << endl;
  Node* current = head;
  int i = 1;
  while (current != NULL) {
    cout << i << ". " << current->NamaMahasiswa171 << " (" << current->NIMMahasiswa171 << ")" << endl;
    i++;
    current = current->next;
  }
}

int main() {
  cout << "\n Queue Mahasiswa " << endl;

  cout << "\n-=- Enqueue/Add Queue Mahasiswa -=-" << endl;
  enqueueAntrian("Fadhel", 2311102171);
  enqueueAntrian("Fuad", 2311102172);
  enqueueAntrian("Rusdi", 9312011173);
  enqueueAntrian("Hardin", 3211102174);
  viewQueue();
  cout << "Jumlah antrian: " << countQueue() << endl;

  cout << "\n-=- Dequeue/Remove Queue Mahasiswa -=-" << endl;
  dequeueAntrian();
  viewQueue();
  cout << "Jumlah antrian: " << countQueue() << endl;

  cout << "\n-=- Clear All Queues -=-" << endl;
  clearQueue();
  viewQueue();
  cout << "Jumlah antrian: " << countQueue() << endl;

  return 0;
}
```
# Output
![alt text](<Screenshot 2024-05-15 230925.png>)

# Penjelasan Program
Program ini mengimplementasikan antrian (queue) dengan struktur data linked list untuk menyimpan informasi mahasiswa. Setiap node dalam linked list menyimpan nama dan NIM mahasiswa. Program ini mencakup beberapa fungsi utama:</br>
- isEmpty: Mengecek apakah antrian kosong.
- enqueueAntrian: Menambahkan data mahasiswa ke antrian
- dequeueAntrian: Menghapus data mahasiswa dari antrian
- countQueue: Menghitung jumlah data mahasiswa dalam antrian dengan mengiterasi melalui semua node.
- clearQueue: Mengosongkan seluruh antrian dengan menghapus semua node secara berurutan.
- viewQueue: Menampilkan seluruh data mahasiswa dalam antrian dengan mengiterasi melalui semua node dan mencetak informasi nama dan NIM.</br>
Dalam fungsi main, program menunjukkan operasi antrian dengan menambahkan beberapa mahasiswa ke antrian, menghapus satu mahasiswa dari antrian, dan kemudian mengosongkan seluruh antrian, sambil mencetak kondisi antrian setelah setiap operasi untuk menunjukkan bagaimana setiap fungsi bekerja. Program ini berguna untuk memahami konsep dasar antrian dan operasi yang terkait, serta bagaimana mengelola data dinamis menggunakan linked list dalam konteks pemrograman struktural.

# REFERENSI
[1] Carroll, Steven, and Alexander Goponenko. "A C++ implementation of a threadsafe priority queue based on multi-dimensional linked lists and MRLock." (2019).
[2] Zheng Li dkk, C++ Programming. Republic State of China: De Gruyter, 2019.
[3] Stroustrup, B., A Tour of C++ Third Edition. United States: Pearson Education, Inc., 2023.

