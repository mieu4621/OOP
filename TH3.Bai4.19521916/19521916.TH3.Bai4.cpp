#include <iostream>
using namespace std;

class Time
{
    int hour;
    int minute;
    int second;

public:
    Time()
    {
        hour = 0;
        minute = 0;
        second = 0;
    }
    Time(int h , int m, int s)
    {
        this->hour = h;
        this->minute = m;
        this->second = s;
    }
    int getHour()
    {
        return hour;
    }
    int getMinute()
    {
        return minute;
    }
    int getSecond()
    {
        return second;
    }
    void setHour(int hour)
    {
        this->hour = hour;
    }
    void setMinute(int minute)
    {
        this->minute = minute;
    }
    void setSecond(int second)
    {
        this->second = second;
    }
    int exchangeSecond()
    {
       int ex;
       ex = hour*3600 + minute * 60 + second;
       return ex; 
    }
    Time operator-(Time b)
    {
        int s = 0,m = 0,h = 0;
        s = second - b.second;
        h = hour - b.hour;
        m = minute - b.minute;
        if(s < 0){
            s += 60;
            m--;
        }
        if(m < 0){
            m += 60;
            h--;
        }
        if(h < 0){
            return Time(0,0,0);
        }
        else{
            return Time(h,m,s);
        }
        
    } 
    Time operator+(Time b)
    {
        return Time(hour + b.hour + ((minute + b.minute) / 60),((minute + b.minute) + (second + b.second) / 60) % 60,(second + b.second) % 60);
    } 
    friend istream& operator>>(istream &is, Time &b)
    {
        is >> b.hour >> b.minute >> b.second;
        return is;
    }
    friend ostream& operator<<(ostream &os, Time b)
    {
        os << b.hour<< ":" << b.minute<< ":" << b.second;
        return os;
    }

};

int main(){
    Time a(4,10,20);
    Time b(1,30,30);
    Time c;
    c = a - b;
    cin >> c;
    cout << c;
    return 0;
}
