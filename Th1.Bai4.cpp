#include <iostream>
using namespace std;

void inputArrayInteger(int a[], int &N)
{
    for (int i = 0; i < N; i++)
    {
        cout << " Enter number " << i << ": ";
        cin >> a[i];
    }
}

// int sortAscArray(int a[], int &N)
void sortAscArray(int a[], int N)
{
    // int min = a[0];
    for (int i = 0; i < N - 1; i++)
    {
        // wrong
        // int min = a[0];
        for (int j = i + 1; j < N; j++)
        {
            // if( a[i] < min )
            // {
            //     // wrong
            //     // a[i] = min;
            //     // cout << min;
            // }
            if (a[j] < a[i])
            {
                int temp;
                temp = a[j];
                a[j] = a[i];
                a[i] = temp;
            }
        }
    }
}

void outputArray(int a[], int N)
{
    for (int i = 0; i < N; i++)
    {
        cout << a[i] << " ";
    }
}
int main()
{
    int N;
    cin >> N;
    int a[N];
    inputArrayInteger(a, N);
    //     cout << sortAscArray(a, N);
    sortAscArray(a, N);
    outputArray(a, N);
}