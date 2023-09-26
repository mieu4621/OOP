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

void sortAscArray(int a[], int N)
{
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            
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
    cout << " Enter N: ";
    cin >> N;
    int a[N];
    inputArrayInteger(a, N);
    sortAscArray(a, N);
    outputArray(a, N);
}