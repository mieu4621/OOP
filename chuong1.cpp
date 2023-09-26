#include <iostream>
using namespace std;

void Input1Fraction(int &a, int &b)
{
    cout << "Enter a =";
    cin >> a;
    cout << "Enter b =";
    cin >> b;
}

void Output1Fraction(int a, int b)
{
    cout << a << "/" << b;
}
// aKhong can xai mang
int commonDevisor(int a, int b)
{

    int arr[((a > b) ? b : a)];
    int k = 0;
    int i = ((a > b) ? b : a);
    for (int i = ((a > b) ? b : a); i >= 2; i--)
    {

        if (a % i == 0 && b % i == 0)
        {
            arr[k] = i;
            k++;
        }
    }
    if (i == 1)
    {
        return 1;
    }
    else
    {
        return arr[k - 1];
    }
}

void ReduceFraction1(int a, int b)
{
    // Khong nen chia truc tiep 2 gia tri dau vao a va b voi viec khai bao tham chieu
    // vi nhu vay se lam2 thay doi truc tiep du lieu da luu tru
    // 1 cach bad code
    // lay gia tri can chia (uoc chung lon nhat)
    int divideNum = commonDevisor(a, b);
    cout << "\nDevice Number: " << divideNum;
    cout << "\nFraction after reduce: ";
    // chia gia tri va xuat ra
    if (a == b)
    {
        cout << "1";
    }
    else
    {
        Output1Fraction(a / divideNum, b / divideNum);
    }
}
int main()
{
    int a, b;
    Input1Fraction(a, b);
    cout << "Fraction: ";
    Output1Fraction(a, b);
    ReduceFraction1(a, b);
}