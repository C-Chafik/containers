/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBT_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarouf <qatar75020@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 18:28:49 by cmarouf           #+#    #+#             */
/*   Updated: 2022/08/14 02:43:29 by cmarouf          ###   ########.fr       */
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
		: 	_node(NULL),
		 	_end(NULL)
		{
			
		}
		
        RBT_iterator( iterator_type node, iterator_type end ) 
		: 	_node(node), 
			_end(end) 
		{
			
		}

		RBT_iterator( const RBT_iterator & x ) 
		: 	_node(x._node), 
			_end(x._end)
		{
			
		}
		
		~RBT_iterator( void ) { }

		RBT_iterator & operator=( const RBT_iterator & x )
		{
			_node = x._node;
			_end = x._end;
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
		
		iterator_type end( void ) const
		{
			return _end;
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
			iterator_type	_end;

		void 	tree_increment( void )
		{
			if (_node)
			{
				_end = _node;
				if ( _node->right )
				{
					_node = _node->right;
					while ( _node->left )
						_node = _node->left;
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
			else
				_node = _end;
		}
    };

	template < class Iterator >
    class const_RBT_iterator
    {
        public:
            typedef const Iterator* 																		iterator_type;
			typedef typename Iterator::value_type 													const value_type;
            typedef typename ft::iterator< bidirectional_iterator_tag, value_type>::iterator_category iterator_category;
            typedef typename ft::iterator< bidirectional_iterator_tag, value_type>::difference_type 	difference_type;
            typedef typename ft::iterator< bidirectional_iterator_tag, value_type>::pointer 			pointer;
            typedef typename ft::iterator< bidirectional_iterator_tag, value_type>::reference 		reference;
		
        const_RBT_iterator( void )
		: 	_node(NULL),
			_end(NULL)
		{
			
		}
		
        const_RBT_iterator( iterator_type node, iterator_type end ) 
		: 	_node(node), 
			_end(end)
		{
			
		}

		const_RBT_iterator( const const_RBT_iterator & x ) 
		: 	_node(x._node), 
			_end(x._end)
		{

		}

		const_RBT_iterator( const RBT_iterator<Iterator> & x ) 
		: 	_node(x.base()), 
			_end(x.end())
		{

		}

		~const_RBT_iterator( void ) 
		{ 
			
		}

		const_RBT_iterator & operator=( const const_RBT_iterator & x )
		{
			_node = x._node;
			_end = x._end;
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

		iterator_type end( void ) const
		{
			return _end;
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
			iterator_type 	_end;

		void 	tree_increment( void )
		{
			if (_node)
			{
				_end = _node;
				if ( _node->right )
				{
					_node = _node->right;
					while ( _node->left )
						_node = _node->left;
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
			else
				_node = _end;
		}
    };
}

#endif