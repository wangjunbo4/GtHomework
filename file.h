/*
 * @Author: Gtylcara.
 * @Date: 2021-11-11 23:58:54
 * @LastEditors: Gtylcara.
 * @LastEditTime: 2021-11-12 00:29:00
 */

#ifndef _FILE_OPT_H_
#define _FILE_OPT_H_

#include <fstream>
#include <cstddef>
#include <tuple>
#include <variant>
#include "sys.h"


template <typename... Ts>
class File
{
    static std::tuple<Ts...> read(std::string path);
    static void write(std::string path, Ts... data);
    static void write(std::string path, std::tuple<Ts...> data);
};

template <typename... Ts>
std::tuple<Ts...> File<Ts...>::read(std::string path)
{
    
}

template <typename... Ts>
void File<Ts...>::write(std::string path, Ts... data)
{

}

template <typename... Ts>
void File<Ts...>::write(std::string path, std::tuple<Ts...> data)
{

}

#endif