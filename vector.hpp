/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarouf <cmarouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 15:49:52 by cmarouf           #+#    #+#             */
/*   Updated: 2022/07/22 17:18:38 by cmarouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <memory>

# include "external_functions/is_integral.hpp"
# include "external_functions/lexicographical_compare.hpp"
# include "external_functions/equal.hpp"
# include "external_functions/enable_if.hpp"
# include "iterators/iterator_traits.hpp"
# include "iterators/reverse_iterator.hpp"

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
            typedef typename    ft::reverse_iterator<iterator> reverse_iterator;
            typedef typename    ft::reverse_iterator<const_iterator> const_reverse_iterator;

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

            vector( const vector & x )
            {
                *this = x;
            }

            ~vector( void ) { _alloc.deallocate(_start, _start - _end); }

            //! Operator =


            vector & operator=( const vector & x )
            {
                size_type i = 0;
                
                reserve(x.size());
                clear();
                
                for ( ; i < x.size() ; i++ )
                {
                    *(_start + i) = *(x._start + i);
                }
                _end = _start + i;
                _alloc = x._alloc;
                return *this;
            }

            
            //! Iterators

            iterator begin( void )
            {
                return _start;
            }

            const_iterator begin( void ) const
            {
                return _start;
            }

            iterator end( void )
            {
                return _end;
            }

            const_iterator end( void ) const
            {
                return _end;
            }

            //! Reverse Iterators

            reverse_iterator rbegin( void )
            {
                return _end;
            }

            const_reverse_iterator rbegin( void ) const
            {
                return _end;
            }

            reverse_iterator rend( void )
            {
                return _start;
            }

            const_reverse_iterator rend( void ) const
            {
                return _start;
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

            void insert( iterator position, size_type n, const value_type & val )
            {
                difference_type sp = position - _start;
                
                if (capacity() == 0)
                    reserve(n);
                else if (size() + n > capacity() * 2)
                    reserve(capacity() + n);
                else if (size() + n > capacity())
                    reserve(capacity() * 2);
                
                position = _start + sp;
                
                for ( pointer tmp_end = _end - 1; tmp_end != position - 1; tmp_end-- )
                {
                    *(tmp_end + n) = *(tmp_end);                   
                }
                for ( size_type i = 0 ; i < n ; i++ )
                {
                    *(position + i) = val;
                }
                _end = _end + n;
            }

            template <class InputIterator>
            void insert (iterator position, InputIterator first, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator >::type last )
            {
                difference_type n = last - first; (void)n;
                difference_type sp = position - _start;(void)sp;

                if (capacity() == 0)
                    reserve(std::distance(first, last));
                else if (size() + std::distance(first, last) > capacity() * 2)
                    reserve(capacity() + std::distance(first, last));
                else if (size() + std::distance(first, last) > capacity())
                    reserve(capacity() * 2);
                
                position = _start + sp;
                for ( pointer tmp_end = _end - 1; tmp_end != position - 1; tmp_end-- )
                {
                    *(tmp_end + std::distance(first, last)) = *(tmp_end);                   
                }
                /*for ( ; first != last + 1 ; first++)
                {
                    *(position) = *first;
                }*/
                for ( difference_type i = 0 ; i < std::distance(first, last) ; i++)
                {
                    *(position + i) = *(first + i);
                }
                _end = _end + std::distance(first, last);
            }

            //! Swap

            void swap( vector & x )
            {
                pointer tmp;

                tmp = _start;
                _start = x._start;
                x._start = tmp;

                tmp = _end;
                _end = x._end;
                x._end = tmp;

                tmp = _endc;
                _endc = x._endc;
                x._endc = tmp;
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
            
            void reserve( size_type n )
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
                if (!_start)
                    return 0;
                return _endc - _start;
            }
            
            size_type size() const
            {
                if (!_start)
                    return 0;
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

    //! Relational Operators

    template <class T, class Alloc>
    bool operator==( const vector<T,Alloc> & lhs, const vector<T,Alloc> & rhs )
    {
        return ( lhs.size() == rhs.size() && equal(lhs.begin(), lhs.end(), rhs.begin()) );
    }

    template <class T, class Alloc>
    bool operator!=( const vector<T,Alloc> & lhs, const vector<T,Alloc> & rhs )
    {
        return !(lhs == rhs);
    }

    template <class T, class Alloc>
    bool operator<( const vector<T,Alloc> & lhs, const vector<T,Alloc> & rhs )
    {
        return lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
    }

    template <class T, class Alloc>
    bool operator<=( const vector<T,Alloc> & lhs, const vector<T,Alloc> & rhs )
    {
        return !(rhs < lhs);
    }

    template <class T, class Alloc>
    bool operator>( const vector<T,Alloc> & lhs, const vector<T,Alloc> & rhs )
    {
        return rhs < lhs;
    }

    template <class T, class Alloc>
    bool operator>=( const vector<T,Alloc> & lhs, const vector<T,Alloc> & rhs )
    {
        return !(lhs < rhs);
    }

    //! Non-Member Swap
    template <class T, class Alloc>
    void swap( vector<T,Alloc> & x, vector<T,Alloc> & y )
    {
        x.swap(y); 
    }
}

#endif