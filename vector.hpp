/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarouf <cmarouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 15:49:52 by cmarouf           #+#    #+#             */
/*   Updated: 2022/07/18 23:17:01 by cmarouf          ###   ########.fr       */
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

            explicit vector( const allocator_type & alloc = allocator_type() ) : _start(NULL), _end(NULL), _alloc(alloc) {}

            explicit vector( size_type n, const value_type & val, const allocator_type & alloc = allocator_type() ) : _start(NULL), _end(NULL), _alloc(alloc)
            {
                assign(n, val);
            }

            ~vector( void ) { _alloc.deallocate(_start, _start - _end); }

            template <class InputIterator>
            void assign (InputIterator first, InputIterator last)
			{
				//clear();
                //if (n > capacity())
                    //reserve();
				size_type tmp = 0;
				
				_start = _alloc.allocate(std::distance(first, last));
				for ( ; first != last ; first++ )
				{
					*(_start + tmp) = *first;
					tmp++;
				}
				_end = _start + tmp;
			}

            void assign( size_type n, const value_type & val )
            {
                //clear();
                //if (n > capacity())
                    //reserve();
                size_type tmp = 0;
                
                _start = _alloc.allocate(n);
                for ( ; tmp < n ; tmp++ )
                {
                    *(_start + tmp) = val;
                }
                _end = _start + tmp;
            }

			void push_back( const value_type& val )
			{
				
			}

        private:
            pointer _start;
            pointer _end;
            allocator_type _alloc;
    };
}

#endif