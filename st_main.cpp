/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st_main.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarouf <cmarouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 13:26:18 by cmarouf           #+#    #+#             */
/*   Updated: 2022/08/16 15:44:43 by cmarouf          ###   ########.fr       */
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

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <list>
#include "vector.hpp"
#include "stack.hpp"
#include <stack>

int main( void )
{
    NM::stack<int, std::list<int> > stack;
    NM::stack<int, std::list<int> > stack2;
    
    {
        stack.push(154);
        stack.push(104);
        stack.push(141);
        stack.push(14564);
        stack.push(415);
        stack.push(151644);
        stack.push(1124);
        stack.push(140);

        std::cout << "Stack empty or not : " << stack.empty() << std::endl;
        
        std::cout << "Stack size : " << stack.size() << std::endl;

        std::cout << "Stack back : " << stack.top() << std::endl;
        
        if ( stack != stack2 )
            std::cout << " stack is different from stack 2 " << std::endl;
        else
            std::cout << " stack is equal to stack 2 " << std::endl;
    }

    return 0;
}