#include <iostream>
#include <fstream>
#include <sstream>
#include <conio.h>
#include <random>

using namespace std;


class Node{
public:
    Node* left = NULL;
    Node* right = NULL;
    Node* wsk = NULL;
    int key;
    int w = 0;

    Node(int a)
    {
        this->key = a;
    }
};



void BR1(Node *&p)
{
    Node* pl = p->left;
    p->left = pl->right;
    pl->right = p;
    p = pl;
}

void BL1(Node *&p)
{
    Node* pr = p->right;
    p->right = pr->left;
    pr->left = p;
    p = pr;
}

bool balanceIL(Node *&p)
{
//    cout<<"IL"<<endl;
    switch (p->w)
    {
        case -1:
        {
//            cout<<"-1"<<endl;
            if (p->right->w == -1)
            {
                BL1(p);
                p->left->w = 0;
            }
            else
            {
                BR1(p->right);
                BL1(p);
                switch (p->w)
                {
                    case 0:
                    {
                        p->left->w = 0;
                        p->right->w = 0;
                    } break;
                    case 1:
                    {
                        p->left->w = 0;
                        p->right->w = -1;
                    } break;
                    case -1:
                    {
                        p->left->w = 1;
                        p->right->w = 0;
                    } break;
                }
            }
            p->w = 0;
            return true;
        } break;

        case 0:
        {
            p->w = -1;
//            cout<<"0"<<endl;
            break;
        }
        case 1:
        {
            p->w = 0;
//            cout<<"1"<<endl;
            return true;
        } break;
    }
    return false;
}

bool balanceIR(Node *&p)
{
//    cout<<"IR"<<endl;
    switch (p->w)
    {
        case 1:
        {
//            cout<<"1"<<endl;
            if (p->left->w == 1)
            {
                BR1(p);
                p ->right->w = 0;
            }
            else
            {
                BL1(p->left);
                BR1(p);
                switch (p->w)
                {
                    case 0:
                    {
                        p->left->w = 0;
                        p->right->w = 0;
                    } break;
                    case 1:
                    {
                        p->left->w = 0;
                        p->right->w = -1;
                    } break;
                    case -1:
                    {
                        p->left->w = 1;
                        p->right->w = 0;
                    } break;
                }
            }
            p->w = 0;
            return true;
        }
            break;

        case 0:
        {
            p->w = 1;
//            cout<<"0"<<endl;
            break;
        }
        case -1:
        {
            p->w = 0;
//            cout<<"-1"<<endl;
            return true;
        } break;
    }
    return false;
}

bool insert(int a, Node *&p)
{
    if (!p)
    {
        p = new Node(a); return false;
    }
    if (p->key > a)
    {
        if (!insert(a, p->left))
            return balanceIR(p);
    }
    else if (p->key < a)
    {
        if (!insert(a, p->right))
            return balanceIL(p);
    }
    return true;
}

bool szukaj(int a, Node *&p,int wysokosc=0)
{
    if(!p)
    {
        return false;
    }
    else if(a > p->key)
    {
        return szukaj(a, p->right, ++wysokosc);
    }
    else if(a < p->key)
    {
        return szukaj(a, p->left, ++wysokosc);
        wysokosc+=1;
    }
    else
    {
        cout << "wysokosc: "<<wysokosc<<endl;
        cout << "waga: "<<p->w;
        return true;
    }
}

void KLP(Node *&p, ofstream &out)
{
    if(p != NULL)
    {
        out<<p->key<<" ("<<p->w<<"), ";
        KLP(p->left, out);
        KLP(p->right, out);
    }
}

void KLP(Node *&p)
{
    if(p != NULL)
    {
        cout<<p->key<<" ("<<p->w<<"), ";
        KLP(p->left);
        KLP(p->right);
    }
}

bool balanceDL(Node *&p)
{
    cout<<"DL"<<endl;
    switch (p->w)
    {
        case -1:
        {
            cout<<"-1"<<endl;
            if(p->right->w == -1)
            {
                BL1(p);
                p->left->w = 0;
            }
            else if (p->right->w == 0)
            {
                cout<<"AA"<<endl;
                BL1(p);
                p->w = 1;
                return true;
            }
            else
            {
                BR1(p->right);
                BL1(p);
                switch (p->w)
                {
                    case 0:
                    {
                        cout<<"0"<<endl;
                        p->left->w = 0;
                        p->right->w = 0;
                    } break;
                    case 1:
                    {
                        cout<<"1"<<endl;
                        p->left->w = 0;
                        p->right->w = -1;
                    } break;
                    case -1:
                    {
                        cout<<"-1"<<endl;
                        p->left->w = 1;
                        p->right->w = 0;
                    } break;
                }
            }
            p->w = 0;
        } break;

            // case 0 jest dobry
        case 0:
        {
            cout<<"0"<<endl;
            p->w = -1;
            return true;
        } break;
            // case 1 jest dobry
        case 1:
        {
            cout<<"1"<<endl;
            p->w = 0;
        } break;
    }
    return false;
}

