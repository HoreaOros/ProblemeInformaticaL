#include <iostream>
#include <fstream>
#define MAX 100
using namespace std;

void Marcare(int a[][MAX], int m, int n, int i, int j, int c)
{
    a[i][j] = c;
    if(j > 0 && a[i][j-1] == 1)
        Marcare(a, m, n, i, j-1, c);
    if(i < m-1 && a[i+1][j] == 1)
        Marcare(a, m, n, i+1, j ,c);
    if(j < n -1 && a[i][j+1] == 1)
        Marcare(a, m, n, i, j+1, c);
    if(i > 0 && a[i-1][j] == 1)
        Marcare(a, m, n, i-1, j, c);
}

void Afisare_Matrice(int a[][MAX],int  m,int  n)
{
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
}
int main()
{
    int a[MAX][MAX];
    int m, n, i, j;
    ifstream f("input.in");
    f >> m >> n;
    for(i = 0; i < m; i++)
        for(j = 0; j < n; j++)
            f >> a[i][j];
    f.close();
    int contor = 2;

    for(i = 0; i < m; i++)
        for(j = 0; j < n; j++)
            if(a[i][j] == 1)
            {
                Marcare(a, m, n, i, j, contor);
                contor++;
            }
    cout << "Fotografia contine: " << contor - 2 << " obiecte" << endl;

    Afisare_Matrice(a, m, n);
    return 0;
}
