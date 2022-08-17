/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_main.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarouf <cmarouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 15:59:04 by cmarouf           #+#    #+#             */
/*   Updated: 2022/08/17 13:36:47 by cmarouf          ###   ########.fr       */
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
#include "../set.hpp"
#include <set>

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
    NM::set<int> set;

    NM::set<int>::iterator it = set.begin(); (void)it;
    NM::set<int>::const_iterator cit = set.begin(); (void)cit;
    
    // set.insert(1);
    // set.insert(10);
    // set.insert(20);
    // set.insert(7800);
    // set.insert(7800000);

    // NM::set<int> cpy_set(set);
    // NM::set<int> rset(set.begin(), set.end());

    {
        // set.find(10);
        // set.lower_bound(-1);
        // set.upper_bound(10);
        // set.equal_range(10);

    }
}



