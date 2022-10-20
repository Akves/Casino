#include "Black_Jack.h"

Black_Jack::Black_Jack()
{
    game = "t";
}

using namespace std;

int Black_Jack::deal_cards()
    {
        /// returns a random card from the deck

        int cards[13]={11, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10};
        int number;
        number = random(0,12);
        return cards[number];
    }

string Black_Jack::compare(int user_score, int computer_score)
        {
            //comparison of the results

            if (user_score > 21 && computer_score > 21)
                return "Przegrales!";
            if (user_score == computer_score)
                return "Remis! ";
            if (user_score == 21)
                return "Wygrales!";
            if (computer_score > 21 && user_score < 21)
                return "Wygrales!";
            if (computer_score == 21)
                return "Przegrales!";
            if (user_score > computer_score && computer_score < 21 && user_score < 21)
                return "Wygrales!";
            else
                return "Przegrales!";
        }

double Black_Jack::win_or_lost(string game_result,double value_bet, double current_credits)
    {
        if (game_result == "Wygrales!")
        {
            return current_credits += value_bet*2;
        }
        else if(game_result == "Przegrales!")
        {
            return current_credits -= value_bet;
        }
        else return current_credits;
    }

void Black_Jack::start()
    {
        while(game == "t")
        {
        user_score=0, computer_score=0, suma = 0;
        draw_card = "t";
        bet_value = GRY::bet();
        char temp = 'n';
                while (enough_money(bet_value, current_credits) == false)
                {
                    cout<<"Masz za malo pieniedzy na taki zaklad, pierw uzupelnij stan konta."<<endl;
                    cout << "Czy chcesz wplacic je teraz? Wpisz (t)-Tak (n)-Nie"<< endl;
                    cin >> temp;
                    if(temp == 't' || temp == 'n')
                        {
                            if(temp=='n')return;
                            string value;
                            cout << "Ile kredytow chcesz doladowac? ";
                            cin >> value;
                            while( !(GRY::check_number(value)) )
                            {
                                cout << "Wpisz wartosc wieksza niz 1, aby kontynuowac lub 0, aby powrocic" << endl;
                                cin >> value;
                            }
                            GRY::add_credits(stoi(value));
                            system("CLS");
                            bet_value = GRY::bet();
                        }
                }


        for(i=0;i<2;i++)
        {
            //first-hand creation player and computer
            loading(1);
            user_cards[i] = deal_cards();
            loading(1);
            computer_cards[i] = deal_cards();
        }

        user_score = user_cards[0] + user_cards[1];
        computer_score = computer_cards[0] + computer_cards[1];

        cout<<"\nTwoje karty to: "<<user_cards[0]<< " " <<user_cards[1]<<" suma : "<<user_score<<endl;
        cout <<"Pierwsza karta krupiera: "<<computer_cards[0]<<endl;

        i = 2;
        while (draw_card == "t")
            //loop that draws the player's cards
        {


            cout<< "Cy chcesz dobrac karte? t/n "<<endl;
            cin>> draw_card;
            if(draw_card == "t")
            {
                user_cards[i] = deal_cards();
                user_score += user_cards[i];
                cout<< "twoja kolejna karta to : "<<user_cards[i]<<" suma: "<<user_score<<endl;
                if (user_score > 21)
                {

                    draw_card = "n";
                    break;
                }
                i++;
                if(i == 3)
                    cout<<"druga karta krupiera to : "<<computer_cards[1]<<" ich suma: "<<computer_score<<endl;
            }
            else
            {
                cout<<"druga karta krupiera to : "<<computer_cards[1]<<" ich suma: "<<computer_score<<endl;
                if (computer_score < 16)
                {
                    computer_cards[2] = deal_cards();
                    computer_score += computer_cards[2];
                    cout<<"kolejna karta krupiera to : "<<computer_cards[2]<<" ich suma: "<<computer_score<<endl;

                }
            }
        }
        cout << compare(user_score, computer_score);
        double value = win_or_lost(compare(user_score, computer_score), bet_value, current_credits );
        cout<<"twoj stan konta: "<< value;
        cout << endl;
        cout<<"twoj stan konta: "<< current_credits;
        cout << endl;
        cout<<"Czy chcesz zagrac jeszcze raz? t/n : ";
        cin>>game;
        while(game != "t" && game != "n")
            {
                cout<<"Nie zrozumialem, czy chcesz zagrac jeszcze raz? t/n : "<<endl;
                cin>>game;
            }
        }
    }
