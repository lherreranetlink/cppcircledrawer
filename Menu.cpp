#include "Menu.h"

void Menu::captureData()
{
    int beginX, beginY, finalX, finalY;
    cout << "Ingrese la coordenada X del centro: ";
    cin >> beginX;
    cout << "Ingrese la coordenada Y del centro: ";
    cin >> beginY;
    cout << "Ingrese la coordenada X del radio: ";
    cin >> finalX;
    cout << "Ingrese la coordenada Y del radio: ";
    cin >> finalY;
    this->drawer = new CircleDrawer(beginX, beginY, finalX, finalY);
}

void Menu::process()
{
    this->drawer->bresenhamAlgorithm();
    this->drawer->ddaAlgorithm();
    this->drawer->printImages();
}

