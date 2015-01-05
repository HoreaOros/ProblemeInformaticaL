#include <iostream>

using namespace std;

void f(long n, int i)
{
    if(n != 0)
        if(n % 3 > 0)
        {
            cout << i;
            f(n / 3, i + 1);
        }
    cout << i;
}
int main()
{
    int n, m, i, j, a[11][11];
  11
  .       do
    {
        cout << "n= ";
        cin >> n;
        cout << "m= ";
        cin >> m;

    }while(!(n >= 2 && n <=10 && m >= 2 && m <=10));

    for(i = 1; i <= n; i++)
        for(j = 1; j <= m; j++)
            if(i < j)
                a[i][j] = i;
            else
                a[i][j] = j;

    for(i = 1; i <= n; i++)
    {
        for(j = 1; j<= m; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
    f(121, 1);

    return 0;
}
