#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <limits>
using namespace std;

struct Graf {
    int docelowy_wierzcholek;
    mutable int waga;
};

struct dane {
    int dystans;
    int poprzednik;
};

void dodajKrawedz(vector<vector<Graf>>& lista, int zrodlowy_wierzcholek, int docelowy_wierzcholek, int waga) {
    Graf krawedz;
    krawedz.docelowy_wierzcholek = docelowy_wierzcholek;
    krawedz.waga = waga;
    lista[zrodlowy_wierzcholek].push_back(krawedz);
}

const int INFINITE_WEIGHT = numeric_limits<int>::max()/2;
dane* BellmanFordDlaDodatkowegoPunktu(int** macierz, int n, int start) {
    dane* tab = new dane[n];
    for (int i = 0; i < n; i++) {
        tab[i].dystans = INFINITE_WEIGHT;
        tab[i].poprzednik = -1;
    }
    tab[start].dystans = 0;
    for (int k = 0; k < n - 1; k++) {
        for (int u = 0; u < n-1; u++) {
            for (int v = 0; v < n-1; v++) {
                if (macierz[u][v] != 0 && tab[v].dystans > tab[u].dystans + macierz[u][v]) {
                    tab[v].dystans = tab[u].dystans + macierz[u][v];
                    tab[v].poprzednik = u;
                }
            }
        }
    }
    return tab;
}

dane* BellmanFordDlaReszty(int** macierz, int n, int start) {
    dane* tab = new dane[n];
    for (int i = 0; i < n; i++) {
        tab[i].dystans = numeric_limits<int>::max();
        tab[i].poprzednik = -1;
    }
    tab[start].dystans = 0;

    for (int k = 0; k < n - 1; k++) {
        for (int u = 0; u < n; u++) {
            for (int v = 0; v < n; v++) {
                if (macierz[u][v] != INFINITE_WEIGHT &&
                    tab[v].dystans > tab[u].dystans + macierz[u][v]) {
                    tab[v].dystans = tab[u].dystans + macierz[u][v];
                    tab[v].poprzednik = u;
                }
            }
        }
    }
    return tab;
}

void Dijkstra(vector<vector<Graf>>& lista_incydencji, int start, int liczba_wierzcholkow, dane* tab,ofstream& output) {
    const int INFINITY = numeric_limits<int>::max();
    vector<int> dystanse(liczba_wierzcholkow, INFINITY);
    vector<bool> odwiedzone(liczba_wierzcholkow, false);

    dystanse[start] = 0;

    for (int count = 0; count < liczba_wierzcholkow - 1; ++count) {
        int u = -1;
        int minDistance = INFINITY;

        // Wybór wierzchołka o najmniejszym dystansie
        for (int v = 0; v < liczba_wierzcholkow; ++v) {
            if (!odwiedzone[v] && dystanse[v] <= minDistance) {
                minDistance = dystanse[v];
                u = v;
            }
        }

        // Oznacz wybrany wierzchołek jako odwiedzony
        odwiedzone[u] = true;

        // Aktualizacja dystansów dla sąsiadujących wierzchołków
        for (const auto& krawedz : lista_incydencji[u]) {
            int v = krawedz.docelowy_wierzcholek;
            int waga = krawedz.waga;

            if (!odwiedzone[v] && dystanse[u] != INFINITY && dystanse[v] > dystanse[u] + waga) {
                dystanse[v] = dystanse[u] + waga;
                tab[v].dystans = dystanse[v];
                tab[v].poprzednik = u;
            }
        }
    }

    for (int i = 1; i < liczba_wierzcholkow; ++i) {
        if (dystanse[i] == INFINITY) {
            output << "INF ";
        } else {
            output << dystanse[i] << " ";
        }
    }

}

void UzupelnienieListy(vector<vector<Graf>>& lista_incydencji,vector<vector<Graf>>& lista_incydencji2,int liczba_wierzcholkow, ifstream& plik,string linia)
{
    for(int j = 1; j < liczba_wierzcholkow; j++) {
        dodajKrawedz(lista_incydencji, 0, j, 0);
    }

    //dodanie krawedzi do list
    int docelowy_wierzcholek, waga, x=0,i=1;
    while (getline(plik, linia)) {
        istringstream line(linia);
        while (line >> docelowy_wierzcholek >> waga) {
            dodajKrawedz(lista_incydencji, i, docelowy_wierzcholek, waga);
            dodajKrawedz(lista_incydencji2, x, docelowy_wierzcholek, waga);
        }
        i++;
        x++;
    }
}

