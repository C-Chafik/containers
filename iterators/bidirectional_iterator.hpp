/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bidirectional_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarouf <cmarouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 15:27:04 by cmarouf           #+#    #+#             */
/*   Updated: 2022/08/09 16:45:42 by cmarouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIDIRECTIONAL_ITERATOR_HPP
# define BIDIRECTIONAL_ITERATOR_HPP

# include "iterators.hpp"

namespace ft
{
    template <class Iterator>
    class bidirectional_iterator
    {
        public:
            typedef Iterator iterator_type;
            typedef typename ft::iterator< bidirectional_iterator_tag, Iterator>::iterator_category iterator_category;
            typedef typename ft::iterator< bidirectional_iterator_tag, Iterator>::value_type value_type;
            typedef typename ft::iterator< bidirectional_iterator_tag, Iterator>::difference_type difference_type;
            typedef typename ft::iterator< bidirectional_iterator_tag, Iterator>::pointer pointer;
            typedef typename ft::iterator< bidirectional_iterator_tag, Iterator>::reference reference;

        bidirectional_iterator( void ) {}

        explicit bidirectional_iterator( iterator_type & it ) { _ptr = it; }
        
        ~bidirectional_iterator( void ) {}
        
        iterator_type base( void ) const
        {
            return _ptr;   
        }

        bidirectional_iterator & operator=( bidirectional_iterator & src )
        {
            if (src != *this)
                _ptr = src._ptr;
            return *this;
        }

        reference operator*( void ) const
        {
            Iterator tmp = _ptr;

            return *tmp;
        }

        reference operator->( void ) const
        {
            return &(operator*());
        }

        bidirectional_iterator & operator++( void )
        {
            ++_ptr;
            return *this;
        }
        
        bidirectional_iterator operator++( int )
        {
            bidirectional_iterator tmp = *this;

            ++_ptr;
            return tmp;
        }

        bidirectional_iterator & operator--( void )
        {
            --_ptr;
            return *this;
        }

        bidirectional_iterator  operator--( int )
        {
            bidirectional_iterator tmp = *this;
            
            --_ptr;
            return tmp;
        }

        private:
            Iterator _ptr;
    };

    template <class Iterator, class Iterator2>
    bool operator==( const bidirectional_iterator<Iterator>& lhs, const bidirectional_iterator<Iterator2>& rhs )
    {
        return lhs.base() == rhs.base();
    }

    template <class Iterator, class Iterator2>
    bool operator!=( const bidirectional_iterator<Iterator>& lhs, const bidirectional_iterator<Iterator2>& rhs )
    {
        return lhs.base() != rhs.base();
    }

}

#endif