#include <PHANSO.h>
using namespace std;
int main()
{
    PHANSO A(16,8);
    cout << "A = "; A.Xuat();
    A.rutgonphanso();
    cout << "\nSau khi rut gon ta co: "; A.Xuat();
    PHANSO B(10,6);
    cout << "\nB = ";B.Xuat();
    cout << "\nA + B = ";A.Xuat();cout << " + ";B.Xuat();cout <<" = ";A.Tong(B).Xuat();
    cout << "\nA - B = ";A.Xuat();cout << " - ";B.Xuat();cout <<" = ";A.Hieu(B).Xuat();
    cout << "\nA x B = ";A.Xuat();cout << " x ";B.Xuat();cout <<" = ";A.Tich(B).Xuat();
    cout << "\nA : B = ";A.Xuat();cout << " : ";B.Xuat();cout <<" = ";A.Thuong(B).Xuat();
    cout << "\nDinh gia tri phan so thu 1: " << A.dinhgiatri();
    cout << "\nDinh gia tri phan so thu 2: " << B.dinhgiatri();
    return 0;
}
