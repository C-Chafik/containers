/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pair.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarouf <qatar75020@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 14:52:00 by cmarouf           #+#    #+#             */
/*   Updated: 2022/08/14 02:19:35 by cmarouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAKE_PAIR_HPP
# define MAKE_PAIR_HPP

# include "pair.hpp"

namespace ft
{
    template < class T1, class T2 >
    ft::pair< T1, T2 > make_pair( T1 x, T2 y )
    {
        return ( ft::pair< T1, T2 >( x, y ) );
    }
    
}

#endif