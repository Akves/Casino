#include "Bandyta.h"
#include "GRY.h"
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <unistd.h>

using namespace std;

Bandyta::Bandyta()
{
    game = "t";
}

void Bandyta::create_reel(string reel[][3])
{
    //funkcja tworzaca beben do gry

    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
            {
                sleep(1);
                this->reel[i][j] = table[GRY::random(0,21)];
                cout <<this->reel[i][j] << " ";
            }
            cout << endl;
    }
}

void Bandyta::check_reel(double bet_value)
{
    //funkcja sprawdzajaca czy ktorys z warunkow jest spelniony

    double multiplier=1;
    bool win=false;
    if( (reel[0][0]==reel[0][1]) && (reel[0][1]==reel[0][2]) )
    {
        win = true;
            if(reel[0][0]=="*")
            {
                multiplier *= 2;
            }
            else if(reel[0][0]=="+")
            {
                multiplier *= 3;
            }
            else if(reel[0][0]=="X")
            {
                multiplier *= 5;
            }
            if(reel[0][0]=="7")
            {
                multiplier *= 10;
            }
    }
    if( (reel[1][0]==reel[1][1]) && (reel[1][1]==reel[1][2]) )
    {
        win = true;
            if(reel[1][0]=="*")
            {
                multiplier *= 2;
            }
            else if(reel[1][0]=="+")
            {
                multiplier *= 3;
            }
            else if(reel[1][0]=="X")
            {
                multiplier *= 5;
            }
            if(reel[1][0]=="7")
            {
                multiplier *= 10;
            }
    }
    if( (reel[2][0]==reel[2][1]) && (reel[2][1]==reel[2][2]) )
    {
        win = true;
            if(reel[2][0]=="*")
            {
                multiplier *= 2;
            }
            else if(reel[2][0]=="+")
            {
                multiplier *= 3;
            }
            else if(reel[2][0]=="X")
            {
                multiplier *= 5;
            }
            if(reel[2][0]=="7")
            {
                multiplier *= 10;
            }
    }
    if( (reel[0][0]==reel[1][1]) && (reel[1][1]==reel[2][2]) )
    {
        win = true;
            if(reel[0][0]=="*")
            {
                multiplier *= 2;
            }
            else if(reel[0][0]=="+")
            {
                multiplier *= 3;
            }
            else if(reel[0][0]=="X")
            {
                multiplier *= 5;
            }
            if(reel[0][0]=="7")
            {
                multiplier *= 10;
            }
    }
    if( (reel[0][2]==reel[1][1]) && (reel[1][1]==reel[2][0]) )
    {
        win = true;
            if(reel[0][2]=="*")
            {
                multiplier *= 2;
            }
            else if(reel[0][2]=="+")
            {
                multiplier *= 3;
            }
            else if(reel[0][2]=="X")
            {
                multiplier *= 5;
            }
            if(reel[0][2]=="7")
            {
                multiplier *= 10;
            }
    }
    cout << endl;
    if(!win)
    {
        cout << "Przegrales";
        add_credits(-bet_value);
    }
    else
    {
        cout << "Wygrales!!!";
        cout << "Twoja wygrana wynosi: " << bet_value*multiplier << endl;
        add_credits(bet_value*multiplier);
    }
}

int Bandyta::start()
{
    while(game == "t")
    {
        system("CLS");
        int bet_value = GRY::bet();

        char temp = 'n';
            while (enough_money(bet_value, show_credits()) == false)
            {
                cout<<"Masz za malo pieniedzy na taki zaklad, pierw uzupelnij stan konta."<<endl;
                cout << "Czy chcesz wplacic je teraz? Wpisz (t)-Tak (n)-Nie"<< endl;
                cin >> temp;
                if(temp == 't' || temp == 'n'){
                    if(temp=='n')return 1;
                    string value;
                    cout << "Ile kredytow chcesz doladowac? ";
                    cin >> value;
                    while( !(GRY::check_number(value)) )
                    {
                        cout << "Wpisz wartosc wieksza niz 0 aby kontynuowac ,lub 0 aby powrocic" << endl;
                        cin >> value;
                    }
                    GRY::add_credits(stoi(value));
                    system("CLS");
                    bet_value = GRY::bet();
                }
            }
        create_reel(reel);
        cout << endl;
        check_reel(bet_value);
        cout << endl;
        cout<<"Czy chcesz zagrac jeszcze raz? t/n : ";
        cin>>game;
        while(game != "t" && game != "n")
            {
                cout<<"Nie zrozumialem, czy chcesz zagrac jeszcze raz? t/n : "<<endl;
                cin>>game;
            }

    }
    return 1;
}

