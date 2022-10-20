#ifndef MENU_H
#define MENU_H
#include <string>
#include <iostream>
#include "GRY.h"

using namespace std;

class Menu: public virtual GRY
{
    public:
        int GetInput();
        void printOption(int, string);
        int printSubMenus(string[100]);
};

#endif // MENU_H
