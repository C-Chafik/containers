/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarouf <cmarouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 12:58:52 by cmarouf           #+#    #+#             */
/*   Updated: 2022/08/17 13:31:02 by cmarouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_TRAITS_HPP
# define ITERATOR_TRAITS_HPP

# include <cstddef>

namespace ft
{

    struct output_iterator_tag 
    {
        
    };
    
    struct input_iterator_tag
    {
        
    };

    struct forward_iterator_tag : input_iterator_tag
    {
        
    };

    struct bidirectional_iterator_tag : forward_iterator_tag
    {
        
    };

    struct random_access_iterator_tag : bidirectional_iterator_tag
    {
            
    };

    template <class Iterator>
    class iterator_traits
    {
        public:
            typedef typename Iterator::difference_type difference_type;
            typedef typename Iterator::value_type value_type;
            typedef typename Iterator::pointer pointer;
            typedef typename Iterator::reference reference;
            typedef typename Iterator::iterator_category iterator_category;
    };

    template <class T>
    class iterator_traits<T*>
    {
        public:
            typedef ptrdiff_t difference_type;
            typedef T value_type;
            typedef T * pointer ;
            typedef T & reference;
            typedef random_access_iterator_tag iterator_category;
    };

    template <class T> 
    class iterator_traits<const T*>
    {
        public:
            typedef ptrdiff_t difference_type;
            typedef T value_type;
            typedef const T * pointer;
            typedef const T & reference;
            typedef random_access_iterator_tag iterator_category;      
    };
}

#endif