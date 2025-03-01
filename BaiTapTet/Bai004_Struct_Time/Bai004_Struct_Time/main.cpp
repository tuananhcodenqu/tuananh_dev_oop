#include <iostream>
using namespace std;

// 1. Định nghĩa cấu trúc Time
struct Time {
    int hour;
    int mins;
    int sec;
};

// Hàm nhập thời gian
void inputTime(Time &t) {
    cout << "Nhap thoi gian (hour min sec): ";
    cin >> t.hour >> t.mins >> t.sec;

    if (t.hour < 0 || t.hour >= 24 || t.mins < 0 || t.mins >= 60 || t.sec < 0 || t.sec >= 60) {
        cout << "Thoi gian khong hop le" << endl;
        exit(1);  // Dừng chương trình nếu nhập sai
    }
}

// Hàm xuất thời gian
void outputTime(const Time &t) {
    cout << t.hour << " gio " << t.mins << " phut " << t.sec << " giay" << endl;
}

// Hàm xử lý thời gian
Time xuly(Time time, Time extra) {
    Time newtime = time;
    newtime.hour += extra.hour;
    newtime.mins += extra.mins;
    newtime.sec += extra.sec;

    while (newtime.sec >= 60) {
        newtime.sec -= 60;
        newtime.mins++;
        if (newtime.mins >= 60) {
            newtime.mins -= 60;
            newtime.hour++;
            if (newtime.hour >= 24) {
                newtime.hour -= 24;
            }
        }
    }

    return newtime;
}

int main() {
    Time time, extra;

    // Nhập thời gian ban đầu
    inputTime(time);

    // Nhập thời gian cần cộng thêm
    cout << "Nhap thoi gian cong them (hour min sec): ";
    inputTime(extra);

    // Xử lý và xuất kết quả
    Time newtime = xuly(time, extra);
    cout << "Thoi gian sau khi duoc cong them la: ";
    outputTime(newtime);

    return 0;
}
