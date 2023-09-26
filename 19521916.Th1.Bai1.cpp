#include <iostream>
#include <stdlib.h> 
using namespace std;

struct Fraction
{
    int Numerator;
    int Denominator;
};

void Input1Fraction(Fraction &x)
{
    cout << " Enter numerator: ";
    cin >> x.Numerator;
    cout << " Enter denominator: ";
    cin >> x.Denominator;

    while (x.Denominator == 0)
    {
        cout << " Enter demominator again: ";
        cin >> x.Denominator;
    }
}

void Input2Fraction(Fraction &a, Fraction &b)
{
    cout << " Enter numerator of fraction 1: ";
    cin >> a.Numerator;
    do
    {
        cout << " Enter demominator of fraction 1: ";
        cin >> a.Denominator;
    }
    while (a.Denominator == 0);
    cout << " Enter numerator of fraction 2: ";
    cin >> b.Numerator;

    do
    {
        cout << " Enter demominator of fraction 2: ";
        cin >> b.Denominator;
    }
    while (b.Denominator == 0);
}

void OutputFraction(Fraction a, int Divisor)
{
    cout << a.Numerator / Divisor << "/" << a.Denominator / Divisor << endl;
}

int FindDivisor(Fraction a)
{
    int i = ((abs(a.Numerator) < abs(a.Denominator)) ? abs(a.Numerator) : abs(a.Denominator));
    int arrDivisor[i];
    int k = 0;

    for (i;i >= 2; i--)
    {
        if (abs(a.Numerator) % i == 0 && abs(a.Denominator % i) == 0)
        {
            arrDivisor[k] = i;
            k++;
        }
    }

    if (k == 0)
    {
        return 1;
    }
    else
    {
        return arrDivisor[k - 1];
    }
}

void OutputLowestTerm(Fraction a)
{
    int Divisor = FindDivisor(a);
    cout << "Divisor: " << Divisor << endl;
    cout << "Lowest Term :";

    if (a.Numerator == a.Denominator)
    {
        cout << "1" << endl;
    }
    else
    {
        OutputFraction(a, Divisor);
    }
}

Fraction FindMaxFraction(Fraction a, Fraction b)
{
    if ((a.Numerator * b.Denominator - b.Numerator * a.Denominator) > 0)
    {
        return a;
    }

    return b;
}

Fraction SumFraction(Fraction a, Fraction b)
{
    Fraction c;
    c.Numerator = a.Numerator * b.Denominator + b.Numerator * a.Denominator;
    c.Denominator = a.Denominator * b.Denominator;
    OutputLowestTerm(c);
    return c;
}

Fraction SubtractFraction(Fraction a, Fraction b)
{
    Fraction c;
    c.Numerator = a.Numerator * b.Denominator - b.Numerator * a.Denominator;
    c.Denominator = a.Denominator * b.Denominator;
    OutputLowestTerm(c);
    return c;
}

Fraction MultipleFraction(Fraction a, Fraction b)
{
    Fraction c;
    c.Numerator = a.Numerator * b.Numerator ;
    c.Denominator = a.Denominator * b.Denominator;
    OutputLowestTerm(c);
    return c;
}

Fraction DivideFraction(Fraction a, Fraction b)
{
    Fraction c;
    c.Numerator = a.Numerator * b.Denominator ;
    c.Denominator = a.Denominator * b.Numerator;
    OutputLowestTerm(c);
    return c;
}

int main()
{
    Fraction a;
    Fraction b;
    Input1Fraction(a);
    OutputLowestTerm(a);
    Input2Fraction(a, b);
    cout << "Max Fraction: ";
    OutputFraction(FindMaxFraction(a, b),1);
    cout << "Sum of 2 fraction: ";
    OutputFraction(SumFraction(a,b), 1);
    cout << "Subtraction of 2 fraction: ";
    OutputFraction(SubtractFraction(a,b), 1);
    cout << "Multiplication of 2 fraction: ";
    OutputFraction(MultipleFraction(a,b), 1);
    cout << "Division of 2 fraction: ";
    OutputFraction(DivideFraction(a,b), 1);
        
}