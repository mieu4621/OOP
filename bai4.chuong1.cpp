//Bài 4(chương 1)
#include <iostream>
using namespace std;
// a.
struct date
{
    int day;
    int month;
    int year;
};

void Input(date &a)
{
    cout << "Enter date: ";
    cin >> a.day >> a.month >> a.year;
}

void OutputNextDay(date &a)
{  
    if( a.day == 31 && a.month < 12){
        a.day = 1;
        a.month += 1;
    }
    else if(a.day == 31 && a.month == 12)
    {
        a.day = 1;
        a.month = 1;
        a.year += 1;
    }
    else
    {
        a.day += 1;
    }
    cout << " Tomorrow is: " << a.day << "/" << a.month << "/" << a.year;
}
//b.
struct Student
{
    string fullName;
    int math;
    int literature;
    float average;
};

void InputSudent(Student &b)
{
    cout << "Enter student's name: ";
    cin >> b.fullName;
    cout << " Enter mark of math: ";
    cin >> b.math;
    while(b.math < 0 || b.math > 10)
    {
        cout <<"Mark only have value from 0 to 10. Please, enter mark of math again:";
        cin >> b.math;
    }
    cout << "Enter mark of literature: ";
    cin >> b.literature;
    while(b.literature < 0 || b.literature > 10) 
    {
        cout <<"Mark only have value from 0 to 10. Please, enter mark of literature again:";
        cin >> b.literature;
    }
}

float AverageScore(Student &b)
{
    b.average = ((float)b.math + b.literature)/2;
    return b.average;
}

void OuputStudent(Student b)
{
    cout << "Student's name: " << b.fullName << endl;
    cout << "Mark of math: " << b.math <<endl;
    cout << "Mark of literature: " << b.literature << endl;
    cout << "Average: " << b.average;
}

int main(){
//a.
    date a;
    Input(a);
    OutputNextDay(a);
//b.
    Student b;
    InputSudent(b);
    AverageScore(b);
    OuputStudent(b);
}