#ifndef QUANLY_H
#define QUANLY_H
#include <bits/stdc++.h>
#include <string>
using namespace std;

class QUANLY
{
    private:
        string id;
        string name;
        int age;
        int math;
        int lite;
        int eng;
        float gpa;
    public:
        void input();
        void display();
        double Gpa();
};

#endif // QUANLY_H
