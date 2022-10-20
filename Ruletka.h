#ifndef RULETKA_H
#define RULETKA_H
#include <iostream>
#include "GRY.h"

class Ruletka: public virtual GRY
{
    public:
        void numbers();
        void even_odd();
        void colour();
        void dozens();
        void halfs();
        Ruletka();
        virtual ~Ruletka();

    private:
        std::string game;
        //ruletka europejska
        int red[18] = {1,3,5,7,9,12,14,16,18,19,21,23,25,27,30,32,34,36};
        int black[18] = {2,4,6,8,10,11,13,15,17,20,22,24,26,28,29,32,33,35};
};

#endif // RULETKA_H
