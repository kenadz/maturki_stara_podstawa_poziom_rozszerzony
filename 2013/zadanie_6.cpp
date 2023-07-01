#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

/*
5736

= 6 * 1 + 3 * 8 + 7 * 64 + 5 * 512


stoi(<string, z jakiego konwerujemy>, <od jakiego miejsca zaczynamy>, <jaki system liczbowy>)

d) Wypisz wszystkie liczby, których zapis dziesiętny jest palindromem
W wyniku dla każdej takiej liczby wypisz jej zapis ósemkowy i dziesiętny.

e) wypisz wszystkie lizcby, które po przekonwertowaniu na dziesiętny są doskonałe
W wyniku dla każdej takiej liczby wypisz jej zapis ósemkowy i dziesiętny.

f) Wypisz wszystkie liczby, które są w zapisie dziesiętnym równe sumie silni swoich cyfr.
54352
5! + 4! + 3! + 5! + 2! = 120 + 24 + 6 + 120 + 2


    pair<int, string> para;
    para.first = 10;
    para.second = "abc";
    cout << para.first << endl;

    make_pair(dana1, dana2) - tworzy parę o takich typach, jakie zostały podane jako parametry


*/

int silnia(int liczba)
{
    int wynik = 1;
    for(int i = 2; i <= liczba ; i++)
    {
        wynik *= i;
    }
    return wynik;
}

int suma_silni_cyfr(string liczba)
{
    int suma = 0;
    for(int i = 0; i < liczba.length(); i++)
    {
        suma += silnia(liczba[i] - '0');
    }
    return suma;
}

int suma_dzielnikow(int liczba)
{
    int suma = 1;
    for (int i = 2; i <= liczba / 2; i++)
    {
        if (liczba % i == 0)
        {
            suma += i;
        }
    }
    return suma;
}

int suma_dzielnikow2(int liczba)
{
    int suma = 1;
    int i = 2;
    while (i * i < liczba)
    {
        if (liczba % i == 0)
        {
            suma += i;
            suma += liczba/i;
        }
        i++;
    }
    if (i * i == liczba) // czy i jest pierwiastkiem liczby
    {
        suma += i;
    }

    return suma;
}

/*
100
1
2 50
4 25
5 20
10


10000 * 10000 = 100 000 000
*/

bool czy_palindrom(string liczba)
{
    for (int i = 0; i < liczba.length() / 2; i++)
    {
        if (liczba[i] != liczba[liczba.size() - i - 1])
        {
            return false;
        }
    }
    return true;
}

int osemkowy_dziesietny(string liczba8)
{
    int liczba10 = 0;
    int wartosc = 1;
    for (int i = liczba8.size() - 1; i >= 0; i--)
    {
        liczba10 += (liczba8[i] - '0') * wartosc;
        wartosc *= 8;
    }
    return liczba10;
}

bool czy_rosnace(string liczba)
{
    for (int i = 0; i < liczba.size() - 1; i++)
    {
        if (liczba[i] > liczba[i + 1])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    string tekst = "aBCdefGH123";
    /*
    for(auto &znak : tekst)
    {
        if(znak >= 'A' && znak <= 'Z')
        {
            znak += 'a' - 'A';
        }
    }
    */
    for(auto &znak : tekst)
    {
        if(znak >= 'a' && znak <= 'z')
        {
            znak -= 'a' - 'A';
        }
    }



    cout << tekst;


    return 0;
    fstream plik("DANE_PR/dane.txt", ios::in);

    if (!(plik.is_open() && plik.good()))
    {
        cout << "BLad";
        return -1;
    }

    string liczba8;

    vector<string> liczby;

    while (plik >> liczba8)
    {
        liczby.push_back(liczba8);
    }
    plik.close();
    int liczby_rowne_osemkowy = 0;
    int liczby_rowne_dziesietny = 0;
    int liczby_rosnace = 0;
    string najwieksza;
    string najmniejsza = "2000001";

    vector<pair<string, string>> palindromy;
    vector<pair<int, string>> doskonale;
    vector<int> suma_silni;

    for (auto liczba : liczby)
    {
        if (liczba.front() == liczba.back())
        {
            liczby_rowne_osemkowy++;
        }

        string dziesietny = to_string(osemkowy_dziesietny(liczba));

        int liczba_10 = stoi(liczba, 0, 8);
        if (dziesietny.front() == dziesietny.back())
        {
            liczby_rowne_dziesietny++;
        }

        if (czy_rosnace(liczba))
        {
            liczby_rosnace++;
            if (liczba_10 > osemkowy_dziesietny(najwieksza))
            {
                najwieksza = liczba;
            }

            if (liczba_10 < osemkowy_dziesietny(najmniejsza))
            {
                najmniejsza = liczba;
            }
        }

        if (czy_palindrom(dziesietny))
        {
            palindromy.push_back(make_pair(dziesietny, liczba));
        }

        if (suma_dzielnikow2(liczba_10) == liczba_10)
        {
            doskonale.push_back(make_pair(liczba_10, liczba));
        }

        if(suma_silni_cyfr(dziesietny) == liczba_10)
        {
            suma_silni.push_back(liczba_10);
        }
    }

    plik.open("wyniki6.txt", ios::out);

    plik << "a) " << liczby_rowne_osemkowy << endl;
    plik << "b) " << liczby_rowne_dziesietny << endl;
    plik << "c) " << liczby_rosnace << endl;
    plik << najwieksza << endl;
    plik << najmniejsza << endl;
    plik << "e) " << endl;
    for (auto para : palindromy)
    {
        plik << para.second << " " << para.first << endl;
    }
    plik << "f) " << endl;
    for (auto para : doskonale)
    {
        plik << para.second << " " << para.first << endl;
    }
    plik << "g) " << endl;
    for(auto x : suma_silni)
    {
        plik << x << endl;
    }
    plik.close();
}