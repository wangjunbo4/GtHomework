/*
 * @Description: 
 * @Author: Gtylcara
 * @Github: https://github.com/wangjunbo4
 * @Date: 2021-11-10 20:55:37
 * @LastEditors: Gtylcara
 * @LastEditTime: 2021-11-10 22:39:41
 * @FilePath: \Homework\list.h
 */

#ifndef _DATA_LIST_H_
#define _DATA_LIST_H_

#include "sys.h"
#include <cstddef>
#include <tuple>




template<typename... Ts>
class Node
{
public:

    Node(){}
    Node(Ts... args)
    {
        data = std::make_tuple(args...);
    }

    static void print(Node *head);

    Node *next;

private:
    std::nullptr_t data;
    
};


#endif 
