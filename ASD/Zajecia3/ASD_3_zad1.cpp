#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

string TAB_NWP(string s1, string s2) {
    int r1 = s1.length();
    int r2 = s2.length();
    int **S = new int*[r1 + 1];
    for (int i = 0; i <= r1; i++) {
        S[i] = new int[r2 + 1];
    }

    for (int i = 0; i <= r1; i++) S[i][0] = 0;
    for (int j = 0; j <= r2; j++) S[0][j] = 0;

    for (int i = 1; i <= r1; i++) {
        for (int j = 1; j <= r2; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                S[i][j] = S[i - 1][j - 1] + 1;
            }
            else
            {
                S[i][j] = max(S[i][j - 1], S[i - 1][j]);
            }
        }
    }

    int i = r1, j = r2;

    string subcode = " ";
    while (i > 0 && j > 0) {
        if (s1[i - 1] == s2[j - 1]) {
            subcode = s1[i - 1] + subcode;
            i--;
            j--;
        } else if (S[i - 1][j] > S[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    for (int i = 0; i <= r1; i++) {
        delete[] S[i];
    }
    delete[] S;

    if (subcode.length() >= 6) {
        return subcode;
    }
    else return 0;
}

int main() {
    ifstream input("In0301.txt");
    ofstream output("Out0301.txt");
    string linia;
    getline(input,linia);
    istringstream line(linia);
    int n;
    line >> n;
    string s1,s2;
    for(int i=0;i<n;i++)
    {
        getline(input,s1);
        getline(input,s2);
        string result = TAB_NWP(s1, s2);
        output << result.length()-1 << " " << result <<endl;
    }
    return 0;
}