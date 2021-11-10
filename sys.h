/*
 * @Description: 
 * @Author: Gtylcara
 * @Github: https://github.com/wangjunbo4
 * @Date: 2021-11-10 19:31:28
 * @LastEditors: Gtylcara
 * @LastEditTime: 2021-11-10 20:40:01
 * @FilePath: \Homework\sys.h
 */




#ifndef _SYS_H_
#define _SYS_H_

#include <iostream>
#include <vector>
#include <string>

#ifndef _WIN32
#include <cstdlib>
#include <unistd.h>
#endif

typedef void (*callback)();

class Opt
{
public:
    std::string text;
    callback func;

    Opt(std::string, callback);

    void setCallback(callback func);
    void exec();
};


class Sys
{
public:

    void menu();
    void usersAccountCtrl(bool isAble);
    bool login();
    void setTitle(std::string title);
    void addOptions(Opt option);
    void addOptions(std::string text, callback func);
    void waitOption();
    void cls();

private:

    std::string title;
    std::vector<Opt> opts;
    bool accountEnabled = false;
};


#endif