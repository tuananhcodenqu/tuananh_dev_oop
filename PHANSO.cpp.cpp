#include "PHANSO.h"
using namespace std;
int gcd(int a, int b){
    return (b==0) ? a : gcd(b,a%b);
}
PHANSO::PHANSO(int TuSo, int MauSo){
    this->TuSo = TuSo;
    this->MauSo = MauSo;
}
void PHANSO::rutgonphanso(){
        int uocchunglonnhat=gcd(TuSo,MauSo);
        this->TuSo /= uocchunglonnhat;
        this->MauSo /= uocchunglonnhat;
        if( this->MauSo < 0 ){
            this->TuSo = -(this->TuSo);
            this->MauSo = -(this->MauSo);
        }
}
double PHANSO::Nhap(){
    return (double(TuSo)/MauSo);
}
void PHANSO::Xuat(){
    if(this->MauSo ==1){cout << this->TuSo;}
    else{
        cout << this->TuSo << "/" << this->MauSo;
    }
}
PHANSO PHANSO::Tong(PHANSO ps){
    PHANSO add;
    add.TuSo = this->TuSo*ps.MauSo + this->MauSo*ps.TuSo;
    add.MauSo = this->MauSo * ps.MauSo;
    add.rutgonphanso();
    return add;
}
PHANSO PHANSO::Hieu(PHANSO ps){
    PHANSO subtract;
    subtract.TuSo = this->TuSo*ps.MauSo - this->MauSo*ps.TuSo;
    subtract.MauSo = this->MauSo * ps.MauSo;
    subtract.rutgonphanso();
    return subtract;
}
PHANSO PHANSO::Tich(PHANSO ps){
    PHANSO multify;
    multify.TuSo = this->TuSo*ps.TuSo;
    multify.MauSo = this->MauSo * ps.MauSo;
    multify.rutgonphanso();
    return multify;
}
PHANSO PHANSO::Thuong(PHANSO ps){
    PHANSO divide;
    divide.TuSo = this->TuSo*ps.TuSo;
    divide.MauSo = this->MauSo * ps.MauSo;
    divide.rutgonphanso();
    return divide;
}
float PHANSO::dinhgiatri(){
    return (float(TuSo)/MauSo);
}
