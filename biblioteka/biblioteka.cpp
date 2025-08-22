#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <Windows.h>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <random>
#include <algorithm>
using namespace std;

vector<int> ostatnie;

string ekstrakcja(int numertabelilinii, int kolumna)
{
    ifstream plik("plik.txt");
    string linia;
    vector<string> tablicalinii;

    while (getline(plik, linia))
    {
        tablicalinii.push_back(linia);
    }

    if (numertabelilinii >= tablicalinii.size()) return "";

    vector<string> element;
    size_t start = 0;
    size_t koniec = tablicalinii[numertabelilinii].find("|");

    while (koniec != string::npos)
    {
        element.push_back(tablicalinii[numertabelilinii].substr(start, koniec - start));
        start = koniec + 1;
        koniec = tablicalinii[numertabelilinii].find("|", start);
    }

    element.push_back(tablicalinii[numertabelilinii].substr(start));

    if (kolumna >= element.size()) return "";
    return element[kolumna];
}

string ekstraktordodatku(int numertabelilinii, int kolumna)
{
    ifstream plik("dodatek.txt");
    string linia;
    vector<string> tablicalinii;

    while (getline(plik, linia))
    {
        tablicalinii.push_back(linia);
    }

    vector<string> element;
    size_t start = 0;
    size_t koniec = tablicalinii[numertabelilinii].find("|");

    while (koniec != string::npos)
    {
        element.push_back(tablicalinii[numertabelilinii].substr(start, koniec - start));
        start = koniec + 1;
        koniec = tablicalinii[numertabelilinii].find("|", start);
    }

    element.push_back(tablicalinii[numertabelilinii].substr(start));
    return element[kolumna];
}

void naglowek()
{
    // Nagłówek tabeli
    cout << "\n"
        << setw(4) << left << "ID"
        << setw(80) << left << "Autor"
        << setw(84) << left << "Tytuł"
        << setw(24) << left << "Gatunek"
        << setw(32) << left << "Wydawnictwo"
        << setw(8) << left << "Strony"
        << setw(16) << left << "Przeczytane?"
        << setw(8) << left << "Typ"
        << "\n";
    cout << string(256, '-') << "\n"; // linia oddzielająca
}

void wypisz(int id)
{
    cout << setw(4) << left << ekstrakcja(id, 0)
        << setw(80) << left << ekstrakcja(id, 1)
        << setw(84) << left << ekstrakcja(id, 2)
        << setw(24) << left << ekstrakcja(id, 3)
        << setw(32) << left << ekstrakcja(id, 4)
        << setw(8) << left << ekstrakcja(id, 5)
        << setw(16) << left << ekstrakcja(id, 6)
        << setw(8) << left << ekstrakcja(id, 7)
        << "\n";
}

int string2int(string stringi)
{
    return stoi(stringi);
}

int sumastron(int llinii)
{
    int x2 = 0;
    int suma = 0;
        while (x2 < llinii)
        {
            suma = suma + string2int(ekstrakcja(x2, 5));
            x2 = x2 + 1;
        }
        return suma;
}

int sumaprzeczytanychstron(int llinii)
{
    int x3 = 0;
    int suma = 0;
    while (x3 < llinii)
    {
        if (ekstrakcja(x3, 6) == "TAK")
        {
            suma = suma + string2int(ekstrakcja(x3, 5));
        }
        x3 = x3 + 1;
    }
    return suma;
}

void gatunek(float llinii, int tryb)
{
    float x4 = 0;
    int SciFi = 0;
    int Historyczne = 0;
    int PopularnoNaukowe = 0;
    int Horror = 0;
    int LiteraturaFaktu = 0;
    int Postapo = 0;
    int Fantastyka = 0;
    int Poradnik = 0;
    int Słownik = 0;
    int Podręcznik = 0;
    int ZbiorZadan = 0;
    int Encyklopedia = 0;
    int Psychologiczne = 0;
    int Bajki = 0;
    int Przewodnik = 0;
    int Muzyka = 0;
    int Felietony = 0;
    int Kryminalne = 0;

    int prog = 0;
    while (x4 < llinii)
    {
        if (ekstrakcja(x4, 3) == "Sci-Fi")
        {
            SciFi = SciFi + 1;
            if (tryb == 1)
            {
                ostatnie.push_back(x4);
            }
        }
        if (ekstrakcja(x4, 3) == "Historyczne")
        {
            Historyczne = Historyczne + 1;
            if (tryb == 2)
            {
                ostatnie.push_back(x4);
            }
        }
        if (ekstrakcja(x4, 3) == "Popularno-Naukowe")
        {
            PopularnoNaukowe = PopularnoNaukowe + 1;
            if (tryb == 3)
            {
                ostatnie.push_back(x4);
            }
        }
        if (ekstrakcja(x4, 3) == "Horror")
        {
            Horror = Horror + 1;
            if (tryb == 4)
            {
                ostatnie.push_back(x4);
            }
        }
        if (ekstrakcja(x4, 3) == "Literatura Faktu")
        {
            LiteraturaFaktu = LiteraturaFaktu + 1;
            if (tryb == 5)
            {
                ostatnie.push_back(x4);
            }
        }
        if (ekstrakcja(x4, 3) == "Postapo")
        {
            Postapo = Postapo + 1;
            if (tryb == 6)
            {
                ostatnie.push_back(x4);
            }
        }
        if (ekstrakcja(x4, 3) == "Fantastyka")
        {
            Fantastyka = Fantastyka + 1;
            if (tryb == 7)
            {
                ostatnie.push_back(x4);
            }
        }
        if (ekstrakcja(x4, 3) == "Poradnik")
        {
            Poradnik = Poradnik + 1;
            if (tryb == 8)
            {
                ostatnie.push_back(x4);
            }
        }
        if (ekstrakcja(x4, 3) == "Słownik")
        {
            Słownik = Słownik + 1;
            if (tryb == 9)
            {
                ostatnie.push_back(x4);
            }
        }
        if (ekstrakcja(x4, 3) == "Podręcznik")
        {
            Podręcznik = Podręcznik + 1;
            if (tryb == 10)
            {
                ostatnie.push_back(x4);
            }
        }
        if (ekstrakcja(x4, 3) == "Zbiór Zadań")
        {
            ZbiorZadan = ZbiorZadan + 1;
            if (tryb == 11)
            {
                ostatnie.push_back(x4);
            }
        }
        if (ekstrakcja(x4, 3) == "Encyklopedia")
        {
            Encyklopedia = Encyklopedia + 1;
            if (tryb == 12)
            {
                ostatnie.push_back(x4);
            }
        }
        if (ekstrakcja(x4, 3) == "Psychologiczne")
        {
            Psychologiczne = Psychologiczne + 1;
            if (tryb == 13)
            {
                ostatnie.push_back(x4);
            }
        }
        if (ekstrakcja(x4, 3) == "Bajki")
        {
            Bajki = Bajki + 1;
            if (tryb == 14)
            {
                ostatnie.push_back(x4);
            }
        }
        if (ekstrakcja(x4, 3) == "Przewodnik")
        {
            Przewodnik = Przewodnik + 1;
            if (tryb == 15)
            {
                ostatnie.push_back(x4);
            }
        }
        if (ekstrakcja(x4, 3) == "Muzyka")
        {
            Muzyka = Muzyka + 1;
            if (tryb == 16)
            {
                ostatnie.push_back(x4);
            }
        }
        if (ekstrakcja(x4, 3) == "Felietony")
        {
            Felietony = Felietony + 1;
            if (tryb == 17)
            {
                ostatnie.push_back(x4);
            }
        }
        if (ekstrakcja(x4, 3) == "Kryminalne")
        {
            Kryminalne = Kryminalne + 1;
            if (tryb == 18)
            {
                ostatnie.push_back(x4);
            }
        }

        float progress = (x4 / (float)llinii) * 100; // aktualny procent ładowania

        while (prog * 10 <= progress)
        {
            cout << "Ładowanie...\t" << prog * 10 << "%" << endl;
            prog = prog + 1;
        }

        x4 = x4 + 1;
    }
    cout << "Ładowanie...\t100%" << endl;

    if (tryb == 0)
    {
        cout << "\n"
            << setw(12) << left << "1. Sci-Fi"
            << setw(16) << left << "2. Historyczne"
            << setw(22) << left << "3. Popularno-Naukowe"
            << setw(12) << left << "4. Horror"
            << setw(22) << left << "5. Literatura Faktu"
            << setw(12) << left << "6. Postapo"
            << setw(16) << left << "7. Fantastyka"
            << setw(12) << left << "8. Poradnik"
            << setw(12) << left << "9. Słownik"
            << setw(16) << left << "10. Podręcznik"
            << setw(18) << left << "11. Zbiór Zadań"
            << setw(20) << left << "12. Encyklopedia"
            << setw(20) << left << "13. Psychologiczne"
            << setw(12) << left << "14. Bajki"
            << setw(16) << left << "15. Przewodnik"
            << setw(12) << left << "16. Muzyka"
            << setw(14) << left << "17. Felietony"
            << setw(22) << left << "18. Kryminalne"
            << "\n";

        cout << string(280, '-') << "\n"; // linia oddzielająca

        cout << setw(12) << left << SciFi
            << setw(16) << left << Historyczne
            << setw(22) << left << PopularnoNaukowe
            << setw(12) << left << Horror
            << setw(22) << left << LiteraturaFaktu
            << setw(12) << left << Postapo
            << setw(16) << left << Fantastyka
            << setw(12) << left << Poradnik
            << setw(12) << left << Słownik
            << setw(16) << left << Podręcznik
            << setw(18) << left << ZbiorZadan
            << setw(20) << left << Encyklopedia
            << setw(20) << left << Psychologiczne
            << setw(12) << left << Bajki
            << setw(16) << left << Przewodnik
            << setw(12) << left << Muzyka
            << setw(14) << left << Felietony
            << setw(22) << left << Kryminalne
            << "\n";
    }
}

