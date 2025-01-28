#include <bits/stdc++.h>
using namespace std;
struct Dathuc{
    int a,b,c;
};
void nhap(Dathuc &p ){
    cout << "Nhap he so a: ";
    cin >> p.a;
    cout << "Nhap he so b: ";
    cin >> p.b;
    cout << "Nhap he so c: ";
    cin >> p.c;
}
void xuat(Dathuc &p){
     if (p.a != 0) {
            if (p.a > 0) cout << p.a << "x^2 ";
            else cout << "- " << -p.a << "x^2 ";
        }
        if (p.b != 0) {
            if (p.b > 0) cout << "+ " << p.b << "x ";
            else cout << "- " << -p.b << "x ";
        }
        if (p.c != 0) {
            if (p.c > 0) cout << "+ " << p.c;
            else cout << "- " << -p.c;
        }
        if (p.a == 0 && p.b == 0 && p.c == 0) {
            cout << "0";
        }
        cout << endl;
    }
// Hàm cộng 2 đa thức
Dathuc cong2dathuc(Dathuc p1, Dathuc p2){
    Dathuc p3;
    p3.a=p1.a+p2.a;
    p3.b=p1.b+p2.b;
    p3.c=p1.c+p2.c;
    return p3;
}
// Hàm trừ 2 đa thức
Dathuc tru2dathuc(Dathuc p1, Dathuc p2){
    Dathuc p4;
    p4.a=p1.a-p2.a;
    p4.b=p1.b-p2.b;
    p4.c=p1.c-p2.c;
    return p4;
}
// Hàm nhân 2 đa thức
void nhan2dathuc(Dathuc p1, Dathuc p2){

    double d4 = p1.a * p2.a;                        // x^4
    double d3 = p1.a * p2.b + p1.b * p2.a;          // x^3
    double d2 = p1.a * p2.c + p1.b * p2.b + p1.c * p2.a; // x^2
    double d1 = p1.b * p2.c + p1.c * p2.b;          // x
    double d0 = p1.c * p2.c;                        // hằng số
     cout << "Ket qua sau khi nhan la: " << endl;
    cout << d4 << "x^4 + " << d3 << "x^3 + " << d2 << "x^2 + " << d1 << "x + " << d0 << endl;
    cout << "Gia tri cua da thuc F(0) la: " << d0;
}
int main(){
    Dathuc p1,p2;
    cout << "Nhap da thuc thu 1: ";
    nhap(p1);
    xuat(p1);
    cout << "Nhap da thuc thu 2: ";
    nhap(p2);
    xuat(p2);
    Dathuc tong=cong2dathuc(p1,p2);
    cout << "Da thuc sau khi cong la: ";
    xuat(tong);
    cout << "Gia tri cua da thuc F(0) la: " << tong.c << endl;
    Dathuc hieu=tru2dathuc(p1,p2);
    cout << "Da thuc sau khi tru la: ";
    xuat(hieu);
    cout << "Gia tri cua da thuc F(0) la: " << hieu.c << endl;
    nhan2dathuc(p1,p2);
}
