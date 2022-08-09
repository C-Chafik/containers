/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarouf <cmarouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 19:51:12 by cmarouf           #+#    #+#             */
/*   Updated: 2022/08/09 21:30:05 by cmarouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_CPP
# define MAP_CPP

# include <iostream>
# include <memory>

# include "utils/pair.hpp"
# include "utils/make_pair.hpp"
# include "utils/is_integral.hpp"
# include "utils/lexicographical_compare.hpp"
# include "utils/equal.hpp"
# include "utils/enable_if.hpp"
# include "iterators/iterator_traits.hpp"
# include "iterators/bidirectional_iterator.hpp"
# include "iterators/RBT_iterator.hpp"
# include "utils/red_black_tree.hpp"

namespace ft
{
	template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<std::pair<const Key,T> > > 
	class map
	{
		public:
			typedef Key key_type;
			typedef T   mapped_type;
			typedef Compare key_compare;
			//typedef value_compare //? Nested function class to compare elements
			typedef Alloc allocator_type;
			
			typedef typename    ft::pair<const key_type, mapped_type> 	value_type;
			typedef typename    allocator_type::difference_type 		difference_type;
			typedef typename    allocator_type::size_type 				size_type;
			typedef typename    allocator_type::reference 				reference;
			typedef typename    allocator_type::const_reference 		const_reference;
			typedef typename    allocator_type::pointer 				pointer;
			typedef typename    allocator_type::const_pointer 			const_pointer;
			typedef typename    ft::RBT<value_type, Compare>::iterator 			iterator;
			typedef typename    ft::RBT<value_type, Compare>::const_iterator 	const_iterator;
			typedef typename    ft::reverse_iterator<iterator> 			reverse_iterator;
			typedef typename    ft::reverse_iterator<const_iterator> 	const_reverse_iterator;

			explicit map( const key_compare & comp = key_compare(), const allocator_type & alloc = allocator_type() ) : _size(0), _cmp(comp), _alloc(alloc)
			{
			}

			// template < class InputIterator >
			// map( InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type() )
			// {
				
			// }

			map( const map & x )
			{
				*this = x;    
			}

			map & operator=( const map & x )
			{
				if ( *this != x )
				{
					_size = x._size;
					_cmp = x._cmp;
					_alloc = x._alloc;
				}
				return *this;
			}

			iterator begin( void )
			{
				return _root.begin();
			}
			
			const_iterator begin( void ) const
			{
				return _root.begin();
			}

			ft::pair<iterator,bool> insert( const value_type & val )
			{
				ft::pair<iterator, bool> ret;
				ret = _root.insert(val);
				return ret;
			}
			
		private:
			RBT<value_type, key_compare> _root;
			size_type       _size;
			key_compare     _cmp;
			allocator_type  _alloc;
		
	};
}

#endif