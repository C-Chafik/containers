/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_main.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarouf <cmarouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 15:04:58 by cmarouf           #+#    #+#             */
/*   Updated: 2022/08/17 20:49:05 by cmarouf          ###   ########.fr       */
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
#include "../map.hpp"
#include <map>

namespace ft
{
    template < class T >
    struct greater
    {
        bool operator()( const T & a, const T & b ) const
        {
            return a > b;
        }
    };
}

void test_constructor( void )
{
    std::cout << REDD << " TEST_CONSTRUCTOR " << WHITE << std::endl;
	std::cout << std::endl;
	
	std::cout << YELLOW << " EMPTY CONSTRUCTOR " << WHITE << std::endl << std::endl;
	NM::map<std::string, int> Map1;
	std::cout << "Map1 size : " << Map1.size() << " | max_size : " << Map1.max_size() << " | is Map1 empty ? : " << Map1.empty() << std::endl;
    std::cout << std::endl;

	std::cout << YELLOW << " RANGE CONSTRUCTOR " << WHITE << std::endl << std::endl;
	NM::map<std::string, int> tmp; tmp["Key1"] = 1; tmp["Key2"] = 2; tmp["Key3"] = 3; tmp["Key5"] = 5;
	NM::map<std::string, int> Map2(tmp.begin(), tmp.end());
	std::cout << "Map2 size : " << Map2.size() << " | max_size : " << Map1.max_size() <<  " | is Map2 empty ? : " << Map2.empty() << std::endl;
    std::cout << std::endl;

	std::cout << YELLOW << " COPY CONSTRUCTOR " << WHITE << std::endl << std::endl;
	NM::map<std::string, int> Map3(Map2);
	std::cout << "Map3 size : " << Map3.size() << " | max_size : " << Map1.max_size() << " | is Map3 empty ? : " << Map3.empty() << std::endl;
	std::cout << std::endl;
}

