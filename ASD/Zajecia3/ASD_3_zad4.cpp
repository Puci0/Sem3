#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

struct Krawedz{
    int zrodlowy_wierzcholek;
    int docelowy_wierzcholek;
    int waga;
};

void dodajKrawedz(vector<vector<Krawedz>>& lista,int zrodlowy_wierzcholek,int docelowy_wierzcholek,int waga)
{
    Krawedz krawedz1;
    krawedz1.docelowy_wierzcholek = docelowy_wierzcholek;
    krawedz1.waga = waga;
    lista[zrodlowy_wierzcholek - 1].push_back(krawedz1);

}

void wyswietlListe(const vector<vector<Krawedz>>& lista)
{
    int liczbaWierzcholkow = lista.size();
    for(int i=0;i<liczbaWierzcholkow;i++)
    {
        cout << i + 1 << ": ";
        for(const Krawedz& krawedz: lista[i])
        {
            cout << krawedz.docelowy_wierzcholek << " " << krawedz.waga << " ";
        }
        cout << endl;
    }
}

ofstream output("Out0304.txt");

void JarnikPrim(const vector<vector<Krawedz>>& lista, int ilosc_wierzcholkow) {
    vector<bool> odwiedzone(ilosc_wierzcholkow, false); // Odwiedzone wierzchołki
    vector<Krawedz> MDR; // Minimalne Drzewo Rozpinające

    vector<pair<int, pair<int, int>>> Q; // Kolejka krawędzi z wagami (waga, (u, v)))
    // Tworzenie sekwencji wszystkich krawędzi grafu wraz z ich wagami
    for (int u = 0; u < ilosc_wierzcholkow; ++u) {
        for (const Krawedz& krawedz : lista[u]) {
            int v = krawedz.docelowy_wierzcholek - 1;
            int waga = krawedz.waga;
            Q.push_back({waga, {u, v}});
        }
    }

    // Sortowanie krawędzi względem ich wag
    sort(Q.begin(), Q.end());

    // Wybierz startowy wierzchołek (może być dowolny)
    int startowyWierzcholek = 0;
    odwiedzone[startowyWierzcholek] = true;

    // Pętla główna - budowanie MDR
    for (int i = 1; i < ilosc_wierzcholkow; ++i) {
        for (const auto& krawedz : Q) {
            int waga = krawedz.first;
            int u = krawedz.second.first;
            int v = krawedz.second.second;

            if (odwiedzone[u] && !odwiedzone[v]) {
                MDR.push_back({u + 1, v + 1, waga}); // Dodaj krawędź do MDR
                odwiedzone[v] = true; // Oznacz wierzchołek jako odwiedzony
                break;
            }
        }
    }
    int ilosc_wag = 0;
    for (const auto& krawedz : MDR) {
        output << krawedz.zrodlowy_wierzcholek << " " << krawedz.docelowy_wierzcholek << " [" << krawedz.waga << "], ";
        ilosc_wag += krawedz.waga;
    }
    output << endl << ilosc_wag;
}

int main() {
    ifstream input("In0304.txt");
    int ilosc_wierzcholkow;
    input >> ilosc_wierzcholkow;
    vector<vector<Krawedz>> lista(ilosc_wierzcholkow);
    string linia;
    input.ignore();
    for (int i = 1; i <= ilosc_wierzcholkow; i++) {
        if (getline(input, linia)) {
            int ilosc_liczb_w_linii = 0;
            istringstream stream(linia);
            int liczba;
            while (stream >> liczba) {
                ilosc_liczb_w_linii++;
            }

            stream.clear();
            stream.seekg(0, ios::beg);
            for (int j = 0; j < ilosc_liczb_w_linii; j += 2) {
                int zrodlowy_wierzcholek = i;
                int docelowy_wierzcholek, waga;

                stream >> docelowy_wierzcholek;
                stream >> waga;

                dodajKrawedz(lista, zrodlowy_wierzcholek, docelowy_wierzcholek, waga);
            }
        }
    }
//    wyswietlListe(lista);
//    cout << endl;
    JarnikPrim(lista, ilosc_wierzcholkow);
}