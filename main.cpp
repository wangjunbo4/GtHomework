/*
 * @Description: 
 * @Author: Gtylcara
 * @Github: https://github.com/wangjunbo4
 * @Date: 2021-11-10 19:46:50
 * @LastEditors: Gtylcara
 * @LastEditTime: 2021-11-10 22:35:56
 * @FilePath: \Homework\main.cpp
 */

#include "sys.h"
#include "list.h"
#include <tuple>

using namespace std;

template<typename T, typename... Ts>
auto printf3(Ts... args) {
    std::make_tuple(args...);
}

int main()
{
    Sys sys;
    Node<long long, std::string, std::string, int, int> data;
    sys.usersAccountCtrl(true);
    sys.setTitle("sfsffa");
    sys.addOptions("sadfsa", []{
        cout << "??";
    });

    // sys.menu();
    // printf3(sys, "you", 0.1, 1000);
}
