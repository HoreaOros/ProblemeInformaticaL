//merge sort
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

#define MAX 1000000
#define NUMBERS_PER_LINE 20

using namespace std;

void Init(int a[], int n)
{
    cout << "Initializing" << endl;
    /* initialize random seed: */
    srand (time(NULL));

    for(int i = 0; i < n ; i++)
        a[i] = rand();

    cout << "Done." << endl;
}

void PrintConsole(int a[], int n)
{
    int i;
    cout << "Dumping..." << endl;
    for( i= 0; i< n; i++)
        cout << a[i] << " ";
    cout << "Done." << endl;
}

void WriteToFile( int a[], int n,char filename[], int nrl)
{
    ofstream f(filename);
    for(int i = 0; i < n; i++)
    {
        if(i > 0 && i%20 == 0)
            f << endl;
        f << a[i] << " ";
    }
    f.close();
}

void Swap(int a[], int i, int j)
{
    int aux;
    aux = a[i];
    a[i] = a[j];
    a[j] = aux;
}

void BubbleSort(int a[],int n)
{
    int i, j;
    cout << "Sorting..." << endl;
    for(i = 0; i < n-1; i++)
    {
        for(j = i + 1; j < n; j++)
            if(a[i] > a[j])
                Swap(a, i, j);
        if(i%10000 == 0)
            cout << i << " ";
    }

    cout << "Sort completed!" << endl;
}

void Merge(int a[], int p, int q, int r)
{
    static int L[MAX] = {0};
    static int R[MAX] = {0};
    int n1, n2;
    n1 = q - p + 1;
    n2 = r - q;
    for(int i = 0; i < n1; i++)
        L[i] = a[p + i];
    for(int i = 0; i < n2; i++)
        R[i] = a[q + 1 + i];

    int i = 0, j = 0, k = 0;

    for(k = p; k <= r; k++)
        if(L[i] < R[j])
            a[k] = L[i++];
        else
            a[k] = R[j++];
}

void MergeSort(int a[], int p, int r)
{
    int q;
    if(p < r)
    {
        q = (p + r) / 2;
        MergeSort(a, p, q);
        MergeSort(a, q + 1, r);
        Merge(a, p, q, r);
    }
}

int main()
{
    static int a[MAX] = {0};

    Init(a, MAX);
    //PrintConsole(a, MAX);

    WriteToFile(a, MAX, "output.txt", NUMBERS_PER_LINE);

    static int frecventa[RAND_MAX+1] = {0};
    for(int i = 0; i < MAX; i++)
    {
        frecventa[a[i]]++;
    }
    //PrintConsole(frecventa, RAND_MAX + 1);
    //BubbleSort(a, MAX);
    //WriteToFile(a, MAX, "outputSorted.txt", NUMBERS_PER_LINE);

    MergeSort(a, 0, MAX-1);
    WriteToFile(a, MAX, "outputSorted.txt", NUMBERS_PER_LINE);

    return 0;
}
