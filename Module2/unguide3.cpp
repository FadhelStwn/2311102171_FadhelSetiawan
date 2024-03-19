#include <iostream>
using namespace std;

int main() {
    int a, max_fadhels, min_2311102171, sum = 0;
    double avg;

    cout << "Masukkan jumlah data: ";
    cin >> a;

    int arr[a];

    // Input elemen
    for (int i = 0; i < a; i++) {
        cout << "Input data ke-" << i + 1 << ": ";
        cin >> arr[i];
    }

    // Mencari nilai maksimum
    max_fadhels = arr[0];
    for (int i = 1; i < a; i++) {
        if (arr[i] > max_fadhels) {
            max_fadhels = arr[i];
        }
    }

    // Mencari nilai 
    min_2311102171 = arr[0];
    for (int i = 1; i < a; i++) {
        if (arr[i] < min_2311102171) {
            min_2311102171 = arr[i];
        }
    }

    // Menghitung jumlah elemen
    for (int i = 0; i < a; i++) {
        sum += arr[i];
    }

    // Menghitung rata-rata
    avg = (double)sum / a;

    // Menampilkan hasil
    cout << endl;
    cout << "Nilai maksimum: " << max_fadhels << endl;
    cout << "Nilai minimum: " << min_2311102171 << endl;
    cout << "Nilai rata-rata: " << avg << endl;

    return 0;
}