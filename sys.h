/*
 * @Description: 
 * @Author: Gtylcara
 * @Github: https://github.com/wangjunbo4
 * @Date: 2021-11-10 19:31:28
 * @LastEditors: Gtylcara
 * @LastEditTime: 2021-12-07 16:26:43
 * @FilePath: \Homework\sys.h
 */

#ifndef _SYS_H_
#define _SYS_H_

#include <iostream>
#include <vector>
#include <string>
#include <cstddef>
#include <tuple>
#include <variant>

#ifndef _WIN32
#include <cstdlib>
#include <unistd.h>
#endif

template <size_t n, typename... T>
constexpr std::variant<T...> _tuple_index(const std::tuple<T...> &tpl, size_t i);

template <typename... T>
constexpr std::variant<T...> tuple_index(const std::tuple<T...> &tpl, size_t i);

template <typename T, typename... Ts>
std::ostream &operator<<(std::ostream &s, std::variant<T, Ts...> const &v);

template <typename T, typename... Ts>
bool operator==(std::variant<T, Ts...> const &v, std::string s);

template <typename T, typename... Ts>
bool operator==(std::variant<T, Ts...> const &v, int i);

template <typename T, typename... Ts>
bool operator==(std::variant<T, Ts...> const &v, double d);

// template <typename... Ts>
// std::tuple<Ts...> operator=(std::vector<std::string> vs);

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

template <typename T, typename... Ts>
std::ostream &operator<<(std::ostream &s, std::variant<T, Ts...> const &v)
{
    std::visit([&](auto &&x) { 
        s << x; 
    }, v);
    return s;
}

template <typename T, typename... Ts>
bool operator==(std::variant<T, Ts...> const &v, std::string s)
{
    std::string s2;
    std::visit([&](auto &&x) { 
        s2 = std::move(x);
    }, v);
    return s == s2;
}

template <typename T, typename... Ts>
bool operator==(std::variant<T, Ts...> const &v, int i)
{
    int i2 = 0;
    std::visit([&](auto &&x) { 
        i2 = std::move(x);
    }, v);
    return i == i2;
}

template <typename T, typename... Ts>
bool operator==(std::variant<T, Ts...> const &v, double d)
{
    double d2;
    std::visit([&](auto &&x) { 
        d2 = std::move(x);
    }, v);
    return d == d2;
}

// template <typename... Ts>
// std::tuple<Ts...> std::tuple<Ts...>::operator=(std::vector<std::string> vs)
// {

// }

#endif