/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_main.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarouf <cmarouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 15:04:58 by cmarouf           #+#    #+#             */
/*   Updated: 2022/08/11 23:03:12 by cmarouf          ###   ########.fr       */
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
    NM::map<std::string, int> Tester;

    std::cout << BLUE << " TESTING MAP INSERT " << std::endl;

    Tester.insert(NM::make_pair<std::string, int>("Keyy4", 42));
    Tester.insert(NM::make_pair<std::string, int>("Keyy2", 52));
    Tester.insert(NM::make_pair<std::string, int>("Keyy3", 62));
    Tester.insert(NM::make_pair<std::string, int>("Keyy1", 72));

    std::cout << std::endl << std::endl << BLUE << " SINGLE ELEMENT " << std::endl;    

    // Map.insert(Tester.begin(), Tester.end());



    Map.insert(NM::make_pair<std::string, int>("Keyy4", 42));
    Map.insert(NM::make_pair<std::string, int>("Keyy2", 52));
    Map.insert(NM::make_pair<std::string, int>("Keyy3", 62));
    Map.insert(NM::make_pair<std::string, int>("Keyy1", 72));

    //     NM::map<std::string, int>::iterator ite = Map.begin();
    // std::cout << ite->first << std::endl;

    // ite++;

    // std::cout << ite->first << std::endl;

    // ite++;

    // std::cout << ite->first << std::endl;

    // ite++;

    // std::cout << ite->first << std::endl;

    for ( NM::map<std::string, int>::iterator it = Map.begin() ; it != Map.end() ; it++ )
    {
        std::cout << it->first << " ";
    }
    
    std::cout << std::endl;
}