void fizyczny(float llinii, string tryb)
{
    float x5 = 0;
    int Ksiazka = 0;
    int Komiks = 0;
    int Ebook = 0;
    int prog = 0;
    while (x5 < llinii)
    {
        if (ekstrakcja(x5, 7) == "Książka")
        {
            Ksiazka = Ksiazka + 1;
            if (tryb == "ks")
            {
                ostatnie.push_back(x5);
            }
        }
        if (ekstrakcja(x5, 7) == "Komiks")
        {
            Komiks = Komiks + 1;
            if (tryb == "ko")
            {
                ostatnie.push_back(x5);
            }
        }
        if (ekstrakcja(x5, 7) == "Ebook")
        {
            Ebook = Ebook + 1;
            if (tryb == "eb")
            {
                ostatnie.push_back(x5);
            }
        }



        float progress = (x5 / (float)llinii) * 100; // aktualny procent ładowania

        while (prog * 25 <= progress)
        {
            cout << "Ładowanie...\t" << prog * 25 << "%" << endl;
            prog = prog + 1;
        }

        x5 = x5 + 1;
    }

    cout << "Ładowanie...\t100%" << endl;

    if (tryb == "0")
    {
        cout << "\n"
            << setw(16) << left << "Książka"
            << setw(16) << left << "Komiks"
            << setw(16) << left << "Ebook"
            << "\n";

        cout << string(48, '-') << "\n"; // linia oddzielająca

        cout << setw(16) << left << Ksiazka
            << setw(16) << left << Komiks
            << setw(20) << left << Ebook
            << "\n";
    }
}

void powiazania(int w2, int tryb)
{
    if (tryb == 0)
    {
        cout << "\n\tPowiązane:" << endl;
        // Nagłówek tabeli
        naglowek();
    }

    // wektory serii
    vector<int> uniwersum_metro_2033 = { 12, 13, 14 };
    vector<int> kroniki_rodu_kane = { 15, 16, 17 };
    vector<int> dom_tajemnic = { 18, 19, 20 };
    vector<int> five_nights_at_freddys = { 21, 22, 23 };
    vector<int> five_nights_at_freddys_guides = { 24, 25, 26 };
    vector<int> fazbear_frights = { 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37 };
    vector<int> percy_jackson = { 38, 39, 40, 41, 42 };
    vector<int> harry_potter = { 43, 44, 45, 46, 47, 48, 49, 50 };
    vector<int> wiedzmin = { 70, 71, 72, 73, 74, 75, 76, 77, 78 };
    vector<int> wladca_pierscieni = { 83, 84, 85 };
    vector<int> szachy_podrecznik = { 53, 54 };
    vector<int> miniatury_matematyczne = { 57, 58, 59, 60 };
    vector<int> szkola_taktyki_szachowej = { 61, 62 };
    vector<int> koszmar_z_elm_street = { 117, 118, 119, 120, 121, 122 };
    vector<int> five_nights_at_freddys_comics = { 167, 168, 169 };
    vector<int> zniwiarz = { 170, 171, 172, 173, 174 };
    vector<int> magiczne_drzewo = { 181, 182, 183, 184, 185, 186, 187, 188 };
    vector<int> klub_podroznika = { 190, 191, 192 };
    vector<int> pamietnik_8bitowego_wojownika = { 193, 194, 195, 196, 197, 198 };
    vector<int> minecraft_podreczniki = { 199, 200, 201, 202 };
    vector<int> trylogia_husycka = { 208, 209, 210 };
    vector<int> outpost = { 211, 212 };
    vector<int> tales_from_the_pizzaplex = { 161, 162, 163, 164, 165, 166 };

    // Master table
    vector<vector<int>> serie =
    {
        uniwersum_metro_2033,
        kroniki_rodu_kane,
        dom_tajemnic,
        five_nights_at_freddys,
        five_nights_at_freddys_guides,
        fazbear_frights,
        percy_jackson,
        harry_potter,
        wiedzmin,
        wladca_pierscieni,
        szachy_podrecznik,
        miniatury_matematyczne,
        szkola_taktyki_szachowej,
        koszmar_z_elm_street,
        five_nights_at_freddys_comics,
        zniwiarz,
        magiczne_drzewo,
        klub_podroznika,
        pamietnik_8bitowego_wojownika,
        minecraft_podreczniki,
        trylogia_husycka,
        outpost,
        tales_from_the_pizzaplex
    };

    if (tryb == 1)
    {
        cout << "\n\tWybierz serię:\n\n1. Uniwersum Metro 2033 \t 2. Kroniki rodu Kane\t3. Dom Tajemnic\t 4. FNAF\t 5. Poradniki FNAF\t6. Fazbear Fright's\t7. Percy Jackson\t8. Harry Potter" << endl
            << "9. Wiedźmin\t10. Władca Pierścieni\t11. Podręcznik Szachowy\t12. Miniatury Matematyczne\t13. Szkoła Taktyki Szachowej\t14. Koszmar z Ulicy Wiązów\t15. Komiksy FNAF" << endl
            << "16. Żniwiarz\t17. Magiczne Drzewo\t18. Klub Podróżnika\t19. Pamiętnik 8-Bitowego Wojownika\t20. Podręczniki Minecraft\t21. Trylogia Husycka\t22. Outpost\t23. TFtP" << endl;
    }

    if (tryb == 2)
    {
        eror6zewn:
        int y;
        cout << "\n\t[1-23]" << endl;
        cin >> y;
        int z = y - 1;

        if (y < 1 or y > 23)
        {
            cout << "\nBłąd! Spróbuj ponownie." << endl;
            goto eror6zewn;
        }

        naglowek();
        size_t r = 0;
        while (r < serie[z].size())
        {
            wypisz(serie[z][r]);
            r = r + 1;
        }
    }
    
    int x = w2 - 1;
    size_t i = 0;

    if (tryb == 0)
    {
        while (i < serie.size())
        {
            size_t j = 0;
            while (j < serie[i].size())
            {
                if (x == serie[i][j])
                {
                    j = 0;
                    while (j < serie[i].size())
                    {
                        wypisz(serie[i][j]);
                        j = j + 1;
                    }
                }
                j = j + 1;
            }
            i = i + 1;
        }
    }
    
}

