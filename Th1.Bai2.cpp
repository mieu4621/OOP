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
    // Day la cach tinh nam nhuan theo am lich cu 19 nam 1 lan nen khong phu hop voi bai toan nay
    // da test cac case nhung khong work
    // switch (a.year % 19)
    // {
    //     case 0:
    //     case 3:
    //     case 6:
    //     case 9: 
    //     case 11: 
    //     case 14:
    //     case 17:
    //         return true;
    //         break;
        
    //     default:
    //         break;
    // }
    // return false;
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
    // if (a.day == 31 && a.month < 12)
    // {
    //     a.day = 1;
    //     a.month += 1;
    // }
    // else if (a.day == 31 && a.month == 12)
    // {
    //     a.day = 1;
    //     a.month = 1;
    //     a.year += 1;
    // }
    // else
    // {
    //     a.day += 1;
    // }
    a.day += 1;
    if(a.month <= 12 && !checkDay(a)){
        a.day = 1;
        a.month += 1;
    }
    if(a.month > 12){
        a.month = 1;
        a.year += 1;
    }
    cout << " Tomorrow is: " << a.day << "/" << a.month << "/" << a.year;
}

int main(){
//a.
    date a;
    Input(a);
    OutputNextDay(a);
}