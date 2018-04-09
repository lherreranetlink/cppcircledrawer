#include "CircleDrawer.h"

CircleDrawer::CircleDrawer(Point init, int radius)
{
    this->center = init;
    this->radius = radius;

    bresenhamColor[0] = 0;
    bresenhamColor[1] = 0;
    bresenhamColor[2] = 0;
    ddaColor[0] = 255;
    ddaColor[1] = 0;
    ddaColor[2] = 0;
}

CircleDrawer::CircleDrawer(int beginX, int beginY, int finalX, int finalY)
{
    this->center.setX(beginX);
    this->center.setY(beginY);

    this->radius = sqrt(pow(finalX - beginX, 2) + pow(finalY - beginY, 2));

    imgBresenham.assign("bresenhamMap.bmp");
    imgDDA.assign("ddaMap.bmp");

    bresenhamColor[0] = 0;
    bresenhamColor[1] = 0;
    bresenhamColor[2] = 0;
    ddaColor[0] = 255;
    ddaColor[1] = 0;
    ddaColor[2] = 0;
}

void CircleDrawer::bresenhamAlgorithm()
{
    int x, y, p = 1 - this->radius;
    x = 0;
    y = this->radius;
    Point actual(x, y);

    proyectPoints(actual);
    while (actual.getX() < actual.getY())
    {
        actual.setX(actual.getX() + 1);
        if (p < 0)
            p = p + 2 * actual.getX() + 1;
        else
        {
            actual.setY(actual.getY() - 1);
            p = p + 2 * (actual.getX() - actual.getY()) + 1;
        }
        proyectPoints(actual);
    }
}

void CircleDrawer::proyectPoints(Point actual)
{
    imgBresenham.draw_point(center.getX() + actual.getX(), center.getY() + actual.getY(), bresenhamColor);
    imgBresenham.draw_point(center.getX() - actual.getX(), center.getY() + actual.getY(), bresenhamColor);
    imgBresenham.draw_point(center.getX() + actual.getX(), center.getY() - actual.getY(), bresenhamColor);
    imgBresenham.draw_point(center.getX() - actual.getX(), center.getY() - actual.getY(), bresenhamColor);
    imgBresenham.draw_point(center.getX() + actual.getY(), center.getY() + actual.getX(), bresenhamColor);
    imgBresenham.draw_point(center.getX() - actual.getY(), center.getY() + actual.getX(), bresenhamColor);
    imgBresenham.draw_point(center.getX() + actual.getY(), center.getY() - actual.getX(), bresenhamColor);
    imgBresenham.draw_point(center.getX() - actual.getY(), center.getY() - actual.getX(), bresenhamColor);
}

void CircleDrawer::ddaAlgorithm()
{
    float xc1,xc2,yc1,yc2,eps,sx,sy;
    int val, i;

    xc1 = this->radius;
    yc1 = 0;
    sx = xc1;
    sy = yc1;
    i = 0;

    do
    {
        val = pow(2, i++);
    }
    while(val < this->radius);

    eps = 1 / pow(2, i - 1);

    do
    {
        xc2 = xc1 + yc1 * eps;
        yc2 = yc1 - eps * xc2;

        imgDDA.draw_point(center.getX() + xc2, center.getY() - yc2, ddaColor);

        xc1 = xc2;
        yc1 = yc2;
    }
    while((yc1 - sy) < eps || (sx - xc1) > eps);
}

void CircleDrawer::printImages()
{
    CImgDisplay bresenham_disp(this->imgBresenham, "Bresenham"), dda_disp(this->imgDDA, "DDA");
    while (!bresenham_disp.is_closed())
        bresenham_disp.wait();
    while (!dda_disp.is_closed())
        dda_disp.wait();
}

