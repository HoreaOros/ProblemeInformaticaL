#include <iostream>
#define MAX 5
using namespace std;

void Print(int c[], int n, int first, int last, int count)
{
    if(first<last)
    {
        for(int i = first; i < last; i++)
            cout << c[i] << " ";
        cout << endl;
    }
    else
    {
        if(count > 0)
        {
            for(int i = first; i < n; i++)
                cout << c[i] << " ";
            for(int i = 0; i < last; i++)
                cout << c[i] << " ";
            cout << endl;
        }
        else
            if(count == 0)
            cout << "Coada este goala" << endl;
    }
}
void Enque(int coada[], int n, int value, int &last, int &count)
{
    if(count < n)
    {
        coada[last] = value;
        count++;
        last++;
        if(last == n)
            last = 0;
    }
}

int Deque(int coada[], int n, int &first)
{
    int ret;

    ret = coada[first];

    first++;
    if(first == n)
        first = 0;
    count--;
    return ret;

}
int main()
{
    int coada[MAX] = {0};
    int first = 0, last = 0, count = 0, value;
    int gata = 0;
    char buffer[10];
    do
    {
        cin >> buffer;
        switch(buffer[0])
        {
        case 'A':
            // adaugare
            cin >> value;
            Enque(coada, MAX, value, last, count);
            break;
        case 'E':
            // eliminare
            if(count > 0)
                cout << Deque(coada, MAX, first) << endl;
            else
                cout << "Coada este goala" << endl;
            break;
        case 'P':
            // afisare
            Print(coada, MAX, first, last, count);
            break;
        case 'Q':
            // iesire
            gata = 1;
            break;
        }
    }while(!gata);
    return 0;
}
