/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarouf <qatar75020@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 19:51:12 by cmarouf           #+#    #+#             */
/*   Updated: 2022/08/14 03:12:35 by cmarouf          ###   ########.fr       */
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
			typedef typename    ft::pair<const key_type, mapped_type> 	value_type;
			class value_compare //? Nested function class to compare elements
			{
  					friend class ft::map< Key, T, Compare, Alloc>;
					protected:
  						key_compare comp;
  						value_compare (key_compare c) : comp(c) {}  // constructed with map's comparison object
					public:
  						typedef bool result_type;
  						typedef value_type first_argument_type;
  						typedef value_type second_argument_type;
  						bool operator() (const value_type& x, const value_type& y) const
  						{
    						return comp(x.first, y.first);
  						}
			};
			typedef Alloc allocator_type;
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

			template < class InputIterator >
			map( InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type() ) : _size(0), _cmp(comp), _alloc(alloc)
			{
				while ( first != last )
				{
					insert(*first);
					first++;	
				}
			}

			map( const map & x )
			{
				*this = x;    
			}

			~map( void )
			{
				_root.clear();	
			}

			map & operator=( const map & x )
			{
				if ( *this != x )
				{
					_cmp = x._cmp;
					_alloc = x._alloc;
					_root.clear();
					_root.insert(x.begin(), x.end());
					_size = x._size;
				}
				return *this;
			}

			//* Iterator

			iterator begin( void )
			{
				return _root.begin();
			}
			
			const_iterator begin( void ) const
			{
				return _root.const_begin();
			}

			iterator end( void )
			{
				return _root.end();	
			}

			const_iterator end( void ) const
			{
				return _root.const_end();	
			}

			//* Reverse Iterator

			reverse_iterator rbegin( void )
			{
				reverse_iterator rbegin(_root.end());

				// rbegin++;
				return rbegin;
			}
			
			const_reverse_iterator rbegin( void ) const
			{
				const_reverse_iterator rbegin(_root.end());

				// rbegin++;
				return rbegin;
			}

			reverse_iterator rend( void )
			{
				return reverse_iterator( _root.begin());
			}

			const_reverse_iterator rend( void ) const
			{
				return reverse_iterator( _root.begin());	
			}

			bool empty( void ) const
			{
				return _size == 0;
			}

			size_type size( void ) const
			{
				return _size;
			}
			
			size_type max_size( void ) const
			{
				return _alloc.max_size();
			}

			mapped_type & operator[]( const key_type & k )
			{
				return (*((insert(ft::make_pair(k, mapped_type()))).first)).second;
			}
			
			ft::pair<iterator,bool> insert( const value_type & val )
			{
				ft::pair<iterator,bool> ret =  _root.insert(val);
				if ( ret.second == true )
					_size++;
				return ret;
			}

			iterator insert( iterator position, const value_type & val )
			{(void) position;
				return _root.insert(val).first;
			}

			template <class InputIterator>
  			void insert ( InputIterator first, InputIterator last )
			{
				while ( first != last )
				{
					_root.insert(*first);
					first++;
				}
			}

			void erase( iterator position )
			{
				_root.erase(position->first);
			}

			size_type erase( const key_type & k )
			{
				ft::pair<iterator,bool> ret = _root.erase(k);
				if ( ret.second == true )
				{
					_size--;
					return 1;
				}
				return 0;
			}

			void erase( iterator first, iterator last )
			{
				iterator tmp;
				while ( first != last )
				{
					tmp = first;
					first++;
					_root.erase(tmp->first);
				}
			}

			void swap( map & x )
			{
				if ( *this != x )
				{
					size_type       			_size_tmp = _size;
					key_compare    	     		_cmp_tmp = _cmp;
					allocator_type  			_alloc_tmp = _alloc;

					_size = x._size;
					_cmp = x._cmp;
					_alloc = x._alloc;

					x._size = _size_tmp;
					x._cmp = _cmp_tmp;
					x._alloc = _alloc_tmp;
					_root.swap(x._root);
				}
			}

			void clear( void )
			{
				_root.clear();
			}

			key_compare key_comp( void ) const
			{
				return _cmp;
			}

			value_compare value_comp( void ) const
			{
				return value_compare(_cmp);
			}

			iterator find( const key_type & k )
			{
				return _root.find(k);
			}

			const_iterator find ( const key_type & k ) const
			{
				return _root.find(k);
			}

			size_type count( const key_type & k ) const
			{
				return _root.count(k);
			}

			iterator lower_bound ( const key_type & k )
			{
				return _root.lower_bound(k);
			}

			const_iterator lower_bound ( const key_type & k ) const
			{
				return _root.lower_bound(k);
			}

			iterator upper_bound ( const key_type & k )
			{
				return _root.upper_bound(k);
			}

			const_iterator upper_bound ( const key_type & k ) const
			{
				return _root.upper_bound(k);
			}

			ft::pair<iterator, iterator> equal_range ( const key_type & k )
			{
				return ft::make_pair<iterator, iterator>(lower_bound(k), upper_bound(k));
			}

			ft::pair<const_iterator, const_iterator> equal_range ( const key_type & k ) const
			{
				return ft::make_pair<const_iterator, const_iterator>(lower_bound(k), upper_bound(k));
			}

			allocator_type get_allocator( void ) const
			{
				return _alloc;
			}

		private:
			RBT<value_type, key_compare> _root;
			size_type       _size;
			key_compare     _cmp;
			allocator_type  _alloc;
		
	};
}

#endif