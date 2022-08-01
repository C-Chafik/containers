/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarouf <cmarouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 18:26:47 by cmarouf           #+#    #+#             */
/*   Updated: 2022/08/01 16:01:19 by cmarouf          ###   ########.fr       */
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

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
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
    }
        v1.push_back(41);

        std::cout << v1.capacity() << std::endl;

        v1.push_back(41);

        std::cout << v1.capacity() << std::endl;

        v1.push_back(41);
        std::cout << "------------------------" << std::endl;
    }
        v1.push_back(41);

        std::cout << v1.capacity() << std::endl;

        v1.push_back(41);

        std::cout << v1.capacity() << std::endl;

        v1.push_back(41);
        std::cout << "------------------------" << std::endl;
    }
        v1.push_back(41);

        std::cout << v1.capacity() << std::endl;

        v1.push_back(41);

        std::cout << v1.capacity() << std::endl;

        v1.push_back(41);
        std::cout << "------------------------" << std::endl;
    }
        v1.push_back(41);

        std::cout << v1.capacity() << std::endl;

        v1.push_back(41);

        std::cout << v1.capacity() << std::endl;

        v1.push_back(41);
        std::cout << "------------------------" << std::endl;
    }

   	{ //! pop_back
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

    /*{ //! insert

        NM::vector<int> v1(5, 42);
        NM::vector<int> v2(5, 88);
        NM::vector<int> v3(78, 1);
        NM::vector<int>::iterator position = v1.begin();
        NM::vector<int>::iterator it = v2.begin();
        NM::vector<int>::iterator ite = v2.end();

        std::cout << MAGENTA << "------------------------" << std::endl;
        std::cout << "TESTING VECTOR INSERT" << std::endl;

        for ( NM::vector<int>::iterator it7 = v1.begin(); it7 != v1.end() ; it7++ )
        {
            std::cout << *it7 << " ";
        }
        std::cout << std::endl;

        std::cout << RED << "V1 SIZE : " << v1.size() << std::endl;
        std::cout << RED << "V1 CAPACITY : " << v1.capacity() << std::endl;

        v1.insert(position, it, ite);

        for ( NM::vector<int>::iterator it7 = v1.begin(); it7 != v1.end() ; it7++ )
        {
            std::cout << *it7 << " ";
        }
        std::cout << std::endl;

        std::cout << RED << "V1 SIZE : " << v1.size() << std::endl;
        std::cout << RED << "V1 CAPACITY : " << v1.capacity()<< std::endl;

        NM::vector<int>::iterator position2 = v1.begin();
        NM::vector<int>::iterator it2 = v3.begin();
        NM::vector<int>::iterator ite2 = v3.end();

        v1.insert(position2 + 5, it2, ite2);

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
    }*/

    /*{ //! Operator =
        NM::vector<int> v1(5, 42);

        for ( NM::vector<int>::iterator it = v1.begin(); it != v1.end() ; it++ )
        {
            std::cout << RED << *it << " ";
        }

        
        NM::vector<int> v2;

        std::cout << std::endl;

        v2 = v1;
        for ( NM::vector<int>::iterator it = v2.begin(); it != v2.end() ; it++ )
        {
            //std::cout << "EMPTY V2 " << std::endl;
            std::cout << RED << *it << " ";
        }
    }*/

    /*{ //! Swap
        NM::vector<int> v1(10, 1);
        NM::vector<int> v2(10, 2);

        std::cout << GREEN << "BEFORE SWAP" <<  std::endl;
        
        for ( NM::vector<int>::iterator it = v1.begin(); it != v1.end() ; it++ )
        {
            std::cout << RED << *it << " ";
        }

        std::cout << std::endl << "===================" <<  std::endl;
        
        for ( NM::vector<int>::iterator it = v2.begin(); it != v2.end() ; it++ )
        {
            std::cout << RED << *it << " ";
        }

        v1.swap(v2);

        std::cout << std::endl << "---------------------" <<  std::endl;

        std::cout << YELLOW << "AFTER SWAP" <<  std::endl;
        
        for ( NM::vector<int>::iterator it = v1.begin(); it != v1.end() ; it++ )
        {
            std::cout << RED << *it << " ";
        }

        std::cout << std::endl << "===================" <<  std::endl;
        
        for ( NM::vector<int>::iterator it = v2.begin(); it != v2.end() ; it++ )
        {
            //std::cout << "EMPTY V2 " << std::endl;
            std::cout << RED << *it << " ";
        }
    }*/

    /*{ //! Non-Member Swap
        NM::vector<int> v1(10, 1);
        NM::vector<int> v2(10, 2);

        std::cout << GREEN << "BEFORE SWAP" <<  std::endl;
        
        for ( NM::vector<int>::iterator it = v1.begin(); it != v1.end() ; it++ )
        {
            std::cout << RED << *it << " ";
        }

        std::cout << std::endl << "===================" <<  std::endl;
        
        for ( NM::vector<int>::iterator it = v2.begin(); it != v2.end() ; it++ )
        {
            std::cout << RED << *it << " ";
        }

        NM::swap(v1, v2);

        std::cout << std::endl << "---------------------" <<  std::endl;

        std::cout << YELLOW << "AFTER SWAP" <<  std::endl;
        
        for ( NM::vector<int>::iterator it = v1.begin(); it != v1.end() ; it++ )
        {
            std::cout << RED << *it << " ";
        }

        std::cout << std::endl << "===================" <<  std::endl;
        
        for ( NM::vector<int>::iterator it = v2.begin(); it != v2.end() ; it++ )
        {
            //std::cout << "EMPTY V2 " << std::endl;
            std::cout << RED << *it << " ";
        }
    }*/

    /*{ //! Relational Operators
        NM::vector<int> v1(10, 42);
        
        NM::vector<int> v2(10, 42);

        if ( v1 == v2 )
            std::cout << GREEN << "EQUAL TRUE" << std::endl;
        else
            std::cout <<  RED << "EQUAL FALSE" << std::endl;
        
        if ( v1 != v2 )
            std::cout << GREEN << "EQUAL TRUE" << std::endl;
        else
            std::cout <<  RED << "EQUAL FALSE" << std::endl;
        
        if ( v1 < v2 )
            std::cout << GREEN << "EQUAL TRUE" << std::endl;
        else
            std::cout <<  RED << "EQUAL FALSE" << std::endl;
        
        if ( v1 <= v2 )
            std::cout << GREEN << "EQUAL TRUE" << std::endl;
        else
            std::cout <<  RED << "EQUAL FALSE" << std::endl;
        
        if ( v1 > v2 )
            std::cout << GREEN << "EQUAL TRUE" << std::endl;
        else
            std::cout <<  RED << "EQUAL FALSE" << std::endl;
        
        if ( v1 >= v2 )
            std::cout << GREEN << "EQUAL TRUE" << std::endl;
        else
            std::cout <<  RED << "EQUAL FALSE" << std::endl;

            
    }*/

    /*{ //! Erase single element
        NM::vector<int> v1(10, 42);
        int i = 0;

        NM::vector<int>::iterator it = v1.begin();
        for ( ; it != v1.end() ; it++ )
        {
            *it = i *3;
            i++;
        }

        for (it = v1.begin() ; it != v1.end() ; it++ )
        {
            std::cout << *it << " ";
        }
        std::cout << std::endl;

        it = v1.begin();
        v1.erase(it + 3);

        for ( it = v1.begin() ; it != v1.end() ; it++ )
        {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
        
    }*/

    /*{ //! Erase Range element
        NM::vector<int> v1(10, 42);
        int i = 0;

        NM::vector<int>::iterator it = v1.begin();
        for ( ; it != v1.end() ; it++ )
        {
            *it = i *3;
            i++;
        }

        for (it = v1.begin() ; it != v1.end() ; it++ )
        {
            std::cout << *it << " ";
        }
        std::cout << std::endl;

        it = v1.begin();
        v1.erase(it, it + 3);

        for ( it = v1.begin() ; it != v1.end() ; it++ )
        {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
        
    }*/

    /*{ //! Debuging
    
        NM::vector<int> v1;

        v1.assign(0, 1);

        NM::vector<int>::iterator it = v1.begin();

        for (; it != v1.end() ; it++ )
        {
            std::cout << *it << " ";
        }
    }*/
	
    /*{ //! Global test of Everything combined
	
        NM::vector<int> v1(10, 42);
		NM::vector<int> v2(v1);
		NM::vector<int> v3(v1.begin(), v1.end());
		
		std::cout << RED << "TESTING EQUALITY" << WHITE << std::endl;
		if (v1 == v2)
			std::cout << "true" << std::endl;
		else
			std::cout << "false" << std::endl;

		if (v1 == v3)
			std::cout << "true" << std::endl;
		else
			std::cout << "false" << std::endl;

		if (v2 == v3)
			std::cout << "true" << std::endl;
		else
			std::cout << "false" << std::endl;

		

		std::cout << RED << "TESTING SIZE-CAPACITY" << WHITE << std::endl << std::endl;


		

		std::cout << "v1 size : " << v1.size() << std::endl;
		std::cout << "v2 size : " << v2.size() << std::endl;
		std::cout << "v3 size : " << v3.size() << std::endl;
		std::cout << "v1 capacity : " << v1.capacity() << std::endl;
		std::cout << "v2 capacity : " << v2.capacity() << std::endl;
		std::cout << "v3 capacity : " << v3.capacity() << std::endl;

		

		std::cout << GREEN << "v1 content :" << std::endl;
		for ( NM::vector<int>::iterator it = v1.begin() ; it != v1.end() ; it++ )
		{
			std::cout << *it << " ";
		}
		std::cout << WHITE << std::endl << std::endl;
		

		std::cout << GREEN << "v2 content :" << std::endl;
		for ( NM::vector<int>::iterator it = v2.begin() ; it != v2.end() ; it++ )
		{
			std::cout << *it << " ";
		}
		std::cout << WHITE << std::endl << std::endl;
		

		std::cout << GREEN << "v3 content :" << std::endl;
		for ( NM::vector<int>::iterator it = v3.begin() ; it != v3.end() ; it++ )
		{
			std::cout << *it << " ";
		}
		std::cout << WHITE << std::endl << std::endl;
		


		std::cout << RED << "TESTING SIZE-CAPACITY AFTER MODIFIERS" << WHITE << std::endl;

		

		v1.insert(v1.begin() + 3, v3.begin(), v3.end());
		v2.push_back(8);
		v3.assign(78, 12);
		

		std::cout << "v1 size : " << v1.size() << std::endl;
		std::cout << "v2 size : " << v2.size() << std::endl;
		std::cout << "v3 size : " << v3.size() << std::endl;
		std::cout << "v1 capacity : " << v1.capacity() << std::endl;
		std::cout << "v2 capacity : " << v2.capacity() << std::endl;
		std::cout << "v3 capacity : " << v3.capacity() << std::endl;

		std::cout << GREEN << "v1 content :" << std::endl;
		for ( NM::vector<int>::iterator it = v1.begin() ; it != v1.end() ; it++ )
		{
			std::cout << *it << " ";
		}
		std::cout << WHITE << std::endl << std::endl;
		

		std::cout << GREEN << "v2 content :" << std::endl;
		for ( NM::vector<int>::iterator it = v2.begin() ; it != v2.end() ; it++ )
		{
			std::cout << *it << " ";
		}
		std::cout << WHITE << std::endl << std::endl;
		

		std::cout << GREEN << "v3 content :" << std::endl;
		for ( NM::vector<int>::iterator it = v3.begin() ; it != v3.end() ; it++ )
		{
			std::cout << *it << " ";
		}
		std::cout << WHITE << std::endl << std::endl << std::endl;

		std::cout << RED << "TESTING ERASING" << WHITE << std::endl;
		
		v1.erase(v1.begin() + 3, v1.end());
		v2.erase(v2.begin() + 1);
		v2.erase(v2.begin() + 1);
		v3.erase(v3.end() - 1);	

		v1.pop_back();
		v2.pop_back();
		v3.pop_back();

		std::cout << "v1 size : " << v1.size() << std::endl;
		std::cout << "v2 size : " << v2.size() << std::endl;
		std::cout << "v3 size : " << v3.size() << std::endl;
		std::cout << "v1 capacity : " << v1.capacity() << std::endl;
		std::cout << "v2 capacity : " << v2.capacity() << std::endl;
		std::cout << "v3 capacity : " << v3.capacity() << std::endl;

		std::cout << GREEN << "v1 content :" << std::endl;
		for ( NM::vector<int>::iterator it = v1.begin() ; it != v1.end() ; it++ )
		{
			std::cout << *it << " ";
		}
		std::cout << WHITE << std::endl << std::endl;
		

		std::cout << GREEN << "v2 content :" << std::endl;
		for ( NM::vector<int>::iterator it = v2.begin() ; it != v2.end() ; it++ )
		{
			std::cout << *it << " ";
		}
		std::cout << WHITE << std::endl << std::endl;
		

		std::cout << GREEN << "v3 content :" << std::endl;
		for ( NM::vector<int>::iterator it = v3.begin() ; it != v3.end() ; it++ )
		{
			std::cout << *it << " ";
		}
		std::cout << WHITE << std::endl << std::endl << std::endl;

		std::cout << RED << "TESTING SWAP" << WHITE << std::endl;

		v1.swap(v3);
		v2.swap(v1);

		std::cout << "v1 size : " << v1.size() << std::endl;
		std::cout << "v2 size : " << v2.size() << std::endl;
		std::cout << "v3 size : " << v3.size() << std::endl;
		std::cout << "v1 capacity : " << v1.capacity() << std::endl;
		std::cout << "v2 capacity : " << v2.capacity() << std::endl;
		std::cout << "v3 capacity : " << v3.capacity() << std::endl;

		std::cout << GREEN << "v1 content :" << std::endl;
		for ( NM::vector<int>::iterator it = v1.begin() ; it != v1.end() ; it++ )
		{
			std::cout << *it << " ";
		}
		std::cout << WHITE << std::endl << std::endl;
		

		std::cout << GREEN << "v2 content :" << std::endl;
		for ( NM::vector<int>::iterator it = v2.begin() ; it != v2.end() ; it++ )
		{
			std::cout << *it << " ";
		}
		std::cout << WHITE << std::endl << std::endl;
		

		std::cout << GREEN << "v3 content :" << std::endl;
		for ( NM::vector<int>::iterator it = v3.begin() ; it != v3.end() ; it++ )
		{
			std::cout << *it << " ";
		}
		std::cout << WHITE << std::endl << std::endl << std::endl;

		std::cout << RED << "TESTING NON MEMBER'S SWAP" << WHITE << std::endl;

		swap(v3, v1);

		swap(v2, v3);

		std::cout << "v1 size : " << v1.size() << std::endl;
		std::cout << "v2 size : " << v2.size() << std::endl;
		std::cout << "v3 size : " << v3.size() << std::endl;
		std::cout << "v1 capacity : " << v1.capacity() << std::endl;
		std::cout << "v2 capacity : " << v2.capacity() << std::endl;
		std::cout << "v3 capacity : " << v3.capacity() << std::endl;

		std::cout << GREEN << "v1 content :" << std::endl;
		for ( NM::vector<int>::iterator it = v1.begin() ; it != v1.end() ; it++ )
		{
			std::cout << *it << " ";
		}
		std::cout << WHITE << std::endl << std::endl;
		

		std::cout << GREEN << "v2 content :" << std::endl;
		for ( NM::vector<int>::iterator it = v2.begin() ; it != v2.end() ; it++ )
		{
			std::cout << *it << " ";
		}
		std::cout << WHITE << std::endl << std::endl;
		

		std::cout << GREEN << "v3 content :" << std::endl;
		for ( NM::vector<int>::iterator it = v3.begin() ; it != v3.end() ; it++ )
		{
			std::cout << *it << " ";
		}
		std::cout << WHITE << std::endl << std::endl << std::endl;
    }*/

	
	/*{//! INSERT SIZE TEST
	
		NM::vector<int>			test(3, 3);
		NM::vector<int>			testi(15, 3);
		NM::vector<int> 		BOB(0, 0);

		std::cout << RED << "BEFORE BOB CAPACITY : " << WHITE << BOB.capacity() << std::endl;
		std::cout << RED << "BEFORE BOB SIZE : " << WHITE << BOB.size() << std::endl;
		
		BOB.insert(BOB.begin(), testi.begin(), testi.end());
		std::cout << RED << "BEFORE BOB CAPACITY : " << WHITE << BOB.capacity() << std::endl;
		std::cout << RED << "BEFORE BOB SIZE : " << WHITE << BOB.size() << std::endl;
		BOB.push_back(0);
		std::cout << RED << "BEFORE BOB CAPACITY : " << WHITE << BOB.capacity() << std::endl;
		std::cout << RED << "BEFORE BOB SIZE : " << WHITE << BOB.size() << std::endl;
		BOB.insert(BOB.begin(), testi.begin(), testi.end());

		std::cout << BLUE << "BEFORE AFTER BOB CAPACITY : " << BLUE << BOB.capacity() << WHITE << std::endl;
		std::cout << BLUE << "BEFORE AFTER BOB SIZE : " << BLUE << BOB.size()<< WHITE << std::endl;
	}*/

	{ //! DEBUG
	
		NM::vector<int>			test(10, 50);
		// NM::vector<int>			testi(15, 3);
		NM::vector<int> 		BOB(1, 1);

		std::cout << RED << "BEFORE BOB CAPACITY : " << WHITE << BOB.capacity() << std::endl;
		std::cout << RED << "BEFORE BOB SIZE : " << WHITE << BOB.size() << std::endl;

		BOB.insert(BOB.begin(), 200, 12);
		BOB.insert(BOB.begin() + 12, 200, 30);
		BOB.insert(BOB.end(), 12, 50);
		BOB.insert(BOB.end() - 1, 0, 60);
		BOB.insert(BOB.end() - 1, 0, 70);
		for ( NM::vector<int>::iterator it = BOB.begin() ; it != BOB.end() ; it++ )
		{
			std::cout << *it << " ";
		}
		std::cout << std::endl << std::endl;

		std::cout << BLUE << "BEFORE AFTER BOB CAPACITY : " << BLUE << BOB.capacity() << WHITE << std::endl;
		std::cout << BLUE << "BEFORE AFTER BOB SIZE : " << BLUE << BOB.size()<< WHITE << std::endl;
	}
		
    /*{
    NM::vector<int>			test(3, 3);

	std::cout << "self assignation test\n";
	NM::vector<NM::vector<int> >	self_assign;
	NM::vector<NM::vector<int> >	*ptr = &self_assign;
	NM::vector<NM::vector<int> >	*ptr2 = &self_assign;

	self_assign.assign(4, test);
	*ptr = *ptr2;

	std::cout << std::boolalpha << (*ptr == *ptr2) << '\n';



	NM::vector<NM::vector<int> > JOHN;
	NM::vector<NM::vector<int> > BOB(5, test);
	std::cout << "BOB(5, test(test, 5)) : \n";
	for (size_t i = 0; i < BOB.size(); i++)
	{
		for (size_t j = 0; j < BOB[i].size(); j++)
			std::cout << BOB[i][j] << ' ';
		std::cout << '\n';
	}
	NM::vector<NM::vector<int> > MIKE(BOB);

	// CTORs
	std::cout << "\nCTORS\n";
	std::cout << "Empty is empty ? " << std::boolalpha << JOHN.empty() << '\n';
	std::cout << "BOB is empty? " << BOB.empty() << '\n';

	std::cout << "Size of JOHN " << JOHN.size() << std::endl;
	std::cout << "Size of BOB " << BOB.size() << std::endl;
	std::cout << "Size of MIKE " << MIKE.size() << std::endl;

	// RESIZE
	size_t	bob_resize = 2;
	std::cout << "\nRESIZE\n";
	BOB.resize(bob_resize);
	std::cout << "Size of JOHN " << JOHN.size() << std::endl;
	if (JOHN.capacity() >= JOHN.size())
		std::cout << "Capacity of JOHN is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 53\n";
	std::cout << "Size of BOB " << BOB.size() << std::endl;
	if (BOB.capacity() >= bob_resize)
		std::cout << "Capacity of BOB is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 58\n";
	std::cout << "Size of MIKE " << MIKE.size() << std::endl;
	if (MIKE.capacity() >= MIKE.size())
		std::cout << "Capacity of MIKE is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 63\n";

	size_t	mike_resize = 9;
	bob_resize = 0;
	
	BOB.resize(bob_resize);
	std::cout << "BOB is empty now ? " << BOB.empty() << '\n';
	MIKE.resize(mike_resize, test);
	std::cout << "Size of JOHN " << JOHN.size() << std::endl;
	if (JOHN.capacity() >= JOHN.size())
		std::cout << "Capacity of JOHN is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 86\n";
	std::cout << "Size of BOB " << BOB.size() << std::endl;
	if (BOB.capacity() >= bob_resize)
		std::cout << "Capacity of BOB is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 91\n";
	std::cout << "Size of MIKE " << MIKE.size() << std::endl;
	if (MIKE.capacity() >= mike_resize)
		std::cout << "Capacity of MIKE is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 96\n";
	for (size_t i = 0; i < MIKE.size(); i++)
	{
		for (size_t j = 0; j < MIKE[i].size(); j++)
		{
			std::cout << MIKE[i][j] << ' ';
		}
	std::cout << std::endl;
	}
    
	// RESERVE
	std::cout << "\nRESERVE\n";

	size_t	john_reserve = 0;
	size_t	bob_reserve = 3;
	size_t	mike_reserve = 4;

	JOHN.reserve(john_reserve);
	BOB.reserve(bob_reserve);
	MIKE.reserve(mike_reserve);
	std::cout << "Size of JOHN " << JOHN.size() << std::endl;
	if (JOHN.capacity() >= john_reserve)
		std::cout << "Capacity of JOHN is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 120\n";
	std::cout << "Size of BOB " << BOB.size() << std::endl;
	if (BOB.capacity() >= bob_reserve)
		std::cout << "Capacity of BOB is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 125\n";
	std::cout << "Size of MIKE " << MIKE.size() << std::endl;
	if (MIKE.capacity() >= mike_reserve)
		std::cout << "Capacity of MIKE is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 130\n";
	for (size_t i = 0; i < MIKE.size(); i++)
	{
		for (size_t j = 0; j < MIKE[i].size(); j++)
			std::cout << MIKE[i][j] << ' ';
	std::cout << std::endl;
	}
   
	//AT
	std::cout << "\nAT\n";
	try
	{
		std::cout << MIKE.at(2).front() << '\n';
		std::cout << MIKE.at(87).back() << '\n';
	}
	catch (std::out_of_range& oor)
	{
		(void)oor;
		std::cout << "OOR error caught\n";
	}

	// FRONT / BACK
	std::cout << "\nFRONT / BACK\n";
	std::cout << "front() of MIKE : " << MIKE.front().front() << '\n';
	std::cout << "back() of MIKE : " << MIKE.back().back() << '\n';

	//ASSIGN
	std::cout << "\nASSIGN\n";
	test.assign(3, 17);
	BOB.assign(3, test);

	//ASSIGN RANGE
	std::cout << "\nASSIGN RANGE\n";
	NM::vector<NM::vector<int> >	assign_range;
	assign_range.assign(8, test);
	assign_range.assign(BOB.begin() + 1, BOB.end() - 2);

	//EMPTY
	std::cout << "\nEMPTY\n";
	std::cout << "BOB is empty ? " << BOB.empty() << '\n';
	std::cout << "BOB at(1) : " << BOB.at(1).front() << '\n';

	//PUSH/POP_BACK
	std::cout << "\nPUSH/POP_BACK\n";
	test.assign(2, 42);
	BOB.push_back(test);
	std::cout << "last elem of BOB : " << BOB.back().back() << '\n';
    std::cout << " right before pop_back" << std::endl;
	BOB.pop_back();
	std::cout << "last elem of BOB : " << BOB.back().back() << '\n';

	//INSERT
	std::cout << "\nINSERT\n";
	NM::vector<NM::vector<int> >	insert_in_me;
	for (int i = 0; i < 15; i++)
	{
		NM::vector<int>	j(2, i);
		insert_in_me.push_back(j);
	}
	for (size_t i = 0; i < insert_in_me.size(); i++)
	{
		for (size_t j = 0; j < insert_in_me.at(i).size(); j++)
			std::cout << insert_in_me.at(i).at(j) << ' ';
		std::cout << '\n';
	}

	NM::vector<NM::vector<int> >::iterator	tmp;
	test.assign(23, 19);
	tmp = insert_in_me.begin() + 4;
	insert_in_me.insert(tmp, 8, test);
	for (size_t i = 0; i < insert_in_me.size(); i++)
	{
		for (size_t j = 0; j < insert_in_me.at(i).size(); j++)
			std::cout << insert_in_me.at(i).at(j) << ' ';
		std::cout << '\n';
	}

	std::cout << "CAPACITY : " << insert_in_me.capacity() << std::endl;
	NM::vector<NM::vector<int> >::const_iterator const_it(insert_in_me.begin());
	std::cout << "Const it.front() : " << std::endl;
	std::cout << (*const_it).front() << '\n';


	//INSERT
	std::cout << "\nINSERT\n";
	NM::vector<NM::vector<int> >	std_insert_in_me;
	for (int i = 0; i < 15; i++)
		std_insert_in_me.push_back(test);
	for (size_t i = 0; i < std_insert_in_me.size(); i++)
		std::cout << std_insert_in_me.at(i).front() << ' ';
	std::cout << '\n';

	NM::vector<NM::vector<int> >::iterator	std_tmp;
	std_tmp = std_insert_in_me.begin() + 4;
	std_insert_in_me.insert(std_tmp, 8, test);
	for (size_t i = 0; i < std_insert_in_me.size(); i++)
		std::cout << std_insert_in_me.at(i).back() << ' ';
	std::cout << '\n';


	//INSERT RANGE
	std::cout << "\nINSERT RANGE\n";
	NM::vector<NM::vector<int> >	insert_bis;
	for (int i = 0; i < 7; i++)
	{
		NM::vector<int>	j(2, i * 3);
		insert_bis.push_back(j);
	}
	for (size_t i = 0; i < insert_bis.size(); i++)
		std::cout << insert_bis[i].back() << ' ';
	std::cout << '\n';

	insert_bis.insert(insert_bis.begin() + 5, insert_in_me.begin(), insert_in_me.end());
	for (size_t i = 0; i < insert_bis.size(); i++)
		std::cout << insert_bis[i].back() << ' ';
	std::cout << '\n';


	//ERASE
	std::cout << "\nERASE\n";
	NM::vector<NM::vector<int> >	erase_in_me;
	for (int i = 0; i < 15; i++)
	{
		NM::vector<int>	j(1, i);
		erase_in_me.push_back(j);
	}
	for (size_t i = 0; i < erase_in_me.size(); i++)
		std::cout << erase_in_me.at(i).front() << ' ';
	std::cout << '\n';

	erase_in_me.erase(erase_in_me.begin() + 7);
	for (size_t i = 0; i < erase_in_me.size(); i++)
		std::cout << erase_in_me.at(i).front() << ' ';
	std::cout << '\n';
	erase_in_me.erase(erase_in_me.begin() + 2, erase_in_me.begin() + 6);
	for (size_t i = 0; i < erase_in_me.size(); i++)
		std::cout << erase_in_me.at(i).front() << ' ';
	std::cout << '\n';

	//SWAP
	std::cout << "\nSWAP\n";
	john_reserve = 4;
	JOHN.reserve(john_reserve);
	BOB.swap(MIKE);
	std::cout << "Size of JOHN " << JOHN.size() << std::endl;
	if (JOHN.capacity() >= JOHN.size())
		std::cout << "Capacity of JOHN is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 272\n";
	std::cout << "Size of BOB " << BOB.size() << std::endl;
	if (BOB.capacity() >= BOB.size())
		std::cout << "Capacity of BOB is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 277\n";
	std::cout << "Size of MIKE " << MIKE.size() << std::endl;
	if (MIKE.capacity() >= MIKE.size())
		std::cout << "Capacity of MIKE is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 282\n";
	for (size_t i = 0; i < MIKE.size(); i++)
	{
		for (size_t j = 0; j < MIKE[i].size(); j++)
			std::cout << MIKE[i][j] << ' ';
	std::cout << std::endl;
	}

	MIKE.swap(JOHN);
	std::cout << "Size of JOHN " << JOHN.size() << std::endl;
	if (JOHN.capacity() >= JOHN.size())
		std::cout << "Capacity of JOHN is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 298\n";
	std::cout << "Size of BOB " << BOB.size() << std::endl;
	if (BOB.capacity() >= BOB.size())
		std::cout << "Capacity of BOB is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 303\n";
	std::cout << "Size of MIKE " << MIKE.size() << std::endl;
	if (MIKE.capacity() >= MIKE.size())
		std::cout << "Capacity of MIKE is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 308\n";
	for (size_t i = 0; i < MIKE.size(); i++)
	{
		for (size_t j = 0; j < MIKE[i].size(); j++)
			std::cout << MIKE[i][j] << ' ';
	std::cout << std::endl;
	}

	//CLEAR
	std::cout << "\nCLEAR\n";
	JOHN.clear();
	MIKE.clear();
	std::cout << "Size of JOHN " << JOHN.size() << std::endl;
	if (JOHN.capacity() >= JOHN.size())
		std::cout << "Capacity of JOHN is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 327\n";
	std::cout << "Size of BOB " << BOB.size() << std::endl;
	if (BOB.capacity() >= BOB.size())
		std::cout << "Capacity of BOB is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 332\n";
	std::cout << "Size of MIKE " << MIKE.size() << std::endl;
	if (MIKE.capacity() >= MIKE.size())
		std::cout << "Capacity of MIKE is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 337\n";
	for (size_t i = 0; i < MIKE.size(); i++)
	{
		for (size_t j = 0; j < MIKE[i].size(); j++)
			std::cout << MIKE[i][j] << ' ';
	std::cout << std::endl;
	}

	//NON MEMBER Functions
	std::cout << "\nNON MEMBER functions\n";
	swap(BOB, MIKE);
	std::cout << "Size of JOHN " << JOHN.size() << std::endl;
	if (JOHN.capacity() >= JOHN.size())
		std::cout << "Capacity of JOHN is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 355\n";
	std::cout << "Size of BOB " << BOB.size() << std::endl;
	if (BOB.capacity() >= BOB.size())
		std::cout << "Capacity of BOB is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 360\n";
	std::cout << "Size of MIKE " << MIKE.size() << std::endl;
	if (MIKE.capacity() >= MIKE.size())
		std::cout << "Capacity of MIKE is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 365\n";
	for (size_t i = 0; i < MIKE.size(); i++)
	{
		for (size_t j = 0; j < MIKE[i].size(); j++)
			std::cout << MIKE[i][j] << ' ';
	std::cout << std::endl;
	}
	
	//RELATIONAL OPERATORS
	std::cout << "\nRELATIONAL OPERATORS\n";
	NM::vector<NM::vector<int> > MIKE_2(MIKE);
	std::cout << "MIKE and BOB are equal ? " << (MIKE == BOB) << '\n';
	std::cout << "MIKE and MIKE_2 are equal ? " << (MIKE == MIKE_2) << '\n';

	std::cout << "\nReal Vector\n";
	NM::vector<NM::vector<int> > real;
	real.assign(5, test);
	for (NM::vector<NM::vector<int> >::iterator it = real.begin(); it != real.end(); it++)
		std::cout << (*it).front() << " ";
	std::cout << '\n';

	std::cout << std::endl;
    
	}
	*/

    return 0;
}


