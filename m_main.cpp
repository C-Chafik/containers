/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_main.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarouf <cmarouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 15:04:58 by cmarouf           #+#    #+#             */
/*   Updated: 2022/08/10 22:06:42 by cmarouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef STL
    #define NM std
#else
    #define NM ft
#endif


#define BLACKK  "\033[1m\033[30m"
#define REDD    "\033[1m\033[31m"
#define GREEN   "\033[1m\033[32m"
#define YELLOW  "\033[1m\033[33m"
#define BLUE    "\033[1m\033[34m"
#define MAGENTA "\033[1m\033[35m"
#define CYAN    "\033[1m\033[36m"
#define WHITE   "\033[1m\033[37m"

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
# include "utils/is_integral.hpp"
# include "utils/pair.hpp"
# include "utils/make_pair.hpp"
# include "utils/lexicographical_compare.hpp"
# include "utils/equal.hpp"
# include "utils/enable_if.hpp"
# include "iterators/iterator_traits.hpp"
# include "iterators/reverse_iterator.hpp"
#include "map.hpp"
#include <map>

int main( void )
{
    NM::map<std::string, int> Map;
 
    

    Map.insert(NM::make_pair<std::string, int>("Key4", 42));
    Map.insert(NM::make_pair<std::string, int>("Key2", 52));
    Map.insert(NM::make_pair<std::string, int>("Key3", 62));
    Map.insert(NM::make_pair<std::string, int>("Key1", 72));

    NM::map<std::string, int>::iterator it = Map.begin();
    NM::map<std::string, int>::iterator ite = Map.end();

    // ite--;

    std::cout << "iterator first value : " << it->first << std::endl;
    std::cout << "iterator second value : " << it->second << std::endl;

    std::cout << "iterator end first value : " << ite->first << std::endl;
    std::cout << "iterator end second value : " << ite->second << std::endl;
    
    // Map.erase("Key2");
    // it = Map.begin();
    
    // int i = 0;
    // while ( i < 3 )
    // {
    //     std::cout << "iterator first value : " << it->first << std::endl;
    //     std::cout << "iterator second value : " << it->second << std::endl;
    //     i++;
    //     it++;
    // }

    // std::cout << "iterator first value : " << it->first << std::endl;
    // std::cout << "iterator second value : " << it->second << std::endl;
    
    // it++;

    // std::cout << "next iterator first value : " << it->first << std::endl;
    // std::cout << "next iterator second value : " << it->second << std::endl;

    // it--;

    // std::cout << "previous iterator first value : " << it->first << std::endl;
    // std::cout << "previous iterator second value : " << it->second << std::endl;

    // it++;
    // it++;

    // std::cout << "next next iterator first value : " << it->first << std::endl;
    // std::cout << "next next iterator second value : " << it->second << std::endl;
}