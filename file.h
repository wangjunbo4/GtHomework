/*
 * @Author: Gtylcara.
 * @Date: 2021-11-11 23:58:54
 * @LastEditors: Gtylcara
 * @LastEditTime: 2021-12-07 16:53:05
 */

#ifndef _FILE_OPT_H_
#define _FILE_OPT_H_

#include <fstream>
#include <sstream>
#include <cstddef>
#include <tuple>
#include <variant>
#include "sys.h"


template <typename... Ts>
class File
{
public:
    static std::vector<std::string> read(std::string path);
    static void write(std::string path, Ts... data);
    static void write(std::string path, std::tuple<Ts...> data);

private:
    static inline char seperator = ' ';
};


// 我 投 降
template <typename... Ts>
std::vector<std::string> File<Ts...>::read(std::string path)
{
    std::ifstream ifs;
    ifs.open(path, std::ios::in);
    while (!ifs.eof())
    {
        std::string s;
        getline(ifs, s);
        
        std::istringstream iss(s);
        std::vector<std::string> sv(sizeof...(Ts));
        std::string buffer;
    
        while (std::getline(iss, buffer, seperator))
        {
            sv.emplace_back(buffer);
        }
    }
    return sv;
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