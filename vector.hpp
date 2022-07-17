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

# include <iostream>
# include <memory>
namespace ft
{
    template < class T, class Alloc = std::allocator<T> >
    class vector
    {
        public:   
            typedef T value_type; //? Aliasing the type T, to value_type
            //typedef T* ptr;
            typedef Alloc allocator_type;
            typedef typename allocator_type::difference_type difference_type;
            typedef typename allocator_type::size_type size_type;
            typedef typename allocator_type::reference reference;
            typedef typename allocator_type::const_reference const_reference;
            typedef typename allocator_type::pointer pointer;
            typedef typename allocator_type::const_pointer const_pointer;

            explicit vector( const allocator_type & alloc = allocator_type() ) : _alloc(alloc), _begin(NULL), _end(NULL) {}

            /*explicit vector( size_type n, const value_type & val, const allocator_type & alloc = allocator_type() ) : _begin(NULL), _end(NULL), _alloc(alloc)
            {
                assign(n, val);
            }

            void assign( size_type n, const value_type & val )
            {
                //clear();
                //if (n > capacity())
                    //reserve();
                for ( ; n > 0 ; n-- )
                {
                    std::cout << "here" << std::endl;
                    *_end = val;
                    _end++;
                }
            }*/

        private:
            pointer _begin;
            pointer _end;
            allocator_type _alloc;
    };
}

#endif