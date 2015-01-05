#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

void SwapRef(int &x, int &y)
{
    int aux;

    aux = x;
    x = y;
    y = aux;
}

int StrLen(char *s)
{
    int i = 0;
    while(s[i] !=  '\0')
        i++;
    return i;

}

void SwapPointer(int *x, int *y)
{
    int aux;

    aux = *x;
    *x = *y;
    *y = aux;
}

int main()
{
    int a = 1 , b = 2;

    cout << a << " " << b << endl;

    SwapPointer(&a, &b);

    cout << a << " " << b << endl;


    char s[] = "Hello";


    cout << "Lungimea sirului este :" << StrLen(s) << endl;


/////////////////////////////////////////////////////////////////
// var 1
    char m[100] = "bacalaureat";
    char vocale[] = "aeiou";
    char *pch;
    int n;
    for(int i = 0; i < strlen(vocale); i++)
    {
        pch = strchr(m, vocale[i]);
        while (pch != NULL)
        {
             n = strlen(pch);
             for(int j = n; j >= 0; j--)
             {
                 pch[j+1] = pch[j];
             }
            *(pch + 1)= toupper(vocale[i]);
            pch=strchr(pch + 1, vocale[i]);
        }
    }
///////////////////////////////////////////////////////////////
// var 2
    char bac[] = "bacalaureat";
    char sol[100];
    int i, j = 0;

    for(i = 0; i < strlen(bac); i++)
    {
        sol[j] = bac[i];
        j++;
        if(strchr(vocale, bac[i]) != NULL)
        {
            sol[j] = toupper(bac[i]);
            j++;
        }
    }
    sol[j] = '\0';
    cout << sol;
//////////////////////////////////////////////////////////////
    return 0;
}
