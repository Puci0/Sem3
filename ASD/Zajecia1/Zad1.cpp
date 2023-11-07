#include <iostream>
#include <fstream>
using namespace std;

int licz = 0;

int silnia(int n)
{
    int result = 1;
    if (n==0 || n==1)
    {
        return 1;
    }
    else
    {
        for(int i=2;i<=n;i++)
        {
            result*=i;
            licz +=1;
        }
        return result;
    }
}


int SN2(int n, int k)
{
    if (k>n/2) k = n-k;
    int licznik = n-k+1;
    for(int i=n-k+2;i<=n;i++)
    {
        licz++;
        licznik*=i;
    }
    return licznik/silnia(k);
}

int SN5(int n, int k)
{
    int tab[n+1][k+1];
    for(int i=0;i<=n;i++) {
        for (int j = 0; j <= k; j++) {
            if (j == 0 || i==j) tab[i][j] = 1;
            else tab[i][j] = 0;
        }
    }
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<=k && j<i;j++)
        {
            tab[i][j] = tab[i-1][j-1] + tab[i-1][j];
            cout << tab[i-1][j-1] << '+' << tab[i-1][j] << " = "<< tab[i-1][j-1] + tab[i-1][j] << endl;
            licz++;
        }
    }

    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=k && j<=i;j++)
        {
            cout << tab[i][j] << " ";
        }
        cout << endl;
    }

    return tab[n][k];
}

int main()
{
    ifstream file("In0101.txt");
    ofstream output("Out0101.txt");
    int n,k;
    file>>n>>k;
    output << "n: " << n << " k: "<< k << endl;
    file.close();
    output << "SN2: "<< SN2(n,k) << " " << licz << endl;
    licz = 0;
    output << "SN5: "<< SN5(n,k) << " " << licz << endl;
    output.close();

}






















