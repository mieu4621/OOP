// Bài 5( chương 1)
#include <iostream>
using namespace std;

struct employee
{
    string id;
    string name;
    string department;
    double baseSalary;
    double bonus;
    double netSalary;
};

void InputInfo(employee a[], int N)
{
    for (int i = 0; i < N; i++)
    {
        cout << "Enter id's employee: ";
        cin >> a[i].id;
        cout << "Enter fullname's employee: ";
        cin >> a[i].name;
        cout << "Enter department: ";
        cin >> a[i].department;
        cout << "Enter base salary: ";
        cin >> a[i].baseSalary;
        cout << "Enter Bonus: ";
        cin >> a[i].bonus;
    }
}

void Output(employee a[], int N)
{
    for (int i = 0; i < N; i++)
    {
        cout << "Id's employee: " << a[i].id << endl;
        cout << "Fullname's employee: " << a[i].name << endl;
        cout << "Department: " << a[i].department << endl;
        cout << "Base salary: " << a[i].baseSalary << endl;
        cout << "Bonus: " << a[i].bonus << endl;
    }
}
double SumSalary(employee a[], int N)
{
    double sum = 0;
    for (int i = 0; i < N; i++)
    {
        a[i].netSalary = a[i].baseSalary + a[i].bonus;
        sum += a[i].netSalary;
    }
    return sum;
}

double MinBaseSalary(employee a[], int N)
{
    double min = a[0].netSalary;
    for (int i = 1; i < N; i++)
    {
        if (a[i].netSalary < min)
        {
            min = a[i].netSalary;
            cout << a[i].name <<a[i].id;
        }
    }
    return min;
}

void OutputWithSalary(employee b)
{
    
}

double Cout(employee a[], int N)
{
    int count = 0;
    for (int i = 0; i < N; i++)
    {
        if (a[i].netSalary > 1200000)
        {
            count++;
        }
    }
    return count;
}
int main()
{
    int N;
    cout << "Enter quality of employee: ";
    cin >> N;
    employee a[N];
    InputInfo(a, N);
    cout << "Sum salary: " << SumSalary(a, N);
    cout << "\nList employees have min salary: \n";
    OutputWithMinSalary(a, N);
    cout <<"Quality of employees have salary > 1200000" << Cout(a, N);
}