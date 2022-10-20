#include "Baccarat.h"

using namespace std;

Baccarat::Baccarat()
{
    srand (time(NULL));
    user_score=0, computer_score=0, game = "t";
}

int Baccarat::deal_cards()
    {
        /// returns a random card from the deck

        int cards[12]={1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 0, 0};
        int number;
        srand(time(NULL));
        number = random(0,11);
        return cards[number];
    }

string Baccarat::first_compare(int user_score, int computer_score)
    {
        //comparison of the first results

        if (user_score == 9 || user_score == 8)
        {
            if(user_score > computer_score) return "Wygrales!";
            else return "Przegrales!";
        }

        if (user_score == 9 && computer_score == 9)
                return "Remis!";

        if (computer_score == 9 || computer_score == 8)
            {
                if(computer_score > user_score) return "Przegrales!";
                else return "Wygrales!";
            }
        else return "Dalej";
    }

double Baccarat::result(int user_score, int computer_score, double bet_value, double current_credits)
    {
        int multiplier = 3;
        string state = first_compare(user_score,computer_score);
        if ( state == "Dalej" )
        {
            cout<<"Czy chcesz dobrac kolejna karte? t/n : ";
            cin>>next_card;
            while(next_card != "t" && next_card != "n")
            {
                cout<<"Nie zrozumialem, czy dobrac kolejna karte? t/n: "<<endl;
                cin>>next_card;
            }
            if(next_card == "t")
            {
                user_cards[2] = deal_cards();
                user_score = (user_score + user_cards[2]) % 10;
                cout<<"\nTwoje kolejna karta to : "<<user_cards[2]<<endl;

                if (computer_score <= 5)
                {
                     computer_cards[2] = deal_cards();
                     computer_score = (computer_score + computer_cards[2]) % 10;
                     cout<<"Kolejna karta krupiera : "<<computer_cards[2]<<endl;
                }
                cout << endl;
                cout<<"Twoj wynik to : "<<user_score<<endl;
                cout<<"Wynik krupiera: "<<computer_score<<endl;
                cout << endl;
                if (state == "Wygrales!")
                    {
                        cout << "Wygrales!!!";
                        cout << "Twoja wygrana wynosi: " << bet_value*multiplier << endl;
                        add_credits(bet_value*multiplier);
                        return show_credits();
                    }
                else if (state == "Przegrales!")
                    {
                        cout << "Przegrales";
                        add_credits(-bet_value);
                        return show_credits();
                    }
                else {
                    cout<<"Remis!";
                    return show_credits();
                }
            }
        }
            else if (first_compare(user_score,computer_score) == "Wygrales!" )
            {
                cout << "Wygrales!!!";
                cout << "Twoja wygrana wynosi: " << bet_value*multiplier << endl;
                add_credits(bet_value*multiplier);
                return show_credits();
            }
            else if(first_compare(user_score,computer_score) == "Przegrales!" )
            {
                cout << "Przegrales";
                add_credits(-bet_value);
                return show_credits();
            }
            else
            {
                cout<<"Remis!"<<endl;
                return show_credits();
            }
        return -1;
    }

void Baccarat::start()
    {
        while(game == "t")
        {
            double bet_value = GRY::bet();
            char temp = 'n';
                while (enough_money(bet_value, show_credits()) == false)
                {
                    cout<<"Masz za malo pieniedzy na taki zaklad, pierw uzupelnij stan konta."<<endl;
                    cout << "Czy chcesz wplacic je teraz? Wpisz (t)-Tak (n)-Nie: ";
                    cin >> temp;
                    while(temp == 't' || temp == 'n')
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

            for(i=0;i<2;i++){
                //first-hand creation player and computer
                loading(1);
                user_cards[i] = deal_cards();
                loading(1);
                computer_cards[i] = deal_cards();
            }

            user_score = (user_cards[0] + user_cards[1]) % 10;
            computer_score = (computer_cards[0] + computer_cards[1]) % 10;

            cout<<"\n\nTwoje karty to : "<<user_cards[0]<<"  "<<user_cards[1]<<endl;
            cout<<"Twoj wynik to: " <<user_score<<endl;
            sleep(1);

            cout<<"\nKarty krupiera : "<<computer_cards[0]<<"  "<<computer_cards[1]<<endl;
            cout<<"Wynik krupiera to : "<<computer_score<<endl;
            sleep(1);
            cout << endl;

            double game_result = result(user_score, computer_score, bet_value, current_credits);
            sleep(1);

            cout<<"\nCzy chcesz zagrac jeszcze raz? t/n : ";
            cin>>game;
                while(game != "t" && game != "n")
                {
                    cout<<"Nie zrozumialem, czy chcesz zagrac jeszcze raz? t/n : "<<endl;
                    cin>>game;
                }
                system("CLS");
        }
        return;
    }
