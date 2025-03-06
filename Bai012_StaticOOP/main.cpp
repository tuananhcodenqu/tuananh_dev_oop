#include <bits/stdc++.h>
#include <string>
#include <STATIC.h>
using namespace std;

int main()
{
    int n;
    cout << "Nhap so luong sinh vien: ";
    cin >> n;
    STATIC stu[n];
    for(int i=0;i<n;i++){
        cout << "Thong tin cua sinh vien thu " << i+1 << ":\n";
        stu[i].input();
    }
    cout << "Tong so sinh vien da duoc tao: " << STATIC::getStudentCount() << endl;
    return 0;
}
