#ifndef STATIC_H
#define STATIC_H
#include <iostream>
#include <string>
class STATIC
{
    private:
        std::string name;
        int id;
        static int studentCount;
    public:
        STATIC();
        void input();
        void display();
        static int getStudentCount();
};


#endif // STATIC_H