void    test_iterator( void )
{
    std::cout << REDD << " TEST_ITERATOR " << WHITE << std::endl << std::endl;
	
	NM::map<std::string, int> Map;
    Map["Key1"] = 10;
    Map["Key2"] = 42;
    Map["Key3"] = 72;
    Map["Key4"] = 1;
    Map["Key5"] = 45;

	std::cout << YELLOW << " ITERATOR " << WHITE << std::endl << std::endl;
	{
		NM::map<std::string, int>::iterator it = Map.begin();
		NM::map<std::string, int>::iterator ite = Map.end();

		for ( ; it != ite ; it++ )
		{
			std::cout << it->first << " [" << it->second << "] : ";
		}
		std::cout << std::endl;
		std::cout << std::endl;
	}

	std::cout << YELLOW << " CONST ITERATOR " << WHITE << std::endl << std::endl;
	{
		NM::map<std::string, int>::const_iterator it = Map.begin();
		NM::map<std::string, int>::const_iterator ite = Map.end();

		for ( ; it != ite ; it++ )
		{
			std::cout << it->first << " [" << it->second << "] : ";
		}
		std::cout << std::endl;
		std::cout << std::endl;
	}

	std::cout << YELLOW << " REVERSE ITERATOR " << WHITE << std::endl << std::endl;
	{
		NM::map<std::string, int>::reverse_iterator it = Map.rbegin();
		NM::map<std::string, int>::reverse_iterator ite = Map.rend();

		for ( ; it != ite ; it++ )
		{
			std::cout << it->first << " [" << it->second << "] : ";
		}
		std::cout << std::endl;
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void    test_insert( void )
{
    NM::pair<std::string, int>pair;

    pair = NM::make_pair("Key1", 1);
    std::cout << REDD << " TEST_INSERT " << WHITE << std::endl;

    NM::map<std::string, int> Map;

    std::cout << YELLOW << " SINGLE ELEMENT INSERT " << WHITE << std::endl << std::endl;

    std::cout << "Map size : " << Map.size() << " | max_size : " << Map.max_size() << " | is Map empty ? : " << Map.empty() << std::endl << std::endl;
    Map.insert(pair);
	{
		NM::map<std::string, int>::iterator it = Map.begin();
		NM::map<std::string, int>::iterator ite = Map.end();

		for ( ; it != ite ; it++ )
		{
			std::cout << it->first << " [" << it->second << "] : ";
		}
		std::cout << std::endl;
		std::cout << std::endl;
	}
    std::cout << "Map size : " << Map.size() << " | max_size : " << Map.max_size() << " | is Map empty ? : " << Map.empty() << std::endl;

    std::cout << YELLOW << " SINGLE ELEMENT WITH HINT INSERT " << WHITE << std::endl << std::endl;

    std::cout << "Map size : " << Map.size() << " | max_size : " << Map.max_size() << " | is Map empty ? : " << Map.empty() << std::endl << std::endl;
    pair = NM::make_pair("Key2", 2);
    Map.insert(Map.begin(), pair);
	{
		NM::map<std::string, int>::iterator it = Map.begin();
		NM::map<std::string, int>::iterator ite = Map.end();

		for ( ; it != ite ; it++ )
		{
			std::cout << it->first << " [" << it->second << "] : ";
		}
		std::cout << std::endl;
		std::cout << std::endl;
	}
    std::cout << "Map size : " << Map.size() << " | max_size : " << Map.max_size() << " | is Map empty ? : " << Map.empty() << std::endl;

    std::cout << YELLOW << " RANGE INSERT " << WHITE << std::endl << std::endl;

    std::cout << "Map size : " << Map.size() << " | max_size : " << Map.max_size() << " | is Map empty ? : " << Map.empty() << std::endl << std::endl;
    pair = NM::make_pair("Key2", 2);
    NM::map<std::string, int> tmp; tmp["Key1"] = 1; tmp["Key2"] = 2; tmp["Key3"] = 3; tmp["Key5"] = 5;
    Map.insert(tmp.begin(), tmp.end());
	{
		NM::map<std::string, int>::iterator it = Map.begin();
		NM::map<std::string, int>::iterator ite = Map.end();

		for ( ; it != ite ; it++ )
		{
			std::cout << it->first << " [" << it->second << "] : ";
		}
		std::cout << std::endl;
		std::cout << std::endl;
	}
    std::cout << "Map size : " << Map.size() << " | max_size : " << Map.max_size() << " | is Map empty ? : " << Map.empty() << std::endl;
    std::cout << std::endl;
	std::cout << std::endl;
}

void    test_erase( void )
{   
    std::cout << REDD << " TEST_ERASE " << WHITE << std::endl << std::endl;

    NM::map<int, int> Map; Map[1] = 20; Map[1] = 222; Map[2] = 84; Map[3] = 516; Map[4] = 615; Map[5] = 1041; Map[6] = 651; Map[7] = 05;

    std::cout << YELLOW << " SINGLE ELEMENT HINT ERASE " << WHITE << std::endl << std::endl;

    std::cout << "Map size : " << Map.size() << " | max_size : " << Map.max_size() << " | is Map empty ? : " << Map.empty() << std::endl << std::endl;
    Map.erase(Map.begin());
	{
		NM::map<int, int>::iterator it = Map.begin();
		NM::map<int, int>::iterator ite = Map.end();

		for ( ; it != ite ; it++ )
		{
			std::cout << it->first << " [" << it->second << "] : ";
		}
		std::cout << std::endl;
		std::cout << std::endl;
	}
    std::cout << "Map size : " << Map.size() << " | max_size : " << Map.max_size() << " | is Map empty ? : " << Map.empty() << std::endl << std::endl;

    std::cout << YELLOW << " SINGLE ELEMENT ERASE " << WHITE << std::endl << std::endl;

    std::cout << "Map size : " << Map.size() << " | max_size : " << Map.max_size() << " | is Map empty ? : " << Map.empty() << std::endl << std::endl;
    Map.erase(5);
	{
		NM::map<int, int>::iterator it = Map.begin();
		NM::map<int, int>::iterator ite = Map.end();

		for ( ; it != ite ; it++ )
		{
			std::cout << it->first << " [" << it->second << "] : ";
		}
		std::cout << std::endl;
		std::cout << std::endl;
	}
    std::cout << "Map size : " << Map.size() << " | max_size : " << Map.max_size() << " | is Map empty ? : " << Map.empty() << std::endl  << std::endl;

    std::cout << YELLOW << " RANGE ERASE " << WHITE << std::endl << std::endl;

    NM::map<int, int>::iterator it = Map.begin();

    it++; it++; it++;

    std::cout << "Map size : " << Map.size() << " | max_size : " << Map.max_size() << " | is Map empty ? : " << Map.empty() << std::endl << std::endl;
    Map.erase(it, Map.end());
	{
		NM::map<int, int>::iterator it = Map.begin();
		NM::map<int, int>::iterator ite = Map.end();

		for ( ; it != ite ; it++ )
		{
			std::cout << it->first << " [" << it->second << "] : ";
		}
		std::cout << std::endl;
		std::cout << std::endl;
	}
    std::cout << "Map size : " << Map.size() << " | max_size : " << Map.max_size() << " | is Map empty ? : " << Map.empty() << std::endl;
    std::cout << std::endl;
}

void    test_operator( void )
{
    std::cout << REDD << " TEST_OPERATOR " << WHITE << std::endl << std::endl;

    NM::map<std::string, int> Map;

    Map["Azerty"] = 1;
    Map["Qwerty"] = 145;
    Map["LOL"] = 14984;
    Map["Aweqewq"] = 1453;
    Map["Key1"] = 145;
    Map["Key1MILLION"] = 1000000;

    std::cout << YELLOW << " TESTING MAP FIND " << WHITE << std::endl << std::endl;

    {
        NM::map<std::string, int>::iterator it;
        NM::map<std::string, int>::const_iterator cit;

        it = Map.find("Key1MILLION");
        cit = Map.find("Key1MILLION");

        std::cout << "normal : ";
        std::cout << it->first << " [" << it->second << "] : " << std::endl;
        std::cout << "const : ";
        std::cout << cit->first << " [" << cit->second << "] : " << std::endl;
    }
    std::cout << std::endl;
    
    std::cout << YELLOW << " TESTING MAP COUNT " << WHITE << std::endl << std::endl;
    {
        std::cout << " Count : " << Map.count("LOL");
    }
    std::cout << std::endl;
    
    std::cout << YELLOW << " TESTING MAP LOWER_BOUND " << WHITE << std::endl << std::endl;

    {
        NM::map<std::string, int>::iterator it;
        NM::map<std::string, int>::const_iterator cit;

        it = Map.lower_bound("Qwerty");
        cit = Map.lower_bound("Qwerty");

        std::cout << "normal : ";
        std::cout << it->first << " [" << it->second << "] : " << std::endl;
        std::cout << "const : ";
        std::cout << cit->first << " [" << cit->second << "] : " << std::endl;
    }
    std::cout << std::endl;

    std::cout << YELLOW << " TESTING MAP UPPER_BOUND " << WHITE << std::endl << std::endl;

    {
        NM::map<std::string, int>::iterator it;
        NM::map<std::string, int>::const_iterator cit;

        it = Map.upper_bound("Azerty");
        cit = Map.upper_bound("Azerty");

        std::cout << "normal : ";
        std::cout << it->first << " [" << it->second << "] : " << std::endl;
        std::cout << "const : ";
        std::cout << cit->first << " [" << cit->second << "] : " << std::endl;
    }
    std::cout << std::endl;

    std::cout << YELLOW << " TESTING MAP EQUAL_RANGE " << WHITE << std::endl << std::endl;
    NM::pair<NM::map<std::string, int>::iterator, NM::map<std::string, int>::iterator> pair;
    NM::pair<NM::map<std::string, int>::const_iterator, NM::map<std::string, int>::const_iterator> const_pair;
    {
        pair = Map.equal_range("Key1");
        const_pair = Map.equal_range("Key1");

        std::cout << "normal : ";
        std::cout << pair.first->first << " [" << pair.first->second << "] : " << std::endl;
        std::cout << pair.second->first << " [" << pair.second->second << "] : " << std::endl;
        std::cout << "const : ";
        std::cout << const_pair.first->first << " [" << const_pair.first->second << "] : " << std::endl;
        std::cout << const_pair.second->first << " [" << const_pair.second->second << "] : " << std::endl;
    }
    std::cout << std::endl;
}

void    	go_crasy( void )
{
    
}

int main( void )
{
    test_constructor();
	test_iterator();
	test_insert();
	test_erase();
    test_operator();
	go_crasy();
    
    return 0;
}
