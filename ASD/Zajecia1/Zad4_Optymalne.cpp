#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{

    ifstream plik("C:\\Users\\user\\CLionProjects\\ASD\\In0104.txt");
    ofstream output("C:\\Users\\user\\CLionProjects\\ASD\\Out0104.txt");
    int szerokosc_korytarza, ilosc_pretow;
    plik >> szerokosc_korytarza >> ilosc_pretow;
    int *y_coords = new int[szerokosc_korytarza+1] {};
    for (int i = 0; i < szerokosc_korytarza + 1; i++) {
        y_coords[i] = 0;
    }
    for (int i = 0; i < ilosc_pretow; i++) {
        int x1, y1, x2, y2;
        plik >> x1 >> y1 >> x2 >> y2;
        if(y2 > y_coords[y1])
        {
            y_coords[y1] = y2;
        }
    }
    plik.close();

    int poczatek_preta = -1;
    int koniec_preta = -1;
    vector<int> niebezpieczne_pasma;
    for(int i = 0;i <= szerokosc_korytarza; i ++)
    {
        if(y_coords[i] != 0)
        {
            // czy nowy pret jest dluzszy od tego ktory sie juz zaczal
            if(poczatek_preta != -1 && y_coords[i]>koniec_preta && koniec_preta != -1)
            {
                koniec_preta = y_coords[i];
            }

            if(poczatek_preta == -1)
            {
                if(i == y_coords[i])
                {
                    niebezpieczne_pasma.push_back(i);
                    niebezpieczne_pasma.push_back(i);
                }
                else
                {
                    poczatek_preta = i;
                    koniec_preta = y_coords[i];
                    niebezpieczne_pasma.push_back(poczatek_preta);
                }
            }
        }
        // sprawdzamy czy pret sie konczy nie wazne czy zaczyna sie nowy czy nie
        if(poczatek_preta != -1 && i == koniec_preta)
        {
            niebezpieczne_pasma.push_back(koniec_preta);
            poczatek_preta = -1;
            koniec_preta = -1;
        }
    }

//    for(int i =0;i<niebezpieczne_pasma.size();i++)
//    {
//        cout << niebezpieczne_pasma[i] << " ";
//    }

// bezpieczne pasma
    int licznik = 0;
    if(niebezpieczne_pasma[0] != 0)
    {
        output << "(0," << niebezpieczne_pasma[0] << ")" << endl;
        licznik++;
    }
    for(int i = 2;i < niebezpieczne_pasma.size(); i+=2)
    {
        //cout << niebezpieczne_pasma[i-1] << " " << niebezpieczne_pasma[i] << " ";
        output << "(" << niebezpieczne_pasma[i-1] << "," << niebezpieczne_pasma[i] << ")" << endl;
        licznik++;
    }
    if(niebezpieczne_pasma[niebezpieczne_pasma.size()-1] != 11)
    {
        output << "(" << niebezpieczne_pasma[niebezpieczne_pasma.size()-1] << "," << szerokosc_korytarza << ")" << endl;
    }
    output << licznik;
}


















