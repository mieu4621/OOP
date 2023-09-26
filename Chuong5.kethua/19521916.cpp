#include <iostream>
using namespace std;
class gate
{
protected:
    int loai;

public:
    gate();
    ~gate();
    virtual void Nhap() = 0;
    virtual int Trave() = 0;
    int GetLoai()
    {
        return loai;
    }
};
class business_gate : public gate
{
protected:
    int don_gia;
    int so_hang;

public:
    business_gate();
    ~business_gate();
    void Nhap()
    {
        cout << "--> Nhap don gia: ";
        cin >> don_gia;
        cout << "--> Nhap so luong hang: ";
        cin >> so_hang;
    }
    int Trave()
    {
        return don_gia * so_hang;
    }
};
class academic_gate : public gate
{
protected:
    int tri_tue;

public:
    academic_gate();
    ~academic_gate();
    void Nhap()
    {
        cout << "--> Nhap tri tue cua nha hien triet: ";
        cin >> tri_tue;
    }
    int Trave()
    {
        return tri_tue;
    }
};
class power_gate : public gate
{
protected:
    int suc_manh;

public:
    power_gate();
    ~power_gate();
    void Nhap()
    {
        cout << "--> Nhap suc manh dung si: ";
        cin >> suc_manh;
    }
    int Trave()
    {
        return suc_manh;
    }
};
int main()
{
    cout << "1. Cong giao thuong" << endl;
    cout << "2. Cong học thuật" << endl;
    cout << "3. Cong suc manh" << endl;
    cout << "Nhap so luong cong: ";
    int SoLuong;
    cin >> SoLuong;
    gate *arrGate[1000];
    // Cau a
    for (int i = 0; i < SoLuong; i++)
    {
        cout << "Nhap loai cong (1,2 hoac 3): ";
        int type;
        cin >> type;
        if (type == 1)
            arrGate[i] = new business_gate();
        if (type == 2)
            arrGate[i] = new academic_gate();
        if (type == 3)
            arrGate[i] = new power_gate();
        arrGate[i]->Nhap();
    }
    int SoTien, TriTue, SucManh;
    cout << "[Nhap thong so cua Hoang Tu]" << endl;
    cout << "--> Nhap so tien: ";
    cin >> SoTien;
    cout << "--> Nhap chi so tri tue: ";
    cin >> TriTue;
    cout << "--> Nhap chi so suc manh: ";
    cin >> SucManh;
    int i = 0;
    while (SoTien > 0 && TriTue > 0 && SucManh > 0 && i < SoLuong)
    {
        if (arrGate[i]->GetLoai() == 1)
        {
            SoTien = arrGate[i]->Trave();
            if (SoTien < 0)
            {
                cout << "Hoang tu da sml o cong " << i + 1;
                break;
            }
            else
            {
                cout << "Hoang tu da vuot qua cong giao thuong[" << i + 1 << "] " << endl;
                cout << "Thong so hien tai[" << SoTien << ", " << TriTue << ", " << SucManh << "] " << endl;
            }
        }
        if (arrGate[i]->GetLoai() == 2)
        {
            if (arrGate[i]->Trave() > TriTue)
            {
                cout << "Hoang tu da sml o cong" << i + 1;
                break;
            }
            else
            {
                cout << "- Hoang tu da vuot qua cong tri tue [" << i + 1 << "]" << endl;
            }
        }
        if (arrGate[i]->GetLoai() == 3)
        {
            SucManh = arrGate[i]->Trave();
            if (SucManh < 0)
            {
                cout << "Hoang tu da sml o cong " << i + 1;
                break;
            }
            else
            {
                cout << "_ Hoang tu da vuot qua cong suc manh [" << i + 1 << "]" << endl;
            }
        }
        if (i == SoLuong - 1)
        {
            cout << "Hoang tu da giai cuu duoc cong chua !!!" << endl;
            break;
        }

        cout << "Thong so hien tai [" << SoTien << ", " << TriTue << ", " << SucManh << "]" << endl;
        i++;
    }
}
