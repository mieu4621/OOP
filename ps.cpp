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
        PhanSo(int tuSo, int mauSo)
        {
            this->tuSo = tuSo;
            this->mauSo = mauSo;
        }
        int getTuSo()
        {
            return tuSo;
        }
        void setTuSo(int num)
        {
            tuSo = num;
        }
        void setMauSo(int deno)
        {
            mauSo = deno;
        }
        int getMauSo()
        {
            return mauSo;
        }
        void nhap()
        {
            cin >> tuSo;
            cin >> mauSo;
        }
        void xuat()
        {
            cout << tuSo << "/" << mauSo;
        }
        int timUocChung()
        {
            int n = ((tuSo > mauSo) ? mauSo : tuSo);
            int arr[n];
            int k = 0;
            for (int i = ((tuSo > mauSo) ? mauSo : tuSo); i >= 2; i--)
            {

                if (tuSo % i == 0 && mauSo % i == 0)
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
        void rutgon()
        {
            if (tuSo == mauSo)
            {
                tuSo = 1;
                mauSo = 1;
            }
            else
            {
                tuSo /= commonDevisor();
                mauSo /= commonDevisor();
            }
        }
        PhanSo operator+(PhanSo &a)
        {
            PhanSo result;
            result.setTuSo(this->tuSo * a.getMauSo() + this->mauSo * a.getTuSo());
            result.setMauSo(this->mauSo * a.getMauSo());
            result.rutgon();
            return result;
        }
        PhanSo operator-(PhanSo &a)
        {
            PhanSo result;
            result.setTuSo(this->tuSo * a.getMauSo() - this->mauSo * a.getTuSo());
            result.setMauSo(this->mauSo * a.getMauSo());
            result.rutgon();
            return result;
        }
        void operator=(PhanSo &a)
        {
            this->tuSo = a.getTuSo();
            this->mauSo = a.getMauSo();
        }
        float chuyenSoThuc()
        {
            return (float)tuSo / mauSo;
        }
        int SoSanh(PhanSo &a)
        {
            if (this->chuyenSoThuc() > a.chuyenSoThuc())
            {
                return 1;
            }
            else if (this->chuyenSoThuc() < a.chuyenSoThuc())
            {
                return 1;
            }
            else
                return 0;
        }
        HonSo chuyenHonSo()
        {
            HonSo result;
            result.PhanNguyen = tuSo / mauSo;
            result.PS.setTuSo(tuSo % mauSo);
            result.PS.setMauSo(mauSo);
            return result;
        }
} 

class HonSo
{
    private:
        int phanNguyen;
        PhanSo PS;

    public:
        HonSo()
        {
            phanNguyen = 0;
            PS.setTuSo(0);
            PS.setMauSo(1);
        }
        HonSo(int phanNguyen, int tu, int mau = 1)
        {
            this->phanNguyen = phanNguyen;
            this->PS.setTuSo(tu);
            this->PS.setMauSo(mau);
        }
        int getPhanNguyen()
        {
            return phanNguyen;

        }
        void setPhanNguyen(int pn)
        {
            phanNguyen = pn;
        }
        void setPhanSo(PhanSo PS)
        {
            this->PS = PS;
        }
        int getPhanSo()
        {
            return PS;
        }
        void nhap()
        {
            cin >> phanNguyen;
            PS.nhap();
        }
        void xuat()
        {
            cout << phanNguyen << ":";
            PS.xuat();
        }
        void rutgon()
        {
           phanNguyen += PS.getTuSo() / PS.getMauSo();
           PS.setTuSo(PS.getTuSo() % PS.getMauSo());
        }
        
        PhanSo operator+(PhanSo &a)
        {
           PhanSo sum;
           sum.getMauSo() = tu++
           
        }
        PhanSo operator-(PhanSo &a)
        {
            

        }
        int SoSanh(PhanSo &a)
        {
            
        }
        HonSo chuyenPhanSo()
        {
           
        }

}
 int main()
{
    return 0;
}