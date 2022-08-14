/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_main.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarouf <qatar75020@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 15:04:58 by cmarouf           #+#    #+#             */
/*   Updated: 2022/08/14 15:27:02 by cmarouf          ###   ########.fr       */
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

    std::cout << REDD << " <==> TESTING MAP INSERT <==> " << std::endl;

    Tester.insert(NM::make_pair<std::string, int>("Keyy4", 42));
    Tester.insert(NM::make_pair<std::string, int>("Keyy2", 52));
    Tester.insert(NM::make_pair<std::string, int>("Keyy3", 62));
    Tester.insert(NM::make_pair<std::string, int>("Keyy1", 72));

    {
        std::cout << std::endl << std::endl << BLUE << " <=> SINGLE ELEMENT <=> " << WHITE << std::endl;

        Map.insert(NM::make_pair<std::string, int>("Keyy4", 42));
        Map.insert(NM::make_pair<std::string, int>("Keyy2", 52));
        Map.insert(NM::make_pair<std::string, int>("Keyy3", 62));
        Map.insert(NM::make_pair<std::string, int>("Keyy1", 72));

        NM::map<std::string, int>::iterator ite = Map.end();

        for ( NM::map<std::string, int>::iterator it = Map.begin() ; it != ite ; it++ )
        {
            std::cout << it->first << " ";
        }

        std::cout << std::endl << std::endl << GREEN << "IN REVERSE ORDER " << WHITE << std::endl;

        NM::map<std::string, int>::reverse_iterator rite = Map.rend();

        for ( NM::map<std::string, int>::reverse_iterator rit = Map.rbegin() ; rit != rite ; rit++ )
        {
            std::cout << rit->first << " ";
        }

        Map.erase(Map.begin(), Map.end());

        std::cout << std::endl << std::endl << BLUE << " <=> IN RANGE <=> " << WHITE << std::endl;

        Map.insert(Tester.begin(), Tester.end());

        NM::map<std::string, int>::iterator ite2 = Map.end();

        for ( NM::map<std::string, int>::iterator it = Map.begin() ; it != ite2 ; it++ )
        {
            std::cout << it->first << " ";
        }

        std::cout << std::endl << std::endl << GREEN << "IN REVERSE ORDER " << WHITE << std::endl;

        NM::map<std::string, int>::reverse_iterator rite2 = Map.rend();

        for ( NM::map<std::string, int>::reverse_iterator rit = Map.rbegin() ; rit != rite2 ; rit++ )
        {
            std::cout << rit->first << " ";
        }

        std::cout << std::endl << std::endl << std::endl;
    }
    {

        std::cout << REDD << " <==> TESTING MAP ERASE <==> " << std::endl;

        Map.insert(NM::make_pair<std::string, int>("Keyy4", 42));
        Map.insert(NM::make_pair<std::string, int>("Keyy2", 52));
        Map.insert(NM::make_pair<std::string, int>("Keyy3", 62));
        Map.insert(NM::make_pair<std::string, int>("Keyy1", 72));

        std::cout << std::endl << std::endl << BLUE << " <=> SINGLE ELEMENT (POSITION) <=> " << WHITE << std::endl;

        std::cout << GREEN << " REMOVING FIRST OBJECT" << std::endl;

        std::cout << GREEN << " BEFORE : ";
        for ( NM::map<std::string, int>::iterator it = Map.begin() ; it != Map.end() ; it++ )
        {
            std::cout << it->first << " ";
        }
        std::cout << std::endl;

        Map.erase(Map.begin());

        std::cout << GREEN << " AFTER : ";
        for ( NM::map<std::string, int>::iterator it = Map.begin() ; it != Map.end() ; it++ )
        {
            std::cout << it->first << " ";
        }
        std::cout << std::endl;

        Map.insert(NM::make_pair<std::string, int>("Keyy4", 42));
        Map.insert(NM::make_pair<std::string, int>("Keyy2", 52));
        Map.insert(NM::make_pair<std::string, int>("Keyy3", 62));
        Map.insert(NM::make_pair<std::string, int>("Keyy1", 72));

        std::cout << GREEN << " REMOVING LAST OBJECT" << std::endl;

        std::cout << GREEN << " BEFORE : ";
        for ( NM::map<std::string, int>::iterator it = Map.begin() ; it != Map.end() ; it++ )
        {
            std::cout << it->first << " ";
        }
        std::cout << std::endl;

        
        NM::map<std::string, int>::iterator end = Map.end();
        end--;
        Map.erase(end);

        std::cout << GREEN << " AFTER : ";
        for ( NM::map<std::string, int>::iterator it = Map.begin() ; it != Map.end() ; it++ )
        {
            std::cout << it->first << " ";
        }
        std::cout << std::endl;

        Map.insert(NM::make_pair<std::string, int>("Keyy4", 42));
        Map.insert(NM::make_pair<std::string, int>("Keyy2", 52));
        Map.insert(NM::make_pair<std::string, int>("Keyy3", 62));
        Map.insert(NM::make_pair<std::string, int>("Keyy1", 72));

        std::cout << GREEN << " REMOVING RANDOM OBJECT" << std::endl;

        std::cout << GREEN << " BEFORE : ";
        for ( NM::map<std::string, int>::iterator it = Map.begin() ; it != Map.end() ; it++ )
        {
            std::cout << it->first << " ";
        }
        std::cout << std::endl;

        NM::map<std::string, int>::iterator rand = Map.begin();
        
        rand++; rand++;
        Map.erase(rand);

        std::cout << GREEN << " AFTER : ";
        for ( NM::map<std::string, int>::iterator it = Map.begin() ; it != Map.end() ; it++ )
        {
            std::cout << it->first << " ";
        }
        std::cout << std::endl;
        std::cout << std::endl;

        std::cout << std::endl << std::endl << BLUE << " <=> SINGLE ELEMENT (USING KEY) <=> " << WHITE << std::endl;

        Map.insert(NM::make_pair<std::string, int>("Keyy4", 42));
        Map.insert(NM::make_pair<std::string, int>("Keyy2", 52));
        Map.insert(NM::make_pair<std::string, int>("Keyy3", 62));
        Map.insert(NM::make_pair<std::string, int>("Keyy1", 72));

        std::cout << GREEN << " REMOVING KEY3" << std::endl;

        std::cout << GREEN << " BEFORE : ";
        for ( NM::map<std::string, int>::iterator it = Map.begin() ; it != Map.end() ; it++ )
        {
            std::cout << it->first << " ";
        }
        std::cout << std::endl;

        
        Map.erase("Keyy3");

        std::cout << GREEN << " AFTER : ";
        for ( NM::map<std::string, int>::iterator it = Map.begin() ; it != Map.end() ; it++ )
        {
            std::cout << it->first << " ";
        }
        std::cout << std::endl;

        std::cout << std::endl << std::endl << BLUE << " <=> IN RANGE <=> " << WHITE << std::endl;

        Map.insert(NM::make_pair<std::string, int>("Keyy7", 42));
        Map.insert(NM::make_pair<std::string, int>("Keyy4", 42));
        Map.insert(NM::make_pair<std::string, int>("Keyy2", 52));
        Map.insert(NM::make_pair<std::string, int>("Keyy3", 62));
        Map.insert(NM::make_pair<std::string, int>("Keyy1", 72));

        std::cout << GREEN << " REMOVING FROM KEY1 TO KEY4" << std::endl;

        std::cout << GREEN << " BEFORE : ";
        for ( NM::map<std::string, int>::iterator it = Map.begin() ; it != Map.end() ; it++ )
        {
            std::cout << it->first << " ";
        }
        std::cout << std::endl;

        NM::map<std::string, int>::iterator b = Map.begin();
        NM::map<std::string, int>::iterator e = Map.begin();
        e++; e++; e++;
        Map.erase(b, e);

        std::cout << GREEN << " AFTER : ";
        for ( NM::map<std::string, int>::iterator it = Map.begin() ; it != Map.end() ; it++ )
        {
            std::cout << it->first << " ";
        }
        std::cout << std::endl;
        
    }
    {
        std::cout << REDD << " <==> TESTING MAP OPERATIONS <==> " << std::endl;

        Map["Keyy77"] = 48;
        Map["Keyy88"] = 48;
        
        for ( NM::map<std::string, int>::iterator it = Map.begin() ; it != Map.end() ; it++ )
        {
            std::cout << it->first << " ";
        }
        std::cout << std::endl;

        Map.insert(NM::make_pair<std::string, int>("Keyy7", 42));
        Map.insert(NM::make_pair<std::string, int>("Keyy4", 42));
        Map.insert(NM::make_pair<std::string, int>("Keyy2", 52));
        Map.insert(NM::make_pair<std::string, int>("Keyy3", 62));
        Map.insert(NM::make_pair<std::string, int>("Keyy1", 72));

        std::cout << GREEN << " TESTING FIND" << std::endl;

        NM::map<std::string, int>::iterator find = Map.find("Keyy77");

        std::cout << find->first << std::endl;

        std::cout << GREEN << " TESTING COUNT" << std::endl;

        std::cout << Map.count("Keyy077") << std::endl;

        std::cout << GREEN << " TESTING LOWER_BOUND" << std::endl;

        std::cout << Map.lower_bound("Keyy4")->first << std::endl;

        std::cout << GREEN << " TESTING UPPER_BOUND" << std::endl;

        std::cout << Map.upper_bound("Keyy4")->first << std::endl;

        std::cout << GREEN << " TESTING EQUAL RANGE" << std::endl;

        NM::pair<NM::map<std::string, int>::const_iterator, NM::map<std::string, int>::const_iterator > ret;

        ret = Map.equal_range("Keyy4");

        std::cout << "LOWER BOUND : " << ret.first->first << std::endl;

        std::cout << "UPPER BOUND : " << ret.second->first << std::endl; 
    }

    {
        std::cout << REDD << " <==> TESTING MAP CONSTRUCTOR <==> " << std::endl;
        
        NM::map<std::string, int> empty;

        NM::map<std::string, int> range(Tester.begin(), Tester.end());
        
        NM::map<std::string, int> copy(range);
    }
}