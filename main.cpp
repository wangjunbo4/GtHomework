/*
 * @Description: 
 * @Author: Gtylcara
 * @Github: https://github.com/wangjunbo4
 * @Date: 2021-11-10 19:46:50
 * @LastEditors: Gtylcara.
 * @LastEditTime: 2021-11-10 23:53:23
 * @FilePath: \Homework\main.cpp
 */

#include "sys.h"
#include "list.h"


using namespace std;

int main()
{
    Sys sys;
    Node<long long, std::string, std::string, int, int> data1(1, "name", "class", 12345, 100);
    Node<long long, std::string, std::string, int, int> data2(2, "name", "class", 12345, 100);
    Node<long long, std::string, std::string, int, int> data3(3, "name", "class", 12345, 100);
    sys.usersAccountCtrl(true);
    sys.setTitle("sfsffa");
    sys.addOptions("sadfsa", []{
        cout << "??";
    });

    sys.menu();
    // printf3(sys, "you", 0.1, 1000);
}
