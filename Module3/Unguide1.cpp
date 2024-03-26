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