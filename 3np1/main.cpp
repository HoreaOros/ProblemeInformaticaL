#include <iostream>
#include <fstream>
#define SHOW_VALUES 1
#define NOT_SHOW_VALUES 0

using namespace std;

int secventa(int x, int &max, int flag)
{
    if (flag == SHOW_VALUES)
        cout << x << ": ";
	int k = 0;

    do
    {
        if(x % 2 == 0)
        {
			x = x / 2;
		}
        else
        {
			x = x * 3 + 1;
		}
		if(max < x)
			max = x;
        k++;
        if (flag == SHOW_VALUES)
            cout << x << " ";
    } while(x != 1);
    if (flag == SHOW_VALUES)
        cout << endl;
	return k;
}
int main()
{
    int n, k, maxs = 0, i, j, aux;
    cout << "n = ";
    cin >> n;
	cout << endl;
	k = secventa(n, maxs, SHOW_VALUES);
    cout << "k = " << k << endl << endl;

	cout << "Maximul din secventa este: " << maxs << endl << endl;
	int a, b;
	cout << "Dati un interval [a,b]: ";
	cin >> a >> b;
	cout << endl;
	k = 0;
	for(int i = a; i <= b; i++)
    {
        aux = secventa(i, maxs, SHOW_VALUES);
		if(aux > k)
		{
			k = aux;
		}
    }

	cout << "Lungimea maxima din intervalul [a, b] este: " << k << endl << endl;
	cout << "Numerele din intervalul [a, b] pentru care obtinem cea mai lunga secventa sunt: " << endl;


    for(i = a; i <= b; i++)
	{
		if(secventa(i, maxs, NOT_SHOW_VALUES) == k)
		{
			cout << i << " ";
		}
	}
    return 0;
}

