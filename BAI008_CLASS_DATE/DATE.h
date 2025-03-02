#ifndef DATE_H
#define DATE_H


class DATE
{
    private:
        int day;
        int month;
        int year;
    public:
        void input();
        void display();
        DATE getnextday();
        DATE getxday(int x);
};

#endif // DATE_H
