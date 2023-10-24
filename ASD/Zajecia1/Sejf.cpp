#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
    ifstream plik("0104.txt");
    ofstream output("Out0104.txt");
    int n, m;
    plik >> n >> m;
    int y_coords[n + 1];
    for (int i = 0; i < n + 1; i++) {
        y_coords[i] = 0;
    }
    for (int i = 0; i < m; i++) {
        int x1, y1, x2, y2;
        plik >> x1 >> y1 >> x2 >> y2;
        if(y2 > y_coords[y1])
        {
            y_coords[y1] = y2;
        }
    }
    plik.close();

    vector<int> result;
    int licznik = 0;
    int ilosc_bezpiecznych_pasm = 0;
    bool przestrzenLasera = false;

    for (int i = 0; i < n; i++) {
        if (y_coords[i] > 0 && i != y_coords[i]) {
            i = y_coords[i] - 1;
            przestrzenLasera = false;
        }
        else {
            if (y_coords[i + 1] == 0 && przestrzenLasera == false) {
                przestrzenLasera = true;
                result.push_back(i);
                licznik++;
            } else if (przestrzenLasera == true && y_coords[i + 1] == 0) {
                continue;
            } else if (przestrzenLasera == true && y_coords[i + 1] != 0) {
                przestrzenLasera = false;
                result.push_back(i + 1);
                licznik++;
            } else {
                result.push_back(i);
                result.push_back(i + 1);
                licznik += 2;
            }
        }
    }

    if (licznik % 2 == 1) {
        result.push_back(n);
    }

    cout << endl;

    for (int i = 0; i < result.size(); i += 2) {
        output << "(" << result[i] << "," << result[i + 1] << ")" << endl;
        ilosc_bezpiecznych_pasm+=1;
    }
    output << "ilosc bezpiecznych pasm: "<< ilosc_bezpiecznych_pasm;
    output.close();
}