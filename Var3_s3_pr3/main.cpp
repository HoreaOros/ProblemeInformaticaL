// 08.12.2014 v3
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int x, j, v[100], i = 0, n;
    ifstream f("NR.TXT");
    while(!f.eof())
    {
        f >> x;
        if(!f.eof() && x >= 100)
        {
            v[i] = x;
            i++;
        }
    }
    f.close();
    n = i;

    for(i = 0; i < n-1; i++)
        for(j = i+1; j < n; j++)
            if(v[i] > v[j])
            {
               x = v[i];
               v[i] = v[j];
               v[j] = x;
            }
    for(i = 0; i < n; i++)
        cout << v[i] << " ";

    return 0;
}
