#include <iostream>
using namespace std;
#include <cmath>

class DaThuc
{
    int bac;
    int *mu;
    int *heSo;

public:
    DaThuc()
    {
        bac = 0;
        mu = new int [1000];
        heSo = new int [1000];
    }
    DaThuc(int bac)
    {
        this->bac = bac;
        mu = new int[bac];
        heSo = new int[bac];
        for(int i = bac; i >= 0; i--)
        {
            mu[i] = i;
            heSo[i] = 0;
        }
    }
    int getBac()
    {
        return bac;
    }
    int* getHeSo()
    {
        return heSo;
    }
    int* getMu()
    {
        return mu;
    }
    friend iostream& operator >> (istream& is, DaThuc &b)
    {
        cout << "Nhap bac: ";
        is >> b.bac;
        b.mu = new int[b.bac];
        b.heSo = new int[b.bac];
        for(int i = b.bac; i >= 0; i--)
        {
            b.mu[i] = i;
            if(i != 0){
                cout << "Nhap he so cho x" << i << " : ";
            }
            else{
                cout << "Nhap he so tu do: ";
            } 
            is >> b.heSo[i];
        }
    }
    friend ostream& operator << (ostream& os, DaThuc b)
    {
        for(int i = b.bac; i > 0; i--)
        {
            if(b.heSo[i] != 1){
                if (b.heSo[i] == -1){
                    os << "-";
                }
                else if (b.heSo[i] != 0){
                    os << b.heSo[i];
                }
            }
            if(b.heSo[i] != 0){
                os << "x";
                if(b.mu[i] != 1){
                    os << b.mu[i];
                }
                if (b.heSo[i] > 0){
                    os << "+";
                }
            }  
        }
        os << b.heSo[0];
    }
    double sum(int x){
        double sum = 0;
        for(int i = bac; i >= 0; i--){
            sum += heSo[i] * pow(x,mu[i]);
        }
        return sum;
    }
    DaThuc operator+(DaThuc b)
    {
        int tmpBac = 0;
        if(bac > b.bac){
            tmpBac = bac;
        }
        else{
            tmpBac = b.bac;
        }
        DaThuc result(tmpBac);
        for(int i = result.bac; i >= 0; i--){
            if(result.mu[i] == this->mu[i]){
                result.heSo[i] += this->heSo[i];
            }
            if(result.mu[i] == b.mu[i]){
                result.heSo[i] += b.heSo[i];
            }
        }
        return result;
    }
    DaThuc operator-(DaThuc b)
    {
        int tmpBac = 0;
        if(bac > b.bac){
            tmpBac = bac;
        }
        else{
            tmpBac = b.bac;
        }
        DaThuc result(tmpBac);

        for(int i = result.bac; i >= 0; i--){
            if(this->mu[i] == b.mu[i]){
                result.heSo[i] = this->heSo[i]  - b.heSo[i];
            }
            else{
                if(result.bac == this->bac){
                    result.heSo[i] = this->heSo[i];
                }
                else{
                    result.heSo[i] -= b.heSo[i];
                }
            }
        }
        return result;
    }
    DaThuc operator*(DaThuc b)
    {
        int tmpBac = 0;
        if(bac > b.bac){
            tmpBac = bac;
        }
        else{
            tmpBac = b.bac;
        }
        DaThuc result(tmpBac);
        for(int i = result.bac; i >= 0; i--){
            result.heSo[i] = 1;
            if(result.mu[i] == this->mu[i]){
                result.heSo[i] *= this->heSo[i];
            }
            if(result.mu[i] == b.mu[i]){
                result.heSo[i] *= b.heSo[i];
            }
        }
        return result;
    }
    DaThuc operator++()
    {
        for(int i = bac; i >= 0; i--){
            this->heSo[i] += 1;
        }
        return *this;
    }
    DaThuc operator++(int)
    {
        DaThuc t = *this;
        for(int i = bac; i >= 0; i--){
            this->heSo[i] += 1;
        }
        return *this;
    }
    DaThuc operator--()
    {
        for(int i = bac; i >= 0; i--){
            this->heSo[i] -= 1;
        }
        return *this;
    }
    DaThuc operator--(int)
    {
        DaThuc t = *this;
        for(int i = bac; i >= 0; i--){
            this->heSo[i] -= 1;
        }
        return *this;
    }
    int operator[](int i){
        return heSo[i];
    }
};
int main(){
    DaThuc a,b;
    cin >> a;
    cout << a << endl;
    int x;
    cout << "\nNhap x de tinh gia tri: ";
    cin >> x;
    cout << "Sum: " << a.sum(x);
    cin >> b;
    cout << a << endl;
    cout << b << endl;
    cout << a + b << endl;
    cout << a - b << endl;
    cout << a * b << endl;
    a++;
    cout << "\na sau khi ++ :";
    cout << a;
    b--;
    cout << "\nb sau khi -- :";
    cout << b;
    int t;
    cout << "Nhap i: ";
    cin >> t;
    cout << "Chi so cua bac thu " << t << " la : " << a[t];
    return 0;
}