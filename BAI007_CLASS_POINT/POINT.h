#ifndef POINT_H
#define POINT_H


class POINT
{
    private:
        int x;
        int y;
    public:
        POINT(int x =0 , int y=0);
        void Input();
        POINT Move(POINT);
        void Display();
        float Distance(POINT);
};

#endif // POINT_H
