/*
 * @Description: 
 * @Author: Gtylcara
 * @Github: https://github.com/wangjunbo4
 * @Date: 2021-11-10 19:46:50
 * @LastEditors: Gtylcara
 * @LastEditTime: 2021-11-11 15:47:10
 * @FilePath: \Homework\main.cpp
 */

#include "sys.h"
#include "list.h"

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
    Sys sys;

    myNode::push_back(data2, data3);
    myNode::push_here(data2, data4);
    head = myNode::push_front(data1, data5);

    // N::push_back()
    
    sys.usersAccountCtrl(true);
    sys.setTitle("example");
    sys.addOptions("print all", []{
        myNode::printAll(head);
    });

    sys.menu();
}
