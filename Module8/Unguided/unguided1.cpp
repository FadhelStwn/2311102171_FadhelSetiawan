#include <iostream>
#include <string>

using namespace std;


bool binarySearch(string kalimat171, char carikalimat171) {
 
  int low171 = 0;
  int high171 = kalimat171.length() - 1;

  
  while (low171 <= high171) {
    
    int mid = (low171 + high171) / 2;

   
    if (kalimat171[mid] == carikalimat171) {
      
      return true;
    } else if (kalimat171[mid] < carikalimat171) {
      
      low171 = mid + 1;
    } else {
     
      high171 = mid - 1;
    }
  }


  return false;
}

int main() {
  
  string kalimat171;
  char carikalimat171;


  cout << "Masukkan kalimat171: ";
  getline(cin, kalimat171);

 
  cout << "Masukkan huruf yang ingin dicari: ";
  cin >> carikalimat171;

  
  bool ditemukan = binarySearch(kalimat171, carikalimat171);

 
  if (ditemukan) {
    cout << "Huruf '" << carikalimat171 << "' ditemukan dalam kalimat." << endl;
  } else {
    cout << "Huruf '" << carikalimat171 << "' tidak ditemukan dalam kalimat." << endl;
  }

  return 0;
}
