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
    string key;
    int w = 0;

    Node(string a)
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

bool insert(string a, Node *&p)
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

bool szukaj(string a, Node *&p)
{
    if(!p)
    {
        return false;
    }
    else if(a > p->key)
    {
        return szukaj(a, p->right);
    }
    else if(a < p->key)
    {
        return szukaj(a, p->left);
    }
    else
    {
        return true;
    }
}

Node *& znajdz(string a, Node *&p)
{
    if(a > p->key)
    {
        return znajdz(a, p->right);
    }
    else if(a < p->key)
    {
        return znajdz(a, p->left);
    }
    else
    {
        return p;
    }
}

void KLP(Node *&p, ofstream &out)
{
    if(p != NULL)
    {
        out<<p->key<<" "<<p->wsk->key<<endl;
        KLP(p->left, out);
        KLP(p->right, out);
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

bool delete_(string a, Node*& p) {
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

void insert(string pesel, string rejestracja, Node *&pesele, Node *&rejestracje)
{
    if(szukaj(pesel,pesele))
    {
        cout <<"Pesel znajduje sie juz w drzewie"<<endl;
    }
    if(szukaj(rejestracja, rejestracje))
    {
        cout <<"Rejestracja znajduje sie juz w drzewie"<<endl;
    }
    insert(pesel,pesele);
    insert(rejestracja,rejestracje);
    Node *p = znajdz(pesel,pesele);
    Node *q = znajdz(rejestracja,rejestracje);
    p->wsk = q;
    q->wsk = p;
}

int main()
{
    Node* pesele = NULL;
    Node* rejestracje = NULL;

    bool dziala = true;

    while (dziala)
    {
        cout<<endl<<endl;
        cout<<"1 - Plik -> wczytaj"<<endl;
        cout<<"2 - Plik -> zapisz"<<endl;
        cout<<"3 - Wstaw -> numer pesel"<<endl;
        cout<<"4 - Wstaw -> numer samochodu"<<endl;
        cout<<"5 - Wyszukaj -> numer pesel"<<endl;
        cout<<"6 - Wyszukaj -> numer samochodu"<<endl;
        cout<<"7 - Usun -> numer pesel"<<endl;
        cout<<"8 - Usun -> numer samochodu"<<endl;

        int wybor;
        cin>>wybor;

        switch (wybor)
        {
            case 1:
            {
                string pesel,rejestracja,linia;
                ifstream file("C:\\Users\\User\\Desktop\\Sem3\\ASD\\Zaj5\\In0501.txt");
                while(getline(file, linia))
                {
                    istringstream line(linia);
                    line >> pesel >> rejestracja;
                    insert(pesel,rejestracja,pesele,rejestracje);
                }
                break;
            }
            case 2:
            {
                ofstream OutTest3("C:\\Users\\User\\Desktop\\Sem3\\ASD\\Zaj5\\Out0501.txt");
                int wybor;
                cout << "1: najpierw pesele, 2: najpierw rejestracje" <<endl<< "Wybor: ";
                cin >> wybor;
                switch(wybor)
                {
                    case 1:
                    {
                        KLP(pesele,OutTest3);
                        break;
                    }
                    case 2:
                    {
                        KLP(rejestracje,OutTest3);
                        break;
                    }
                }
                OutTest3.close();
                break;
            }
            case 3:
            {
                string pesel,rejestracja;
                cout << "Podaj numer pesel: ";
                cin >> pesel;
                cout << "Podaj rejestracje: ";
                cin >> rejestracja;
                insert(pesel, rejestracja, pesele, rejestracje);
                break;
            }
            case 4:
            {
                string pesel,rejestracja;
                cout << "Podaj rejestracje: ";
                cin >> rejestracja;
                cout << "Podaj pesel: ";
                cin >> pesel;
                insert(pesel,rejestracja,pesele,rejestracje);
                break;

            }
            case 5:
            {
                string rejestracja;
                cout << "Podaj rejestracje: ";
                cin >> rejestracja;
                if(!szukaj(rejestracja,rejestracje))
                {
                    cout << "Nie ma takiego peselu w drzewie";
                }
                else
                {
                    Node *p = znajdz(rejestracja,rejestracje);
                    cout << "Numer pesel: "<<p->wsk->key<<endl;
                }
                break;
            }
            case 6:
            {
                string pesel;
                cout<<"Podaj pesel: ";
                cin>>pesel;

                if(!szukaj(pesel, pesele))
                {
                    cout<<"Brak rejestracji w drzewie"<<endl;
                }
                else
                {
                    Node *p = znajdz(pesel, pesele);
                    cout<<"Rejestracja: "<<p->wsk->key<<endl;
                }

                break;
            }
            case 7:
            {
                string pesel;
                cout<<"Numer pesel: ";
                cin>>pesel;

                if(!szukaj(pesel, pesele))
                {
                    cout<<"Brak numeru pesel w drzewie."<<endl;
                }
                else
                {
                    Node *p = znajdz(pesel, pesele);
                    delete_(p->wsk->key, rejestracje);
                    delete_(p->key, pesele);
                }

                break;
            }
            case 8:
            {
                string rejestracja;
                cout<<"Podaj rejestracje: ";
                cin>>rejestracja;

                if(!szukaj(rejestracja,rejestracje))
                {
                    cout<<"Brak rejestracji w drzewie"<<endl;
                }
                else
                {
                    Node *p = znajdz(rejestracja,rejestracje);
                    delete_(p->wsk->key, pesele);
                    delete_(p->key, rejestracje);
                }
                break;
            }
        }
    }
}