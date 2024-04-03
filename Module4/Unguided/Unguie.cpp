#include <iostream>
#include <iomanip>
using namespace std;
//Nama : Fadhel Setiawan
//NIM  : 2311102171

// Deklarasi Struct Node
struct node {
    string nama;
    string nim;
    node *next;
};

// Deklarasi variabel head dan tail
node *head;
node *tail;

// Inisialisasi linked list
void init() {
    head = NULL;
    tail = NULL;
}

// Pengecekan apakah linked list kosong
bool isempty() {
    return head == NULL;
}
// Menghitung jumlah node dalam linked list
int hitunglist() {
    int jumlah = 0;
    node *bantu = head;
    while (bantu != NULL) {
        jumlah++;
        bantu = bantu->next;
    }
    return jumlah;
}

// Menambah data mahasiswa di depan linked list
void insertdepan(string nama, string nim) {
    // Membuat node baru
    node *baru = new node;
    baru->nama = nama;
    baru->nim = nim;
    baru->next = NULL;

    // Jika linked list kosong
    if (isempty()) {
        head = tail = baru;
    } else {
        baru->next = head;
        head = baru;
    }
}

// Menambah data mahasiswa di belakang linked list
void insertbelakang(string nama, string nim) {
    // Membuat node baru
    node *baru = new node;
    baru->nama = nama;
    baru->nim = nim;
    baru->next = NULL;

    // Jika linked list kosong
    if (isempty()) {
        head = tail = baru;
    } else {
        tail->next = baru;
        tail = baru;
    }
}

// Menambah data mahasiswa di tengah linked list
void inserttengah(string nama, string nim, int posisi) {
    if (posisi < 1 || posisi > hitunglist() + 1) {
        cout << "Posisi diluar jangkauan" << endl;
    } else {
        if (posisi == 1) {
            insertdepan(nama, nim);
        } else if (posisi == hitunglist() + 1) {
            insertbelakang(nama, nim);
        } else {
            node *baru = new node;
            baru->nama = nama;
            baru->nim = nim;

            node *bantu = head;
            for (int i = 1; i < posisi - 1; ++i) {
                bantu = bantu->next;
            }

            baru->next = bantu->next;
            bantu->next = baru;
        }
    }
}

// Mengubah data mahasiswa di depan linked list
void ubahdepan(string nama, string nim) {
    if (!isempty()) {
        // Menyimpan data sebelum diubah
        string nama_sebelum = head->nama;
        string nim_sebelum = head->nim;

        // Mengubah data
        head->nama = nama;
        head->nim = nim;

        // Menampilkan informasi
        cout << "Data telah diubah dari " << nama_sebelum << " menjadi " << nama << endl;
    } else {
        cout << "Linked list masih kosong!" << endl;
    }
}

// Mengubah data mahasiswa di belakang linked list
void ubahbelakang(string nama, string nim) {
    if (!isempty()) {
        // Menyimpan data sebelum diubah
        string nama_sebelum = tail->nama;
        string nim_sebelum = tail->nim;

        // Mengubah data
        tail->nama = nama;
        tail->nim = nim;

        // Menampilkan informasi
        cout << "Data telah diubah dari " << nama_sebelum << " menjadi " << nama << endl;
    } else {
        cout << "Linked list masih kosong!" << endl;
    }
}

// Mengubah data mahasiswa di tengah linked list
void ubahtengah(string nama, string nim, int posisi) {
    if (posisi < 1 || posisi > hitunglist()) {
        cout << "Posisi diluar jangkauan" << endl;
    } else {
        node *bantu = head;
        for (int i = 1; i < posisi; ++i) {
            bantu = bantu->next;
        }

        // Menyimpan data sebelum diubah
        string nama_sebelum = bantu->nama;
        string nim_sebelum = bantu->nim;

        // Mengubah data
        bantu->nama = nama;
        bantu->nim = nim;

        // Menampilkan informasi
        cout << "Data pada posisi " << posisi << " telah diubah dari " << nama_sebelum << " menjadi " << nama << endl;
    }
}

// Menghapus data mahasiswa di depan linked list
void hapusdepan() {
    if (!isempty()) {
        node *hapus = head;
        if (head == tail) {
            head = tail = NULL;
        } else {
            head = head->next;
        }
        delete hapus;
    } else {
        cout << "Linked list kosong!" << endl;
    }
}

// Menghapus data mahasiswa di belakang linked list
void hapusbelakang() {
    if (!isempty()) {
        node *hapus = tail;
        if (head == tail) {
            head = tail = NULL;
        } else {
            node *bantu = head;
            while (bantu->next != tail) {
                bantu = bantu->next;
            }
            tail = bantu;
            tail->next = NULL;
        }
        delete hapus;
    } else {
        cout << "Linked list kosong!" << endl;
    }
}

// Menghapus data mahasiswa di tengah linked list
void hapustengah(int posisi) {
    if (posisi < 1 || posisi > hitunglist()) {
        cout << "Posisi diluar jangkauan" << endl;
    } else {
        if (posisi == 1) {
            hapusdepan();
        } else if (posisi == hitunglist()) {
            hapusbelakang();
        } else {
            node *hapus = head;
            for (int i = 1; i < posisi - 1; ++i) {
                hapus = hapus->next;
            }
            node *hapus_node = hapus->next;
            hapus->next = hapus_node->next;
            delete hapus_node;
        }
    }
}

