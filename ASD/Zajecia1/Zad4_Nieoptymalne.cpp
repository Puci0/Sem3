#include <iostream>
#include <fstream>
using namespace std;

void sortowaniePar(int Tab[], int n) {
    for (int i = 0; i < n; i += 2) {
        for (int j = i + 2; j < n; j += 2) {
            if (Tab[i] > Tab[j]) {
                int temp1 = Tab[i];
                Tab[i] = Tab[j];
                Tab[j] = temp1;

                int temp2 = Tab[i + 1];
                Tab[i + 1] = Tab[j + 1];
                Tab[j + 1] = temp2;
            }
        }
    }
}

int main() {
    ifstream plik("C:\\Users\\User\\CLionProjects\\Algorytmy1\\In0104.txt");
    ofstream output("C:\\Users\\User\\CLionProjects\\Algorytmy1\\Out0104.txt");
    int n,m;
    plik>>n>>m;
    int rozmiar = m*4+2;
    int *tab = new int[rozmiar]; // int tab[rozmiar]
    int i=0;
    while(plik>>tab[i])
    {
        //cout << tab[i] << " ";
        i++;
    }

    int tablica_y[m*2];
    int licznik = 0;
    int szerokosc_korytarza = n;
    int ilosc_wspolrzednych = m*2;
    //cout << "Tablica y: ";
    for (int i = 1; i < rozmiar; i += 2) {
        tablica_y[licznik] = tab[i];
        //cout << tablica_y[licznik] << " ";
        licznik++;
    }

    sortowaniePar(tablica_y, ilosc_wspolrzednych);

    //cout << endl << "Posortowana tablica: ";
    //for (int i = 0; i < ilosc_wspolrzednych; i++) {
    //cout << tablica_y[i] << " ";
    //}

    //algorytm

    int iloscPasm = 0;
    int poprzedniaPozycja = 0;
    const int maxLiczbaPasm = szerokosc_korytarza * 2;
    int bezpiecznePasma[maxLiczbaPasm];

    for (int i = 0; i < ilosc_wspolrzednych; i += 2) {
        int y1 = tablica_y[i];
        int y2 = tablica_y[i + 1];

        if (y1 > poprzedniaPozycja) {
            // Dodaj bezpieczne pasmo
            bezpiecznePasma[iloscPasm] = poprzedniaPozycja;
            iloscPasm++;
            bezpiecznePasma[iloscPasm] = y1;
            iloscPasm++;
        }

        poprzedniaPozycja = y2;
    }

    if (poprzedniaPozycja < szerokosc_korytarza) {
        bezpiecznePasma[iloscPasm] = poprzedniaPozycja;
        iloscPasm++;
        bezpiecznePasma[iloscPasm] = szerokosc_korytarza;
        iloscPasm++;
    }

    // wyniki
    //cout << endl;
    for (int i = 0; i < iloscPasm; i += 2) {
        output << "(" << bezpiecznePasma[i] << ", " << bezpiecznePasma[i + 1] << ")\n";
    }

    output << iloscPasm / 2;
}