void Johnson(int** macierz, int** macierz2, int liczba_wierzcholkow,vector<vector<Graf>>& lista_incydencji,vector<vector<Graf>>& lista_incydencji2,ofstream& output)
{
    //pierwsza macierz
    for (int i = 0; i < liczba_wierzcholkow; i++) {
        macierz[i] = new int[liczba_wierzcholkow];
        for (int j = 0; j < liczba_wierzcholkow; j++) {
            macierz[i][j] = INFINITE_WEIGHT;
        }
    }
    for (int i = 0; i < liczba_wierzcholkow; i++) {
        for (const auto& krawedz : lista_incydencji[i]) {
            macierz[i][krawedz.docelowy_wierzcholek] = krawedz.waga;
        }
    }
    int s = 0;
    dane* tab = BellmanFordDlaReszty(macierz, liczba_wierzcholkow, s);
    output << "[";
    for (int i = 0; i < liczba_wierzcholkow; i++) {
        output << tab[i].dystans << " ";
    }
    output << "]";

    //druga macierz
    for (int i = 0; i < liczba_wierzcholkow-1; i++) {
        macierz2[i] = new int[liczba_wierzcholkow];
        for (int j = 0; j < liczba_wierzcholkow-1; j++) {
            macierz2[i][j] = 0;
        }
    }
    for (int i = 0; i < liczba_wierzcholkow-1; i++) {
        for (const auto& krawedz : lista_incydencji2[i]) {
            macierz2[i][krawedz.docelowy_wierzcholek-1] = krawedz.waga;
        }
    }

    //zmiana wag na nieujemne
    for (int u = 0; u < liczba_wierzcholkow; u++) {
        for (const auto& krawedz : lista_incydencji[u]) {
            int v = krawedz.docelowy_wierzcholek;
            if (macierz[u][v] != INFINITE_WEIGHT) {
                krawedz.waga = krawedz.waga + tab[u].dystans - tab[v].dystans;
            }
        }
    }
    output << endl;
    for (int i = 0; i < liczba_wierzcholkow; ++i) {
        output << "[" << i << "]  ";
        for (const auto& krawedz : lista_incydencji[i]) {
            output << "(" << krawedz.docelowy_wierzcholek << ", " << krawedz.waga << ") ";
        }
        output << endl;
    }

    //djikstry
    for(int start=1;start<liczba_wierzcholkow;start++)
    {
        dane* tab2 = BellmanFordDlaDodatkowegoPunktu(macierz2, liczba_wierzcholkow, start-1);
        output << "DELTA^[" << start << "] [";
        Dijkstra(lista_incydencji,start,liczba_wierzcholkow,tab,output);
        output << "], D["<<start<<"] [";
        for (int i = 0; i < liczba_wierzcholkow-1; i++) {
            if(tab2[i].dystans >1000000)
            {
                output << "INF ";
            }else{
                output << tab2[i].dystans << " ";
            }
        }
        output << "]\n";
    }
}


int main() {
    ifstream plik("C:\\Users\\User\\Desktop\\Sem3\\ASD\\Zajecia4\\input.txt");
    ofstream output("C:\\Users\\User\\Desktop\\Sem3\\ASD\\Zajecia4\\output.txt");
    string linia;
    getline(plik,linia);
    istringstream line(linia);
    int liczba_wierzcholkow;
    line >> liczba_wierzcholkow;
    liczba_wierzcholkow+=1;
    vector<vector<Graf>> lista_incydencji(liczba_wierzcholkow);
    vector<vector<Graf>> lista_incydencji2(liczba_wierzcholkow);

    UzupelnienieListy(lista_incydencji,lista_incydencji2,liczba_wierzcholkow,plik,linia);

    int** macierz = new int*[liczba_wierzcholkow];
    int** macierz2 = new int*[liczba_wierzcholkow];

    Johnson(macierz,macierz2,liczba_wierzcholkow,lista_incydencji,lista_incydencji2,output);

}