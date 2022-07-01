/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarouf <cmarouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 15:49:52 by cmarouf           #+#    #+#             */
/*   Updated: 2022/07/01 17:19:36 by cmarouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>

namespace ft
{
    template < class T, class Alloc = std::allocator<T> >
    class vector
    {
        typedef T value_type; //? Aliasing the type T, to value_type 
        typedef T* pointer; //? Aliasing the pointer to T, to pointer.

        T::value_type content =;
        
    };
}

#endif