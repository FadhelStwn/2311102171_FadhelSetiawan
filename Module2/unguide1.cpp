#include <iostream>
using namespace std;

int main() {
    int n_2311102171, num_Fadhel;
    cout << "Masukkan jumlah data: ";
    cin >> n_2311102171;

    int dataArray[n_2311102171];

    cout << "Masukkan data: ";
    for (int i = 0; i < n_2311102171; i++) {
        cin >> num_Fadhel;
        dataArray[i] = num_Fadhel;
    }

    cout << "Data Array: ";
    for (int i = 0; i < n_2311102171; i++) {
        cout << dataArray[i] << " ";
    }
    cout << endl;

    cout << "Nomor Genap : ";
    for (int i = 0; i < n_2311102171; i++) {
        if (dataArray[i] % 2 == 0) {
            cout << dataArray[i] << ", ";
        }
    }
    cout << endl;

    cout << "Nomor Ganjil : ";
    for (int i = 0; i < n_2311102171; i++) {
        if (dataArray[i] % 2 != 0) {
            cout << dataArray[i] << ", ";
        }
    }
    cout << endl;

    return 0;
}