#include <iostream>
using namespace std;

class PhanSo
{
    private:
        int tuSo;
        int mauSo;
    public:
        PhanSo()
        {
            tuSo = 0;
            mauSo = 1;
        }
        ~PhanSo(){}
        int getTuSo()
        {
            return tuSo;
        }
        void setTuSo(int tu)
        {
            tuSo = tu;
        }
};

int main()
{
    PhanSo frac;
    int a = frac.getTuSo();
    int b = 8;
    b = 8;
    b = 8;
    
    frac.setTuSo(b);
    
    cout << a;
    return 0;
}