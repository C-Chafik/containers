/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_main.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarouf <cmarouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 15:04:58 by cmarouf           #+#    #+#             */
/*   Updated: 2022/08/08 20:35:59 by cmarouf          ###   ########.fr       */
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
# include "utils/lexicographical_compare.hpp"
# include "utils/equal.hpp"
# include "utils/enable_if.hpp"
# include "iterators/iterator_traits.hpp"
# include "iterators/reverse_iterator.hpp"
#include "map.hpp"
#include <map>

int main( void )
{
    std::map<int, int> Map;
    Map[7] = 1;
    Map[3] = 2;
    Map[18] = 3;
    Map[10] = 4;
    Map[22] = 5;
    Map[26] = 6;
    Map[8] = 7;
    Map[11] = 8;

    // std::cout << " The Begin is :" << Map.begin()->first << std::endl;
    // std::map<int, int>::iterator it = Map.begin();
    // // for (std::map<int, int>::iterator it = Map.begin() ; it != Map.end() ; it++)
    // // {
    // //     std::cout << it->first  << " " << it->second << " " << std::endl;
    // // }
    // it++;
    // std::cout << it->first  << " " << it->second << " " << std::endl;
    // it--;
    // std::cout << it->first  << " " << it->second << " " << std::endl;
    // //std:: cout << WHITE << std::endl << std::endl;
}