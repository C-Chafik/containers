/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarouf <cmarouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 14:01:19 by cmarouf           #+#    #+#             */
/*   Updated: 2022/06/30 15:26:32 by cmarouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP

namespace ft
{
    template < typename T >
    class Vectorator
    {
        private:
            T *_ptr;
        
        public :
            using difference_type = typename std::iterator<std::random_acces_iterator_tag, Type>::difference_type;
            
            Vectorator( void ) { this->ptr = NULL };

            //! Need to do some research about the iterator's construction/destruction.
            //Vectorrator( Vectorator const & src ) { *this = src; };

            //Vectorator & operator=( Vectorator const & src ) { this->ptr = src.ptr; return *this };

            //~Vectorrator( void ) {};
        
            //Vectorator & operator==( Vectorator const & src ) { return this->ptr == src.ptr; };


            
            //! Arithmetic Besoin d'aide pour comprendre.
            //Vectorator operator+( Vectorator const & src ) const {return _ptr + src._ptr};
            //Vectorator operator-( Vectorator const & src ) const {return _ptr - src._ptr};

            //Vectorator operator+( difference_type src ) const { return _ptr + src };
            //Vectorator operator+( difference_type src ) const { return _ptr - src };
            
            
            
            //? 


            
            //? Incrementation

            //Pre Incrementation
            Vectorator &    operator++( void ) {_ptr++; return *this};
            Vectorator &    operator--( void ) {_ptr--; return *this};
            
            //Post incrementation
            Vectorator    operator++( int ) const { Vectorator(*this) tmp; _ptr++; return tmp};
            Vectorator    operator--( int ) const { Vectorator(*this) tmp; _ptr--; return tmp};
            
            
            //? Comparaison
            
            bool operator==( Vectorator const & src ) const { return _ptr == src._ptr };
            bool operator!=( Vectorator const & src ) const { return _ptr != src._ptr };
            bool operator>( Vectorator const & src ) const { return _ptr > src._ptr };
            bool operator<( Vectorator const & src ) const { return _ptr < src._ptr };
            bool operator<=( Vectorator const & src ) const { return _ptr <= src._ptr };
            bool operator>=( Vectorator const & src ) const { return _ptr >= src._ptr };
            
    }
}

#endif