/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarouf <cmarouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 18:26:47 by cmarouf           #+#    #+#             */
/*   Updated: 2022/07/19 17:41:48 by cmarouf          ###   ########.fr       */
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

    
    NM::vector<int> v2(10, 42);

    std::cout << "Size = " << v2.size();
    //std::cout << "Vector's max size " << v2.max_size() << std::endl;
    std::cout << " Capacity = " << v2.capacity() << std::endl;
    //std::cout << "Is vector empty ? " << v2.empty() << std::endl;
    //NM::vector<int> v2(100, 42);

    v2.resize(5);
    v2.resize(5);

    v2.resize(20);

    v2.resize(5);

    v2.resize(5);

    v2.resize(5);

    

    return 0;
}


