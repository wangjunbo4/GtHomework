/*
 * @Description: 
 * @Author: Gtylcara
 * @Github: https://github.com/wangjunbo4
 * @Date: 2021-11-10 19:31:30
 * @LastEditors: Gtylcara
 * @LastEditTime: 2021-11-10 20:40:54
 * @FilePath: \Homework\sys.cpp
 */



#include "sys.h"

Opt::Opt(std::string text, callback func)
{
    this->func = func;
    this->text = text;
}

void Opt::setCallback(callback func)
{
    this->func = func;
}
void Opt::exec()
{
    func();
    rewind(stdin);
    getchar();
}

bool Sys::login()
{
    std::string username, password;
    std::cout << "Please input username and password: ";
    std::cin >> username >> password;
    bool isLoggedin = false;

    char u[30], p[30], a[30];
    FILE *fp;
    if ((fp = fopen("account.txt", "r")) == NULL)
    {
        printf("user info read error!\n");
        exit(0);
    }

    while (!feof(fp))
    {
        fscanf(fp, "%s %s %s", u, p, a);
        if (std::string(u) == username && std::string(p) == password)
        {
            isLoggedin = true;
        }
    }
    return isLoggedin;
}


void Sys::menu()
{
    if (accountEnabled)
    {
        if (!login())
        {
            std::cout << "Wrong username or password\n";
            exit(0);
        }
    }

    while (1)
    {
        cls();
        std::cout << "********** " << title << " **********\n";
        for (int i = 0; i < opts.size(); i++)
        {
            std::cout << "*** " << i + 1 << ". " << opts[i].text << " ***\n";
        }

        waitOption();
    }
   
}
void Sys::cls()
{
#if defined (_WIN32) || defined (_WIN64) 
    system("cls"); //windows
#else
    system("clear"); //linux macos
#endif

    rewind(stdin);
}
void Sys::waitOption()
{
    int in = getchar() - '0';

    cls();

    if (in <= opts.size())
    {
        opts[in - 1].exec();
    }
}

void Sys::setTitle(std::string title)
{
    this->title = title;
}

void Sys::addOptions(Opt option)
{
    opts.push_back(option);
}

void Sys::addOptions(std::string text, callback func)
{
    opts.push_back(Opt(text, func));
}

void Sys::usersAccountCtrl(bool isAble)
{
    accountEnabled = isAble;
}