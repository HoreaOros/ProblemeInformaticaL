#include <iostream>

using namespace std;

int main()
{
    int x = 1, y = 2, i;
    float f = 0.0f;

    (x == 1) || (y++ < 10);

    cout << y << endl;

    for (i = 1; i <= 1000000; i++)
        f = f + 0.01f;

    cout << f << endl;
    return 0;
}
