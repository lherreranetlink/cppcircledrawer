#ifndef CIRCLEDRAWER_H_INCLUDED
#define CIRCLEDRAWER_H_INCLUDED
#include <cmath>
#include "Point.h"
#include "CImg.h"

#define RGB_SIZE 3
#define RED_LAYER 0
#define GREEN_LAYER 1
#define BLUE_LAYER 2

using namespace cimg_library;

class CircleDrawer
{
private:
    Point center;
    int radius;
    CImg<unsigned char> imgBresenham;
    CImg<unsigned char> imgDDA;
    unsigned char bresenhamColor[RGB_SIZE], ddaColor[RGB_SIZE];
    void proyectPoints(Point actual);
public:
    CircleDrawer(Point init, int radius);
    CircleDrawer(int beginX, int beginY, int finalX, int finalY);
    void bresenhamAlgorithm();
    void ddaAlgorithm();
    void printImages();
};



#endif // CIRCLEDRAWER_H_INCLUDED
