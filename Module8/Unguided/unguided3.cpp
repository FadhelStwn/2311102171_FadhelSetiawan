#include <iostream>

using namespace std;

int main() {
    int n = 10;
    int data171[n] = {9, 4, 1, 4, 7, 10, 5, 4, 12, 4};
    int cari171 = 4;
    int count171 = 0;  
    int indeks[n]; 
    int i;

   
    for (i = 0; i < n; i++) {
        if (data171[i] == cari171) {
            indeks[count171] = i; 
            count171++;
        }
    }

    cout << "\nHitunglah berapa banyak angka 4 dengan menggunakan algoritma Sequential Search!" << endl;
    cout << "\n-------------------------------------------------------------------------------" << endl;
    cout << "\nData : {9, 4, 1, 4, 7, 10, 5, 4, 12, 4}" << endl;

    cout << "\nNomor " << cari171 << " berjumlah " << count171 << " pada data tersebut " << endl;

    
    if (count171 > 0) {
        cout << "\nnomor " << cari171 << " ditemukan pada indeks berikut : ";
        for (i = 0; i < count171; i++) {
            cout << indeks[i];
            if (i != count171 - 1) {
                cout << ", ";
            }
        }
        cout << endl;
    } else {
        cout << "\nnomor" << cari171 << " tidak ditemukan di mana pun!" << endl;
    }
    return 0;
}