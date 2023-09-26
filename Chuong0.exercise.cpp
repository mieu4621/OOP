#include <iostream>
using namespace std;

struct Date{
  int day;
  int month;
  int year;
};

struct officeWorker {
  string name;
  Date dayOfBirth;
  int dayWorking;
  float salary;
};

struct productionEmployee{
  string name;
  Date dayOfBirth;
  int baseSalary;
  int product;
  float salary;
};

int calculateSalary (int baseSalary , int product, int dayWorking)
{
//   int SN,SM;
//   SN = baseSalary + product * 5000;
//   SM = dayWorking * 100000;
//   return SN ;
    return baseSalary + product * 5000 + dayWorking * 100000;
}

void typeInforOfficeWorker(officeWorker arr[], int n){
    for(int i =0; i<=n; i++){
        cout << "Enter oficeWoker a[" << i << "] : ";
        cout << "\nEnter name: ";
        cin >> arr[i].name;
        cout <<"\nEnter day of birth:";
        cout <<"\nEnter day: ";
        cin >> arr[i].dayOfBirth.day;
        cout <<"\nEnter month: ";
        cin >> arr[i].dayOfBirth.month;
        cout <<"\nEnter year: ";
        cin >> arr[i].dayOfBirth.year;
        cout <<"\nEnter day working: ";
        cin >> arr[i].dayWorking;
        arr[i].salary = calculateSalary(0,0,arr[i].dayWorking);
    }
};
productionEmployee typeInforProductionEmployee(){
//   productionEmployee employee;
    for(int i = 0; i < M; i++)
    {
        cout << "\nEnter name: ";
         cin >> employee.name;
        cout <<"\nEnter day of birth:";
        cout <<"\nEnter day: ";
        cin >> employee.dayOfBirth.day;
        cout <<"\nEnter month: ";
        cin >> employee.dayOfBirth.month;
        cout <<"\nEnter year: ";
        cin >> employee.dayOfBirth.year;
        cout <<"\nEnter base salary: ";
        cin >> employee.baseSalary;
        cout <<"\nEnter the number of product: ";
        cin >> employee.product;
        employee.salary = calculateSalary(employee.baseSalary,employee.product,0);
        return employee;
    }
    
};
void demontrateInforOfficeWorker(officeWorker worker){
    cout << "\nName: " << worker.name << endl ;
    cout << "Day of Birth: " << worker.dayOfBirth.day << "/" << worker.dayOfBirth.month << "/" << worker.dayOfBirth.year << endl;
    cout << "Day working: " << worker.dayWorking << endl;
    cout << "Salary: " << worker.salary;
};

void demontrateInforProductionEmployee(productionEmployee employee){
    cout << "\nName: " << employee.name << endl ;
    cout << "Day of Birth: " << employee.dayOfBirth.day << "/" << employee.dayOfBirth.month << "/" << employee.dayOfBirth.year << endl;
    cout << "Base salary: " << employee.baseSalary << endl;
    cout << "The number of product: " << employee.product << endl;
    cout << "Salary: "<< employee.salary;
};

int main() {
    
    // int N,M;
    // cin>>N>>M;
    // cout << "Quatity of office workers " << N << "\n";
    // cout << "Quatity of production employees " << M << "\n";



    cout << "\nOffice Worker: ";
    officeWorker a[];
    productionEmployee b[];
    a = typeInforOfficeWorker();

    cout << "\nProduct Employee: ";
    productionEmployee b;
    b = typeInforProductionEmployee();

    cout << "\nOffice Worker: ";
    demontrateInforOfficeWorker(a);
    cout << "\nProduct Employee: ";
    demontrateInforProductionEmployee(b);
    return 0;
}
