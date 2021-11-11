/*
 * @Description: 
 * @Author: Gtylcara
 * @Github: https://github.com/wangjunbo4
 * @Date: 2021-11-10 20:55:37
 * @LastEditors: Gtylcara
 * @LastEditTime: 2021-11-11 15:54:13
 * @FilePath: \Homework\list.h
 */

#ifndef _DATA_LIST_H_
#define _DATA_LIST_H_

#include "sys.h"
#include <cstddef>
#include <tuple>
#include <variant>

template <size_t n, typename... T>
constexpr std::variant<T...> _tuple_index(const std::tuple<T...> &tpl, size_t i);

template <typename... T>
constexpr std::variant<T...> tuple_index(const std::tuple<T...> &tpl, size_t i);

template <typename T0, typename... Ts>
std::ostream &operator<<(std::ostream &s, std::variant<T0, Ts...> const &v);



template<typename... Ts>
class Node
{
public:

    Node();
    Node(Ts... args);
    Node(Node *next, Ts... args);
    
    static void printAll(Node *head);
    static void push_back(Node *head, Node *data);
    static void push_here(Node *node, Node *data);

    // return the new head of the list
    static Node<Ts...>* push_front(Node *head, Node *data);
    static void sort(Node *head);
    static void modify(Node *node);
    static void del(Node *node);
    static void search(Ts..., int index);
    static inline void setSeperator(std::string s) { seperator = s; }

    inline void setNext(Node *next) { this->next = next; }
    void print();

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

template <size_t n, typename... T>
constexpr std::variant<T...> _tuple_index(const std::tuple<T...> &tpl, size_t i)
{
    if constexpr (n >= sizeof...(T))
        throw std::out_of_range("Out of Range");
    if (i == n)
        return std::variant<T...>{std::in_place_index<n>, std::get<n>(tpl)};
    return _tuple_index< (n < sizeof...(T) - 1 ? n + 1 : 0)>(tpl, i);
}

template <typename... T>
constexpr std::variant<T...> tuple_index(const std::tuple<T...> &tpl, size_t i)
{
    return _tuple_index<0>(tpl, i);
}

template <typename T0, typename... Ts>
std::ostream &operator<<(std::ostream &s, std::variant<T0, Ts...> const &v)
{
    std::visit([&](auto &&x) { 
        s << x; 
    }, v);
    return s;
}

#endif 
