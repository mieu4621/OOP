#include <iostream>
using namespace std;
// a.
struct date
{
    int day;
    int month;
    int year;
};
bool checkNamNhuan(date a){
    if(a.year % 400 == 0 || a.year % 4 == 0){
        return true;
    }
    return false;
}
bool checkDay(date a){
    switch (a.month)
    {
        case 2:
            if(a.day <= 29 && checkNamNhuan(a) || a.day <= 28 && !checkNamNhuan(a)){
                return true;
            }
            else {
                return false;
            }
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            if(a.day <= 30){
                return true;
            }
            else{
                return false;
            }
            break;
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            if(a.day <= 31){
                return true;
            }
            else{
                return false;
            }
            break;
        default:
            break;
    }
}

void Input(date &a)
{
    cout << "Enter year: " << endl;
    cin >> a.year;
    do
    {
        cout << "Enter valid month (1 - 12): ";
        cin >> a.month;
    } while (a.month < 1 || a.month > 12);
    do
    {
        cout << "Enter valid day: ";
        cin >> a.day;
    } while (!checkDay(a));
}

void OutputNextDay(date &a)
{
  
    a.day += 1;
    if(a.month <= 12 && !checkDay(a)){
        a.day = 1;
        a.month += 1;
    }
    if(a.month > 12){
        a.month = 1;
        a.year += 1;
    }
    cout << " Tomorrow is: " << a.day << "/" << a.month << "/" << a.year << endl;
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