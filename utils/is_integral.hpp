/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarouf <cmarouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 20:52:46 by cmarouf           #+#    #+#             */
/*   Updated: 2022/07/18 21:34:48 by cmarouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IS_INTEGRAL_HPP
#   define IS_INTEGRAL_HPP

namespace ft
{
    template< class T, T v>
    struct integral_constant
    {
        typedef T type;
        const static bool value = v;
    };
    
    template<class T>
    struct is_integral: integral_constant<bool, false> //!should check that bool //? No specialisation so no integral type, which is false
    {
        
    };
    
    template<>
    struct is_integral<char>: integral_constant<char, true>
    {
        
    };

    /*template<>
    struct is_integral<char16_t>: integral_constant<char16_t, true>
    {
        
    };

    template<>
    struct is_integral<char32_t>: integral_constant<char32_t, true>
    {
        
    };*/

    template<>
    struct is_integral<wchar_t>: integral_constant<wchar_t, true>
    {
        
    };

    template<>
    struct is_integral<signed char>: integral_constant<signed char, true>
    {
        
    };
    
    template<>
    struct is_integral<short int>: integral_constant<short int, true>
    {
        
    };

    template<>
    struct is_integral<int>: integral_constant<int, true>
    {
        
    };

    template<>
    struct is_integral<long int>: integral_constant<long int, true>
    {
        
    };

    template<>
    struct is_integral<long long int>: integral_constant<long long int, true>
    {
        
    };

    template<>
    struct is_integral<unsigned char>: integral_constant<unsigned char, true>
    {
        
    };

    template<>
    struct is_integral<unsigned short int>: integral_constant<unsigned short int, true>
    {
        
    };

    template<>
    struct is_integral<unsigned int>: integral_constant<unsigned int, true>
    {
        
    };
    
    template<>
    struct is_integral<unsigned long int>: integral_constant<unsigned long int, true>
    {
        
    };

    template<>
    struct is_integral<unsigned long long int>: integral_constant<unsigned long long int, true>
    {
        
    };
}

#endif