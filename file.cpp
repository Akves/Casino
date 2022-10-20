#include "file.h"
#include <fstream>
#include <iostream>
#include <string>
#include <windows.h>
#include <vector>

file::file(){
    std::string current_login, current_password;
    int current_credits;
}

std::string file::show_login()
{
    return current_login;
}
int file::show_credits()
{
    return current_credits;
}
bool file::register_()
{
    std::string login, password, line;
    int counter = 1;

    std::cout << "Wpisz login: ";
    std::cin >> login;

    std::fstream file;
    file.open("file.txt",std::ios::in);
    if(!file.good())
        return false;

    while(getline(file,line))
    {
        if( (counter-1)%3==0 && login==line)
        {
            std::cout << "Istnieje juz uzytkownik o takiej nazwie";
            Sleep(1000);
            return false;
        }
    counter++;
    }

    file.close();

    std::cout << "Wpisz haslo: ";
    std::cin >> password;

    file.open("file.txt",std::ios::out|std::ios::app);
    if(file.good()==false)
        return -1;
    file << login << std::endl;
    file << password << std::endl;
    file << 0 << std::endl;

    file.close();
    success_p= true;
    return true;
}

bool file::login()
{
    std::fstream file;
    file.open("file.txt",std::ios::in);
    if(!file.good())
        return false;
    std::string login, password, line;
    bool state1 = false;
    int counter = 1, temp_credits=0;

    std::cout << "Wpisz login: ";
    std::cin >> login;
    std::cout << std::endl << "Wpisz haslo: ";
    std::cin >> password;

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

bool file::add_credits(int value)
{
    std::fstream file;
    file.open("file.txt",std::ios::in);
    if(!file.good())
        return false;

    std::vector<std::string> lines;
    std::string line;
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

    file.open("file.txt",std::ios::out);
    if(!file.good())
        return false;

    for (int i = 0; i < lines.size(); i++)
    {
        if (i != counter)
            file << lines[i] << std::endl;
        else
            file << temp_credits << std::endl;
    }

    current_credits = temp_credits;

    file.close();
    return true;
}

bool file::check_number(std::string str)
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
