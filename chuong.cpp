#include <iostream>
using namespace std;

struct PHANSO
{
    int tuSo;
    int mauSo;
};

void Input(PHANSO x[], int N)
{   
    for ( int i = 0; i < N; i++)
    {
        cout <<"Enter tuSo: ";
        cin >> x[i].tuSo;
        cout << "Enter mauSo";
        cin >> x[i].mauSo;  
    }
    
}



int main()
{   
    int N;
    cout << "Enter N: ";
    cin >> N;
    PHANSO x[N];
    x[0].tuSo = 6;
    x[0].mauSo = 12;
    for(int i = (x[0].tuSo > x[0].mauSo) ? x[0].mauSo:x[0].tuSo; i >= 2; i--)
    {
        if( x[0].tuSo % i == 0 && x[0].mauSo % i == 0)
        {
            x[0].tuSo = x[0].tuSo / i;
            x[0].mauSo = x[0].mauSo / i;
        }
    }
    cout << x[0].tuSo << "/" << x[0].mauSo;
}