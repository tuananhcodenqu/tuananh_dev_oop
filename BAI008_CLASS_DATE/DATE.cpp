#include "DATE.h"
#include <bits/stdc++.h>
using namespace std;
bool isLeapYear(int year){
    return (year % 4 ==0 && year % 100 !=0) || (year % 4 == 0);
}
int daysInMonth(int month, int year){
    switch(month){
    case 1 : case 3 : case 5 : case 7 : case 8 : case 10 : case 12:
        return 31;
    case 4 : case 6 : case 9 : case 11 :
        return 30;
    case 2 :
        return isLeapYear(year) ? 29 : 28;
    }
}
void DATE::input(){
    do{cin >> day >> month >> year;}while(day < 1 || day > daysInMonth(month,year) || month < 1 || month > 12);
}
void DATE::display(){
    cout << "Ngay " << day << " Thang " << month << " Nam " << year;
}
DATE DATE::getnextday(){
    DATE nextday = *this;
    nextday.day++;
    if(nextday.day > daysInMonth(nextday.month,nextday.year)){
        nextday.day=1;
        nextday.month++;
        if(nextday.month > 12){
            nextday.month=1;
            nextday.year++;
        }
    }
    return nextday;
}
DATE DATE::getxday(int x){
    DATE resday = *this;
    resday.day += x;
    while(resday.day > daysInMonth(resday.month,resday.year)){
        resday.day -= daysInMonth(resday.month,resday.year);
        resday.month++;
    if(resday.month > 12 ){
        resday.month = 1;
        resday.year++;
        }
    }
    return resday;
}
