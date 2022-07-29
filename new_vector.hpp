/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarouf <qatar75020@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 15:49:52 by cmarouf           #+#    #+#             */
/*   Updated: 2022/07/29 00:42:40 by cmarouf          ###   ########.fr       */
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

            explicit vector( const allocator_type & alloc = allocator_type() ) : _ptr(NULL), _size(0), _capacity(0) _alloc(alloc) {}

            template <class InputIterator>
            explicit vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()) : _ptr(NULL), _size(0), _capacity(std::distance(first, last)), _alloc(alloc)
            {
                assign(first, last);
            }

            explicit vector( size_type n, const value_type & val = value_type(), const allocator_type & alloc = allocator_type() ) : _ptr(NULL), _size(n), _capacity(n), _alloc(alloc)
            {
                assign(n, val);
            }

            vector( const vector & x ) : _ptr(x._ptr), _size(x._size), _capacity(x._capacity), _alloc(x._alloc)
            {
                *this = x;
            }

            ~vector( void ) 
            {
                // clear();
                // _alloc.deallocate(_start, sizeof(value_type) * _capacity);
                
            }

            //! Operator =


            vector & operator=( const vector & x )
            {
                if (*this == x)
                    return *this;
                assign(x.begin(), x.end());
                return *this;
            }

            
            //! Iterators

            iterator begin( void )
            {
                return _ptr;
            }

            const_iterator begin( void ) const
            {
                return _ptr;
            }

            iterator end( void )
            {
                return _ptr + _size;
            }

            const_iterator end( void ) const
            {
                 return _ptr + _size;
            }

            //! Reverse Iterators

            reverse_iterator rbegin( void )
            {
                return reverse_iterator(_ptr + size);
            }

            const_reverse_iterator rbegin( void ) const
            {
                return reverse_iterator(_ptr + size);
            }

            reverse_iterator rend( void )
            {
                return reverse_iterator(_ptr);
            }

            const_reverse_iterator rend( void ) const
            {
                return reverse_iterator(_ptr);
            }

            //! Modifier
            
            template < class InputIterator >
            void assign ( InputIterator first, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator >::type last )
			{
                size_type len = std::distance(first, last);
				clear();
                if (len > _capacity)
                    reserve(len);
				size_type i = 0;
                
				for ( ; first != last ; first++ )
				{					
                    _alloc.construct(_ptr + i, *first);
					i++;
				}
				_size += i;
			}
            
            void assign( size_type n, const value_type & val )
            {
                clear();
                if (n > _capacity)
                    reserve(n);
                size_type i = 0;
                
                for ( ; i < n ; i++ )
                {
                    _alloc.construct((_ptr + i), val);
                }
                _size += n;
            }
            
            void clear( )
            {
                size_type i = 0;
                
                for ( ; i < _size ; i++ )
                {
                    _alloc.destroy(_ptr + i);
                }
                _size = 0;
            }

            void push_back ( const value_type & val )
            {
                if (_capacity > 0 && _size == _capacity)
                {
                    pointer tmp = _alloc.allocate(tmp, _capacity * 2);
                    for ( size_type i = 0 ; i < _size ; i++ )
                    {
                        _alloc.construct((tmp + i), _ptr + i);
                    }
                }
            }

            void pop_back( )
            {
                if (_size > 0)
                {
                    _alloc.destroy(_ptr + _size - 1);
                    _size--;
                }
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
                difference_type n = std::distance(first, last);
                difference_type sp = position - _start;

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
                for ( difference_type i = 0 ; i < n ; i++)
                {
                    *(position + i) = *(first++);
                }
                _end = _end + n;
            }

            //! Erase

            iterator erase( iterator position )
            {
                difference_type sp = position - _start;
                
                position = _start + sp;
                if (position)
                    _alloc.destroy(position);
                for ( pointer tmp = position + 1 ; tmp != _end ; tmp++)
                {
                    *(tmp - 1) = *tmp;
                }
                _end = _end - 1;
                return position;
            }

            iterator erase( iterator first, iterator last )
            {
                difference_type len = std::distance(first, last);
                
                
                pointer tmp_destroy = first;
                for ( ; tmp_destroy != last ; tmp_destroy++ )
                {
                    _alloc.destroy(tmp_destroy);
                }
                pointer tmp_relocate = first;
                for ( difference_type i = 0 ; _start + i != _end ; i++)
                {
                    *(tmp_relocate) = *(tmp_relocate + std::distance(first, last));
                    tmp_relocate++;
                }
                _end = _end - len;
                return first;
            }

            //! Swap

            void swap( vector & x )
            {
                pointer tmp;

                tmp = _ptr;
                _ptr = x._ptr;
                x._ptr = tmp;

                size_type tmp_size = _size;
                _size = x._size;
                x._size = tmp_size;

                size_type tmp_capacity = _capacity;
                 _capacity = x. _capacity;
                x. _capacity = tmp_capacity;
            }
            
            //! Capacity

            void resize (size_type n, value_type val = value_type())
            {
                if (n > max_size())
                    throw std::length_error("vector::reserve");
                
                if (n < size())
                {
                    for ( size_type i = n; i < size() ; i++)
                    {
                        if (_start + i)
                            _alloc.destroy(_start + i);
                    }
                }
                else if (n > size())
                {
                    if (n > capacity())
                        reserve(n);
                    for ( size_type i = size(); i < n ; i++ )
                    {   
                        _alloc.construct((_start + i), val);
                    }
                }
                _end = _start + n;
            }
            
            void reserve( size_type n )
            {
                if (n > max_size())
                    throw std::length_error("vector::reserve");
                if (n > capacity())
                {
                    pointer     tmp;
                    size_type   i = 0;
                    
                    tmp = _alloc.allocate(sizeof(value_type) * n);
                    for ( ; _start + i != _end ; i++ )
                    {
                        _alloc.construct((tmp + i), *(_start + i));
                        // _alloc.destroy(_start + i);
                    }
                    clear();
                    if (capacity() != 0)
                        _alloc.deallocate(_start, sizeof(value_type) * capacity());
                    _end = tmp + i;
                    _endc = tmp + n;
                    _start = tmp;
                }
            }
            
            bool empty() const
            {
                return size == 0;   
            }
            
            size_type capacity() const
            {
                return _capacity;
            }
            
            size_type size() const
            {
                return _size;
            }

            size_type max_size() const
            {
                return _alloc.max_size();
            }

			//! Element access

            reference operator[] ( size_type n ) { return *(_ptr + n); }

            const_reference operator[] (size_type n) const { return *(_ptr + n); }

            reference at ( size_type n ) 
            {
                if (n >= _size)
                    throw(std::out_of_range("at")); 
                return *(_ptr + n); 
            }

            const_reference at ( size_type n)  const
            {
                if (n >= _size)
                    throw(std::out_of_range("at")); 
                return *(_ptr + n);
            }

            reference front( ) { return *_ptr; }

            const_reference front( ) const { return *_ptr; }

            reference back() { return *((_ptr + _size) - 1); }

            const_reference back() const { return *((_ptr + _size) - 1); }

            //! Allocator
            
            allocator_type get_allocator() const { allocator_type tmp; return tmp; }
            

        private:
            // pointer _start;
            // pointer _end;
            // pointer _endc;
            pointer _ptr;
            size_type _size;
            size_type _capacity;
            allocator_type _alloc;
    };

    //! Relational Operators

    template <class T, class Alloc>
    bool operator==( const vector<T,Alloc> & lhs, const vector<T,Alloc> & rhs )
    {
        return ( lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin()) );
    }

    template <class T, class Alloc>
    bool operator!=( const vector<T,Alloc> & lhs, const vector<T,Alloc> & rhs )
    {
        return !(lhs == rhs);
    }

    template <class T, class Alloc>
    bool operator<( const vector<T,Alloc> & lhs, const vector<T,Alloc> & rhs )
    {
        return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
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
        if (x == y)
            return ;
        x.swap(y); 
    }
}

#endif