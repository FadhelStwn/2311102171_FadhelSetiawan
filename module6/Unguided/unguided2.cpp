#include <iostream>
#include <stack>

using namespace std;

string pengulang171(string kalimat171) {
  stack<char> s; // Buat stack untuk menyimpan karakter kalimat

  for (int i = 0; i < kalimat171.length(); i++) { // Masukkan karakter kalimat ke stack
    s.push(kalimat171[i]);
  }

  string setelahmengulangi171; // Membalik kalimat dengan mengeluarkan karakter dari stack
  while (!s.empty()) {
    setelahmengulangi171 += s.top();
    s.pop();
  }

  return setelahmengulangi171;
}

int main() {
  string kalimat171;
  cout << "-=-=- Membalik Kata -=-=-" << endl;

  do {
  cout << "\n Masukkan kalimat yang ingin dibalikkan: ";  // Input kalimat dari pengguna
  getline(cin, kalimat171);

  string setelahmengulangi171 = pengulang171(kalimat171);  // Membalik kalimat

  cout << " Kalimat yang dibalik: " << setelahmengulangi171 << endl; // Menampilkan kalimat yang dibalik

  } while (kalimat171 != "exit");
  return 0;
}