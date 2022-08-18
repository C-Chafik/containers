/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_benchmark.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarouf <cmarouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 16:05:28 by cmarouf           #+#    #+#             */
/*   Updated: 2022/08/18 16:47:10 by cmarouf          ###   ########.fr       */
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
#include "../map.hpp"
#include <map>

long long getCurrentTime( void ) 
{
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return (tv.tv_sec) * 1000 + (tv.tv_usec / 1000);
}

int main( void )
{
    NM::map<int, int> Map;


	long long start = getCurrentTime();

    for ( int i = 0 ; i < 10000000 ; i++ )
    {
        Map.insert(NM::pair<int, int>(i, i));
    }

	{
		NM::map<int, int>::iterator it = Map.begin();
		NM::map<int, int>::iterator ite = Map.end();
		for ( ;  it != ite ; it++ )
		{
			// std::cout << *it << " ";
		}
		std::cout << std::endl;
	}

	Map.erase(Map.begin(), Map.end());

	
	std::cout << getCurrentTime() - start << "ms" << std::endl;
	
    
    return 0;
}