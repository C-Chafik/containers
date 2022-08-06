/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enable_if.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarouf <cmarouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 18:15:33 by cmarouf           #+#    #+#             */
/*   Updated: 2022/07/18 21:27:20 by cmarouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENABLE_IF_HPP
# define ENABLE_IF_HPP


namespace ft
{
    template<bool Cond, class T = void> 
    struct enable_if
    {
    
    };
    
    template<class T> 
    struct enable_if<true, T> 
    { 
        typedef T type; 
    };
}

#endif