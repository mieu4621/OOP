#include <iostream>
using namespace std;

class Fraction
{
    int numerator;
    int denominator;

public:
    Fraction()
    {
        numerator = 0;
        denominator = 1;
    };
    Fraction(int nu, int de)
    {
        this->numerator = nu;
        this->denominator = de;
    }
    int getNumerator()
    {
        return numerator;
    }
    int getDenominator()
    {
        return denominator;
    }
    void inputFraction()
    {
        cout << "\nEnter numerator of fraction: ";
        cin >> numerator;
        cout << "Enter denominator: ";
        cin >> denominator;
    }
    void outputFraction()
    {
        cout << "\nFraction: " << numerator << "/" << denominator;
    }
    void operator=(Fraction b)
    {
        this->numerator = b.numerator;
        this->denominator = b.denominator;
    }
    Fraction operator+(Fraction b)
    {
        return Fraction(numerator * b.denominator + b.numerator * denominator, denominator * b.denominator);
    }
    Fraction operator-(Fraction b)
    {
        return Fraction(numerator * b.denominator - b.numerator * denominator, denominator * b.denominator);
    }
    Fraction operator*(Fraction b)
    {
        return Fraction(numerator * b.numerator, denominator * b.denominator);
    }
    Fraction operator/(Fraction b)
    {
        return Fraction(numerator * b.denominator, denominator * b.numerator);
    }
    bool operator<(Fraction b)
    {
        if (numerator * b.denominator < b.numerator * denominator)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
     bool operator> (Fraction b)
    {
        if (numerator * b.denominator > b.numerator * denominator)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool operator<= (Fraction b)
    {
        if (numerator * b.denominator <= b.numerator * denominator)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool operator>= (Fraction b)
    {
        if (numerator * b.denominator >= b.numerator * denominator)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
int main()
{
    Fraction a;
    Fraction b;
    Fraction c;
    a.inputFraction();
    a.outputFraction();
    b.inputFraction();
    b.outputFraction();
    c = a + b;
    c.outputFraction();
    c = a - b;
    c.outputFraction();
    c = a * b;
    c.outputFraction();
    c = a / b;
    c.outputFraction();
    return 0;
}
