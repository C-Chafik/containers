/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_benchmark.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarouf <cmarouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 16:06:06 by cmarouf           #+#    #+#             */
/*   Updated: 2022/08/18 16:48:19 by cmarouf          ###   ########.fr       */
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

#include <sys/time.h>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "../set.hpp"
#include <set>

long long getCurrentTime( void ) 
{
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return (tv.tv_sec) * 1000 + (tv.tv_usec / 1000);
}

int main( void )
{
    NM::set<int> set;


	long long start = getCurrentTime();

    for ( int i = 0 ; i < 10000000 ; i++ )
    {
        set.insert(i);
    }

	{
		NM::set<int>::iterator it = set.begin();
		NM::set<int>::iterator ite = set.end();
		for ( ;  it != ite ; it++ )
		{
			// std::cout << *it << " ";
		}
		std::cout << std::endl;
	}

	set.erase(set.begin(), set.end());

	
	std::cout << getCurrentTime() - start << "ms" << std::endl;
	
    
    return 0;
}