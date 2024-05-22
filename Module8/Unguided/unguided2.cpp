#include <iostream>
#include <cctype>

using namespace std;

bool isVowel(char karakter171) { 
    karakter171 = tolower(karakter171); 
    return (karakter171 == 'a' || karakter171 == 'e' || karakter171 == 'i' || karakter171 == 'o' || karakter171 == 'u'); 
}

void countVowels(const string &kata171, int vocal171[5]) { 
   
    for (char karakter171 : kata171) {
        if (isVowel(karakter171)) {  
            switch (tolower(karakter171)) { 
                case 'a': 
                    vocal171[0]++; 
                    break;
                case 'e':
                    vocal171[1]++; 
                    break;
                case 'i':
                    vocal171[2]++; 
                    break;
                case 'o':
                    vocal171[3]++; 
                    break;
                case 'u':
                    vocal171[4]++; 
                    break;
            }
        }
    }
}

int main() {
    string kata171;
    cout << "\n Menghitung Banyak Huruf Vokal" << endl;

    do
    {
    cout << "\n------------------------------" << endl;
    cout << "\nMasukan Sebuah Kalimat :"; getline(cin, kata171);

    int vocal171[5] = {0}; 

    countVowels(kata171, vocal171); 

    cout << "\nKalimat yang kamu masukan terdiri dari huruf vokal ini:\n";
    cout << "a: " << vocal171[0] << endl;
    cout << "e: " << vocal171[1] << endl;
    cout << "i: " << vocal171[2] << endl;
    cout << "o: " << vocal171[3] << endl;
    cout << "u: " << vocal171[4] << endl;
    
    } while (kata171 != "!");
    
}