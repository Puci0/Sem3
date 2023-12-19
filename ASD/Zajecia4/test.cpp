#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <limits>
using namespace std;

struct dane {
    int dystans;
    int poprzednik;
};

void wypiszdane(int wezel, dane d) {
    cout << wezel << "\t" << d.dystans << "\t";
    if (d.poprzednik == -1) {
        cout << "Brak poprzednika" << endl;
    } else {
        cout << d.poprzednik << endl;
    }
}

dane* BellmanFord(int** macierz, int n, int start) {
    dane* tab = new dane[n];
    for (int i = 0; i < n; i++) {
        tab[i].dystans = 500000;
        tab[i].poprzednik = -1;
    }
    tab[start].dystans = 0;
    for (int k = 0; k < n - 1; k++) {
        for (int u = 0; u < n; u++) {
            for (int v = 0; v < n; v++) {
                if (macierz[u][v] != 0 &&
                    tab[v].dystans > tab[u].dystans + macierz[u][v]) {
                    tab[v].dystans = tab[u].dystans + macierz[u][v];
                    tab[v].poprzednik = u;
                }
            }
        }
    }
    return tab;
}

int main() {
    int n, s;
    cout << "Ile wierzcholkow ma graf?\n n = ";
    cin >> n;
    cout << "Podaj wierzcholek poczatkowy\n s = ";
    cin >> s;
    cout << "Podaj macierz:" << endl;
    int** macierz = new int*[n];
    for (int i = 0; i < n; i++) {
        macierz[i] = new int[n];
        for (int j = 0; j < n; j++)
            cin >> macierz[i][j];
    }
    dane* tab = BellmanFord(macierz, n, s);
    cout << "Wezel\tOdl.\tPoprzednik" << endl;
    for (int i = 0; i < n; i++)
        wypiszdane(i, tab[i]);
    system("pause");
    return 0;
}
