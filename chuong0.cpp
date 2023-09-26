#include<iostream>
using namespace std;
// next, improve the code base ? make it shorter ?
struct date
{
    int day;
    int month;
    int year;
};

struct officeWorker
{
    string name;
    date dayOfBirth;
    int dayWorking;
    int salary; 
};

struct productionEmloyee
{
    string name;
    date dayOfBirth;
    int baseSalary;
    int product;
    int salary;
};

void typeInforOfficeWorker(officeWorker a[], int N)
{
    for(int i = 0; i < N; i++)
    {
        cout << "Enter office worker's name: ";
        cin >> a[i].name;
        cout << "Enter office Worker's day of birth: ";
        cin >> a[i].dayOfBirth.day >> a[i].dayOfBirth.month >> a[i].dayOfBirth.year;
        cout << " Enter office worker's day working: ";
        cin >> a[i].dayWorking;
    }
}

void typeInforProductionEmloyee(productionEmloyee b[], int M)
{
    for(int i = 0; i < M; i++)
    {
        cout << "Enter production Emloyee's name: ";
        cin >> b[i].name;
        cout << "Enter production Emloyee's day of birth: ";
        cin >> b[i].dayOfBirth.day >> b[i].dayOfBirth.month >> b[i].dayOfBirth.year;
        cout << " Enter production Emloyee's base salary: ";
        cin >> b[i].baseSalary;
        cout << " Enter production Emloyee's product: ";
        cin >> b[i].product;
        
    }
}

void demonstrateOfficeWorker(officeWorker a[], int N)
{
    for(int i = 0; i < N; i++)
    {
        cout << "Office worker's name: " << a[i].name << endl;
        cout << "Office worker's day of birth: " << a[i].dayOfBirth.day << "/" << a[i].dayOfBirth.month << "/" << a[i].dayOfBirth.year << endl;
        cout << "Office worker's day working : " << a[i].dayWorking << endl;
    }
}

void demonstrateProductionEmloyee(productionEmloyee b[], int M)
{
    for(int i = 0; i < M; i++)
    {
        cout << "ProductionEmloyee's name: " << b[i].name << endl;
        cout << "ProductionEmloyee's day of birth: " << b[i].dayOfBirth.day << "/" << b[i].dayOfBirth.month << "/" << b[i].dayOfBirth.year << endl;
        cout << "ProductionEmloyee's base salary: " <<  b[i].baseSalary<< endl;
        cout << "ProductionEmloyee's product: " <<  b[i].product<< endl;
    }
}

int sumSalaryOfOfficeWorker(officeWorker a[], int N)
{
    int sumO = 0;
    for(int i = 0; i < N; i++ )
    {
        {
        a[i].salary = a[i].dayWorking*100000;
        sumO += a[i].salary;
    }
    cout <<" Sum salary of office worker = " << sumO << endl; // isn't this line work ?
    }    
    return sumO;
}

int sumSalaryOfProductionEmloyee(productionEmloyee b[],int M)
{
    int sumP =0;
    for(int i = 0; i < M; i++)
    {
        {
            b[i].salary = b[i].baseSalary +b[i].product * 5000;
            sumP += b[i].salary;
        }
        cout <<" Sum salary of production employee = " << sumP << endl; // isn't this line work ? idiot

    }
    return sumP;
    
}

void calSalaryOfEachOfficeWorker(officeWorker a[], int N)
{
    for(int i = 0; i < N; i++)
    {
        a[i].salary = a[i].dayWorking*100000;
        cout <<"Salary of each office worker(" <<a[i].name << ") = " << a[i].salary <<endl;
    }
    
}

void calSalaryOfEachProductionEmployee(productionEmloyee b[], int M)
{

    for(int i = 0; i < M; i++)
    {
        b[i].salary = b[i].baseSalary + b[i].product * 5000;
         cout <<"Salary of each production employee (" << b[i].name << ") = " << b[i].salary <<endl;
    }
}

int sumSalary(int sumO, int sumP)
{
    int sumAll = sumO + sumP;
    cout <<" Salary of employee = " << sumAll << endl;
    return sumAll;
}
int sortByDayOfBirth(officeWorker a[], productionEmloyee b[] , int N, int &M )
{
    for( int i = 0; i < N - 1; i++)
    {
        for ( int j = i +1; j < M; j++)
        {
            if(a[i].dayOfBirth.year < a[i + 1].dayOfBirth.year  )
         int swap = a[i].dayOfBirth.day;
         a[i].dayOfBirth.day = b[i].dayOfBirth.day;         

        }
    }
}
// what used of these 2 line ?

// answer me before this morning
// why need declare fun ? ??? annser cc  gi z ?
// we don't EVEN need ? 
//  go sleeep 
// too much for a day ?

int main()
{
    int sumO, sumP;
    int N,M;
    cout <<" Enter N: ";
    cin >> N;
    cout <<" Enter M: ";
    cin >> M;
    officeWorker a[N];
    typeInforOfficeWorker(a, N);
    demonstrateOfficeWorker(a, N);
    sumSalaryOfOfficeWorker(a, N);
    calSalaryOfEachOfficeWorker(a, N);
    productionEmloyee b[M];
    typeInforProductionEmloyee(b, M);
    demonstrateProductionEmloyee(b, M);
    sumSalaryOfProductionEmloyee(b, M);
    calSalaryOfEachProductionEmployee(b, M);
    sumO = sumSalaryOfOfficeWorker(a,N);
    sumP = sumSalaryOfProductionEmloyee(b,M);
    cout << "Sum salary = " << sumO + sumP;
    // too long
    // func name is trash. make  it shorrt and more tech feel.
}