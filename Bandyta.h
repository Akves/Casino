#define BANDYTA_H
#include <iostream>
#include <stdio.h>
#include "GRY.h"

class Bandyta: public virtual GRY
{
    public:
        int start();
        Bandyta();

    private:
    std::string game;
    std::string reel[3][3];
    std::string table[22]={"*","+","*","X","+","X","*","7","+","X","*","+","+","X","+","*","*","7","+","X","*","*"};
    void create_reel(std::string[][3]);
    void check_reel(double);
};
