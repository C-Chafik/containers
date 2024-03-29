/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarouf <cmarouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 13:27:01 by cmarouf           #+#    #+#             */
/*   Updated: 2022/08/18 15:42:39 by cmarouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

# include "vector.hpp"
# include <cstddef>

namespace ft
{
	template < class T, class Container = ft::vector<T> > 
	class stack
	{
		public :
			typedef T           value_type;
			typedef Container   container_type;
			typedef size_t      size_type;

		explicit stack( const container_type & ctnr = container_type() ) : _ctnr(ctnr)
		{
			
		}

		bool empty( void ) const
		{
			return _ctnr.empty();   
		}

		size_type size( void ) const
		{
			return _ctnr.size();   
		}

		value_type & top( void )
		{
			return _ctnr.back();
		}

		const value_type & top( void ) const
		{
			return _ctnr.back();
		}

		void push( const value_type & val)
		{
			_ctnr.push_back(val);	
		}
		
		void pop( void )
		{
			_ctnr.pop_back();
		}
		
  		friend bool operator==( const stack & lhs, const stack & rhs )
		{
			return lhs._ctnr == rhs._ctnr;
		}
		
  		friend bool operator<( const stack & lhs, const stack & rhs )
		{
			return lhs._ctnr < rhs._ctnr;
		}

		protected:
			container_type _ctnr;
	};

	template <class T, class Container>
  	bool operator!=( const stack<T,Container> & lhs, const stack<T,Container> & rhs )
	{
		return !(lhs == rhs);
	}

	template <class T, class Container>
  	bool operator<=( const stack<T,Container> & lhs, const stack<T,Container> & rhs )
	{
		return !(rhs < lhs);
	}

	template <class T, class Container>
  	bool operator>( const stack<T,Container> & lhs, const stack<T,Container> & rhs )
	{
		return rhs < lhs;
	}

	template <class T, class Container>
  	bool operator>=( const stack<T,Container> & lhs, const stack<T,Container> & rhs )
	{
		return !(lhs < rhs);
	}
}

# endif