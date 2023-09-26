#include <iostream>
using namespace std;

struct student{
    string name;
    string mssv;
};

void typeInforStudent(student array[])
{
    for(int i = 0; i < 2; i++)
    {
        cout << "Enter student's name: ";
        cin >> array[i].name;
        cout << "Enter student's id: ";
        cin >> array[i].mssv;
    }
}

void illustrateInforStudent(student array[])
{
    for(int i = 0; i < 2; i++)
    {
        cout << array[i].name << "-" << array[i].mssv << endl;
    }
}

int main(){
    student s[2];
    typeInforStudent(s);
    illustrateInforStudent(s);
    return 0;
}