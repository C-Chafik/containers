/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_benchmark.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarouf <cmarouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 16:06:45 by cmarouf           #+#    #+#             */
/*   Updated: 2022/08/18 16:42:09 by cmarouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef STL
	#define NM std
#else
	#define NM ft
#endif

#define BLACK   "\033[1m\033[30m"
#define RED     "\033[1m\033[31m"
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
#include <stdio.h>
#include "../vector.hpp"
#include <vector>

long long getCurrentTime( void ) 
{
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return (tv.tv_sec) * 1000 + (tv.tv_usec / 1000);
}

int main( void )
{
	NM::vector<int> v1;

	long long start = getCurrentTime();

	v1.insert(v1.begin(), 10000000, 42);

	{
		NM::vector<int>::iterator it = v1.begin();
		NM::vector<int>::iterator ite = v1.end();
		for ( ;  it != ite ; it++ )
		{
			// std::cout << *it << " ";
		}
		std::cout << std::endl;
	}

	v1.erase(v1.begin(), v1.end());

	
	std::cout << getCurrentTime() - start << "ms" << std::endl;
	
    return 0;
}