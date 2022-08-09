/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarouf <cmarouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 14:12:29 by cmarouf           #+#    #+#             */
/*   Updated: 2022/08/09 16:24:20 by cmarouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

# include "iterator_traits.hpp"

namespace ft
{
    template <class Iterator> 
    class reverse_iterator
    {
        public:
            typedef Iterator iterator_type;
            typedef typename iterator_traits<Iterator>::iterator_category iterator_category;
            typedef typename iterator_traits<Iterator>::value_type value_type;
            typedef typename iterator_traits<Iterator>::difference_type difference_type;
            typedef typename iterator_traits<Iterator>::pointer pointer;
            typedef typename iterator_traits<Iterator>::reference reference;

        reverse_iterator( void ) { };

        explicit reverse_iterator( iterator_type it ) { _ptr = it; };

        template <class Iter>
        reverse_iterator( const reverse_iterator<Iter>& rev_it ) { _ptr = rev_it.base(); };

        iterator_type base( void ) const
        {
            return _ptr;   
        }

        reference operator*( void ) const
        {
            Iterator tmp = _ptr;

            return *--tmp;
        }

        reverse_iterator operator+( difference_type n ) const
        {
            return reverse_iterator(_ptr - n);
        }

        reverse_iterator & operator++( void )
        {
            --_ptr;
            return *this;
        }
        
        reverse_iterator  operator++( int )
        {
            reverse_iterator tmp = *this;

            --_ptr;
            return tmp;
        }

        reverse_iterator & operator+=( difference_type n )
        {
            _ptr -= n;
            return *this;
        }

        reverse_iterator operator-( difference_type n ) const
        {
            return reverse_iterator(_ptr + n);
        }

        reverse_iterator & operator--( void )
        {
            ++_ptr;
            return *this;
        }

        reverse_iterator  operator--( int )
        {
            reverse_iterator tmp = *this;
            
            ++_ptr;
            return tmp;
        }

        reverse_iterator & operator-=( difference_type n )
        {
            _ptr += n;
            return *this;
        }

        pointer operator->( void ) const
        {
            return &(operator*());
        }
        reference operator[]( difference_type n ) const
        {
            return *(*this + n);
        }

        private :
            Iterator _ptr;
    };

    template <class Iterator, class Iterator2>
    bool operator==( const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator2>& rhs )
    {
        return lhs.base() == rhs.base();
    }

    template <class Iterator, class Iterator2>
    bool operator!=( const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator2>& rhs )
    {
        return lhs.base() != rhs.base();
    }

    template <class Iterator, class Iterator2>
    bool operator<( const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator2>& rhs )
    {
        return lhs.base() > rhs.base();
    }

    template <class Iterator, class Iterator2>
    bool operator<=( const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator2>& rhs )
    {
        return lhs.base() >= rhs.base();
    }

   template <class Iterator, class Iterator2>
    bool operator>( const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator2>& rhs )
    {
        return lhs.base() < rhs.base();
    }

    template <class Iterator, class Iterator2>
    bool operator>=( const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator2>& rhs )
    {
        return lhs.base() <= rhs.base();
    }

    template <class Iterator>
    reverse_iterator<Iterator> operator+( typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator>& rev_it )
    {
        return reverse_iterator<Iterator>(rev_it.base() - n);
    }
    
    template <class Iterator, class Iterator2>
    typename reverse_iterator<Iterator>::difference_type operator-( const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator2>& rhs )
    {
        return rhs.base() - lhs.base();
    }
}

#endif
