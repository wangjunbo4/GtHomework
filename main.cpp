/*
 * @Description: example
 * @Author: Gtylcara
 * @Github: https://github.com/wangjunbo4
 * @Date: 2021-11-10 19:46:50
 * @LastEditors: Gtylcara
 * @LastEditTime: 2021-11-12 22:45:49
 * @FilePath: \Homework\main.cpp
 */

#include "sys.h"
#include "file.h"
#include "list.h"


// define the type you need, and you will be more easily to call it
#define Type long long, std::string, std::string, int, int


auto data2 = new Node<Type>(2, "child1", "class", 12345, 100);
auto data1 = new Node<Type>(data2, 1, "head", "class", 12345, 100);

auto data3 = new Node<Type>(3, "push_back", "class", 12345, 100);
auto data4 = new Node<Type>(4, "push_here", "class", 12345, 100);
auto data5 = new Node<Type>(5, "push_front", "class", 12345, 100);
auto head = data1;
using namespace std;

int main()
{
    // instantiation class Sys
    Sys sys;

    File<Type>::read("./data.txt");

    // three kinds of push, all of them are static
    Node<Type>::push_back(data2, data3);
    Node<Type>::push_here(data2, data4);
    head = Node<Type>::push_front(data1, data5);

    // search No.1 element of the data tuple called "push_here" and print to cmd window
    std::cout << tuple_index(
        Node<Type>::search(head, 1, "push_here")->getData(),
        0
    ) << "\n";
    
    //enable user login
    sys.usersAccountCtrl(true);

    // your system's name
    sys.setTitle("example");

    // add one option and its function
    sys.addOptions("print all", []{
        Node<Type>::printAll(head);
    });

    sys.addOptions("exit", []{
        exit(0);
    });

    // start the menu
    sys.menu();
}
