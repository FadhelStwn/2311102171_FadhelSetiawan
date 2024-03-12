#include <iostream>
#include <map> // Library supaya bisa menggunakan fungsi map dibawah

using namespace std;

int main() {
    
    // Deklarasi map dengan key int dan value string
    map<int, string> wisata112;
  
    // Menambahkan elemen-elemen ke dalam map
    wisata112[1] = "taman";
    wisata112[2] = "curug";
    wisata112[3] = "pemandian air panas";
    wisata112[4] = "rumah hantu";
    wisata112[5] = "museum";

    cout << "-=-= Wisata Fadhel! =-=-" << endl;
    for (int i = 1; i <= wisata112.size(); ++i) { // Looping untuk menampilkan semua elemen map
        cout << "No." << i << " " << wisata112[i] << endl; // Menampilkan elemen map
    }

    return 0;
}