bool balanceDR(Node *&p)
{
    cout<<"DR"<<endl;
    switch (p->w)
    {
        case 1:
        {
            cout<<"1"<<endl;
            if(p->left->w == 1)
            {
                BR1(p);
                p->right->w = 0;
            }
            else if (p->left->w == 0)
            {
                cout<<"AA"<<endl;;
                BR1(p);
                p->w = -1;
                return true;
            }
            else
            {
                BL1(p->left);
                BR1(p);
                switch (p->w)
                {
                    case 0:
                    {
                        cout<<"0"<<endl;
                        p->left->w = 0;
                        p->right->w = 0;
                    } break;
                    case 1:
                    {
                        cout<<"1"<<endl;
                        p->left->w = 0;
                        p->right->w = -1;
                    } break;
                    case -1:
                    {
                        cout<<"-1"<<endl;
                        p->left->w = 1;
                        p->right->w = 0;
                    } break;
                }
            }
            p->w = 0;
            return false;
        } break;

            // case 0 jest dobry
        case 0:
        {
            cout<<"0"<<endl;
            p->w = 1;
            return true;
        } break;

            // case -1 jest dobry
        case -1:
        {
            cout<<"-1"<<endl;
            p->w = 0;
        } break;
    }
    return false;
}

bool del(Node*& q, Node* p) {
    if (q->right) {
        if (!del(q->right, p)) return balanceDR(q);
    } else {
        p->key = q->key;
        Node* q1 = q;
        q = q->left;
        delete q1;
        return false;
    }
    return true;
}

bool delete_(int a, Node*& p) {
    if (p) {
        if (p->key > a) {
            if (!delete_(a, p->left)) return balanceDL(p);
        } else if (p->key < a) {
            if (!delete_(a, p->right)) return balanceDR(p);
        } else {
            Node* q = p;
            if (!q->left) {
                p = p->right;
                delete q;
                return false;
            } else if (!q->right) {
                p = p->left;
                delete q;
                return false;
            } else {
                if (!del(q->left, p)) return balanceDL(p);
            }
        }
    }
    return true;
}



int main()
{
    Node* root = NULL;

    string linia;
    int a;
    bool dziala = true;

    srand(time(NULL));

    while (dziala)
    {
        cout<<endl<<endl;
        cout<<"1 - Wczytaj dane z pliku"<<endl;
        cout<<"2 - Losowanie"<<endl;
        cout<<"3 - Zapisz do pliku"<<endl;
        cout<<"4 - Waga i poziom"<<endl;
        cout<<"5 - Szukaj"<<endl;
        cout<<"6 - Dodaj"<<endl;
        cout<<"7 - Usun"<<endl;
        cout<<"8 - Wypisz na ekran"<<endl;

        int wybor;
        cin>>wybor;

        switch (wybor)
        {
            case 1:
            {
                ifstream file("C:\\Users\\User\\Desktop\\Sem3\\ASD\\Zaj5\\In0501.txt");
                getline(file, linia);
                file.close();
                istringstream line(linia);
                while (line >> a) {
                    insert(a, root);
                }
                break;
            }
            case 2:
            {
                int a,b,c;
                cout<<"Podaj zakres liczb: ";
                cin >> a >> b;
                cout<<"Podaj ilosc liczb: ";
                cin >> c;
                int zakres = b-a+1;
                ofstream OutTest3("C:\\Users\\User\\Desktop\\Sem3\\ASD\\Zaj5\\Out0501.txt");
                for(int i=0;i<c;i++)
                {
                    int wylosowana_liczba = rand()%zakres+a;
                    insert(wylosowana_liczba,root);
                    OutTest3 << wylosowana_liczba << " ";
                }
                OutTest3.close();
                break;
            }
            case 3:
            {
                ofstream out("C:\\Users\\User\\Desktop\\Sem3\\ASD\\Zaj5\\Out0501.txt");
                KLP(root, out);
                out.close();
                break;
            }
            case 4:
            {
                cout<<"Szukana liczba: ";
                cin>>a;
                if(szukaj(a, root))
                {
                    cout<<" Liczba jest w drzewie AVL";
                }
                else
                {
                    cout<<"Brak danej liczby w drzewie";
                }
                break;
            }
            case 5:
            {
                int el;
                cout << "Podaj szukany element: "<<endl;
                cin >> el;
                szukaj(el,root,0);
                break;
            }
            case 6:
            {
                cout<<"Podaj liczbe: ";
                cin>>a;
                insert(a, root);
                break;
            }
            case 7:
            {
                cout<<"Podaj liczbe do usuniecia: ";
                cin>>a;
                delete_(a, root);
                break;
            }
            case 8:
            {
                KLP(root);
                break;
            }
        }
    }
}