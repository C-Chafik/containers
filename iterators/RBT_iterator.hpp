/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBT_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarouf <cmarouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 18:28:49 by cmarouf           #+#    #+#             */
/*   Updated: 2022/08/08 20:40:23 by cmarouf          ###   ########.fr       */
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
			
            typedef Iterator 														iterator_type;
            typedef typename bidirectional_iterator<Iterator>::iterator_category 	iterator_category;
            typedef typename bidirectional_iterator<Iterator>::value_type 			value_type;
            typedef typename bidirectional_iterator<Iterator>::difference_type 		difference_type;
            typedef typename bidirectional_iterator<Iterator>::pointer 				pointer;
            typedef typename bidirectional_iterator<Iterator>::reference 			reference;

        RBT_iterator( void )
		: 	_node(NULL)
		{
			
		}
		
        explicit RBT_iterator( iterator_type & node ) { _node = node; }

		~RBT_iterator( void ) {}

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

		RBT_iterator & operator++( void )
		{
			tree_increment();
			return *this;
		}

		RBT_iterator & operator++( int )
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

		RBT_iterator & operator--( int )
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
			Iterator 	_node;

		void 	tree_increment( void )
		{
			if ( _node->right )
			{
				Iterator tmp = _node->right;
				while ( tmp->left )
				{
					tmp = tmp->left;
				}
				_node = tmp;
			}
			else
			{
				Iterator tmp = _node->parent;
				if ( tmp->right == _node ) //? Need to undurstand deeply this condition
				{
					while ( tmp->right == _node )
					{
						_node = tmp;
						tmp = tmp->parent;
					}
				}
				if ( _node->right != tmp )
					_node = tmp;
			}
		}

		void	tree_decrement( void )
		{
			if ( _node )
			{
				if ( _node->left )
				{
					_node = _node->left;
					while ( _node->right )
						_node = _node->right;
				}
				else
				{
					Iterator tmp = _node->parent;
					while ( tmp->left == _node ) //? Need to undurstand deeply this loop
					{
						_node = tmp;
						tmp = tmp->parent;
					}
					_node = tmp;
				}
			}
			else //* else its just gonna go to NULL
				_node = _node->parent;
		}
    };
}

#endif