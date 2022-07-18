/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarouf <cmarouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 18:26:47 by cmarouf           #+#    #+#             */
/*   Updated: 2022/07/18 21:56:32 by cmarouf          ###   ########.fr       */
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
    NM::vector<int> v1(100, 42);

    return 0;
}


