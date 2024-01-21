#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <algorithm>

using namespace std;

struct Krawedz {
    int zrodlowy_wierzcholek;
    int docelowy_wierzcholek;
    int waga;

    Krawedz(int zrodlowy, int docelowy, int w) : zrodlowy_wierzcholek(zrodlowy), docelowy_wierzcholek(docelowy), waga(w) {}
};

void dodajKrawedz(vector<vector<Krawedz>>& lista, int zrodlowy_wierzcholek, int docelowy_wierzcholek, int waga) {
    Krawedz krawedz1(zrodlowy_wierzcholek, docelowy_wierzcholek, waga);
    lista[zrodlowy_wierzcholek - 1].push_back(krawedz1);
}

void heapify(vector<Krawedz>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left].waga > arr[largest].waga) {
        largest = left;
    }

    if (right < n && arr[right].waga > arr[largest].waga) {
        largest = right;
    }

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heap_sort(vector<Krawedz>& arr) {
    int n = arr.size();

    // Budujemy kopiec (heap)
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // Wydobywamy elementy z kopca
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

void JarnikPrim(const std::vector<vector<Krawedz>>& lista, int ilosc_wierzcholkow) {
    vector<Krawedz> Q;
    vector<int> MDR_Wierzcholki;
    vector<Krawedz> MDR_Krawedzie;
    int sumaWag = 0;

    // Tworzymy sekwencję wszystkich krawędzi grafu
    for (int u = 0; u < ilosc_wierzcholkow; ++u) {
        for (const Krawedz& krawedz : lista[u]) {
            Q.push_back(krawedz);
        }
    }

    heap_sort(Q);

    // Wybieramy startowy wierzchołek
    int startowyWierzcholek = 1;
    MDR_Wierzcholki.push_back(startowyWierzcholek);

    // Generujemy MDR
    for (int i = 1; i < ilosc_wierzcholkow; ++i) {
        for (const Krawedz& krawedz : Q) {
            int u = krawedz.zrodlowy_wierzcholek;
            int v = krawedz.docelowy_wierzcholek;

            // Sprawdzamy warunki
            bool u_in_W = find(MDR_Wierzcholki.begin(), MDR_Wierzcholki.end(), u) != MDR_Wierzcholki.end();
            bool v_not_in_W = find(MDR_Wierzcholki.begin(), MDR_Wierzcholki.end(), v) == MDR_Wierzcholki.end();

            if (u_in_W && v_not_in_W) {
                // Dodajemy krawędź do MDR, aktualizujemy zbiór wierzchołków i sumujemy wagi
                MDR_Krawedzie.push_back(krawedz);
                MDR_Wierzcholki.push_back(v);
                sumaWag += krawedz.waga;
                break;
            }
        }
    }

    // Wyświetlamy krawędzie w MDR
    ofstream output("C:\\Users\\User\\Desktop\\Sem3\\ASD\\Zajecia3\\Out0304.txt");
    for (const Krawedz& krawedz : MDR_Krawedzie) {
        output << krawedz.zrodlowy_wierzcholek << " " << krawedz.docelowy_wierzcholek << " [" << krawedz.waga << "], ";
    }
    output << endl << sumaWag;
}
int main() {
    ifstream input("C:\\Users\\User\\Desktop\\Sem3\\ASD\\Zajecia3\\In0304.txt");
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

    JarnikPrim(lista, ilosc_wierzcholkow);

    return 0;
}