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