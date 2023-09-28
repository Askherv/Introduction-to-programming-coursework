/**********
** SAKARYA UNIVERSITY
** BILGISAYAR MUHENDISLIGI BOLUMU
** PROGRAMLAMAYA GIRIS
**
** OGRENCI ADI: NIHAD ASGAROV
** OGRENCI NUMARASI: B211210554
** DERS GRUBU: B
**********/

#include<iostream>
#include<Windows.h>


using namespace std;
const char DUZCIZGI = 205;
const char SOLUSTKOSE = 201;
const char SAGUSTKOSE = 187;
const char DIKEYCIZGI = 186;
const char ASAGIAYRAC = 203;
const char SOLALTKOSE = 200;
const char SAGALTKOSE = 188;
const char YUKARIAYRAC = 202;
const char HARFLER[26]
{
    'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'
};
enum Renk
{
    LIGHTBLUE = 9,
    LIGHTGREEN = 10,
    LIGHTCYAN = 11,
    LIGHTRED = 12,
    LIGHTMAGENTA = 13,
    YELLOW = 14,
};

class Karakter {
public:
    char harf;
    Renk renk;
};

class Katar
{
public:
    void cikar();
    void ekle();
    void yazdir();
    int karakterSayisi;
private:
    Karakter karakterler[50];
};


void Katar::yazdir()
{
    if (karakterSayisi != 0) {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        for (int i = 0; i < karakterSayisi; i++)
        {
            cout << SOLUSTKOSE << DUZCIZGI << SAGUSTKOSE;
        }
        cout << endl;
        for (int i = 0; i < karakterSayisi; i++)
        {
            cout << DIKEYCIZGI;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), karakterler[i].renk);
            cout << karakterler[i].harf;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
            cout << DIKEYCIZGI;
        }
        cout << endl;
        for (int i = 0; i < karakterSayisi; i++)
        {
            cout << SOLALTKOSE << DUZCIZGI << SAGALTKOSE;
        }
        cout << endl << endl;
    }
}

void Katar::cikar()
{
    if (karakterSayisi == 0) {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
        cout << "Cikarma Yapilamaz" << endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        return;
    }
    cout << "Onceki Durum - Eleman Sayisi=" << karakterSayisi << endl;
    yazdir();
    karakterSayisi--;
    cout << "Sonraki Durum - Eleman Sayisi=" << karakterSayisi << endl;
    yazdir();
}

void Katar::ekle()
{
    if (karakterSayisi == 50) {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
        cout << "Ekleme Yapilamaz" << endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        return;
    }
    cout << "Onceki Durum - Eleman Sayisi=" << karakterSayisi << endl;
    yazdir();
    Karakter karakter;
    karakter.harf = HARFLER[rand() % 26];
    karakter.renk = static_cast<Renk>(rand() % 6 + 9);
    karakterler[karakterSayisi++] = karakter;
    cout << "Sonraki Durum - Eleman Sayisi=" << karakterSayisi << endl;
    yazdir();
}


int main() {
    int gorev;
    srand(time(NULL));
    Katar katar = Katar();
    do {
        cout << "islem seciniz" << endl;
        cout << "1-karakter ekle" << endl;
        cout << "2-karakter cikar" << endl;
        cout << "3-programdan cikis" << endl;
        cin >> gorev;
        switch (gorev) {
        case 1: katar.ekle(); break;
        case 2: katar.cikar(); break;
        default: break;
        }
    } while (gorev != 3);
    return 0;
}