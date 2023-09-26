#include <iostream>
using namespace std;

void Input1Fraction(int &a, int &b)
{
    cout << "Enter a =";
    cin >> a;
    cout << "Enter b =";
    cin >> b;
    while(b == 0)
    {
        cout <<"Enter b again ():";
        cin >> b;
    }
}

void Output1Fraction(int a, int b)
{
    cout << a << "/" << b;
}

int commonDevisor(int a, int b)
{

    int arr[((a > b) ? b : a)];
    int k = 0;
    int i = ((a > b) ? b : a);
    for (int i = ((a > b) ? b : a); i >= 2; i--)
    {

        if (a % i == 0 && b % i == 0)
        {
            arr[k] = i;
            k++;
        }
    }
    if (i == 1)
    {
        return 1;
    }
    else
    {
        return arr[k - 1];
    }
}

void ReduceFraction1(int a, int b)
{
    int divideNum = commonDevisor(a, b);
    cout << "\nDevice Number: " << divideNum;
    cout << "\nFraction after reduce: ";
    
    if (a == b)
    {
        cout << "1";
    }
    else
    {
        Output1Fraction(a / divideNum, b / divideNum);
    }
}
int main()
{
    int a, b;
    Input1Fraction(a, b);
    cout << "Fraction: ";
    Output1Fraction(a, b);
    ReduceFraction1(a, b);
}