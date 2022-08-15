/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_main.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarouf <cmarouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 15:04:58 by cmarouf           #+#    #+#             */
/*   Updated: 2022/08/15 22:11:55 by cmarouf          ###   ########.fr       */
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
// # include "utils/is_integral.hpp"
// # include "utils/pair.hpp"
// # include "utils/make_pair.hpp"
// # include "utils/lexicographical_compare.hpp"
// # include "utils/equal.hpp"
// # include "utils/enable_if.hpp"
// # include "iterators/iterator_traits.hpp"
// # include "iterators/reverse_iterator.hpp"
#include "map.hpp"
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

    {
        std::cout << REDD << " <==> TESTING MAP WITH A CUSTOM KEY COMPARE <==> " << std::endl;

        NM::map<std::string, int, ft::greater<std::string> > test(Tester.begin(), Tester.end());
        NM::map<std::string, int> test2(Tester.begin(), Tester.end());
        NM::map<std::string, int> test3;

        test3["1"] = 1;
        test3["2"] = 1;
        test3["3"] = 1;
        test3["4"] = 1;
        test3["5"] = 1;

        std::cout << GREEN << " MAP WITH GREATER THAN: ";
        for ( NM::map<std::string, int>::iterator it = test.begin() ; it != test.end() ; it++ )
        {
            std::cout << it->first << " ";
        }
        std::cout << std::endl;

        std::cout << GREEN << " MAP WITH LESS THAN: ";
        for ( NM::map<std::string, int>::iterator it = test2.begin() ; it != test2.end() ; it++ )
        {
            std::cout << it->first << " ";
        }
        std::cout << std::endl;
        
        std::cout << " MAX SIZE : " << test.max_size() << std::endl;
        std::cout << " SIZE : " << test.size() << std::endl;

        test.erase(test.begin(), test.end());

        test2.insert(NM::make_pair<std::string, int>("1", 72));
        test2.insert(NM::make_pair<std::string, int>("2", 72));
        test2.insert(NM::make_pair<std::string, int>("4", 72));
        test2.insert(NM::make_pair<std::string, int>("4l", 72));
        test2.insert(NM::make_pair<std::string, int>("Ke5y1", 72));
        test2.insert(NM::make_pair<std::string, int>("Kdsfeyy0", 72));
        test2.insert(NM::make_pair<std::string, int>("ldfsfol", 72));
        test2.insert(NM::make_pair<std::string, int>("ldsfdsol", 72));
        test2.insert(NM::make_pair<std::string, int>("Kefdsfsdyy1", 72));
        test2.insert(NM::make_pair<std::string, int>("Kefdsfsdfyy0", 72));
        test2.insert(NM::make_pair<std::string, int>("losdfl", 72));
        test2.insert(NM::make_pair<std::string, int>("lofsdl", 72));
        test2.insert(NM::make_pair<std::string, int>("Kfsdeyy1", 72));
        test2.insert(NM::make_pair<std::string, int>("Kefsdyy0", 72));
        test2.insert(NM::make_pair<std::string, int>("lofsdl", 72));
        test2.insert(NM::make_pair<std::string, int>("lofdsl", 72));
        test2.insert(NM::make_pair<std::string, int>("Kesdfyy1", 72));
        test2.insert(NM::make_pair<std::string, int>("Ksdfeyy0", 72));
        test2.insert(NM::make_pair<std::string, int>("lsdfol", 72));
        test2.insert(NM::make_pair<std::string, int>("lsdfol", 72));
        test2.insert(NM::make_pair<std::string, int>("4ewql", 72));
        test2.insert(NM::make_pair<std::string, int>("Keewq5y1", 72));
        test2.insert(NM::make_pair<std::string, int>("Kdewqsfeyy0", 72));
        test2.insert(NM::make_pair<std::string, int>("ldewqfsfol", 72));
        test2.insert(NM::make_pair<std::string, int>("ldewqsfdsol", 72));
        test2.insert(NM::make_pair<std::string, int>("Kefdsewqfsdyy1", 72));
        test2.insert(NM::make_pair<std::string, int>("Kefdsfsdewqfyy0", 72));
        test2.insert(NM::make_pair<std::string, int>("losdfewql", 72));
        test2.insert(NM::make_pair<std::string, int>("lofsdewql", 72));
        test2.insert(NM::make_pair<std::string, int>("Kfsewqdeyy1", 72));
        test2.insert(NM::make_pair<std::string, int>("Keewqfsdyy0", 72));
        test2.insert(NM::make_pair<std::string, int>("loeqwqfsdl", 72));
        test2.insert(NM::make_pair<std::string, int>("loewqfdsl", 72));
        test2.insert(NM::make_pair<std::string, int>("Kesdfywy1", 72));
        test2.insert(NM::make_pair<std::string, int>("Ksdefeyy0", 72));
        test2.insert(NM::make_pair<std::string, int>("lsedfol", 72));
        test2.insert(NM::make_pair<std::string, int>("leqsdefol", 72));
        test2.insert(NM::make_pair<std::string, int>("4el", 72));
        test2.insert(NM::make_pair<std::string, int>("Kee5y1", 72));
        test2.insert(NM::make_pair<std::string, int>("Kddsasfeyy0", 72));
        test2.insert(NM::make_pair<std::string, int>("ldcxsfol", 72));
        test2.insert(NM::make_pair<std::string, int>("ld sfdsol", 72));
        test2.insert(NM::make_pair<std::string, int>("Kedsafzxdsfsdyy1", 72));
        test2.insert(NM::make_pair<std::string, int>("Kefcxzdsfsdfyy0", 72));
        test2.insert(NM::make_pair<std::string, int>("loxzcsdfl", 72));
        test2.insert(NM::make_pair<std::string, int>("lofdassdl", 72));
        test2.insert(NM::make_pair<std::string, int>("Kfsdsadeyy1", 72));
        test2.insert(NM::make_pair<std::string, int>("Kefdsasdyy0", 72));
        test2.insert(NM::make_pair<std::string, int>("loddddfsdl", 72));
        test2.insert(NM::make_pair<std::string, int>("lodffdsl", 72));
        test2.insert(NM::make_pair<std::string, int>("Keddsdfyy1", 72));
        test2.insert(NM::make_pair<std::string, int>("Ksdddfeyy0", 72));
        test2.insert(NM::make_pair<std::string, int>("lsdfdol", 72));
        test2.insert(NM::make_pair<std::string, int>("lsddfol", 72));
        test2.insert(NM::make_pair<std::string, int>("Ksddddddfeyy0", 72));
        test2.insert(NM::make_pair<std::string, int>("lsdfdddol", 72));
        test2.insert(NM::make_pair<std::string, int>("lsdddddfol", 72));
        test2.insert(NM::make_pair<std::string, int>("Ksddddfeyy0", 72));
        test2.insert(NM::make_pair<std::string, int>("lsdddfdddol", 72));
        test2.insert(NM::make_pair<std::string, int>("lsdddfol", 72));
        test2.insert(NM::make_pair<std::string, int>("lsddddddfol", 72));

        if ( test3 > test2 )
            std::cout << " is inferior " << std::endl;
        else
            std::cout << " is superior" << std::endl;


        std::cout << "test3 size :" << test3.size() << std::endl;
        std::cout << "test2 size :" << test2.size() << std::endl;

        // test2.swap(test3);

        test3.swap(test2);

         std::cout << "test3 size :" << test3.size() << std::endl;
        std::cout << "test2 size :" << test2.size() << std::endl;

        std::cout << "test2 :" << std::endl;
        for ( NM::map< const std::string, int>::const_iterator it = test2.begin() ; it != test2.end() ; it++ )
        {
            std::cout << it->first << " ";
        }
        std::cout << std::endl;

        std::cout << "reverse test2 :" << std::endl;
        for ( NM::map< const std::string, int>::const_reverse_iterator it = test2.rbegin() ; it != test2.rend() ; it++ )
        {
            std::cout << it->first << " ";
        }
        std::cout << std::endl;

        std::cout << "test3 :" << std::endl;
        for ( NM::map< const std::string, int>::const_iterator it = test3.begin() ; it != test3.end() ; it++ )
        {
            std::cout << it->first << " ";
        }
        std::cout << std::endl;
        std::cout << "reverse test3 :" << std::endl;
        for ( NM::map< const std::string, int>::const_reverse_iterator it = test3.rbegin() ; it != test3.rend() ; it++ )
        {
            std::cout << it->first << " ";
        }
    }
}