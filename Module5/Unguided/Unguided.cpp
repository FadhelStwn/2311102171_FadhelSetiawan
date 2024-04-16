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