/*
 * @Description: example
 * @Author: Gtylcara
 * @Github: https://github.com/wangjunbo4
 * @Date: 2021-11-10 19:46:50
 * @LastEditors: Gtylcara
 * @LastEditTime: 2021-11-11 21:45:45
 * @FilePath: \Homework\main.cpp
 */

#include "sys.h"
#include "list.h"


// define the type you need, and you will be more easily to call it
typedef Node<long long, std::string, std::string, int, int> myNode;

auto data3 = new myNode(3, "push_back", "class", 12345, 100);
auto data2 = new myNode(2, "child1", "class", 12345, 100);
auto data1 = new myNode(data2, 1, "head", "class", 12345, 100);

auto data4 = new myNode(4, "push_here", "class", 12345, 100);
auto data5 = new myNode(5, "push_front", "class", 12345, 100);
auto head = data1;

using namespace std;

int main()
{
    // instantiation class Sys
    Sys sys;

    // three kinds of push, all of them are static
    myNode::push_back(data2, data3);
    myNode::push_here(data2, data4);
    head = myNode::push_front(data1, data5);

    // search No.1 element of the data tuple called "push_here" and print to cmd window
    std::cout << tuple_index(
        myNode::search(head, 1, "push_here")->getData(),
        0
    ) << "\n";
    
    //enable user login
    sys.usersAccountCtrl(true);

    // your system's name
    sys.setTitle("example");

    // add one option and its function
    sys.addOptions("print all", []{
        myNode::printAll(head);
    });

    sys.addOptions("exit", []{
        exit(0);
    });

    // start the menu
    sys.menu();
}
