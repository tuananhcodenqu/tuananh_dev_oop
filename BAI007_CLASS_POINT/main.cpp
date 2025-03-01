#include <POINT.h>
#include <iostream>
using namespace std;

int main()
{
    POINT a,b;
    cout << "Nhap toa do ban dau: ";a.Input();
    cout << "Nhap tung do va hoanh do dich chuyen: ";b.Input();
    cout << "Sau khi di chuyen la: ";b.Move(a);b.Display();
    cout << "\nKhoang cach giua diem ban dau va diem sau khi dich chuyen la:  "<< a.Distance(b);
}
