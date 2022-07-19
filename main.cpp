/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarouf <cmarouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 18:26:47 by cmarouf           #+#    #+#             */
/*   Updated: 2022/07/19 19:35:44 by cmarouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef STL
    #define NM std
#else
    #define NM ft
#endif

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

    { //!
        
    }
    

    return 0;
}