// Menghapus seluruh data di dalam linked list
void hapuslist() {
    while (!isempty()) {
        hapusdepan();
    }
    cout << "Linked list berhasil dihapus semua!" << endl;
}

// Menampilkan seluruh data dalam linked list
void tampilkan() {
    if (!isempty()) {
        node *bantu = head;
        int nomor = 1; // Variabel untuk nomor indeks atau nomor urut
        cout << setw(5) << left << "No" << setw(15) << left << "NAMA" << "NIM" << endl;
        while (bantu != NULL) {
            cout << setw(5) << left << nomor << setw(15) << left << bantu->nama << bantu->nim << endl;
            bantu = bantu->next;
            nomor++; // Menginkremen nomor indeks atau nomor urut
        }
    } else {
        cout << "Linked list kosong!" << endl;
    }
}
int main() {
    init();
    int pilihan;
    string nama;
    string nim;
    int posisi;

    do {
        // Menampilkan menu
        cout << "Menu Linked List Non Circular Mahasiswa" << endl;
        cout <<endl;
        cout << "1.Tambah Depan" << endl;
        cout << "2.Tambah Belakang" << endl;
        cout << "3.Tambah Tengah" << endl;
        cout << "4.Ubah Depan" << endl;
        cout << "5.Ubah Belakang" << endl;
        cout << "6.Ubah Tengah" << endl;
        cout << "7.Hapus Depan" << endl;
        cout << "8.Hapus Belakang" << endl;
        cout << "9.Hapus Tengah" << endl;
        cout << "10.Hapus List" << endl;
        cout << "11.Tampilkan" << endl;
        cout << "0.Keluar" << endl;
        cout << "Pilih Operasi: ";
        cin >> pilihan;
        cout <<endl;

        switch (pilihan) {
            case 1:
                cout <<"=TAMBAH DEPAN="<<endl;
                cout << endl;
                cout << "Masukkan Nama :";
                cin >> nama;
                cout << "Masukkan NIM :";
                cin >> nim;
                cout<<endl;
                cout << "Data telah ditambahkan"<<endl;
                cout << endl;
                insertdepan(nama, nim);
                break;
            case 2:
                cout << "=Tambah Belakang"<<endl;
                cout <<endl;
                cout << "Masukkan Nama :";
                cin >> nama;
                cout << "Masukkan NIM :";
                cin >> nim;
                cout<<endl;
                cout << "Data telah ditambahkan"<<endl;
                cout << endl;
                insertbelakang(nama, nim);
                break;
            case 3:
                cout << "=Tambah Tengah="<<endl;
                cout<<endl;
                cout << "Masukkan Nama :";
                cin >> nama;
                cout << "Masukkan NIM :";
                cin >> nim;
                cout << "Masukkan Posisi :";
                cin >> posisi;
                cout<<endl;
                cout << "Data telah ditambahkan"<<endl;
                cout << endl;
                inserttengah(nama, nim, posisi);
                break;
            case 4:
                cout << "=Ubah Depan="<<endl;
                cout<<endl;
                cout << "Masukkan Nama :";
                cin >> nama;
                cout << "Masukkan NIM :";
                cin >> nim;
                cout << endl;
                ubahdepan(nama, nim);
                break;
            case 5:
                cout << "Ubah Belakang"<<endl;
                cout <<endl;
                cout << "Masukkan Nama :";
                cin >> nama;
                cout << "Masukkan NIM :";
                cin >> nim;
                cout << endl;
                ubahbelakang(nama, nim);
                break;
            case 6:
                cout << "Ubah Tengah"<<endl;
                cout <<endl;
                cout << "Masukkan Nama :";
                cin >> nama;
                cout << "Masukkan NIM :";
                cin >> nim;
                cout << "Masukkan Posisi :";
                cin >> posisi;
                cout << endl;
                ubahtengah(nama, nim, posisi);
                break;
            case 7:
                cout << "=Hapus Depan="<<endl;
                cout <<endl;
                cout <<"Masukkan Nama"<<endl;
                cin >>nama;
                cout << "data "<<nama<<" berhasil untuk dihapus"<<endl;
                cout <<endl;
                hapusdepan();
                break;
            case 8:
                cout << "=Hapus Belakang="<<endl;
                cout <<endl;
                cout <<"Masukkan Nama"<<endl;
                cin >>nama;
                cout << "data "<<nama<<" berhasil untuk dihapus"<<endl;
                cout <<endl;
                hapusbelakang();
                break;
            case 9:
                cout << "=Hapus Tengah="<<endl;
                cout <<endl;
                cout <<"Masukkan Nama"<<endl;
                cin >>nama;
                cout <<"Posisi"<<endl;
                cin >>posisi;
                cout << "data "<<nama<<" berhasil untuk dihapus"<<endl;
                cout <<endl;
                hapustengah(posisi);
                break;
            case 10:
                cout << "=Hapus List="<<endl;
                cout <<endl;
                hapuslist();
                break;
            case 11:
                cout << "=Menampilkan Semua data mahasiswa="<<endl;
                cout <<endl;
                cout <<"=Data Mahasiswa="<<endl;
                cout << endl;
                tampilkan();
                break;
            case 0:
                cout << "Keluar dari program." << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilihan != 0);

    return 0;
}