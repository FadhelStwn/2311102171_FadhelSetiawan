#include <iostream>
#include <stack>

using namespace std;

bool Palindrome_171(string kalimat171)
{
  for (int i = 0; i < kalimat171.length(); i++)
  { // Konversi kalimat ke huruf kecil
    kalimat171[i] = tolower(kalimat171[i]);
  }

  stack<char> s; // Buat stack untuk menyimpan karakter kalimat

  for (int i = 0; i < kalimat171.length(); i++)
  { // Masukkan karakter kalimat ke stack
    s.push(kalimat171[i]);
  }

  for (int i = 0; i < kalimat171.length() / 2; i++)
  { // Bandingkan karakter dari depan dan belakang kalimat
    if (kalimat171[i] != s.top())
    {
      return false;
    }
    s.pop();
  }

  return true;
}

int main()
{
  string kalimat171;
  cout << "-=-=- PALINDROME CHECKER -=-=-" << endl;

  do
  {
    cout << "\n Masukkan kalimat: "; // Input kalimat dari pengguna
    getline(cin, kalimat171);

    if (Palindrome_171(kalimat171))
    { // Periksa apakah kalimat palindrom atau bukan
      cout << " Kalimat " << kalimat171 << " adalah : Palindrom!" << endl;
    }
    else
    {
      cout << " Kalimat " << kalimat171 << " bukan : Palindrom!" << endl;
    }

  } while (kalimat171 != "exit");
  return 0;
}