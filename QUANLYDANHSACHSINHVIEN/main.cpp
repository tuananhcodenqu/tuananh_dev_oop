#include <QUANLY.h>
#include <bits/stdc++.h>
using namespace std;

int main()
{
   int n;
   cout << "Nhap so luong sinh vien: ";
   cin >> n;
   vector<QUANLY> stu(n);
   for (int i = 0; i < n; ++i) {
        cout << "\nNhap thong tin sinh vien thu " << i + 1 << ":\n";
        stu[i].input();
   }
   cout << "\nDanh sach sinh vien:\n";
   cout << "ID\tTen\tTuoi\tToan\tVan\tAnh\tDiem TB\n";
    for (auto &x : stu) {
        x.display();
    }
    QUANLY *maxgpa = &stu[0];
    for(auto &x: stu){
        if(x.Gpa() > maxgpa->Gpa()){
            maxgpa = (QUANLY*)&x;
        }
    }
     cout << "\nSinh vien co diem trung binh cao nhat:\n";
    maxgpa->display();
    return 0;
}
