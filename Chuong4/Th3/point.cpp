#include<iostream>
using namespace std;
class Point
{
    float hoanhDo;
    float tungDo;
public:
    Point()
    {
        hoanhDo = 0;
        tungDo = 0;
    }
    Point(float x, float y)
    {
        this ->hoanhDo = x;
        this ->tungDo = y;
    }
    friend ostream &operator<< ( ostream &os, Point a)
    {
        os
    }
};