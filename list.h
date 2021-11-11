/*
 * @Description: 
 * @Author: Gtylcara
 * @Github: https://github.com/wangjunbo4
 * @Date: 2021-11-10 20:55:37
 * @LastEditors: Gtylcara.
 * @LastEditTime: 2021-11-12 00:04:34
 * @FilePath: \Homework\list.h
 */

#ifndef _DATA_LIST_H_
#define _DATA_LIST_H_

#include "sys.h"
#include <cstddef>
#include <tuple>
#include <variant>



template<typename... Ts>
class Node
{
public:

    Node();
    Node(Ts... args);
    Node(Node *next, Ts... args);
    inline void setNext(Node *next) { this->next = next; }
    void print();
    inline std::tuple<Ts...> getData() { return data; }
    
    static void printAll(Node *head);
    static void push_back(Node *head, Node *data);
    static void push_here(Node *node, Node *data);

    // return the new head of the list
    static Node<Ts...>* push_front(Node *head, Node *data);
    static void sort(Node *head);
    static void modify(Node *node, std::tuple<Ts...> data);
    static void del(Node *head, Node* node);
    
    static inline void setSeperator(std::string s) { seperator = s; }


    /*
        head: head of the list you want to search
        index: the number of the tuple to storge one pack of data, start from 0
        content: the content you want to search, must be the same type as you searched from tuple 
    */
    template<typename T>
    static Node<Ts...>* search(Node *head, int index, T content)
    {
        while (head != nullptr)
        {
            if (tuple_index(head->data, index) == content)
            {
                return head;
            }

            head = head->next;
        }
    }
    

    Node *next = nullptr;

private:
    std::tuple<Ts...> data;
    int dataLength = 0;
    static inline std::string seperator = "\t\t\t";
};

template<typename... Ts>
void Node<Ts...>::push_back(Node *head, Node *data)
{
    if (head == nullptr)
        head = std::move(data);
    else
    {
        while (head->next != nullptr)
        {
            head = head->next;
        }
        push_here(head, data);
    }
}


template<typename... Ts>
void Node<Ts...>::push_here(Node *node, Node *data)
{
    auto temp = node->next;
    node->next = data;
    data->next = temp;
}

template<typename... Ts>
Node<Ts...>* Node<Ts...>::push_front(Node *head, Node *data)
{
    if (head == nullptr)
    {
        head = std::move(data);
        return head;
    }
    else
    {
        data->next = head;
        return data;
    }
}

template<typename... Ts>
void Node<Ts...>::modify(Node *node, std::tuple<Ts...> data)
{
    node->data = std::move(data);
}


template<typename... Ts>
void Node<Ts...>::del(Node *head, Node* node)
{
    if (head == nullptr)
        return;
    
    if (head == node)
        free(node);

    auto pre = head;
    auto after = head->next;

    while (after != node)
    {
        pre = pre->next;
        after = after->next;
    }

    pre->next = after->next;
    free(after);
}


template<typename... Ts>
void Node<Ts...>::printAll(Node *head)
{
    while (head != nullptr)
    {
        head->print();
        head = head->next;
    }
}

template<typename... Ts>
void Node<Ts...>::print()
{
    for (int i = 0; i < dataLength; i++)
    {
        std::cout << tuple_index(data, i) << Node<Ts...>::seperator;
    }
    std::cout << "\n";
}

template<typename... Ts>
Node<Ts...>::Node()
{
    setNext(nullptr);
}

template<typename... Ts>
Node<Ts...>::Node(Ts... args) : Node() 
{
    setNext(nullptr);
    data = std::make_tuple(args...);
    dataLength = sizeof...(Ts);
}

template<typename... Ts>
Node<Ts...>::Node(Node *next, Ts... args)
{
    setNext(next);
    data = std::make_tuple(args...);
    dataLength = sizeof...(Ts);
}

#endif 
