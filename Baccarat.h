#ifndef BACCARAT_H
#define BACCARAT_H
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <unistd.h>
#include "GRY.h"

class Baccarat: public virtual GRY
{
    public:
        void start();
        Baccarat();

    private:
        std::string first_compare(int,int);
        int computer_cards[2], user_cards[2],i,user_score,computer_score;
        std::string next_card, game;
        int deal_cards();
        double result(int, int, double, double);
};

#endif // BACCARAT_H
