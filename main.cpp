/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarouf <cmarouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 18:26:47 by cmarouf           #+#    #+#             */
/*   Updated: 2022/07/21 00:02:43 by cmarouf          ###   ########.fr       */
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

/*#include <vector>
#include <iostream>

int main(void)
}
    std::vector<int> v1;

    std::cout << "size" << v1.size() << std::endl;
    std::cout << "max_size" << v1.max_size() << std::endl;
    std::cout << "capacity" << v1.capacity() << std::endl;

    template <class T>
    void print(void){
        T::valuetype
    }
}*/

#include "external_functions/is_integral.hpp"
#include "external_functions/equal.hpp"
#include "external_functions/enable_if.hpp"
#include "iterators/iterator_traits.hpp"
#include "iterators/reverse_iterator.hpp"
#include "vector.hpp"
#include <vector>

int main( void )
{   
    /*std::vector<int> v1(100, 42);

    std::vector<int>::iterator it = v1.begin();

    std::vector<int>::iterator ite = v1.end();*/

    //(void)it; (void)ite;
    
    /*{ //! Test : resize
        NM::vector<int> v1(10, 42);

        v1.resize(5);

        v1.resize(0);

        v1.resize(10);
    }*/

    /*{ //! Test : push_back
        NM::vector<int> v1(1, 42);

        std::cout << "------------------------" << std::endl;
        std::cout << "TESTING VECTOR PUSH_BACK" << std::endl;

        std::cout << v1.capacity() << std::endl;

        v1.push_back(15);

        std::cout << v1.capacity() << std::endl;

        v1.push_back(12);

        std::cout << v1.capacity() << std::endl;

        v1.push_back(4984);

        std::cout << v1.capacity() << std::endl;

        v1.push_back(41);

        std::cout << v1.capacity() << std::endl;

        v1.push_back(41);

        std::cout << v1.capacity() << std::endl;

        v1.push_back(41);

        std::cout << v1.capacity() << std::endl;

        v1.push_back(41);
        std::cout << "------------------------" << std::endl;
    }*/

   /* { //! pop_back
        NM::vector<int> v1(1, 42);

        std::cout << "------------------------" << std::endl;
        std::cout << "TESTING VECTOR POP_BACK" << std::endl;

        std::cout << v1.size() << std::endl;

        v1.pop_back();

        std::cout << v1.size() << std::endl;

         v1.pop_back();

        std::cout << v1.size() << std::endl;

         v1.pop_back();

        std::cout << v1.size() << std::endl;

         v1.pop_back();

        std::cout << v1.size() << std::endl;

         v1.pop_back();

        std::cout << v1.size() << std::endl;

         v1.pop_back();

        std::cout << v1.size() << std::endl;

         v1.pop_back();
        std::cout << "------------------------" << std::endl;   
    }*/

    /*{ //! insert STD

        std::vector<int> v1(6, 42);
        std::vector<int>::iterator it = v1.begin();

        std::cout << MAGENTA << "------------------------" << std::endl;
        std::cout << "TESTING VECTOR INSERT" << std::endl;

        for ( std::vector<int>::iterator it7 = v1.begin(); it7 != v1.end() ; it7++ )
        {
            std::cout << *it7 << " ";
        }
        std::cout << std::endl;

        std::cout << RED << "V1 SIZE : " << v1.size() << std::endl;
        std::cout << RED << "V1 CAPACITY : " << v1.size() << std::endl;

        v1.insert(it + 3, 6);

        for ( std::vector<int>::iterator it7 = v1.begin(); it7 != v1.end() ; it7++ )
        {
            std::cout << *it7 << " ";
        }
        std::cout << std::endl;

        std::cout << RED << "V1 SIZE : " << v1.size() << std::endl;
        std::cout << RED << "V1 CAPACITY : " << v1.size() << std::endl;

        std::vector<int>::iterator it2 = v1.begin();

        v1.insert(it2, 6);

        for ( std::vector<int>::iterator it7 = v1.begin(); it7 != v1.end() ; it7++ )
        {
            std::cout << *it7 << " ";
        }
        std::cout << std::endl;

        std::cout << RED << "V1 SIZE : " << v1.size() << std::endl;
        std::cout << RED << "V1 CAPACITY : " << v1.size() << std::endl;

        std::vector<int>::iterator it3 = v1.begin();

        v1.insert(it3, 6);

        for ( std::vector<int>::iterator it7 = v1.begin(); it7 != v1.end() ; it7++ )
        {
            std::cout << *it7 << " ";
        }
        std::cout << std::endl;

        std::cout << RED << "V1 SIZE : " << v1.size() << std::endl;
        std::cout << RED << "V1 CAPACITY : " << v1.size() << std::endl;

        std::vector<int>::iterator it4 = v1.begin();

        v1.insert(it4, 6);

        for ( std::vector<int>::iterator it7 = v1.begin(); it7 != v1.end() ; it7++ )
        {
            std::cout << *it7 << " ";
        }
        std::cout << std::endl;

        std::cout << RED << "V1 SIZE : " << v1.size() << std::endl;
        std::cout << RED << "V1 CAPACITY : " << v1.size() << std::endl;

        for ( std::vector<int>::iterator it7 = v1.begin(); it7 != v1.end() ; it7++ )
        {
            std::cout << *it7 << " ";
        }
        std::cout << std::endl;

        
        
        std::cout << MAGENTA << "------------------------" << std::endl;   
    }*/

    { //! insert

        NM::vector<int> v1(6, 42);
        NM::vector<int>::iterator it = v1.begin();

        std::cout << MAGENTA << "------------------------" << std::endl;
        std::cout << "TESTING VECTOR INSERT" << std::endl;

        for ( NM::vector<int>::iterator it7 = v1.begin(); it7 != v1.end() ; it7++ )
        {
            std::cout << *it7 << " ";
        }
        std::cout << std::endl;

        std::cout << RED << "V1 SIZE : " << v1.size() << std::endl;
        std::cout << RED << "V1 CAPACITY : " << v1.capacity() << std::endl;

        v1.insert(it + 3, 6);

        for ( NM::vector<int>::iterator it7 = v1.begin(); it7 != v1.end() ; it7++ )
        {
            std::cout << *it7 << " ";
        }
        std::cout << std::endl;

        std::cout << RED << "V1 SIZE : " << v1.size() << std::endl;
        std::cout << RED << "V1 CAPACITY : " << v1.capacity()<< std::endl;

        NM::vector<int>::iterator it2 = v1.begin();

        v1.insert(it2, 6);

        for ( NM::vector<int>::iterator it7 = v1.begin(); it7 != v1.end() ; it7++ )
        {
            std::cout << *it7 << " ";
        }
        std::cout << std::endl;

        std::cout << RED << "V1 SIZE : " << v1.size() << std::endl;
        std::cout << RED << "V1 CAPACITY : " << v1.capacity() << std::endl;

        NM::vector<int>::iterator it3 = v1.begin();

        v1.insert(it3, 6);

        for ( NM::vector<int>::iterator it7 = v1.begin(); it7 != v1.end() ; it7++ )
        {
            std::cout << *it7 << " ";
        }
        std::cout << std::endl;

        std::cout << RED << "V1 SIZE : " << v1.size() << std::endl;
        std::cout << RED << "V1 CAPACITY : " << v1.capacity() << std::endl;

        NM::vector<int>::iterator it4 = v1.begin();

        v1.insert(it4, 6);

        for ( NM::vector<int>::iterator it7 = v1.begin(); it7 != v1.end() ; it7++ )
        {
            std::cout << *it7 << " ";
        }
        std::cout << std::endl;

        std::cout << RED << "V1 SIZE : " << v1.size() << std::endl;
        std::cout << RED << "V1 CAPACITY : " << v1.capacity() << std::endl;

        for ( NM::vector<int>::iterator it7 = v1.begin(); it7 != v1.end() ; it7++ )
        {
            std::cout << *it7 << " ";
        }
        std::cout << std::endl;

        
        
        std::cout << MAGENTA << "------------------------" << std::endl;   
    }
    

    return 0;
}
