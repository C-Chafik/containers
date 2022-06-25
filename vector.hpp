/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarouf <cmarouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 15:49:52 by cmarouf           #+#    #+#             */
/*   Updated: 2022/06/25 18:03:07 by cmarouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>

namespace ft
{
    template< class T, class allocator = std::allocator<T> >
    class   vector
    {
        typedef T                               value_type;
        typedef allocator                       allocator_type;
        typedef 

        explicit vector();
    };
}

#endif