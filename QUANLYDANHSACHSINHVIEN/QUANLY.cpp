#include "QUANLY.h"
using namespace std;
void QUANLY::input(){
    cout << "Nhap ma sinh vien: ";
        cin >> id;
        cin.ignore();
        cout << "Nhap ten sinh vien: ";
        getline(cin, name);
        cout << "Nhap tuoi: ";
        cin >> age;
        cout << "Nhap diem toan: ";
        cin >> math;
        cout << "Nhap diem Van: ";
        cin >> lite;
        cout << "Nhap diem Anh: ";
        cin >> eng;
}
double QUANLY::Gpa(){
    return (math * 2 + lite * 2 + eng) / 5.0;
}
void QUANLY::display(){
     cout << id << "\t" << name << "\t" << age << "\t"
             << math << "\t" << lite << "\t" << eng << "\t"
             << Gpa() << endl;
}
