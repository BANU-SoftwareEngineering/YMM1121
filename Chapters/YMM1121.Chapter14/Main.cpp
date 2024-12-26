// YMM1121.Chapter14.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

#include <iostream>
#include <fstream>   // ofstream, ifstream, fstream
#include <string>

// Bu fonksiyonlar "main()" fonksiyonunun alt�nda yer ald��� i�in �nce tan�ml�yoruz.
int Ornek1(std::string);
int Ornek2(std::string);
int Ornek3(std::string);

// LAB. UYGULAMASI
int Ornek4(); // Dosyaya Yazma �rne�i
int Ornek5(); // Dosyadan Okuma �rne�i
int Ornek6(); // Dosyadan Sat�r Sat�r Okuma �rne�i

int main()
{
    // string t�r�ndeki bir de�i�kene dosya ad�n� tan�ml�yoruz.
    std::string dosyaAdi = "ornek.txt";

    // ofstream kullanarak dosyaya yazma �rne�i.
    Ornek1(dosyaAdi);

    // ifstream kullanarak dosya okuma �rne�i.
    Ornek2(dosyaAdi);

    // fstream kullanarak dosya okuma ve yazma �rne�i.
    Ornek3("ornek2.txt");

    return 0;
}


/// <summary>
///  ofstream kullanarak dosyaya yazma.
/// </summary>
/// <returns></returns>
int Ornek1(std::string dosyaAdi)
{
    // Dosyaya yazmak i�in ofstream nesnesi olu�turma
    std::ofstream dosyaYaz(dosyaAdi);
    // "ornek.txt" ad�nda bir dosya yoksa olu�turur, varsa i�eri�ini s�f�rlar.

    // Dosyan�n a��l�p a��lmad���n� kontrol et;
    if (!dosyaYaz.is_open()) {
        std::cerr << "Dosya a��lamad�!" << std::endl;
        return 1;
    }

    dosyaYaz << "Merhaba D�nya!" << std::endl;
    dosyaYaz << "C++ ile dosyalama dersine ho� geldiniz." << std::endl;

    // Dosyadaki i�lemler bittikten sonra dosyay� kapat�yoruz;
    dosyaYaz.close();

    return 0;
}

/// <summary>
///  ifstream kullanarak dosya okuma.
/// </summary>
/// <returns></returns>
int Ornek2(std::string dosyaAdi) {

    // Dosyay� okumak i�in ifstream nesnesi
    std::ifstream dosyaOku(dosyaAdi);

    // Dosyan�n a��l�p a��lmad���n� kontrol et;
    if (!dosyaOku.is_open()) {
        std::cerr << "Dosya a��lamad�!" << std::endl;
        return 1;
    }

    std::string satir;
    // Dosyay� sat�r sat�r okuyabiliriz
    while (std::getline(dosyaOku, satir)) { // her seferinde bir sat�r okur ve sat�r�n sonuna gelince durur.
        std::cout << satir << std::endl;
    }

    // Dosyadaki i�lemler bittikten sonra dosyay� kapat�yoruz;
    dosyaOku.close();

    return 0;
}


/// <summary>
///  fstream kullanarak hem dosya okuma hem de yazma.
/// </summary>
/// <returns></returns>
int Ornek3(std::string dosyaAdi) {

    // Hem okuma hem yazma i�in fstream
    std::fstream dosya(dosyaAdi, std::ios::in | std::ios::out | std::ios::app);
    // dosya yoksa olu�turur, varsa a�ar. 'ios::app' ile dosya sonuna yaz�l�r.

    // Dosyan�n a��l�p a��lmad���n� kontrol et;
    if (!dosya.is_open()) {
        std::cerr << "Dosya a��lamad�!" << std::endl;
        return 1;
    }

    // Yazma i�lemi
    dosya << "Bu sat�r dosyan�n sonuna eklendi." << std::endl;

    // ��lemden sonra dosya imlecini (seek) ba�a almak, okuma yapmak i�in gereklidir.
    dosya.seekg(0, std::ios::beg);

    // Dosyadan sat�r sat�r okuma i�lemi;
    std::string satir;
    while (std::getline(dosya, satir)) {
        std::cout << satir << std::endl;
    }

    // Dosyadaki i�lemler bittikten sonra dosyay� kapat�yoruz;
    dosya.close();

    return 0;
}


/// <summary>
///   Dosyalara Yazma ve Okuma �rnekleri
///   <Yazma>
/// </summary>
/// <returns></returns>
int Ornek4() {
    
    // Dosya olu�turulur/varsa s�f�rlan�r
    std::ofstream dosyaYaz("veri.txt");

    if (!dosyaYaz) {
        std::cerr << "Dosya a��lamad�!" << std::endl;
        return 1;
    }

    // Kullan�c�dan veri al!
    std::string ad;
    int yas;
    std::cout << "Ad�n�z� giriniz: ";
    std::cin >> ad;
    std::cout << "Ya��n�z� giriniz: ";
    std::cin >> yas;

    // Dosyaya yaz!
    dosyaYaz << ad << std::endl;
    dosyaYaz << yas << std::endl;

    dosyaYaz.close(); // Dosyay� kapat.

    return 0;
}

/// <summary>
///   Dosyalara Yazma ve Okuma �rnekleri
///   <Okuma>
/// </summary>
/// <returns></returns>
int Ornek5() {
    std::ifstream dosyaOku("veri.txt");

    if (!dosyaOku) {
        std::cerr << "Dosya a��lamad�!" << std::endl;
        return 1;
    }

    std::string ad;
    int yas;

    dosyaOku >> ad;   // sat�r sat�r veya bo�luk ayr�m�na g�re okur
    dosyaOku >> yas;

    std::cout << "Ad: " << ad << std::endl;
    std::cout << "Yas: " << yas << std::endl;

    dosyaOku.close();

    return 0;
}

/// <summary>
///  Sat�r Sat�r Okuma (getline)
/// </summary>
/// <returns></returns>
int Ornek6() {
    std::ifstream dosyaOku("satirlar.txt");

    if (!dosyaOku.is_open()) {
        std::cerr << "Dosya a��lamad�!" << std::endl;
        return 1;
    }

    std::string satir;
    int satirNumarasi = 1;

    while (std::getline(dosyaOku, satir)) {
        std::cout << satirNumarasi << ". " << satir << std::endl;
        satirNumarasi++;
    }

    dosyaOku.close();
    return 0;
}