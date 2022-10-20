#ifndef BLACK_JACK_H
#define BLACK_JACK_H
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <unistd.h>
#include "GRY.h"


class Black_Jack: public virtual GRY
{
    public:
        void start();
        Black_Jack();

    protected:
        std::string game;
        int user_score, computer_score=0,i, suma = 0, bet_value;
        int user_cards[10], computer_cards[10];
        bool is_game_over = false;
        std::string draw_card;
        int deal_cards();
        std::string compare(int, int);
        double win_or_lost(std::string ,double , double);

    private:
};

#endif // BLACK_JACK_H
