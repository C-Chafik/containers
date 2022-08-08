/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pair.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarouf <cmarouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 14:52:00 by cmarouf           #+#    #+#             */
/*   Updated: 2022/08/08 15:04:30 by cmarouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAKE_PAIR_HPP
# define MAKE_PAIR_HPP

# include "pair.hpp"

namespace ft
{
    template < class T1, class T2 >
    pair< T1, T2 > make_pair( T1 x, T2 y )
    {
        return ( pair< T1, T2 >( x, y ) );
    }
    
}

#endif