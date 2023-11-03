#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
void swap(int &a,int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}
void quick_sort(vector<int> &tab,int left,int right)
{
    int pivot = tab[(left+right)/2];
    int i=left-1;
    int j=right+1;
    while(1)
    {
        while (tab[++i] < pivot);
        while (tab[--j] > pivot);
        if(i<=j)
        {
            swap(tab[i],tab[j]);
        }
        else
        {
            break;
        }
    }
    if(j > left)
        quick_sort(tab, left, j);
    if(i < right)
        quick_sort(tab, i, right);
}
int main()
{
    vector<int> tab;
    ifstream input("C:\\Users\\user\\CLionProjects\\ASD_2\\In0201.txt");
    ofstream output("C:\\Users\\user\\CLionProjects\\ASD_2\\Out0201.txt");
    int value;
    while(input >> value)
    {
        tab.push_back(value);
    }
    quick_sort(tab,0,tab.size()-1);
    for(int i=0;i<tab.size();i++)
    {
        output << tab[i] << " ";
    }
}
















