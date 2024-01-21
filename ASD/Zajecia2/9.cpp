#include <iostream>
#include <fstream>
using namespace std;

int sr;
bool wyszukiwanie_binarne(int l,int p, int szukana_liczba, int tab[])
{
    if(l<=p)
    {
        sr = (l+p)/2;
        if (tab[sr] == szukana_liczba) return true;
        else if (tab[sr] > szukana_liczba)
        {
            return wyszukiwanie_binarne(l,sr-1,szukana_liczba,tab);
        }
        else
        {
            return wyszukiwanie_binarne(sr+1,p,szukana_liczba,tab);
        }
    }
    return false;
}


int main()
{
    ifstream input("C:\\Users\\user\\Desktop\\Sem3\\ASD\\Zajecia2\\In0209.txt");
    ofstream output("C:\\Users\\user\\Desktop\\Sem3\\ASD\\Zajecia2\\Out0209.txt");

    int n;
    input >> n;
    int tab_nieposortowana[n],tab_posortowana[n];
    
    //wczytanie danych z pliku
    for(int i=0; i<n; i++)
    {
        input >> tab_nieposortowana[i];
    }
    cout << endl;
    for(int i=0; i<n; i++)
    {
        input >> tab_posortowana[i];
    }

    // algorytm
    int szukana,licznik=0;
    for(int i=0; i<n; i++)
    {
        szukana = tab_nieposortowana[i];
        if(wyszukiwanie_binarne(0,n-1,szukana,tab_posortowana) == true)
        {
            output << szukana << " ";
            licznik++;
        }
    }
    output << endl << licznik;
}