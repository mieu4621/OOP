#include <iostream>
#include<math.h>
using namespace std;

class complexNumber
{
    double real;
    double imaginary;

public:
    complexNumber()
    {
        real = 0;
        imaginary = 0;
    }
    complexNumber( double r,double im)
    {
        this->real = r;
        this ->imaginary = im;
    }
    double getReal()
    {
        return real;
    }
    double getImaginary()
    {
        return imaginary;
    }
    void setReal()
    {
        this -> real = real;   
    }
    void setImaginary()
    {
        this->imaginary = imaginary;
    }
    ~complexNumber()
    {

    }
    friend istream& operator>>(istream &is, complexNumber &b)
    {
        cout << "Enter real number: ";
        is >> b.real;
        cout << "Enter imaginary number: ";
        is >> b.imaginary;
        return is;
    }
    friend ostream& operator<<(ostream &os, complexNumber b)
    {
        if (b.real == 0 && b.imaginary == 0)
        {
            os << "Complex number = 0" << "\n"; 
        }
        else if (b.real == 0 && b.imaginary != 0)
        {
            os << "Complex number = " << b.imaginary << "i" << "\n";
        }
        else if (b.real != 0 && b.imaginary == 0)
        {
            os << "Complex number = " << b.real<< "\n";
        }
        else
        { 
            if (b.imaginary < 0)
            os <<"Complex number = " << b.real << (b.imaginary)<< "i"<< "\n";
            else
            os <<"Complex number = " << b.real << "+" << b.imaginary << "i"<< "\n";
        }
        return os;
    }
    bool operator==(complexNumber b)
    {
        if(real == b.real && imaginary == b.imaginary)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool operator!=(complexNumber b)
    {
        if(real != b.real || imaginary != b.imaginary)
        {
            return true;
        }
        else
        {
            return false;
        }
    }   
    complexNumber operator+(complexNumber b)
    {
        complexNumber add;
        add.real = real + b.real;
        add.imaginary = imaginary +b.imaginary;
        return add;
    }
     complexNumber operator-(complexNumber b)
    {
        complexNumber sub;
        sub.real = real - b.real;
        sub.imaginary = imaginary +b.imaginary;
        return sub;
    }
    complexNumber operator*(complexNumber b)
    {
        complexNumber multi;
        multi.real = real*b.real - imaginary*b.imaginary;
        multi.imaginary = real*b.imaginary + imaginary*b.real;
        return multi;
    }
    complexNumber operator/(complexNumber b)
    {
        complexNumber dis;
        dis.real = (real*b.real - imaginary*b.imaginary)/ (pow(b.real,2) +pow(b.imaginary,2));
        dis.imaginary = (imaginary*b.real - real*b.imaginary) / (pow(b.real,2) + pow(b.imaginary,2));
    }

};
int main()
{
    complexNumber a,b;
    cin >> a;
    cin >> b;
    cout << a;
    cout <<"sum: " << a + b << "\n";
    cout <<"sub: " << a - b << "\n";
    cout <<"multi: " << a * b << "\n";
    cout <<"Dis: " << a / b << "\n";
    cout <<"Compare =" << (a == b) ;
    cout <<"Compare !=" << (a != b) ;
}