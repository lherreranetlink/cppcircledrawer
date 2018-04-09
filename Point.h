#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED

class Point
{
private:
    int x, y;
public:
    Point();
    Point(int x, int y);
    void setX(int x);
    int getX();
    void setY(int y);
    int getY();
};

#endif // POINT_H_INCLUDED
