#include <bits/stdc++.h>
using namespace std;

struct Complex{
    double a;
    double b;
};

Complex  *Nhap (){
    Complex *cplx = new Complex;
    cin >> cplx->a >> cplx->b;
    return cplx;
}

void Xuat (Complex cplx){
    cout << cplx.a;
    if (cplx.b > 0) cout << "+" << cplx.b <<"i";
    if (cplx.b < 0) cout << cplx.b <<"i";
}

Complex Cong (Complex cplx1, Complex cplx2){
    Complex tong;
    tong.a = cplx1.a + cplx2.a;
    tong.b = cplx1.b + cplx2.b;
    return tong;
}

Complex Tru (Complex cplx1, Complex cplx2){
    Complex hieu;
    hieu.a = cplx1.a - cplx2.a;
    hieu.b = cplx1.b - cplx2.b;
    return hieu;
}

Complex Nhan (Complex cplx1, Complex cplx2){
    Complex tich;
    tich.a = cplx1.a * cplx2.a - cplx1.b * cplx2.b;
    tich.b = cplx1.a * cplx2.b + cplx1.b * cplx2.a;
    return tich;
}

Complex Chia (Complex cplx1, Complex cplx2){
    Complex thuong;
    int mau = pow (cplx2.a, 2) + pow (cplx2.b, 2);
    if (mau == 0){
        return {0, 0};
    }
    thuong.a = (cplx1.a * cplx2.a + cplx1.b * cplx2.b)/mau;
    thuong.b = (cplx1.b * cplx2.a - cplx1.a * cplx2.b)/mau;
    return thuong;
}

double Modun (const Complex &cplx){
    double modn = 0;
    int sum = pow(cplx.a, 2) + pow(cplx.b, 2);
    modn = sqrt(sum);
    return modn;
}

int main (){
    Complex *A = Nhap ();
    Complex *B = Nhap ();
    cout << "Tong, hieu, tich , thuong, modun cua hai so phuc lan luot la: ";
    Xuat(Cong(*A, *B)); cout << endl;
    Xuat(Tru(*A, *B)); cout << endl;
    Xuat(Nhan(*A, *B)); cout << endl;
    Xuat(Chia(*A, *B)); cout << endl;
    cout << Modun (*A); cout << endl;
    cout << Modun (*B);
    delete A;
    delete B;
}
