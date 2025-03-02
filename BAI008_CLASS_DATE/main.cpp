#include <iostream>
#include <DATE.h>
using namespace std;

int main()
{
    DATE today;
    int x;
    cout << "Ngay hom nay la: ";today.input();today.display();
    DATE nextday = today.getnextday();
    cout << "\nNgay mai la ngay: ";nextday.display();
    cout << " \nNhap x: ";
    cin >> x;
    DATE getxday = today.getxday(x);
    cout << x << " ngay nua la ngay: ";;getxday.display();
    return 0;
}
