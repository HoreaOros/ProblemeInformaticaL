#include <iostream>

using namespace std;

int f(int n)
{
    int s = 0, d = 2;
    while(n > 1)
    {
        if(n % d == 0)
        {
            s++;
            n = n / d;
        }
        else
        {
            d++;
        }
    }
    return s;
}

int main()
{
    int n, c1 = 0, c2 = 0, c3 = 0;
    cout << "n=";
    cin >> n;

    c3 = n % 10;
    c2 = n % 100 / 10;
    c1 = n / 100;

    if(c1 == 0 && c2 == 0)
        if(f(c3) == 1)
            cout << "DA";
        else
            cout << "NU";
    else
        if(c1 == 0)
            if(f(c2 * 10 + c3) == 1 && f(c3 * 10 + c2) == 1)
                cout << "DA";
            else
                cout << "NU";
        else
        {
            if(f(c1 * 100 + c2 * 10 + c3) == 1 &&
               f(c1 * 100 + c3 * 10 + c2) == 1 &&
               f(c2 * 100 + c1 * 10 + c3) == 1 &&
               f(c2 * 100 + c3 * 10 + c1) == 1 &&
               f(c3 * 100 + c1 * 10 + c2) == 1 &&
               f(c3 * 100 + c2 * 10 + c1) == 1)
                cout << "DA";
            else
                cout << "NU";
        }
    return 0;
}
