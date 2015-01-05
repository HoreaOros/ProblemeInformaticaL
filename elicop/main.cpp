#include <iostream>
#include <fstream>
#define MAX 100
using namespace std;

void Det01(int a[][MAX+1], int L1, int C1, int L2, int C2, int p, int &v0, int &v1)
{
    int aux, i, j;
    if(L1 > L2)
    {
        aux = L1;
        L1 = L2;
        L2 = aux;
        aux = C1;
        C1 = C2;
        C2 = aux;
    }
    if(C1 < C2)
        if(p < 0)
        {
            for(i = L1; i<= L2; i++)
                for(j = C1; j <= C1 + i - L1; j++)
                    if(a[i][j] == 1)
                        v1++;
                    else
                        v0++;
                    // a[i][j]?v1++:v0++;
        }
        else
            for(i = L1; i<= L2; i++)
                for(j = C1 + i - L1; j <= C2; j++)
                    if(a[i][j] == 1)
                        v1++;
                    else
                        v0++;
    else
        if(p < 0)
            for(i = L1; i<= L2; i++)
                for(j = C1 - (i - L1); j <= C1; j++)
                    if(a[i][j] == 1)
                        v1++;
                    else
                        v0++;
        else
            for(i = L1; i<= L2; i++)
                for(j = C2; j <= C1 - (i - L1); j++)
                    if(a[i][j] == 1)
                        v1++;
                    else
                        v0++;
}

int main()
{
    int k, n1 = 0, n2 = 0, e[40], a[MAX+1][MAX+1], n, m, i, j;
    int v0, v1;
    ifstream f("elicop.in");

    f >> m >> n;
    for(i = 1; i <= m; i++)
        for(j = 1; j <= n; j++)
            f >> a[i][j];
    f >> k;
    int L1, C1, L2, C2, p;
    for(i = 1; i <= k; i++)
    {
        f >> L1 >> C1 >> L2 >> C2 >> p;
        v0 = v1 = 0;
        Det01(a, L1, C1, L2, C2, p, v0, v1);
        if(v0 == 0)
            n1++;
        else
            if(v0 > v1)
            {
                e[n2] = i;
                n2++;
            }
    }
    f.close();
    cout << n1 << endl;
    cout << n2 << " ";
    for(i = 0; i < n2; i++)
        cout << e[i] << " ";
    return 0;
}
