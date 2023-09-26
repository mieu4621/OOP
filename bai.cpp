#include <iostream>
using namespace std;

class Fraction
{
private:
    int numerator, denominator; 
     Fraction(int n, int d)
    {
        numerator = n;
        if (d==0) 
        {
            cout << "ERROR: ATTEMPTING TO DIVIDE BY ZERO" << endl;
            exit(0); // will terminate the program if division by 0 is attempted
        }
        else
            denominator = d;
    }

public:
    Fraction()
    {
        numerator = 1;
        denominator = 1;
    }
    
    Fraction Sum(Fraction otherFraction)
    {
        int n = numerator*otherFraction.denominator+otherFraction.numerator*denominator;
        int d = denominator*otherFraction.denominator;
        return Fraction(n/gcd(n,d),d/gcd(n,d));
    }
    Fraction Difference(Fraction otherFraction)
    {
        int n = numerator*otherFraction.denominator-otherFraction.numerator*denominator;
        int d = denominator*otherFraction.denominator;
        return Fraction(n/gcd(n,d),d/gcd(n,d));
    }
    Fraction Product(Fraction otherFraction)
    {
        int n = numerator*otherFraction.numerator;
        int d = denominator*otherFraction.denominator;
        return Fraction(n/gcd(n,d),d/gcd(n,d));
    }
    Fraction Division(Fraction otherFraction)
    {
        int n = numerator*otherFraction.denominator;
        int d = denominator*otherFraction.numerator;
        return Fraction(n/gcd(n,d),d/gcd(n,d));
    }
    // I got the GCD algorithm from the following source:
    // Source C#: http://www.ww.functionx.com/csharp2/examples/gcd.htm
    int gcd(int n, int d)
    {
        int remainder;
        while (d != 0)
        {
            remainder = n % d;
            n = d;
            d = remainder;
        }
        return n;
    }
    void show() // Display method
    {
        if (denominator == 1) // e.g. fraction 2/1 will display simply as 2
            cout << numerator << endl;
        else
            cout << numerator << "/" << denominator << endl;
    }
};

int main()
{
    Fraction a(1,2);
    Fraction b(1,4);
    Fraction c;

    c = a.Sum(b); // Result: 3/4
    c.show();

    c = a.Difference(b); // Result: 1/4
    c.show();

    c = a.Product(b); // Result: 1/8
    c.show();

    c = a.Division(b); // Result: 2
    c.show();

    return 0;
}