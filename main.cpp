#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <time.h>
#include <ctime>
#include <stdio.h>
#include <string>
#include <ctype.h>
#include "Menu.h"
#include "Ruletka.h"
#include "Bandyta.h"
#include "GRY.h"
#include "Baccarat.h"
#include "Black_Jack.h"
#include "file.h"

using namespace std;

class MainMenuRuletka : public Menu, public Ruletka
{
public:
	MainMenuRuletka()
	{
		string subMenus[100] = {"Obstaw liczby", "Obstaw parzyste lub nieparzyste", "Obstaw kolor", "Obstaw tuziny", "Obstaw polowy", "Cofnij"};

		int choice = printSubMenus(subMenus);

        switch(choice){

            case 1:
                Ruletka::numbers();
            break;

            case 2:
                Ruletka::even_odd();
            break;

            case 3:
                Ruletka::colour();
            break;

            case 4:
                Ruletka::dozens();
            break;

            case 5:
                Ruletka::halfs();
            break;

            case 6:
                system("CLS");
            break;

		}
	};
};

class MainMenuGames : public Menu, public Bandyta, public Black_Jack, public Baccarat
{
public:
	MainMenuGames()
	{
		string subMenus[100] = {"Ruletka", "Jednoreki Bandyta", "Doladuj konto"};

		int choice = printSubMenus(subMenus);

        switch(choice){

            case 1:{
                cout << "\nWitaj w Ruletce, powodzenia\n" << endl;
                MainMenuRuletka MainMenuRuletka;
            break;}

            case 2:{
                cout << "\nWitaj w Jednorekim Bandycie, powodzenia\n" << endl;
                Bandyta::start();
            break;}

            case 3:{
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
            break;}

		}
	};
};

class MainMenu : public Menu
{
public:
    MainMenu()
	{
		string subMenus[100] = {"Logowanie", "Rejestracja"};

		int choice = Menu::printSubMenus(subMenus);

        switch(choice){

            case 1:
                system("CLS");
                GRY::login();
                system("CLS");
                if(GRY::success_l==true)
                {
                    while(true)
                    {
                        cout << "Uzytkownik: " << show_login() << " -|- Zetony: " << show_credits() << endl;
                        MainMenuGames MainMenuGames;
                    }
                }
                else
                    cout << "Blad logowania";

            break;

            case 2:
                system("CLS");
                GRY::register_();
                system("CLS");
                if(GRY::success_p==true)
                    cout << "Udalo ci sie zarejestrowac!\n";
                else
                    cout << "Blad rejestracji!\n\n";
            break;
		}
	};
};

/////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    while(true)
        MainMenu MainMenu;

    return 0;
}




























