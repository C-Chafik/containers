/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBT_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarouf <cmarouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 18:28:49 by cmarouf           #+#    #+#             */
/*   Updated: 2022/08/10 22:01:00 by cmarouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBT_ITERATOR_HPP
# define RBT_ITERATOR_HPP

# include "../iterators/bidirectional_iterator.hpp"

namespace ft
{
    template < class Iterator >
    class RBT_iterator
    {
        public:													
            typedef Iterator* 																		iterator_type;
			typedef typename Iterator::value_type 															value_type;
            typedef typename ft::iterator< bidirectional_iterator_tag, value_type>::iterator_category iterator_category;
            typedef typename ft::iterator< bidirectional_iterator_tag, value_type>::difference_type 	difference_type;
            typedef typename ft::iterator< bidirectional_iterator_tag, value_type>::pointer 			pointer;
            typedef typename ft::iterator< bidirectional_iterator_tag, value_type>::reference 		reference;

        RBT_iterator( void )
		: 	_node(NULL)
		{
			
		}
		
        RBT_iterator( iterator_type node ) { _node = node; }

		RBT_iterator( const RBT_iterator & x ) : _node(x._node)
		{
			
		}
		
		~RBT_iterator( void ) { }

		RBT_iterator & operator=( const RBT_iterator & x )
		{
			if ( *this != x )
			{
				_node = x._node;
			}
			return *this;
		}

		reference operator*( void ) const
        {
            return _node->data;
        }

		pointer operator->( void ) const
        {
            return &(_node->data);
        }

		iterator_type base( void ) const
		{
			return _node;
		}

		RBT_iterator & operator++( void )
		{
			tree_increment();
			return *this;
		}

		RBT_iterator operator++( int )
		{
			RBT_iterator tmp = *this;
			
			tree_increment();
			return tmp;
		}

		RBT_iterator & operator--( void )
		{
			tree_decrement();
			return *this;
		}

		RBT_iterator operator--( int )
		{
			RBT_iterator tmp = *this;
			
			tree_decrement();
			return tmp;
		}

		bool operator==( const RBT_iterator & rhs )
		{
			return _node == rhs._node;
		}

		bool operator!=( const RBT_iterator & rhs )
		{
			return _node != rhs._node;
		}

		private:
			iterator_type 	_node;

		void 	tree_increment( void )
		{
			if (_node)
			{
				if ( _node->right )
				{
					iterator_type tmp = _node->right;
					while ( tmp->left )
					{
						tmp = tmp->left;
					}
					_node = tmp;
				}
				else
				{
					while (_node->parent && _node->parent->right == _node)
						_node = _node->parent;
					_node = _node->parent;
				}
			}
		}

		void	tree_decrement( void )
		{
			if (_node)
			{
				if ( _node->left )
				{
					_node = _node->left;
					while ( _node->right )
						_node = _node->right;
				}
				else
				{
					while (_node->parent && _node->parent->left == _node)
						_node = _node->parent;
					_node = _node->parent;
				}
			}
		}
    };

	template < class Iterator >
    class const_RBT_iterator
    {
        public:
            typedef const Iterator* 																		iterator_type;
			typedef typename Iterator::value_type 															value_type;
            typedef typename ft::iterator< bidirectional_iterator_tag, Iterator>::iterator_category iterator_category;
            typedef typename ft::iterator< bidirectional_iterator_tag, Iterator>::difference_type 	difference_type;
            typedef typename ft::iterator< bidirectional_iterator_tag, Iterator>::pointer 			pointer;
            typedef typename ft::iterator< bidirectional_iterator_tag, Iterator>::reference 		reference;

        const_RBT_iterator( void )
		: 	_node(NULL)
		{
			
		}
		
        const_RBT_iterator( iterator_type & node ) { _node = node; }

		~const_RBT_iterator( void ) {}

		const_RBT_iterator & operator=( const_RBT_iterator & x )
		{
			if ( *this != x )
			{
				_node = x._node;
			}
			return *this;
		}

		reference operator*( void ) const
        {
            return _node->data;
        }

		pointer operator->( void ) const
        {
            return &(_node->data);
        }

		iterator_type base( void ) const
		{
			return _node;
		}

		const_RBT_iterator & operator++( void )
		{
			tree_increment();
			return *this;
		}

		const_RBT_iterator & operator++( int )
		{
			const_RBT_iterator tmp = *this;
			
			tree_increment();
			return tmp;
		}

		const_RBT_iterator & operator--( void )
		{
			tree_decrement();
			return *this;
		}

		const_RBT_iterator & operator--( int )
		{
			const_RBT_iterator tmp = *this;
			
			tree_decrement();
			return tmp;
		}

		bool operator==( const const_RBT_iterator & rhs )
		{
			return _node == rhs._node;
		}

		bool operator!=( const const_RBT_iterator & rhs )
		{
			return _node != rhs._node;
		}

		private:
			iterator_type 	_node;

		void 	tree_increment( void )
		{
			if (_node)
			{
				if ( _node->right )
				{
					iterator_type tmp = _node->right;
					while ( tmp->left )
					{
						tmp = tmp->left;
					}
					_node = tmp;
				}
				else
				{
					while (_node->parent && _node->parent->right == _node)
						_node = _node->parent;
					_node = _node->parent;
				}
			}
		}

		void	tree_decrement( void )
		{
			if (_node)
			{
				if ( _node->left )
				{
					_node = _node->left;
					while ( _node->right )
						_node = _node->right;
				}
				else
				{
					while (_node->parent && _node->parent->left == _node)
						_node = _node->parent;
					_node = _node->parent;
				}
			}
		}
    };
}

#endif