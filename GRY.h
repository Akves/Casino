#ifndef GRY_H
#define GRY_H
#include <iostream>
#include <unistd.h>
#include <ctime>
#include <fstream>
#include <string>
#include <windows.h>
#include <vector>

class GRY
{
    public:
        GRY();
        bool register_();
        bool login();
        bool success_l=false;
        bool success_p=false;
        std::string show_login();
        int show_credits();
        bool add_credits(int);
        int random(int,int);
        void loading(int);
        virtual ~GRY();
        void cls(void);
        bool check_number(std::string);
        bool check_double(std::string);

    protected:
        bool enough_money(int,int);
        int bet();

};

static std::string current_login, current_password;
static int current_credits;
#endif // GRY_H
