#include <iostream>
using namespace std;

// 1. Định nghĩa cấu trúc Date
struct Date {
	int day;
	int month;
	int year;
};

// 2. Kiểm tra năm nhuận
bool isLeapYear(int year) {
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// 3. Hàm trả về số ngày trong một tháng
int daysInMonth(int month, int year) {
    switch (month) {
    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
        return 31;
    case 4: case 6: case 9: case 11:
        return 30;
    case 2:
        return isLeapYear(year) ? 29 : 28;
    default:
        return 0;
    }
}

// 4. Hàm trả về ngày tiếp theo
Date getNextDay(Date current) {
    Date nextDate = current;
    nextDate.day++;

    if (nextDate.day > daysInMonth(current.month, current.year)) {
        nextDate.day = 1;
        nextDate.month++;

        if (nextDate.month > 12) {
            nextDate.month = 1;
            nextDate.year++;
        }
    }

    return nextDate;
}
Date addXday(Date current, int x){
    Date resDate=current;
    resDate.day = current.day+x;
    while(resDate.day > daysInMonth(current.month, current.year)) {
        resDate.day -= daysInMonth(current.month, current.year);
        resDate.month++;

        if (resDate.month > 12) {
            resDate.month = 1;
            resDate.year++;
            }
    }
    return resDate;
}
int main() {
    Date today;

    cout << "Nhap ngay (dd mm yyyy): ";
    cin >> today.day >> today.month >> today.year;

    if (today.month < 1 || today.month > 12 || today.day < 1 || today.day > daysInMonth(today.month, today.year)) {
        cout << "Ngay khong hop le" << endl;
        return 1;
    }

//    Date nextDay = getNextDay(today);
//
//    cout << "Ngay tiep theo la: " << nextDay.day << "/" << nextDay.month << "/" << nextDay.year << endl;
    int x;
    cout << "Cong them "; cin >> x; cout << "ngay tiep theo " << endl;
    Date resDay= addXday(today,x);
    cout << "sau khi cong them " << x << " ngay thi ngay tiep theo la: " << resDay.day << "/" << resDay.month << "/" << resDay.year << endl;
    return 0;
}
