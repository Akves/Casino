#include "Ruletka.h"
#include "GRY.h"
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <unistd.h>

using namespace std;

    Ruletka::Ruletka()
{
        game = "t";
}

void Ruletka::numbers()
{
    int multiplier = 35;

    while(game == "t")
    {
        system("CLS");
        string choice_str;
        cout << "\nWpisz liczbe ktora chcesz obstawic(0-36): ";
        cin >> choice_str;

        if(GRY::check_number(choice_str))
            {

                int choice = stoi(choice_str);
                while(choice<0 || choice >36)
                    {
                        cout << "\n\nWpisz liczbe z zakresu 0-36: ";
                        cin >> choice;
                    };

                double bet_value = GRY::bet();
                char temp = 'n';
                while (enough_money(bet_value, show_credits()) == false)
                {
                    cout<<"Masz za malo pieniedzy na taki zaklad, pierw uzupelnij stan konta."<<endl;
                    cout << "Czy chcesz wplacic je teraz? Wpisz (t)-Tak (n)-Nie"<< endl;
                    cin >> temp;
                    if(temp == 't' || temp == 'n'){
                        if(temp=='n')break;
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
                cout << "\nbet wynosi: " << bet_value << endl;

                int number = GRY::random(1,36);
                loading(2);
                cout << "\nWylosowana liczba: " << number << endl;

                if(choice == number)
                    {
                        cout << "Wygrales!!!";
                        cout << "Twoja wygrana wynosi: " << bet_value*multiplier << endl;
                        add_credits(bet_value*multiplier);
                    }
                else
                    {
                        cout << "Przegrales";
                        add_credits(-bet_value);
                    }
            }
        else
            {
                cout << "\n\nLiczba musi znajdowac sie w zakresie od 0 do 36";
            }
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

void Ruletka::even_odd()
{
    int multiplier = 2;

    while(game == "t")
    {
        system("CLS");
        string choice_str;
        do
        {
            cout << "Aby wybrac wpisz (1)-parzyste lub (2)-nieparzyste: ";
            cin >> choice_str;
        }while( !(stoi(choice_str)==1 || stoi(choice_str)==2) );

    int bet_value = GRY::bet();
    cout << "bet " << bet_value << " | " << show_credits() << endl;
    char temp = 'n';
        while (enough_money(bet_value, show_credits()) == false)
        {
            cout<<"Masz za malo pieniedzy na taki zaklad, pierw uzupelnij stan konta."<<endl;
            cout << "Czy chcesz wplacic je teraz? Wpisz (t)-Tak (n)-Nie"<< endl;
            cin >> temp;
            if(temp == 't' || temp == 'n'){
                if(temp=='n')break;
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

            int rand = GRY::random(36,1);
            loading(2);
            cout << "\nWylosowana liczba: " << rand << endl;

            if( rand%2 == 0 && choice_str[0] == 1)
            {
                cout << "Wygrales!!!";
                cout << "Twoja wygrana wynosi: " << bet_value*multiplier << endl;
                add_credits(bet_value*multiplier);
            }
            else if( rand%2 == 1 && choice_str[0] == 2)
            {
                cout << "Wygrales!!!";
                cout << "Twoja wygrana wynosi: " << bet_value*multiplier << endl;
                add_credits(bet_value*multiplier);
            }
            else
            {
                cout << "Przegrales";
                add_credits(-bet_value);
            }
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

void Ruletka::colour()
{
    int multiplier = 2;

    while(game == "t")
    {
        system("CLS");
        string choice_str;
        do
        {
            cout << "Czerwone:";
            for(int i=0;i<18;i++){
                cout << " " << red[i];
            }
            cout << endl;
            cout << "Czarne:";
            for(int i=0;i<18;i++){
                cout << " " << black[i];
            }

            cout << "\n\nAby wybrac wpisz (1)-czerwone lub (2)-czarne: ";
            cin >> choice_str;
        }while( !(stoi(choice_str) == 1 || stoi(choice_str)  == 2) );

        double bet_value = GRY::bet();
        char temp = 'n';

        while (enough_money(bet_value, show_credits()) == false)
        {
            cout<<"Masz za malo pieniedzy na taki zaklad, pierw uzupelnij stan konta."<<endl;
            cout << "Czy chcesz wplacic je teraz? Wpisz (t)-Tak (n)-Nie"<< endl;
            cin >> temp;
            if(temp == 't' || temp == 'n'){
                if(temp=='n')break;
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

        int rand = GRY::random(1,36);
        loading(2);
        cout << "\nWylosowana liczba: " << rand << endl;

            int i=0;
            bool temp_2 = false;
            do{
                if(red[i] == rand)//jezeli wylosowana liczba nalezy do czerwonego koloru
                {
                    temp_2 = true;
                    if(temp_2 == true && choice_str == "1")
                    {
                        cout << "Wygrales!!!";
                        cout << "Twoja wygrana wynosi: " << bet_value*multiplier << endl;
                        add_credits(bet_value*multiplier);
                        break;
                    }
                }
                else if(temp_2 == false && choice_str == "2")
                {
                    cout << "Wygrales!!!";
                    cout << "Twoja wygrana wynosi: " << bet_value*multiplier << endl;
                    add_credits(bet_value*multiplier);
                    break;
                }
                else
                {
                    cout << "Przegrales";
                    add_credits(-bet_value);
                    break;
                }

                i++;
            }while(true);

        cout << endl;
        cout<<"Czy chcesz zagrac jeszcze raz? t/n : ";
        cin>>game;

        while(game != "t" && game != "n")
        {
            cout<<"Nie zrozumialem, czy chcesz zagrac jeszcze raz? t/n : "<<endl;
            cin>>game;
        }
    }
    system("CLS");
}

void Ruletka::dozens()
{
    int multiplier = 2;

    while(game == "t")
    {
        system("CLS");
        string choice_str;
        do
        {
            cout << "Aby wybrac wpisz (1) 1-12, (2) 13-24, (3) 25-36: ";
            cin >> choice_str;
        }while( !(stoi(choice_str) == 1 || stoi(choice_str) == 2 || stoi(choice_str) == 3));

        double bet_value = GRY::bet();
        char temp = 'n';
        while (enough_money(bet_value, show_credits()) == false)
        {
            cout<<"Masz za malo pieniedzy na taki zaklad, pierw uzupelnij stan konta."<<endl;
            cout << "Czy chcesz wplacic je teraz? Wpisz (t)-Tak (n)-Nie"<< endl;
            cin >> temp;
            if(temp == 't' || temp == 'n'){
                if(temp=='n')break;
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
        int rand = GRY::random(1,36);
        loading(2);
        cout << "\nWylosowana liczba: " << rand << endl;

        if(  (rand<=12) && (choice_str[0] == '1')  )
            {
                cout << "Wygrales!!!";
                cout << "Twoja wygrana wynosi: " << bet_value*multiplier << endl;
                add_credits(bet_value*multiplier);
            }
        else if(  (rand <= 24 && rand >= 13) && (choice_str[0] == '2') )
            {
                cout << "Wygrales!!!";
                cout << "Twoja wygrana wynosi: " << bet_value*multiplier << endl;
                add_credits(bet_value*multiplier);
            }
        else if( (rand>=25) && (choice_str[0] == '3') )
            {
                cout << "Wygrales!!!";
                cout << "Twoja wygrana wynosi: " << bet_value*multiplier << endl;
                add_credits(bet_value*multiplier);
            }
        else
            {
                cout << "Przegrales";
                add_credits(-bet_value);
            }
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

void Ruletka::halfs()
{
    int multiplier = 2;

    while(game == "t")
    {
        system("CLS");
        string choice_str;
        do
        {
            cout << "Aby wybrac wpisz (1) 1-18 lub (2) 19-36: ";
            cin >> choice_str;
        }while( !(stoi(choice_str) == 1 || stoi(choice_str)  == 2));

        double bet_value = GRY::bet();
        char temp = 'n';
        while (enough_money(bet_value, show_credits()) == false)
        {
            cout<<"Masz za malo pieniedzy na taki zaklad, pierw uzupelnij stan konta."<<endl;
            cout << "Czy chcesz wplacic je teraz? Wpisz (t)-Tak (n)-Nie"<< endl;
            cin >> temp;
            if(temp == 't' || temp == 'n'){
                if(temp=='n')break;
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

        int rand = GRY::random(1,36);
        loading(2);

        cout << "\nWylosowana liczba: " << rand << endl;

        if(  (rand<=18) && (choice_str[0] == '1')  )
            {
                cout << "Wygrales!!!";
                cout << "Twoja wygrana wynosi: " << bet_value*multiplier << endl;
                add_credits(bet_value*multiplier);
            }
        else if(  (rand >= 19) && (choice_str[0] == '2') )
            {
                cout << "Wygrales!!!";
                cout << "Twoja wygrana wynosi: " << bet_value*multiplier << endl;
                add_credits(bet_value*multiplier);
            }
        else
            {
                cout << "Przegrales";
                add_credits(-bet_value);
            }
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
Ruletka::~Ruletka()
{
    //dtor
}
