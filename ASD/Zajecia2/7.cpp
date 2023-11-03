#include <iostream>
#include <fstream>
using namespace std;

typedef struct Drzewo{
    int liczba;
    struct Drzewo *L;
    struct Drzewo *P;
};

void insert(struct Drzewo **korzen, int wartosc)
{
    if(*korzen == NULL)
    {
        *korzen = (struct Drzewo *)malloc(sizeof(struct Drzewo));
        (*korzen)->liczba = wartosc;
        (*korzen)->L = NULL;
        (*korzen)->P = NULL;
    }
    else
    {
        if (wartosc < (*korzen)->liczba)
        {
            insert(&((*korzen)->L),wartosc);
        }
        else if(wartosc > (*korzen)->liczba)
        {
            insert(&((*korzen)->P),wartosc);
        }
    }
}

int znajdz(struct Drzewo *korzen, int wartosc)
{
    if(korzen==NULL)
    {
        return 0;
    }
    if(korzen->liczba == wartosc)
    {
        return korzen->liczba;
    }
    if(wartosc < korzen->liczba)
    {
        return znajdz(korzen->L, wartosc);
    }
    else
    {
        return znajdz(korzen->P, wartosc);
    }
}

ofstream output("C:\\Users\\user\\CLionProjects\\ASD_2\\Out0207.txt");
void KLP(struct Drzewo *korzen)
{
    if(korzen != NULL)
    {
        output << korzen->liczba << " ";
        KLP(korzen->L);
        KLP(korzen->P);
    }
}


int main()
{
    ifstream input("C:\\Users\\user\\CLionProjects\\ASD_2\\In0207.txt");
    struct Drzewo *korzen = NULL;
    int wartosc;
    while(input >> wartosc)
    {
        insert(&korzen,wartosc);
    }
    KLP(korzen);
}