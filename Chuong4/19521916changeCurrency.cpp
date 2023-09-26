#include <iostream>
using namespace std;

enum curUnit
{
    vnd,
    usd,
    aud,
    eur,
    jpy
};
class Currency
{
    float money;
    curUnit unit;
    float exchageRate;

public:
    Currency()
    {
        money = 0;
        unit = usd;
        exchageRate = 0;
    }
    Currency(float money, curUnit unit, float exchageRate)
    {
        this->money = money;
        this->unit = unit;
        this->exchageRate = exchageRate;
    }
    float getMoney()
    {
        return money;
    }
    curUnit getUnit()
    {
        return unit;
    }
    float getExchageRate()
    {
        return exchageRate;
    }
    friend istream &operator>>(istream &is, Currency &b)
    {
        int u;
        is >> b.money >> u;
        switch (u)
        {
        case 1:
            b.unit = vnd;
            break;
        case 2:
            b.unit = usd;
            break;
        case 3:
            b.unit = aud;
            break;
        case 4:
            b.unit = eur;
            break;
        case 5:
            b.unit = jpy;
            break;
        }
        return is;
    }
    friend ostream &operator<<(ostream &os, Currency b)
    {
        os << b.money << " " << b.unit << "Exchage rate: " << b.exchageRate;
        return os;
    }
    Currency ExchageMoney()
    {
        Currency ex;
        switch (unit)
        {
        case vnd:
            ex.money = money * 0.00042;

            break;
        case usd:
            ex.money = money * 1;
            break;
        case aud:
            ex.money = money * 0.683298;
            break;
        case jpy:
            ex.money = money * 0.007605;
            break;
        case eur:
            ex.money = money * 1.122;
            break;
        }
        ex.unit = usd;
        return ex;
    }
    Currency operator+(Currency b)
    {
        Currency sum;
        sum.money = this->ExchageMoney().money + b.ExchageMoney().money;
        sum.unit = usd;
        return sum;
    }
    Currency operator-(Currency b)
    {
        Currency minus;
        minus.money = this->ExchageMoney().money - b.ExchageMoney().money;
        minus.unit = usd;
        return minus;
    }
    Currency operator++()
    {
        Currency sumMoney;
        sumMoney.money = this->money + 1;
        sumMoney.unit = this -> unit;
        return sumMoney;
    }
    Currency operator--()
    {
        Currency misMoney;
        misMoney.money = this->money - 1;
        misMoney.unit = this -> unit;
        return misMoney;
    }
    bool operator>(Currency b)
    {
        if (this->ExchageMoney().money > b.ExchageMoney().money)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool operator<(Currency b)
    {
        return this->ExchageMoney().money < b.ExchageMoney().money;
    }
    bool operator==(Currency b)
    {
        return this->ExchageMoney().money == b.ExchageMoney().money;
    }
};
int main()
{
    Currency a, b;
    cin >> a;
    cout << a << endl;
    cin >> b;
    cout << b << endl;
    cout << a + b<< endl;
    cout << a - b << endl;
    cout << ++a << endl;
    cout << --a << endl;
    if (a > b)
    {
        cout << true << endl;
    }
    else
    {
        cout << false << endl;
    }
    if (a < b)
    {
        cout << true << endl;
    }
    else
    {
        cout << false << endl;
    }
    if (a == b)
    {
        cout << true << endl;
    }
    else
    {
        cout << false << endl;
    }
}