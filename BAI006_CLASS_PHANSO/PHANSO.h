#ifndef PHANSO_H
#define PHANSO_H
#include <bits/stdc++.h>
class PHANSO
{
    private:
        int TuSo;
        int MauSo;
    public:
        PHANSO(int TuSo = 0, int MauSo = 1);
        double Nhap();
        void Xuat();
        PHANSO Tong(PHANSO);
        PHANSO Hieu(PHANSO);
        PHANSO Tich(PHANSO);
        PHANSO Thuong(PHANSO);
        void rutgonphanso();
        float dinhgiatri();
};
#endif // PHANSO_H
