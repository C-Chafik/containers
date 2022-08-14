/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarouf <qatar75020@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 21:57:26 by cmarouf           #+#    #+#             */
/*   Updated: 2022/08/14 02:19:14 by cmarouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
#   define PAIR_HPP

namespace ft
{
    template <class T1, class T2>
    struct pair
    {
        //* Members type
        typedef T1 first_type;
        typedef T2 second_type;


        //* Members variable
        first_type  first;
        second_type second;

        //* Constructor
        pair( void ) : first(first_type()), second(second_type())
        {
            
        }

        pair( const first_type & a, const second_type & b ) : first(a), second(b)
        {
            
        }

        template<class U, class V>
        pair( const pair<U, V> & pr ) : first(pr.first), second(pr.second)
        {
        
        }
        
        //* Operator =
        pair & operator=( const pair & pr )
        {
            if ( this == &pr )
                return *this;
            first = pr.first;
            second = pr.second;
            return *this;
        }
    };
    
    template <class T1, class T2>
    bool operator==( const pair<T1,T2> & lhs, const pair<T1,T2> & rhs )
    {
        return (lhs.first == rhs.first) && (lhs.second == rhs.second);
    }

    template <class T1, class T2>
    bool operator!=( const pair<T1,T2> & lhs, const pair<T1,T2> & rhs )
    {
        return !(lhs == rhs);
    }

    template <class T1, class T2>
    bool operator<( const pair<T1,T2> & lhs, const pair<T1,T2> & rhs )
    {
        return lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second);
    }

    template <class T1, class T2>
    bool operator<=( const pair<T1,T2> & lhs, const pair<T1,T2> & rhs )
    {
        return !(rhs < lhs);
    }

    template <class T1, class T2>
    bool operator>( const pair<T1,T2> & lhs, const pair<T1,T2> & rhs )
    {
        return rhs < lhs;
    }

    template <class T1, class T2>
    bool operator>=( const pair<T1,T2> & lhs, const pair<T1,T2> & rhs )
    {
        return !(lhs < rhs);
    }
}

#endif