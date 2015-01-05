#include <iostream>
#include <fstream>

using namespace std;

int sub(int v[],int n, int a)
{
    int c = 0;
    for(int  i = 0; i < n; i++)
        if(v[i] < a)
            c++;
    return c;
}

int main()
{
//    int n;
//    int nr, c = 0;
//    cout << "n=";
//    cin >> n;
//    ifstream f("bac.txt");
//
//    while(!f.eof())
//    {
//        f >> nr;
//        if(!f.eof() && nr % n == 0)
//        {
//            cout << nr << " ";
//            c++;
//        }
//    }
//    if(c == 0)
//        cout << "Nu exista";

    int n, v[100], s = 0;
    cout << " n=";
    cin >> n;

    for( int i =0; i < n; i++)
        cin >> v[i];

    for(int i = 0 ; i < n; i++)
        s = s + sub (v, n, v[i]);
    if(s == n * (n-1)/2)
        cout << "DA";
    else
        cout << "NU";

    return 0;
}
