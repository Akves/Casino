#include "Menu.h"
#include <string>
#include <iostream>

using namespace std;

// gets number from user and checks if it's int
int Menu::GetInput()
	{
		string choice;
		while (true)
		{
			cin >> choice;
			if (!GRY::check_number(choice))
			{
				return -1;
			}
			else
			{
				return stoi(choice);
			}
		}
	}

// prints options from subMenus variable
void Menu::printOption(int number, string option)
	{
		cout << number << ": " << option << endl;
	}


int Menu::printSubMenus(string *subMenus)
{
    while (true)
    {
        int x = 1;
        while (subMenus[x - 1].size() != 0 && subMenus[x - 1].size() < 100)
        {
            printOption(x, subMenus[x - 1]);
            x++;
        }
        printOption(x, "Wyjscie");

        cout << endl;
        int choice = GetInput();
        if (choice == x)
        {
            cout << "Exiting..." << endl;
            exit(0);
            // EXIT
        }
        else if (choice == -1 || choice < 1 || choice > x)
        {
            cout << "Podaj liczbe od 1 do " << x << endl;
        }
        else
        {
            return choice;
        }
    }
}
