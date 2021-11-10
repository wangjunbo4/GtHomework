/*
 * @Description: 
 * @Author: Gtylcara
 * @Github: https://github.com/wangjunbo4
 * @Date: 2021-11-10 20:55:37
 * @LastEditors: Gtylcara.
 * @LastEditTime: 2021-11-11 02:05:06
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
    
    static void print(Node *head);
    static void push_back(Node *head);
    static void push_front(Node *head);
    static void sort(Node *head);
    static void modify(Node *node);
    static void del(Node *node);
    static void search(Ts..., int index);

    Node *next;

private:
    std::tuple<Ts...> data;
    int dataLength = 0;
};



template<typename... Ts>
Node<Ts...>::Node()
{
    
}

template<typename... Ts>
Node<Ts...>::Node(Ts... args)
{
    data = std::make_tuple(args...);
    dataLength = sizeof...(Ts);

    for (int i = 0; i < dataLength; i++)
    {
        std::cout << tuple_index(data, i) << std::endl;
    }
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
