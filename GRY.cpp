#include "GRY.h"
#include <fstream>
#include <iostream>
#include <string>
#include <windows.h>
#include <vector>

using namespace std;

GRY::GRY()
{
    srand(time(NULL));
    string current_login, current_password;
    int current_credits;
}

//returns login of currently logged in user
string GRY::show_login()
{
    return current_login;
}

//returns credits of currently logged in user
int GRY::show_credits()
{
    return current_credits;
}

//adds new account
bool GRY::register_()
{
    string login, password, line;
    int counter = 1;

    cout << "Wpisz login: ";
    cin >> login;

    fstream file;
    file.open("file.txt",ios::in);
    if(!file.good())
        return false;

    while(getline(file,line))
    {
        if( (counter-1)%3==0 && login==line)
        {
            cout << "Istnieje juz uzytkownik o takiej nazwie";
            Sleep(1000);
            return false;
        }
    counter++;
    }

    file.close();

    cout << "Wpisz haslo: ";
    cin >> password;

    file.open("file.txt",ios::out|ios::app);
    if(file.good()==false)
        return -1;
    file << login << endl;
    file << password << endl;
    file << 0 << endl;

    file.close();
    success_p= true;

    return true;
}

//compares login and password with file
bool GRY::login()
{
    fstream file;
    file.open("file.txt",ios::in);
    if(!file.good())
        return false;
    string login, password, line;
    bool state1 = false;
    int counter = 1, temp_credits=0;

    cout << "Wpisz login: ";
    cin >> login;
    cout << endl << "Wpisz haslo: ";
    cin >> password;

    while(getline(file,line))
    {
        if( (counter-1)%3==0 && login==line)
        {
            getline(file,line);
            if(password==line)
            {
                state1=true;
            }
            if(state1==true)
            {
                getline(file,line);
                temp_credits=stoi(line);
                break;
            }
        }
    counter++;
    }

    if(state1==true)
    {
        current_login = login;
        current_password = password;
        current_credits = temp_credits;
        success_l= true;
    }

    file.close();
    return true;
}

//adding credits for currently logged in user
bool GRY::add_credits(int value)
{
    fstream file;
    file.open("file.txt",ios::in);
    if(!file.good())
        return false;

    vector<string> lines;
    string line;
    int counter=0, temp_counter=1, temp_credits=0;

    while(getline(file,line))
    {
        if((temp_counter-1)%3==0 && current_login==line)
            counter = temp_counter+2;

        if(temp_counter==counter)
            temp_credits=stoi(line);

        lines.push_back(line);
        temp_counter++;
    }

    file.close();

    counter--;
    temp_credits+=value;

    file.open("file.txt",ios::out);
    if(!file.good())
        return false;

    for (int i = 0; i < lines.size(); i++)
    {
        if (i != counter)
            file << lines[i] << endl;
        else
            file << temp_credits << endl;
    }

    current_credits = temp_credits;

    file.close();
    return true;
}

//checks if number is int
bool GRY::check_number(string str)
{
	for (int i = 0; i < str.size(); i++)
	{
		if( !(isdigit(str[i])) )
		{
			return false;
		}
	}
	return true;
}

//checks if number is double
bool GRY::check_double(string str)
{
    bool dot = false;
    for (int i = 0; i < str.size(); i++)
    {
        if (!(isdigit(str[i]) || str[i] == '.'))
        {
        if (str[i] == '.' && !(dot))
        {
            dot = true;
            continue;
        }
        if (!(isdigit(str[i])))
        {
            return false;
        }
        }
    }
    return true;
}

//returning pseudo random number
int GRY::random(int min,int max)
    {
        int number;
        return number = rand() % max + min;
    }

//animation of loading
void GRY::loading(int j)
{
    for (int i=0; i<j; i++)
    {
        cout <<"\r   "<<char(187)<<"   ";
        usleep(400000);
        cout <<"\r   "<<char(188)<<"   ";
        usleep(400000);
        cout <<"\r   "<<char(200)<<"   ";
        usleep(400000);
        cout <<"\r   "<<char(201)<<"   ";
        usleep(400000);
    }
    cout <<"\r       ";
}

//gets value that user wants to play with
int GRY::bet()
    {
        string bet_value = "";
        while (true)
            {
                cout << "\nPodaj wartosc ktora chcesz obstawic: ";
                cin >> bet_value;
                if ( (GRY::check_number(bet_value) == true) && stoi(bet_value)>0)
                    {
                        return stoi(bet_value);
                    }
                else
                    {
                        cout << "\nblad, wpisz jeszcze raz";
                    }
            }
    }

//checks if user have enough credits
bool GRY::enough_money(int bet_value, int current_credits)
    {
        if (bet_value <= current_credits)
            return true;
        else
            return false;
    }

GRY::~GRY()
{

}
