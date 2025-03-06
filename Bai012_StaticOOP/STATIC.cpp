#include "STATIC.h"
#include <bits/stdc++.h>
#include <string>
using namespace std;
int STATIC::studentCount = 0;
STATIC::STATIC(){
    studentCount++;
}
void STATIC::input(){
    cout << "Nhap ten sinh vien: ";
    cin >> name;
    cin.ignore();
    cout << "Nhap ma sinh vien: ";
    cin >> id;
}
void STATIC::display(){
    cout << "NAME: " << name << "ID: " << id << endl;
}
int STATIC::getStudentCount() {
    return studentCount;
}
