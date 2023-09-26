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
    Fraction(int nu)
    {
        this->numerator = nu;
        this->denominator = 1;
    }
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
    friend istream& operator>>(istream &is, Fraction &b)
    {
        cout << "\nEnter numerator of fraction: ";
        is >> b.numerator;
        cout << "Enter denominator: ";
        is >> b.denominator;
        return is;
    }
    friend ostream& operator<<(ostream &os, Fraction b)
    {
        os << "\nFraction: " << b.numerator << "/" << b.denominator;
        return os;
    }
};

class FractionList
{
    int n;
    Fraction *list;

public:
    FractionList()
    {
        n = 0;
        list = new Fraction [1000];
    };
    friend istream& operator>>(istream &is, FractionList &b)
    {
        cout << "Enter quantity: ";
        cin >> b.n;
        for (int i = 0; i < b.n; i++)
        {
            cin >> b.list[i];
        }
    }
    friend ostream& operator<<(ostream &os, FractionList b)
    {
        for (int i = 0; i < b.n; i++)
        {
            cout << b.list[i];
        }
    }
    Fraction sum(){
        Fraction sum;
        for (int i = 0; i < n; i++)
        {
            sum = sum + list[i];
        }
        return sum;
    }
    Fraction mul(){
        Fraction mul(1,1);
        for (int i = 0; i < n; i++)
        {
            mul = mul * list[i];
        }
        return mul;
    }
    void sort(){
        for (int i = 0; i < n - 1; i++)
            for (int j = 0; j < n - i - 1; j++)
                if (list[j] > list[j + 1]) {
                    // swap arr[j+1] and arr[j]
                    Fraction temp = list[j];
                    list[j] = list[j + 1];
                    list[j + 1] = temp;
                }
    }
    Fraction findMax(){
        sort();
        return list[n - 1];
    }
    Fraction sumMaxWithNumber(int n){
        return findMax() + Fraction(n);
    }
};
int main()
{
    FractionList a;
    cin >> a;
    cout << a;
    cout << "\nSum Fraction: ";
    cout << a.sum();
    cout << "\nMutiple Fraction: ";
    cout << a.mul();
    cout << "\nMutiple Fraction: ";
    cout << "\nList Fraction Ascending: ";
    cout << a;
    int n;
    cout << "\nEnter the number want to sum with max fraction: ";
    cin >> n;
    cout << a.sumMaxWithNumber(n);
    return 0;
}
