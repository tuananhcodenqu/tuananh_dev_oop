#include "POINT.h"
#include <bits/stdc++.h>
using namespace std;
POINT::POINT(int x, int y){
    this->x=x;
    this->y=y;
}
void POINT::Input(){
    cin >> x;
    cin >> y;
}
POINT POINT::Move(POINT a){
    this->x+=a.x;
    this->y+=a.y;
    return *this;
}
void POINT::Display(){
    cout << "(" << x << "," << y << ")";
}
float POINT::Distance(POINT a){
    return sqrt(pow(this->x-a.x,2)+pow(this->y-a.y,2));
}
