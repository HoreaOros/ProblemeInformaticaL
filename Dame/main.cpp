#include <iostream>
#include<iomanip>
#include<cmath>
#define MAX 100
using namespace std;

void init(int v[], int k)
{
    v[k] = -1;
}

int succesor(int v[], int k, int n)
{
    int as = 0;
    if(v[k] < n - 1)
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
		if((v[k] == v[i]) || (v[k] - v[i] == k - i) || (i + v[i] == k + v[k]))
			ev = 0;
    return ev;
}

void tipar(int v[], int n)
{
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n;j++)
			if(v[i] == j)
				cout << setw(2) << "o";
			else
				cout << setw(2) << "x";
		cout << endl;
	}
	cout << endl;
}

int solutie(int v[], int k, int n)
{
    return k == n-1;
}

void dame(int n)
{
    int v[MAX] = {0}, k = 0, as, ev, nrsol = 0;

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
            {
                tipar(v, n);
                nrsol++;
            }
            else
            {
                k++;
                init(v, k);
            }
        }
        else
            k--;
    }
    cout << "Sunt " << nrsol << " solutii\n";
}


int main()
{
    int n;
    cout << "Numarul de linii: ";
    cin >> n;


    dame(n);

    return 0;
}
