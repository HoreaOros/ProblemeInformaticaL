#include <iostream>
#define MAX 100
using namespace std;

void init(int v[], int k)
{
    v[k] = 0;
}

int succesor(int v[], int k, int n)
{
    int as = 0;
    if(v[k] < n)
    {
        v[k]++;
        as = 1;
    }
    return as;
}

int valid(int v[], int k, int n)
{
    int ev = 1;
    for(int i = 0; i < k && ev == 1; i++)
        if(v[k]  == v[i])
            ev = 0;
    return ev;
}

int solutie(int v[], int k, int n)
{
    return k == n-1;
}

void tipar(int v[], int k, int n)
{
    for(int i = 0; i < n; i++)
        cout << v[i] << " ";
    cout << endl;
}

void permutari(int n)
{
    int v[MAX] = {0}, k = 0, as, ev;

    init(v, k);

    while(k >= 0)
    {
        do
        {
            as = succesor(v, k, n);
            if (as == 1)
                ev = valid(v, k, n);
        }while(as && !ev);
        if(as)
        {
            if(solutie(v, k, n))
                tipar(v, k, n);
            else
            {
                k++;
                init(v, k);
            }
        }
        else
            k--;
    }
}

// produs cartezian

int validPC(int v[], int k, int n)
{
    return 1;
}

void pc(int n)
{
    int v[MAX] = {0}, k = 0, as, ev;

    init(v, k);

    while(k >= 0)
    {
        do
        {
            as = succesor(v, k, n);
            if (as == 1)
                ev = validPC(v, k, n);
        }while(as && !ev);
        if(as)
        {
            if(solutie(v, k, n))
                tipar(v, k, n);
            else
            {
                k++;
                init(v, k);
            }
        }
        else
            k--;
    }
}

//aranjamente

int solutieArj(int v[], int k, int n, int r)
{
    return k == r-1;
}

void aranjamente(int n, int r)
{
    int v[MAX] = {0}, k = 0, as, ev;

    init(v, k);

    while(k >= 0)
    {
        do
        {
            as = succesor(v, k, n);
            if (as == 1)
                ev = valid(v, k, n);
        }while(as && !ev);
        if(as)
        {
            if(solutieArj(v, k, n, r))
                tipar(v, k, r);
            else
            {
                k++;
                init(v, k);
            }
        }
        else
            k--;
    }
}

// combinari
void initCMB(int v[], int k)
{
    if(k == 0)
        v[k] = 0;
    else
        v[k] = v[k-1];
}

int validCMB(int v[], int k, int n)
{
    return 1;
}

void combinari(int n, int r)
{
    int v[MAX] = {0}, k = 0, as, ev;

    initCMB(v, k);

    while(k >= 0)
    {
        do
        {
            as = succesor(v, k, n);
            if (as == 1)
                ev = validCMB(v, k, n);
        }while(as && !ev);
        if(as)
        {
            if(solutieArj(v, k, n, r))
                tipar(v, k, r);
            else
            {
                k++;
                initCMB(v, k);
            }
        }
        else
            k--;
    }
}


int main()
{
    int n;
    cout << "n=";
    cin >> n;

    cout << "Permutari\n";
    permutari(n);

    cout << "Produs cartezia\n";
    pc(n);

    cout<< "Aranjamente de n luate cate k\n";

    int k;
    cout << "k = ";
    cin >> k;
    aranjamente(n, k);

    cout << "Combinari\n";
    combinari(n, k);
    return 0;
}