void przeczytane(float llinii, int tryb)
{
    float x6 = 0;
    int t = 0;
    int n = 0;
    int prog = 0;
    while (x6 < llinii)
    {
        if (ekstrakcja(x6, 6) == "TAK")
        {
            t = t + 1;
        }
        if (ekstrakcja(x6, 6) == "NIE")
        {
            n = n + 1;
            ostatnie.push_back(x6);
        }
        

        float progress = (x6 / (float)llinii) * 100; // aktualny procent ładowania

        while (prog * 10 <= progress)
        {
            cout << "Ładowanie...\t" << prog * 10 << "%" << endl;
            prog = prog + 1;
        }

        x6 = x6 + 1;
    }

    cout << "Ładowanie...\t100%" << endl;


    if (tryb == 0)
    {
        cout << "\n"
            << setw(16) << left << "Przeczytane"
            << setw(16) << left << "Nieprzeczytane"
            << "\n";

        cout << string(48, '-') << "\n"; // linia oddzielająca

        cout << setw(16) << left << t
            << setw(16) << left << n
            << "\n";
    }
}

void sortowaniestron(int llinii)
{
    vector<vector<int>> rozsortowane;
    int i = 0;

    while (i < llinii)
    {
        int id = string2int(ekstrakcja(i, 0));
        int strony = string2int(ekstrakcja(i, 5));
        rozsortowane.push_back({ id, strony });              // rozsortowane = {ID, l. stron}, {ID, l.stron}...
        i = i + 1;
    }

    sort(rozsortowane.begin(), rozsortowane.end(),
        [](const vector<int>& a, const vector<int>& b) {
            return a[1] > b[1];
        });

    ostatnie.clear();
    i = 0;
    while (i < rozsortowane.size())
    {
        ostatnie.push_back(rozsortowane[i][0]);
        i++;
    }
}

