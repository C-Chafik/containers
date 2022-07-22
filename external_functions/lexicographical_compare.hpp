/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexicographical_compare.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarouf <cmarouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 16:36:05 by cmarouf           #+#    #+#             */
/*   Updated: 2022/07/22 16:48:47 by cmarouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXICOGRAPHICAL_COMPARE_HPP
# define LEXICOGRAPHICAL_COMPARE_HPP

template <class InputIterator1, class InputIterator2>
bool lexicographical_compare( InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2 )
{
    while ( first1 != last1 )
    {
        if ( first2 == last2 || *first2 < *first1 )
            return false;
        else if ( *first1 < *first2 )
            return true;
        ++first1; ++first2;
    }
  return ( first2 != last2 );
}

template <class InputIterator1, class InputIterator2, class Compare>
bool lexicographical_compare( InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2, Compare comp )
{
    while ( first1 != last1 )
    {
        if ( first2 == last2 || comp(*first2, first1))
            return false;
        else if (comp(*first1, *first2))
            return true;
        ++first1; ++first2;
    }
  return ( first2 != last2 );
}


#endif