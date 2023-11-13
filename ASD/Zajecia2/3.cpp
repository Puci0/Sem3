#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int fib(int n) {
    static vector<int> table;
    if (n <= 1) {
        return n;
    }
    else if (n >= table.size()) {
        table.resize(n+1);
    }

    if (table[n] == 0) {
        table[n] = fib(n-1) + fib(n-2);
    }
    return table[n];
}

int main()
{
    ifstream input("C:\\Users\\user\\Desktop\\Sem3\\ASD\\Zajecia2\\In0203.txt");
    ofstream output("C:\\Users\\user\\Desktop\\Sem3\\ASD\\Zajecia2\\Out0203.txt");
    int n;
    input >> n;
    int i = 0;
    while(fib(i) < n)
    {
        output << fib(i) << " ";
        i++;
    }
}