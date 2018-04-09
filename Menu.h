#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include <iostream>
#include "CircleDrawer.h"

using namespace std;

class Menu
{
private:
    CircleDrawer* drawer;
public:
    void captureData();
    void process();
};


#endif // MENU_H_INCLUDED
