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

// Bu fonksiyonlar "main()" fonksiyonunun altýnda yer aldýðý için önce tanýmlýyoruz.
int Ornek1(std::string);
int Ornek2(std::string);
int Ornek3(std::string);

// LAB. UYGULAMASI
int Ornek4(); // Dosyaya Yazma Örneði
int Ornek5(); // Dosyadan Okuma Örneði
int Ornek6(); // Dosyadan Satýr Satýr Okuma Örneði

int main()
{
    // string türündeki bir deðiþkene dosya adýný tanýmlýyoruz.
    std::string dosyaAdi = "ornek.txt";

    // ofstream kullanarak dosyaya yazma örneði.
    Ornek1(dosyaAdi);

    // ifstream kullanarak dosya okuma örneði.
    Ornek2(dosyaAdi);

    // fstream kullanarak dosya okuma ve yazma örneði.
    Ornek3("ornek2.txt");

    return 0;
}


/// <summary>
///  ofstream kullanarak dosyaya yazma.
/// </summary>
/// <returns></returns>
int Ornek1(std::string dosyaAdi)
{
    // Dosyaya yazmak için ofstream nesnesi oluþturma
    std::ofstream dosyaYaz(dosyaAdi);
    // "ornek.txt" adýnda bir dosya yoksa oluþturur, varsa içeriðini sýfýrlar.

    // Dosyanýn açýlýp açýlmadýðýný kontrol et;
    if (!dosyaYaz.is_open()) {
        std::cerr << "Dosya açýlamadý!" << std::endl;
        return 1;
    }

    dosyaYaz << "Merhaba Dünya!" << std::endl;
    dosyaYaz << "C++ ile dosyalama dersine hoþ geldiniz." << std::endl;

    // Dosyadaki iþlemler bittikten sonra dosyayý kapatýyoruz;
    dosyaYaz.close();

    return 0;
}

/// <summary>
///  ifstream kullanarak dosya okuma.
/// </summary>
/// <returns></returns>
int Ornek2(std::string dosyaAdi) {

    // Dosyayý okumak için ifstream nesnesi
    std::ifstream dosyaOku(dosyaAdi);

    // Dosyanýn açýlýp açýlmadýðýný kontrol et;
    if (!dosyaOku.is_open()) {
        std::cerr << "Dosya açýlamadý!" << std::endl;
        return 1;
    }

    std::string satir;
    // Dosyayý satýr satýr okuyabiliriz
    while (std::getline(dosyaOku, satir)) { // her seferinde bir satýr okur ve satýrýn sonuna gelince durur.
        std::cout << satir << std::endl;
    }

    // Dosyadaki iþlemler bittikten sonra dosyayý kapatýyoruz;
    dosyaOku.close();

    return 0;
}


/// <summary>
///  fstream kullanarak hem dosya okuma hem de yazma.
/// </summary>
/// <returns></returns>
int Ornek3(std::string dosyaAdi) {

    // Hem okuma hem yazma için fstream
    std::fstream dosya(dosyaAdi, std::ios::in | std::ios::out | std::ios::app);
    // dosya yoksa oluþturur, varsa açar. 'ios::app' ile dosya sonuna yazýlýr.

    // Dosyanýn açýlýp açýlmadýðýný kontrol et;
    if (!dosya.is_open()) {
        std::cerr << "Dosya açýlamadý!" << std::endl;
        return 1;
    }

    // Yazma iþlemi
    dosya << "Bu satýr dosyanýn sonuna eklendi." << std::endl;

    // Ýþlemden sonra dosya imlecini (seek) baþa almak, okuma yapmak için gereklidir.
    dosya.seekg(0, std::ios::beg);

    // Dosyadan satýr satýr okuma iþlemi;
    std::string satir;
    while (std::getline(dosya, satir)) {
        std::cout << satir << std::endl;
    }

    // Dosyadaki iþlemler bittikten sonra dosyayý kapatýyoruz;
    dosya.close();

    return 0;
}


/// <summary>
///   Dosyalara Yazma ve Okuma Örnekleri
///   <Yazma>
/// </summary>
/// <returns></returns>
int Ornek4() {
    
    // Dosya oluþturulur/varsa sýfýrlanýr
    std::ofstream dosyaYaz("veri.txt");

    if (!dosyaYaz) {
        std::cerr << "Dosya açýlamadý!" << std::endl;
        return 1;
    }

    // Kullanýcýdan veri al!
    std::string ad;
    int yas;
    std::cout << "Adýnýzý giriniz: ";
    std::cin >> ad;
    std::cout << "Yaþýnýzý giriniz: ";
    std::cin >> yas;

    // Dosyaya yaz!
    dosyaYaz << ad << std::endl;
    dosyaYaz << yas << std::endl;

    dosyaYaz.close(); // Dosyayý kapat.

    return 0;
}

/// <summary>
///   Dosyalara Yazma ve Okuma Örnekleri
///   <Okuma>
/// </summary>
/// <returns></returns>
int Ornek5() {
    std::ifstream dosyaOku("veri.txt");

    if (!dosyaOku) {
        std::cerr << "Dosya açýlamadý!" << std::endl;
        return 1;
    }

    std::string ad;
    int yas;

    dosyaOku >> ad;   // satýr satýr veya boþluk ayrýmýna göre okur
    dosyaOku >> yas;

    std::cout << "Ad: " << ad << std::endl;
    std::cout << "Yas: " << yas << std::endl;

    dosyaOku.close();

    return 0;
}

/// <summary>
///  Satýr Satýr Okuma (getline)
/// </summary>
/// <returns></returns>
int Ornek6() {
    std::ifstream dosyaOku("satirlar.txt");

    if (!dosyaOku.is_open()) {
        std::cerr << "Dosya açýlamadý!" << std::endl;
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