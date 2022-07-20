/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarouf <cmarouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 15:49:52 by cmarouf           #+#    #+#             */
/*   Updated: 2022/07/21 00:19:15 by cmarouf          ###   ########.fr       */
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
            typedef             T value_type; //? Aliasing the type T, to value_type
            typedef             Alloc allocator_type;
            typedef typename    allocator_type::difference_type difference_type;
            typedef typename    allocator_type::size_type size_type;
            typedef typename    allocator_type::reference reference;
            typedef typename    allocator_type::const_reference const_reference;
            typedef typename    allocator_type::pointer pointer;
            typedef typename    allocator_type::const_pointer const_pointer;
            typedef T *         iterator;
            typedef const T *   const_iterator;

            explicit vector( const allocator_type & alloc = allocator_type() ) : _start(NULL), _end(NULL), _alloc(alloc) {}

            template <class InputIterator>
            explicit vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()) : _start(NULL), _end(NULL), _endc(NULL), _alloc(alloc)
            {
                assign(first, last);
            }

            explicit vector( size_type n, const value_type & val, const allocator_type & alloc = allocator_type() ) : _start(NULL), _end(NULL), _endc(NULL), _alloc(alloc)
            {
                assign(n, val);
            }

            ~vector( void ) { _alloc.deallocate(_start, _start - _end); }

            
            //! Iterators

            iterator begin()
            {
                return _start;
            }

            const_iterator begin() const
            {
                return _start;
            }

            iterator end()
            {
                return _end;
            }

            const_iterator end() const
            {
                return _end;
            }

            //! Modifier
            
            template < class InputIterator >
            void assign ( InputIterator first, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator >::type last )
			{
				clear();
                if (std::distance(first, last) > capacity())
                    reserve(std::distance(first, last));
				size_type tmp = 0;
				
				for ( ; first != last ; first++ )
				{					
                    *(_start + tmp) = *first;
					tmp++;
				}
				_end = _start + tmp;
			}
            
            void assign( size_type n, const value_type & val )
            {
                clear();
                if (n > capacity())
                    reserve(n);
                size_type tmp = 0;
                
                for ( ; tmp < n ; tmp++ )
                {
                    *(_start + tmp) = val;
                }
                _end = _start + tmp;
            }
            
            void clear( )
            {
                size_type tmp = 0;

                for ( ; _start + tmp != _end ; tmp++)
                {
                    _alloc.destroy(_start + tmp);
                }
            }

            void push_back ( const value_type & val )
            {
                if (capacity() == 0)
                    reserve(1);
                if ( size() + 1 > capacity() )
                    reserve(capacity() * 2);
               _end++;
               *_end = val;
            }

            void pop_back( )
            {
                if (!empty())
                    _alloc.destroy(_end);
                _end--;
            }

            iterator insert( iterator position, const value_type& val )
            {
                difference_type sp = position - _start;
                if (capacity() == 0)
                    reserve(1);
                else if (size() + 1 > capacity())
                    reserve(capacity() * 2);
                
                position = _start + sp;
                for ( pointer tmp_end = _end ; tmp_end != position; tmp_end-- )
                {
                    *tmp_end = *(tmp_end - 1); 
                }
                *position = val;
                _end = _end + 1;
                return position;
            }
            
            //! Capacity

            void resize (size_type n, value_type val = value_type())
            {
                if (n > capacity())
                    reserve(n);
                if (n < size())
                {
                    pointer tmp = _end;

                    for ( ; n < size() ; tmp--, n++)
                    {
                        _alloc.destroy(tmp);
                    }
                    _end = tmp;
                }
                else if (n > size())
                {
                    pointer tmp = _end;
                    size_type i = size();
                    for ( ; i < n ; i++, tmp++ )
                    {
                        *tmp = val;
                    }
                    _end = tmp;
                }
                std::cout << "new capacity = " << capacity() << " new size = " << size() << std::endl;
            }
            
            void reserve (size_type n)
            {
                if (n > capacity())
                {
                    pointer     tmp;
                    size_type   i = 0;
                    
                    
                    tmp = _alloc.allocate(sizeof(value_type) * n);
                    for ( ; _start + i != _end ; i++ )
                    {
                        *(tmp + i) = *(_start + i);
                    }
                    _alloc.deallocate(_start, size());
                    _end = tmp + i;
                    _endc = tmp + n;
                    _start = tmp;
                }
            }
            
            bool empty() const
            {
                return (_end - _start) == 0;   
            }
            
            size_type capacity() const
            {
                return _endc - _start;
            }
            
            size_type size() const
            {
                return _end - _start;
            }

            size_type max_size() const
            {
                return _alloc.max_size();
            }

			//! Element access

            reference operator[] ( size_type n ) { return *(_start + n); }

            const_reference operator[] (size_type n) const { return *(_start + n); }

            reference at ( size_type n ) 
            {
                if (n >= size())
                    throw(std::out_of_range("at")); 
                return *(_start + n); 
            }

            const_reference at ( size_type n)  const
            {
                if (n >= size())
                    throw(std::out_of_range("at")); 
                return *(_start + n);
            }

            reference front( ) { return *_start; }

            const_reference front( ) const { return *_start; }

            reference back() { return *(_end - 1); }

            const_reference back() const { return *(_end - 1); }

            //! Allocator
            
            allocator_type get_allocator() const { allocator_type tmp; return tmp; }
            

        private:
            pointer _start;
            pointer _end;
            pointer _endc;
            allocator_type _alloc;
    };
}

#endif