int main()
{
    setlocale(LC_ALL, "");
    SetConsoleOutputCP(1250);

    random_device rd;
    mt19937 gen(rd());

    ifstream zapychacz2("plik.txt");
    int llinii = 0;
    string zapychacz1;
    while (getline(zapychacz2, zapychacz1))
    {
        llinii++;
    }

    cout << "\n\n" << endl;

    cout << "\tBBBBBBB    IIIII  BBBBBBB   LL       IIIII   OOOOOOO  TTTTTTTTT EEEEEEE  KK  KK    AAAAA  \n";
    cout << "\tBB    BB    III   BB    BB  LL        III   OO     OO    TTT    EE       KK KK    AA   AA \n";
    cout << "\tBB    BB    III   BB    BB  LL        III   OO     OO    TTT    EE       KKKK    AA     AA\n";
    cout << "\tBBBBBBB     III   BBBBBBB   LL        III   OO     OO    TTT    EEEEEEE  KK KK   AAAAAAAAA\n";
    cout << "\tBB    BB    III   BB    BB  LL        III   OO     OO    TTT    EE       KK  KK  AA     AA\n";
    cout << "\tBB    BB    III   BB    BB  LL        III   OO     OO    TTT    EE       KK  KK  AA     AA\n";
    cout << "\tBBBBBBB    IIIII  BBBBBBB   LLLLLLL  IIIII   OOOOOOO     TTT    EEEEEEE  KK  KK  AA     AA v1.3\n";

    cout << "\n\n" << endl;

    cout << "Liczba skatalogowanych obiektów: " << llinii << endl;


start:
    ostatnie.resize(0);

    cout << "\n\nWybierz opcję : \n\n\t0 - Wyjdź.\n\t1 - Wyświetl wszystko.\n\t2 - Analiza ilości stron.\n\t3 - Podział gatunkowy.\n\t4 - Rodzaj fizyczny.\n\t5 - Wybierz książkę. "
        << "\n\t6 - Wykaz serii\n\t7 - Do przeczytania.\n\t8 - Losuj\n\t9 - Wyczyść.\n\t10 - Pomoc" << endl;
    int wybor;
    cin >> wybor;

    if (wybor < 0 or wybor > 10)
    {
        cout << "Błędny wybór. Spróbuj ponownie." << endl;
        goto start;
    }

    if (wybor == 0)
    {
        exit(0);
    }

    if (wybor == 1)
    {
        // Nagłówek tabeli
        cout << "\n"
            << setw(4) << left << "ID"
            << setw(80) << left << "Autor"
            << setw(84) << left << "Tytuł"
            << setw(24) << left << "Gatunek"
            << setw(32) << left << "Wydawnictwo"
            << setw(8) << left << "Strony"
            << setw(16) << left << "Przeczytane?"
            << setw(8) << left << "Typ"
            << "\n";

        cout << string(256, '-') << "\n"; // linia oddzielająca

        // Dane z pliku
        for (int x1 = 0; x1 < llinii; x1++)
        {
            cout << setw(4) << left << ekstrakcja(x1, 0)
                << setw(80) << left << ekstrakcja(x1, 1)
                << setw(84) << left << ekstrakcja(x1, 2)
                << setw(24) << left << ekstrakcja(x1, 3)
                << setw(32) << left << ekstrakcja(x1, 4)
                << setw(8) << left << ekstrakcja(x1, 5)
                << setw(16) << left << ekstrakcja(x1, 6)
                << setw(8) << left << ekstrakcja(x1, 7)
                << "\n";
        }
        cout << "\n";
        int w0;
        cout << "\nWybierz opcję:\t[1/2/3]\n\n1 - Ustawienia sortowania\t 2 - Szczegóły\t\t 0 - Powrót" << endl;
        cin >> w0;
        if (w0 == 0)
        {
            goto start;
        }
        if (w0 == 1)
        {
            punktsortu:
            cout << "\nWybierz opcję sortowania:" << endl;
            cout << "1 - ID\t 2 - Długość\t 0 - Powrót" << endl;
            int w4;
            cin >> w4;

            if (w4 == 0)
            {
                goto start;
            }
            if (w4 == 1)
            {
                for (int xnwm = 0; xnwm < llinii; xnwm++)
                {
                    cout << setw(4) << left << ekstrakcja(xnwm, 0)
                        << setw(80) << left << ekstrakcja(xnwm, 1)
                        << setw(84) << left << ekstrakcja(xnwm, 2)
                        << setw(24) << left << ekstrakcja(xnwm, 3)
                        << setw(32) << left << ekstrakcja(xnwm, 4)
                        << setw(8) << left << ekstrakcja(xnwm, 5)
                        << setw(16) << left << ekstrakcja(xnwm, 6)
                        << setw(8) << left << ekstrakcja(xnwm, 7)
                        << "\n";
                }
                goto punktsortu;
            }
            if (w4 == 2)
            {
                sortowaniestron(llinii);
            }


            naglowek();
            size_t i = 0;
            while (i < ostatnie.size())
            {
                wypisz(ostatnie[i]-1);
                i = i + 1;
            }
            goto punktsortu;
        }
        if (w0 == 2)
        {
            goto opcja5;
        }
    }
    if (wybor == 2)
    {
        cout << "\n\t\t\t\tSuma stron zgromadzonego zbioru: " << sumastron(llinii) << endl;
        cout << "\t\t\t\tSuma przeczytanych stron: " << sumaprzeczytanychstron(llinii) << endl;
        float avrg;
        float ssfloat = sumastron(llinii);
        float llinfloat = llinii;
        avrg = ssfloat/llinfloat;
        cout << "\t\t\t\tŚrednia długość książki w zbiorze: " << avrg << endl;

        goto start;
    }
    if (wybor == 3)
    {
        gatunek(llinii, 0);
        int XD;
        int w1;
        opcja3:

        cout << "\n\nWybierz kategorię.\t(1-17)" << endl;
        cout << "Aby wrócić, wpisz >>0<<.\n" << endl;
        cin >> w1;
        if (w1 == 0)
        {
            goto start;
        }
        if (w1 == 1)
        {
            gatunek(llinii, w1);
            size_t i = 0;

            // Nagłówek tabeli
            cout << "\n"
                << setw(4) << left << "ID"
                << setw(80) << left << "Autor"
                << setw(84) << left << "Tytuł"
                << setw(24) << left << "Gatunek"
                << setw(32) << left << "Wydawnictwo"
                << setw(8) << left << "Strony"
                << setw(16) << left << "Przeczytane?"
                << setw(8) << left << "Typ"
                << "\n";

            cout << string(256, '-') << "\n"; // linia oddzielająca

            while (i < ostatnie.size()) {
                // Dane z pliku
                
                cout << setw(4) << left << ekstrakcja(ostatnie[i], 0)
                     << setw(80) << left << ekstrakcja(ostatnie[i], 1)
                     << setw(84) << left << ekstrakcja(ostatnie[i], 2)
                     << setw(24) << left << ekstrakcja(ostatnie[i], 3)
                     << setw(32) << left << ekstrakcja(ostatnie[i], 4)
                     << setw(8) << left << ekstrakcja(ostatnie[i], 5)
                     << setw(16) << left << ekstrakcja(ostatnie[i], 6)
                     << setw(8) << left << ekstrakcja(ostatnie[i], 7)
                     << "\n";
                
                i = i + 1;
            }
            goto start;
        }
        if (w1 == 2)
        {
            gatunek(llinii, w1);
            size_t i = 0;

            // Nagłówek tabeli
            cout << "\n"
                << setw(4) << left << "ID"
                << setw(80) << left << "Autor"
                << setw(84) << left << "Tytuł"
                << setw(24) << left << "Gatunek"
                << setw(32) << left << "Wydawnictwo"
                << setw(8) << left << "Strony"
                << setw(16) << left << "Przeczytane?"
                << setw(8) << left << "Typ"
                << "\n";

            cout << string(256, '-') << "\n"; // linia oddzielająca

            while (i < ostatnie.size())
            {
                // Dane z pliku

                cout << setw(4) << left << ekstrakcja(ostatnie[i], 0)
                    << setw(80) << left << ekstrakcja(ostatnie[i], 1)
                    << setw(84) << left << ekstrakcja(ostatnie[i], 2)
                    << setw(24) << left << ekstrakcja(ostatnie[i], 3)
                    << setw(32) << left << ekstrakcja(ostatnie[i], 4)
                    << setw(8) << left << ekstrakcja(ostatnie[i], 5)
                    << setw(16) << left << ekstrakcja(ostatnie[i], 6)
                    << setw(8) << left << ekstrakcja(ostatnie[i], 7)
                    << "\n";

                i = i + 1;
            }
            goto start;
        }
        if (w1 == 3)
        {
            gatunek(llinii, w1);
            size_t i = 0;

            // Nagłówek tabeli
            cout << "\n"
                << setw(4) << left << "ID"
                << setw(80) << left << "Autor"
                << setw(84) << left << "Tytuł"
                << setw(24) << left << "Gatunek"
                << setw(32) << left << "Wydawnictwo"
                << setw(8) << left << "Strony"
                << setw(16) << left << "Przeczytane?"
                << setw(8) << left << "Typ"
                << "\n";

            cout << string(256, '-') << "\n"; // linia oddzielająca

            while (i < ostatnie.size())
            {
                // Dane z pliku

                cout << setw(4) << left << ekstrakcja(ostatnie[i], 0)
                    << setw(80) << left << ekstrakcja(ostatnie[i], 1)
                    << setw(84) << left << ekstrakcja(ostatnie[i], 2)
                    << setw(24) << left << ekstrakcja(ostatnie[i], 3)
                    << setw(32) << left << ekstrakcja(ostatnie[i], 4)
                    << setw(8) << left << ekstrakcja(ostatnie[i], 5)
                    << setw(16) << left << ekstrakcja(ostatnie[i], 6)
                    << setw(8) << left << ekstrakcja(ostatnie[i], 7)
                    << "\n";

                i = i + 1;
            }
            goto start;
        }
        if (w1 == 4)
        {
            gatunek(llinii, w1);
            size_t i = 0;

            // Nagłówek tabeli
            cout << "\n"
                << setw(4) << left << "ID"
                << setw(80) << left << "Autor"
                << setw(84) << left << "Tytuł"
                << setw(24) << left << "Gatunek"
                << setw(32) << left << "Wydawnictwo"
                << setw(8) << left << "Strony"
                << setw(16) << left << "Przeczytane?"
                << setw(8) << left << "Typ"
                << "\n";

            cout << string(256, '-') << "\n"; // linia oddzielająca

            while (i < ostatnie.size())
            {
                // Dane z pliku

                cout << setw(4) << left << ekstrakcja(ostatnie[i], 0)
                    << setw(80) << left << ekstrakcja(ostatnie[i], 1)
                    << setw(84) << left << ekstrakcja(ostatnie[i], 2)
                    << setw(24) << left << ekstrakcja(ostatnie[i], 3)
                    << setw(32) << left << ekstrakcja(ostatnie[i], 4)
                    << setw(8) << left << ekstrakcja(ostatnie[i], 5)
                    << setw(16) << left << ekstrakcja(ostatnie[i], 6)
                    << setw(8) << left << ekstrakcja(ostatnie[i], 7)
                    << "\n";

                i = i + 1;
            }
            goto start;
        }
        if (w1 == 5)
        {
            gatunek(llinii, w1);
            size_t i = 0;

            // Nagłówek tabeli
            cout << "\n"
                << setw(4) << left << "ID"
                << setw(80) << left << "Autor"
                << setw(84) << left << "Tytuł"
                << setw(24) << left << "Gatunek"
                << setw(32) << left << "Wydawnictwo"
                << setw(8) << left << "Strony"
                << setw(16) << left << "Przeczytane?"
                << setw(8) << left << "Typ"
                << "\n";

            cout << string(256, '-') << "\n"; // linia oddzielająca

            while (i < ostatnie.size())
            {
                // Dane z pliku

                cout << setw(4) << left << ekstrakcja(ostatnie[i], 0)
                    << setw(80) << left << ekstrakcja(ostatnie[i], 1)
                    << setw(84) << left << ekstrakcja(ostatnie[i], 2)
                    << setw(24) << left << ekstrakcja(ostatnie[i], 3)
                    << setw(32) << left << ekstrakcja(ostatnie[i], 4)
                    << setw(8) << left << ekstrakcja(ostatnie[i], 5)
                    << setw(16) << left << ekstrakcja(ostatnie[i], 6)
                    << setw(8) << left << ekstrakcja(ostatnie[i], 7)
                    << "\n";

                i = i + 1;
            }
            goto start;
        }
        if (w1 == 6)
        {
            gatunek(llinii, w1);
            size_t i = 0;

            // Nagłówek tabeli
            cout << "\n"
                << setw(4) << left << "ID"
                << setw(80) << left << "Autor"
                << setw(84) << left << "Tytuł"
                << setw(24) << left << "Gatunek"
                << setw(32) << left << "Wydawnictwo"
                << setw(8) << left << "Strony"
                << setw(16) << left << "Przeczytane?"
                << setw(8) << left << "Typ"
                << "\n";

            cout << string(256, '-') << "\n"; // linia oddzielająca

            while (i < ostatnie.size())
            {
                // Dane z pliku

                cout << setw(4) << left << ekstrakcja(ostatnie[i], 0)
                    << setw(80) << left << ekstrakcja(ostatnie[i], 1)
                    << setw(84) << left << ekstrakcja(ostatnie[i], 2)
                    << setw(24) << left << ekstrakcja(ostatnie[i], 3)
                    << setw(32) << left << ekstrakcja(ostatnie[i], 4)
                    << setw(8) << left << ekstrakcja(ostatnie[i], 5)
                    << setw(16) << left << ekstrakcja(ostatnie[i], 6)
                    << setw(8) << left << ekstrakcja(ostatnie[i], 7)
                    << "\n";

                i = i + 1;
            }
            goto start;
        }
        if (w1 == 7)
        {
            gatunek(llinii, w1);
            size_t i = 0;

            // Nagłówek tabeli
            cout << "\n"
                << setw(4) << left << "ID"
                << setw(80) << left << "Autor"
                << setw(84) << left << "Tytuł"
                << setw(24) << left << "Gatunek"
                << setw(32) << left << "Wydawnictwo"
                << setw(8) << left << "Strony"
                << setw(16) << left << "Przeczytane?"
                << setw(8) << left << "Typ"
                << "\n";

            cout << string(256, '-') << "\n"; // linia oddzielająca

            while (i < ostatnie.size())
            {
                // Dane z pliku

                cout << setw(4) << left << ekstrakcja(ostatnie[i], 0)
                    << setw(80) << left << ekstrakcja(ostatnie[i], 1)
                    << setw(84) << left << ekstrakcja(ostatnie[i], 2)
                    << setw(24) << left << ekstrakcja(ostatnie[i], 3)
                    << setw(32) << left << ekstrakcja(ostatnie[i], 4)
                    << setw(8) << left << ekstrakcja(ostatnie[i], 5)
                    << setw(16) << left << ekstrakcja(ostatnie[i], 6)
                    << setw(8) << left << ekstrakcja(ostatnie[i], 7)
                    << "\n";

                i = i + 1;
            }
            goto start;
        }
        if (w1 == 8)
        {
            gatunek(llinii, w1);
            size_t i = 0;

            // Nagłówek tabeli
            cout << "\n"
                << setw(4) << left << "ID"
                << setw(80) << left << "Autor"
                << setw(84) << left << "Tytuł"
                << setw(24) << left << "Gatunek"
                << setw(32) << left << "Wydawnictwo"
                << setw(8) << left << "Strony"
                << setw(16) << left << "Przeczytane?"
                << setw(8) << left << "Typ"
                << "\n";

            cout << string(256, '-') << "\n"; // linia oddzielająca

            while (i < ostatnie.size())
            {
                // Dane z pliku

                cout << setw(4) << left << ekstrakcja(ostatnie[i], 0)
                    << setw(80) << left << ekstrakcja(ostatnie[i], 1)
                    << setw(84) << left << ekstrakcja(ostatnie[i], 2)
                    << setw(24) << left << ekstrakcja(ostatnie[i], 3)
                    << setw(32) << left << ekstrakcja(ostatnie[i], 4)
                    << setw(8) << left << ekstrakcja(ostatnie[i], 5)
                    << setw(16) << left << ekstrakcja(ostatnie[i], 6)
                    << setw(8) << left << ekstrakcja(ostatnie[i], 7)
                    << "\n";

                i = i + 1;
            }
            goto start;
        }
        if (w1 == 9)
        {
            gatunek(llinii, w1);
            size_t i = 0;

            // Nagłówek tabeli
            cout << "\n"
                << setw(4) << left << "ID"
                << setw(80) << left << "Autor"
                << setw(84) << left << "Tytuł"
                << setw(24) << left << "Gatunek"
                << setw(32) << left << "Wydawnictwo"
                << setw(8) << left << "Strony"
                << setw(16) << left << "Przeczytane?"
                << setw(8) << left << "Typ"
                << "\n";

            cout << string(256, '-') << "\n"; // linia oddzielająca

            while (i < ostatnie.size())
            {
                // Dane z pliku

                cout << setw(4) << left << ekstrakcja(ostatnie[i], 0)
                    << setw(80) << left << ekstrakcja(ostatnie[i], 1)
                    << setw(84) << left << ekstrakcja(ostatnie[i], 2)
                    << setw(24) << left << ekstrakcja(ostatnie[i], 3)
                    << setw(32) << left << ekstrakcja(ostatnie[i], 4)
                    << setw(8) << left << ekstrakcja(ostatnie[i], 5)
                    << setw(16) << left << ekstrakcja(ostatnie[i], 6)
                    << setw(8) << left << ekstrakcja(ostatnie[i], 7)
                    << "\n";

                i = i + 1;
            }
            goto start;
        }
        if (w1 == 10)
        {
            gatunek(llinii, w1);
            size_t i = 0;

            // Nagłówek tabeli
            cout << "\n"
                << setw(4) << left << "ID"
                << setw(80) << left << "Autor"
                << setw(84) << left << "Tytuł"
                << setw(24) << left << "Gatunek"
                << setw(32) << left << "Wydawnictwo"
                << setw(8) << left << "Strony"
                << setw(16) << left << "Przeczytane?"
                << setw(8) << left << "Typ"
                << "\n";

            cout << string(256, '-') << "\n"; // linia oddzielająca

            while (i < ostatnie.size())
            {
                // Dane z pliku

                cout << setw(4) << left << ekstrakcja(ostatnie[i], 0)
                    << setw(80) << left << ekstrakcja(ostatnie[i], 1)
                    << setw(84) << left << ekstrakcja(ostatnie[i], 2)
                    << setw(24) << left << ekstrakcja(ostatnie[i], 3)
                    << setw(32) << left << ekstrakcja(ostatnie[i], 4)
                    << setw(8) << left << ekstrakcja(ostatnie[i], 5)
                    << setw(16) << left << ekstrakcja(ostatnie[i], 6)
                    << setw(8) << left << ekstrakcja(ostatnie[i], 7)
                    << "\n";

                i = i + 1;
            }
            goto start;
        }
        if (w1 == 11)
        {
            gatunek(llinii, w1);
            size_t i = 0;

            // Nagłówek tabeli
            cout << "\n"
                << setw(4) << left << "ID"
                << setw(80) << left << "Autor"
                << setw(84) << left << "Tytuł"
                << setw(24) << left << "Gatunek"
                << setw(32) << left << "Wydawnictwo"
                << setw(8) << left << "Strony"
                << setw(16) << left << "Przeczytane?"
                << setw(8) << left << "Typ"
                << "\n";

            cout << string(256, '-') << "\n"; // linia oddzielająca

            while (i < ostatnie.size())
            {
                // Dane z pliku

                cout << setw(4) << left << ekstrakcja(ostatnie[i], 0)
                    << setw(80) << left << ekstrakcja(ostatnie[i], 1)
                    << setw(84) << left << ekstrakcja(ostatnie[i], 2)
                    << setw(24) << left << ekstrakcja(ostatnie[i], 3)
                    << setw(32) << left << ekstrakcja(ostatnie[i], 4)
                    << setw(8) << left << ekstrakcja(ostatnie[i], 5)
                    << setw(16) << left << ekstrakcja(ostatnie[i], 6)
                    << setw(8) << left << ekstrakcja(ostatnie[i], 7)
                    << "\n";

                i = i + 1;
            }
            goto start;
        }
        if (w1 == 12)
        {
            gatunek(llinii, w1);
            size_t i = 0;

            // Nagłówek tabeli
            cout << "\n"
                << setw(4) << left << "ID"
                << setw(80) << left << "Autor"
                << setw(84) << left << "Tytuł"
                << setw(24) << left << "Gatunek"
                << setw(32) << left << "Wydawnictwo"
                << setw(8) << left << "Strony"
                << setw(16) << left << "Przeczytane?"
                << setw(8) << left << "Typ"
                << "\n";

            cout << string(256, '-') << "\n"; // linia oddzielająca

            while (i < ostatnie.size())
            {
                // Dane z pliku

                cout << setw(4) << left << ekstrakcja(ostatnie[i], 0)
                    << setw(80) << left << ekstrakcja(ostatnie[i], 1)
                    << setw(84) << left << ekstrakcja(ostatnie[i], 2)
                    << setw(24) << left << ekstrakcja(ostatnie[i], 3)
                    << setw(32) << left << ekstrakcja(ostatnie[i], 4)
                    << setw(8) << left << ekstrakcja(ostatnie[i], 5)
                    << setw(16) << left << ekstrakcja(ostatnie[i], 6)
                    << setw(8) << left << ekstrakcja(ostatnie[i], 7)
                    << "\n";

                i = i + 1;
            }
            goto start;
        }
        if (w1 == 13)
        {
            gatunek(llinii, w1);
            size_t i = 0;

            // Nagłówek tabeli
            cout << "\n"
                << setw(4) << left << "ID"
                << setw(80) << left << "Autor"
                << setw(84) << left << "Tytuł"
                << setw(24) << left << "Gatunek"
                << setw(32) << left << "Wydawnictwo"
                << setw(8) << left << "Strony"
                << setw(16) << left << "Przeczytane?"
                << setw(8) << left << "Typ"
                << "\n";

            cout << string(256, '-') << "\n"; // linia oddzielająca

            while (i < ostatnie.size())
            {
                // Dane z pliku

                cout << setw(4) << left << ekstrakcja(ostatnie[i], 0)
                    << setw(80) << left << ekstrakcja(ostatnie[i], 1)
                    << setw(84) << left << ekstrakcja(ostatnie[i], 2)
                    << setw(24) << left << ekstrakcja(ostatnie[i], 3)
                    << setw(32) << left << ekstrakcja(ostatnie[i], 4)
                    << setw(8) << left << ekstrakcja(ostatnie[i], 5)
                    << setw(16) << left << ekstrakcja(ostatnie[i], 6)
                    << setw(8) << left << ekstrakcja(ostatnie[i], 7)
                    << "\n";

                i = i + 1;
            }
            goto start;
        }
        if (w1 == 14)
        {
            gatunek(llinii, w1);
            size_t i = 0;

            // Nagłówek tabeli
            cout << "\n"
                << setw(4) << left << "ID"
                << setw(80) << left << "Autor"
                << setw(84) << left << "Tytuł"
                << setw(24) << left << "Gatunek"
                << setw(32) << left << "Wydawnictwo"
                << setw(8) << left << "Strony"
                << setw(16) << left << "Przeczytane?"
                << setw(8) << left << "Typ"
                << "\n";

            cout << string(256, '-') << "\n"; // linia oddzielająca

            while (i < ostatnie.size())
            {
                // Dane z pliku

                cout << setw(4) << left << ekstrakcja(ostatnie[i], 0)
                    << setw(80) << left << ekstrakcja(ostatnie[i], 1)
                    << setw(84) << left << ekstrakcja(ostatnie[i], 2)
                    << setw(24) << left << ekstrakcja(ostatnie[i], 3)
                    << setw(32) << left << ekstrakcja(ostatnie[i], 4)
                    << setw(8) << left << ekstrakcja(ostatnie[i], 5)
                    << setw(16) << left << ekstrakcja(ostatnie[i], 6)
                    << setw(8) << left << ekstrakcja(ostatnie[i], 7)
                    << "\n";

                i = i + 1;
            }
            goto start;
        }
        if (w1 == 15)
        {
            gatunek(llinii, w1);
            size_t i = 0;

            // Nagłówek tabeli
            cout << "\n"
                << setw(4) << left << "ID"
                << setw(80) << left << "Autor"
                << setw(84) << left << "Tytuł"
                << setw(24) << left << "Gatunek"
                << setw(32) << left << "Wydawnictwo"
                << setw(8) << left << "Strony"
                << setw(16) << left << "Przeczytane?"
                << setw(8) << left << "Typ"
                << "\n";

            cout << string(256, '-') << "\n"; // linia oddzielająca

            while (i < ostatnie.size())
            {
                // Dane z pliku

                cout << setw(4) << left << ekstrakcja(ostatnie[i], 0)
                    << setw(80) << left << ekstrakcja(ostatnie[i], 1)
                    << setw(84) << left << ekstrakcja(ostatnie[i], 2)
                    << setw(24) << left << ekstrakcja(ostatnie[i], 3)
                    << setw(32) << left << ekstrakcja(ostatnie[i], 4)
                    << setw(8) << left << ekstrakcja(ostatnie[i], 5)
                    << setw(16) << left << ekstrakcja(ostatnie[i], 6)
                    << setw(8) << left << ekstrakcja(ostatnie[i], 7)
                    << "\n";

                i = i + 1;
            }
            goto start;
        }
        if (w1 == 16)
        {
            gatunek(llinii, w1);
            size_t i = 0;

            // Nagłówek tabeli
            cout << "\n"
                << setw(4) << left << "ID"
                << setw(80) << left << "Autor"
                << setw(84) << left << "Tytuł"
                << setw(24) << left << "Gatunek"
                << setw(32) << left << "Wydawnictwo"
                << setw(8) << left << "Strony"
                << setw(16) << left << "Przeczytane?"
                << setw(8) << left << "Typ"
                << "\n";

            cout << string(256, '-') << "\n"; // linia oddzielająca

            while (i < ostatnie.size())
            {
                // Dane z pliku

                cout << setw(4) << left << ekstrakcja(ostatnie[i], 0)
                    << setw(80) << left << ekstrakcja(ostatnie[i], 1)
                    << setw(84) << left << ekstrakcja(ostatnie[i], 2)
                    << setw(24) << left << ekstrakcja(ostatnie[i], 3)
                    << setw(32) << left << ekstrakcja(ostatnie[i], 4)
                    << setw(8) << left << ekstrakcja(ostatnie[i], 5)
                    << setw(16) << left << ekstrakcja(ostatnie[i], 6)
                    << setw(8) << left << ekstrakcja(ostatnie[i], 7)
                    << "\n";

                i = i + 1;
            }
            goto start;
        }
        if (w1 == 17)
        {
            gatunek(llinii, w1);
            size_t i = 0;

            // Nagłówek tabeli
            cout << "\n"
                << setw(4) << left << "ID"
                << setw(80) << left << "Autor"
                << setw(84) << left << "Tytuł"
                << setw(24) << left << "Gatunek"
                << setw(32) << left << "Wydawnictwo"
                << setw(8) << left << "Strony"
                << setw(16) << left << "Przeczytane?"
                << setw(8) << left << "Typ"
                << "\n";

            cout << string(256, '-') << "\n"; // linia oddzielająca

            while (i < ostatnie.size())
            {
                // Dane z pliku

                cout << setw(4) << left << ekstrakcja(ostatnie[i], 0)
                    << setw(80) << left << ekstrakcja(ostatnie[i], 1)
                    << setw(84) << left << ekstrakcja(ostatnie[i], 2)
                    << setw(24) << left << ekstrakcja(ostatnie[i], 3)
                    << setw(32) << left << ekstrakcja(ostatnie[i], 4)
                    << setw(8) << left << ekstrakcja(ostatnie[i], 5)
                    << setw(16) << left << ekstrakcja(ostatnie[i], 6)
                    << setw(8) << left << ekstrakcja(ostatnie[i], 7)
                    << "\n";

                i = i + 1;
            }
            goto start;
        }
    }
    if (wybor == 4)
    {
        string tryb = "0";
        fizyczny(llinii, tryb);
        opcja4:

        cout << "\n\nWybierz tryb filtrowania.\t\t(Uwaga! Case Sensitive!)\n\t\t\t  [ks/ko/eb]" << endl;
        cout << "Aby wrócić, wpisz >>p<<.\n" << endl;

        cin >> tryb;

        if (tryb == "p")
        {
            goto start;
        }

        if (tryb == "ks")
        {
            fizyczny(llinii, tryb);
            size_t i = 0;

            // Nagłówek tabeli
            cout << "\n"
                << setw(4) << left << "ID"
                << setw(80) << left << "Autor"
                << setw(84) << left << "Tytuł"
                << setw(24) << left << "Gatunek"
                << setw(32) << left << "Wydawnictwo"
                << setw(8) << left << "Strony"
                << setw(16) << left << "Przeczytane?"
                << setw(8) << left << "Typ"
                << "\n";

            cout << string(256, '-') << "\n"; // linia oddzielająca

            while (i < ostatnie.size()) {
                // Dane z pliku

                cout << setw(4) << left << ekstrakcja(ostatnie[i], 0)
                    << setw(80) << left << ekstrakcja(ostatnie[i], 1)
                    << setw(84) << left << ekstrakcja(ostatnie[i], 2)
                    << setw(24) << left << ekstrakcja(ostatnie[i], 3)
                    << setw(32) << left << ekstrakcja(ostatnie[i], 4)
                    << setw(8) << left << ekstrakcja(ostatnie[i], 5)
                    << setw(16) << left << ekstrakcja(ostatnie[i], 6)
                    << setw(8) << left << ekstrakcja(ostatnie[i], 7)
                    << "\n";

                i = i + 1;
            }
            goto opcja4;
        }
        if (tryb == "ko")
        {
            fizyczny(llinii, tryb);
            size_t i = 0;

            // Nagłówek tabeli
            cout << "\n"
                << setw(4) << left << "ID"
                << setw(80) << left << "Autor"
                << setw(84) << left << "Tytuł"
                << setw(24) << left << "Gatunek"
                << setw(32) << left << "Wydawnictwo"
                << setw(8) << left << "Strony"
                << setw(16) << left << "Przeczytane?"
                << setw(8) << left << "Typ"
                << "\n";

            cout << string(256, '-') << "\n"; // linia oddzielająca

            while (i < ostatnie.size()) {
                // Dane z pliku

                cout << setw(4) << left << ekstrakcja(ostatnie[i], 0)
                    << setw(80) << left << ekstrakcja(ostatnie[i], 1)
                    << setw(84) << left << ekstrakcja(ostatnie[i], 2)
                    << setw(24) << left << ekstrakcja(ostatnie[i], 3)
                    << setw(32) << left << ekstrakcja(ostatnie[i], 4)
                    << setw(8) << left << ekstrakcja(ostatnie[i], 5)
                    << setw(16) << left << ekstrakcja(ostatnie[i], 6)
                    << setw(8) << left << ekstrakcja(ostatnie[i], 7)
                    << "\n";

                i = i + 1;
            }
            goto opcja4;
        }
        if (tryb == "eb")
        {
            fizyczny(llinii, tryb);
            size_t i = 0;

            // Nagłówek tabeli
            cout << "\n"
                << setw(4) << left << "ID"
                << setw(80) << left << "Autor"
                << setw(84) << left << "Tytuł"
                << setw(24) << left << "Gatunek"
                << setw(32) << left << "Wydawnictwo"
                << setw(8) << left << "Strony"
                << setw(16) << left << "Przeczytane?"
                << setw(8) << left << "Typ"
                << "\n";

            cout << string(256, '-') << "\n"; // linia oddzielająca

            while (i < ostatnie.size()) {
                // Dane z pliku

                cout << setw(4) << left << ekstrakcja(ostatnie[i], 0)
                    << setw(80) << left << ekstrakcja(ostatnie[i], 1)
                    << setw(84) << left << ekstrakcja(ostatnie[i], 2)
                    << setw(24) << left << ekstrakcja(ostatnie[i], 3)
                    << setw(32) << left << ekstrakcja(ostatnie[i], 4)
                    << setw(8) << left << ekstrakcja(ostatnie[i], 5)
                    << setw(16) << left << ekstrakcja(ostatnie[i], 6)
                    << setw(8) << left << ekstrakcja(ostatnie[i], 7)
                    << "\n";

                i = i + 1;
            }
            goto opcja4;
        }

        goto start;
    }
    if (wybor == 5)
    {
        opcja5:
        cout << "\nWybierz numer katalogu:\t\t(>>0<< aby powrócić.)\n\t";
        int w2;
        cin >> w2;

        if (w2 == 0)
        {
            goto start;
        }

        // Nagłówek tabeli
        cout << "\n"
            << setw(4) << left << "ID"
            << setw(80) << left << "Autor"
            << setw(84) << left << "Tytuł"
            << setw(24) << left << "Gatunek"
            << setw(32) << left << "Wydawnictwo"
            << setw(8) << left << "Strony"
            << setw(16) << left << "Przeczytane?"
            << setw(8) << left << "Typ"
            << "\n";

        cout << string(256, '-') << "\n"; // linia oddzielająca

        // Dane z pliku
        cout << setw(4) << left << ekstrakcja(w2-1, 0)
            << setw(80) << left << ekstrakcja(w2-1, 1)
            << setw(84) << left << ekstrakcja(w2-1, 2)
            << setw(24) << left << ekstrakcja(w2-1, 3)
            << setw(32) << left << ekstrakcja(w2-1, 4)
            << setw(8) << left << ekstrakcja(w2-1, 5)
            << setw(16) << left << ekstrakcja(w2-1, 6)
            << setw(8) << left << ekstrakcja(w2-1, 7)
            << "\n";
        cout << "\n";

        cout << "\n\n\n";

        cout << "\n"
            << "\nID                         |" << ekstraktordodatku(w2 - 1, 0) 
            << "\n                           |"
            << "\nKomentarz                  |" << ekstraktordodatku(w2 - 1, 1)
            << "\n                           |"
            << "\nSzczegóły                  |" << ekstraktordodatku(w2 - 1, 2)
            << "\n                           |"
            << "\nOcena                      |" << ekstraktordodatku(w2 - 1, 3)
            << "\n                           |"
            << "\nData ostatniego ukończenia |" << ekstraktordodatku(w2 - 1, 4) << "." << ekstraktordodatku(w2 - 1, 5) << "." << ekstraktordodatku(w2 - 1, 6)
            << "\n";

        cout << "\n Czy wyświetlić powiązane?\t[t/n]\t\t(Nie oznacza powrót.)" << endl;
        string czy;
        cin >> czy;
        if (czy == "t")
        {
            powiazania(w2, 0);
            goto opcja5;
        }
        if (czy == "n")
        {
            goto opcja5;
        }
    }
    if (wybor == 6)
    {
        powiazania(0, 1);
        powiazania(0, 2);
        goto start;
    }
    if (wybor == 7)
    {
        przeczytane(llinii, 0);
        size_t i = 0;

        naglowek();
        while (i < ostatnie.size())
        {
            wypisz(ostatnie[i]);
            i = i + 1;
        }

        cout << "\n\n" << endl;
        goto start;

    }
    if (wybor == 8)
    {
        uniform_int_distribution<> dis(0, llinii);
        int losowa_liczba = dis(gen);
        int w3;
        cout << "\nAby wybrać losowy wpis wprowadź - 1.\nAby wybrać nieprzeczytaną książkę wprowadź - 2" << endl;
        cin >> w3;
        if (w3 == 1)
        {
            naglowek();
            wypisz(losowa_liczba);
            goto start;
        }
        if (w3 == 2)
        {
            przeczytane(llinii, 1);
            size_t losrozmiar = ostatnie.size();
            uniform_int_distribution<> dis(0, losrozmiar);
            int los = dis(gen);
            naglowek();
            wypisz(ostatnie[los]);
            goto start;
        }
    }
    if (wybor == 9)
    {
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << endl;
        goto start;
    }
    if (wybor == 10)
    {
        cout << "\nWyświetl wszystko - wyświetla tabelę zawierającą całe zbiory zawarte w bibliotece. Można stąd przejść bezpośrednio do opcji 5." << endl;
        cout << "\nAnaliza ilości stron - wyświetla różne, matematyczne statystyki związane ze stronami zebranych książek." << endl;
        cout << "\nPodział gatunkowy - ukazuje tabelę ilościową zbiorów z podziałem na gatunki literackie. \nDzięki podfunkcji pozwala na zobaczenie tabeli monogatunkowej." << endl;
        cout << "\nRodzaj fizyczny - ukazuję podobną do poprzedniej tabelę z podziałem na fizyczne właściwości literatury. \nZawiera też równie podobną podfunkcje co poprzednia opcja." << endl;
        cout << "\nWybierz książkę - pozwala na zobaczenie szczegółów dotyczących konkretnej książki. Wymaga znajomości ID szukanego elementu!\nPodfunkcja pozwala zobaczyć powiązane wpisy w katalogu." << endl;
        cout << "\nWykaz serii - pokazuje listę serii, które znajdują się w bibliotece." << endl;
        cout << "\nDo przeczytania - wyświetla tabelę liczbową z przeczytanymi i nieprzeczytanymi książkami, oraz ukazuje wyspecyfikowaną listę tych nieukończonych." << endl;
        cout << "\nLosuj - pozwala wejść do losowego wpisu w bibliotece. Można wejść specyficznie do katalogu losowej nieprzeczytanej jeszcze książki." << endl;

        cout << "\nWyczyść - Przesuwa poprzednie komunikaty w górę." << endl;

        cout << "\n\nAby dodać wpis do bazy danych należy:\n\t-otworzyć plik.txt (w tym samym folderze co plik wykonywalny programu),\n\t-wpisać dane w nowej linii zachowując taki sam system jak poprzednie wpisy\n\t(numer|autor|nazwa książki|gatunek [Uwaga! Case Sensitive!]|wydawnictwo|liczba stron|status przeczytania książki|fizyczna forma [Książka/Komiks/Ebook][Uwaga! Case Sensitive]\n" << endl;
        cout << "UWAGA! >>plik.txt<<, oraz >>dodatek.txt<< MUSZĄ BYĆ FORMATOWANE W ANSI!" << endl;
        cout << "\n!!!UWAGA!!! POWIĄZANIA W OPCJI 5 MUSZĄ BYĆ USTAWIONE RĘCZNIE W KODZIE!" << endl;
        cout << "\nPlik >>dodatek.txt<< zawiera następujące informacje:\n\t[ID/komentarz/szczegółowe informacje/ocena autora programu/data ostatniego ukończenia(dzień|miesiąc|rok)]" << endl;

        cout << "\n\nNaciśnij >E< aby wyjść.";
        string xd;
        cin >> xd;
        goto start;

    }
}
