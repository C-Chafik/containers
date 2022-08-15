/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_black_tree.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarouf <cmarouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 17:19:57 by cmarouf           #+#    #+#             */
/*   Updated: 2022/08/15 22:34:48 by cmarouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RED_BLACK_TREE_HPP
# define RED_BLACK_TREE_HPP

//* A red black tree staties fies the following properties
//* The Root is black
//* There are no two adjacent red nodes (A red node cannot have a red parent or red child).
//* Every Leaf (initialised as NULL) is Black
//* If a Red node has children, then they must be Black
//* For each node, any simple path from a node, to all the way down, got to have the same ammount of black-depth(number of black nodes crossed)

//? Each node will have the following variable
//? int color (will use an enum)
//? value_type key
//? Node leftChild
//? Node rightChild
//? Node *root

# include "RBT_Nodes.hpp" 

enum	e_RB
{
	RED,
	BLACK  
};

//? RBT <=> Red_Black_Tree

namespace	ft
{
    template < class T, class Compare, class Node = Node<T>, class T_alloc = std::allocator<T>, class N_alloc = std::allocator<Node> > 
    class RBT
    {
        public:
			typedef T																value_type;
			typedef typename value_type::first_type									key_type;
			typedef typename value_type::second_type								mapped_type;
			typedef Compare															key_compare;
			typedef T_alloc															allocator_type; //* We actually need the mapped_type allocator to get the right size_type
			typedef N_alloc															allocator_nodes;
			typedef typename allocator_type::size_type								size_type;
			typedef typename ft::RBT_iterator<Node>									iterator;
			typedef typename ft::const_RBT_iterator<Node>							const_iterator;
			typedef typename Node::Node_pointer										Node_pointer;
			typedef typename Node::const_Node_pointer								const_Node_pointer;
			typedef typename Node::reference_Node									reference_Node;
			typedef typename Node::const_reference_Node								const_reference_Node;
			
			//* Default constructor, with the default key_compare
			RBT( void ) : _root(NULL), _cmp(key_compare()), _alloc(allocator_nodes()), _talloc(allocator_type())
			{
			}
			
			//* Constructor with the manually given key_compare
			explicit RBT( const key_compare & new_cmp ) : _root(NULL), _cmp(new_cmp), _alloc(allocator_nodes()), _talloc(allocator_type())
			{
				 
			}

			//* Constructor by copy
			RBT( const RBT & src )
			{
				*this = src;
			}
			
			//* Destructor
			~RBT( void )
			{
				clear();
			}

			//* Operator =
			RBT & operator=( const RBT & src )
			{
				if ( *this != src )
				{
					_root = src._root;
					_cmp = src._cmp;
					_alloc = src._alloc;
				}
				return *this;
			}
			
			//* Iterators
			iterator end( void )
			{
				return iterator(NULL, _maximum(_root));
			}
			
			const_iterator const_end( void ) const
			{
				return const_iterator(NULL, _maximum(_root));
			}
			
			iterator begin( void )
			{
				return iterator(_minimum(_root), NULL);	
			}

			const_iterator const_begin( void ) const
			{
				return const_iterator(_minimum(_root), NULL);	
			}

			size_type max_size( void ) const
			{
				return _alloc.max_size();
			}

			//* Insertion

			ft::pair<iterator,bool> insert( const value_type & data )
			{
				if ( _root == NULL ) //* If the tree is empty or not
				{
					_root = _alloc.allocate(sizeof(Node_pointer) * 1);
					_alloc.construct(_root, Node(data));
					_root->color = BLACK;
					return ft::make_pair<iterator, bool>(iterator(_root, NULL), true);
				}
				else
				{
					Node_pointer x = _root;
					Node_pointer y = NULL;
					while ( x )
					{
						y = x;
						if (_cmp(x->data.first, data.first))
							x = x->right;
						else if (_cmp(data.first, x->data.first))
							x = x->left;
						else // * Else it already exist !
							return ft::make_pair<iterator, bool>(iterator(x, NULL), false);
					}
					x = _alloc.allocate(sizeof(Node_pointer) * 1);
					_alloc.construct(x, Node(data));
					x->parent = y;
					if (_cmp(y->data.first, x->data.first))
						y->right = x;
					else
						y->left = x;
					_insert_fix(x);
					return ft::make_pair<iterator, bool>(iterator(x, NULL), true);
				}
			}

			//* Erasing

			ft::pair<iterator,bool> erase( const key_type & key ) //! Il faut placer le pointeur del a la data recu en parametre, et le destruire si il existe.
			{
				Node_pointer del = _root;

				while ( del && del->data.first != key )
				{
					if (_cmp(key, del->data.first))
						del = del->left;
					else if (_cmp(del->data.first, key))
						del = del->right;
					else
						break ;
				}
				if ( del == NULL )
					return ft::make_pair<iterator, bool>(iterator(NULL, NULL), false);
				
				Node_pointer x;
				Node_pointer y = del;
				int	old_color = y->color;
							
				if ( del->left == NULL )
				{
					x = del->right;
					_transplant(del, del->right);
				}
				else if ( del->right == NULL )
				{
					x = del->left;
					_transplant(del, del->left);
				}
				else
				{
					y = _minimum(del->right);
					old_color = y->color;
					x = y->right;
					if ( x && y->parent == del )
						x->parent = y;
					else
					{
						_transplant(y, y->right);
						y->right = del->right;
						if (y->right)
							y->right->parent = y;
					}
					_transplant(del, y);
					y->left = del->left;
					if (y->left)
						y->left->parent = y;
					y->color = del->color;
				}
				_alloc.destroy(del);
				_alloc.deallocate(del, sizeof(Node_pointer) * 1);
				if ( old_color == BLACK )
					_erase_fix(x);
				return ft::make_pair<iterator, bool>(iterator(x, NULL), true);
			}

			//* Swap			
			void swap( RBT & x )
			{
				Node_pointer		_root_tmp = _root;
				key_compare			_cmp_tmp = _cmp;
				allocator_nodes		_alloc_tmp = _alloc;

				_root = x._root;
				_cmp = x._cmp;
				_alloc = x._alloc;

				x._root = _root_tmp;
				x._cmp = _cmp_tmp;
				x._alloc = _alloc_tmp;
			}

			//* Clear
			void clear( void )
			{
				_root = _recursive_dump(_root);
			}

			//* Operations

			iterator find ( const key_type & k )
			{
				Node_pointer x = _root;
				
				while ( x )
				{
					if (_cmp(x->data.first, k))
							x = x->right;
					else if (_cmp(k, x->data.first))
							x = x->left;
					else // * Found it!
						return iterator(x, NULL);
				}
				return end();
			}

			const_iterator find ( const key_type & k ) const
			{
				Node_pointer x = _root;
				
				while ( x )
				{
					if (_cmp(x->data.first, k))
							x = x->right;
					else if (_cmp(k, x->data.first))
							x = x->left;
					else // * Found it!
						return const_iterator(x, NULL);
				}
				return const_end();
			}

			size_type count( const key_type & k ) const
			{
				Node_pointer x = _root;
				
				while ( x )
				{
					if (_cmp(x->data.first, k))
							x = x->right;
					else if (_cmp(k, x->data.first))
							x = x->left;
					else // * Found it!
						return 1;
				}
				return 0;
			}

			iterator lower_bound ( const key_type & k )
			{
				iterator b = begin();
				iterator e = end();
				while ( b != e)
				{
					if (!_cmp(b->first, k))
						return b;
					b++;
				}
				return b;
			}

			const_iterator lower_bound ( const key_type & k ) const
			{
				const_iterator b = const_begin();
				const_iterator e = const_end();
				while ( b != e)
				{
					if (!_cmp(b->first, k))
						return b;
					b++;
				}
				return b;
			}

			iterator upper_bound ( const key_type & k )
			{
				iterator b = begin();
				iterator e = end();
				while ( b != e)
				{
					if (_cmp(k, b->first))
						return b;
					b++;
				}
				return b;
			}

			const_iterator upper_bound ( const key_type & k ) const
			{
				const_iterator b = const_begin();
				const_iterator e = const_end();
				while ( b != e)
				{
					if (_cmp(k, b->first))
						return b;
					b++;
				}
				return b;
			}

		private:
			Node_pointer		_root;
			key_compare			_cmp;
			allocator_nodes		_alloc;
			allocator_type		_talloc;


			//? Lets begin with the rotation function, in order to prepare the field for the insertion / erasing

			//* Left Rotation
			void _rotate_left( Node_pointer x )
			{
				Node_pointer y = x->right;
				
				x->right = y->left;
				if ( y->left )
					y->left->parent = x;
				y->parent = x->parent;
				if ( x->parent == NULL )
					_root = y;
				else if ( x == x->parent->left )
					x->parent->left = y;
				else
					x->parent->right = y;
				y->left = x;
				x->parent = y;	
			}

			//* Right Rotation
			void _rotate_right( Node_pointer x )
			{
				Node_pointer y = x->left;

				x->left = y->right;
				if ( y->right )
					y->right->parent = x;
				y->parent = x->parent;
				if ( x->parent == NULL )
					_root = y;
				else if ( x == x->parent->right )
					x->parent->right = y;
				else
					x->parent->left = y;
				y->right = x;
				x->parent = y;	
			}

			//* Transplant
			void _transplant( Node_pointer u, Node_pointer v)
			{
				if ( u->parent == NULL )
					_root = v;
				else if ( u == u->parent->left )
					u->parent->left = v;
				else
					u->parent->right = v;
				if (v)
					v->parent = u->parent;
			}

			//* Tree Eradication
			Node_pointer _recursive_dump( Node_pointer start )
			{
				if (!start)
					return NULL;
				if ( start->right )
					_recursive_dump(start->right);
				if ( start->left )
					_recursive_dump(start->left);
				_alloc.destroy(start);
				_alloc.deallocate(start, sizeof(Node_pointer) * 1);
				return NULL;
			}

			//* Find the maximum from a node
			Node_pointer _maximum( Node_pointer start ) const
			{
				if (!start)
					return NULL;
				if (start->right)
					return _maximum(start->right);
				return start;
			}

			//* Find the minimum from a node
			Node_pointer _minimum( Node_pointer start ) const
			{
				if (!start)
					return NULL;
				if (start->left)
					return _minimum(start->left);
				return start;
			}

			//* Rebalancing the tree after insertion
			void _insert_fix( Node_pointer z )
			{
				while ( z->parent && z->parent->color == RED )
				{
					if ( z->parent->parent->left == z->parent )
					{
						if ( z->parent->parent->right && z->parent->parent->right->color == RED )
						{
							z->parent->parent->left->color = BLACK;
							z->parent->parent->right->color = BLACK;
							z->parent->parent->color = RED;
							z = z->parent->parent;
						}
						else
						{
							if ( z == z->parent->right )
							{
								z = z->parent;
								_rotate_left(z);
							}
							z->parent->color = BLACK;
							z->parent->parent->color = RED;
							_rotate_right(z->parent->parent);
						}
					}
					else
					{
						if ( z->parent->parent->left && z->parent->parent->left->color == RED )
						{
							z->parent->parent->left->color = BLACK;
							z->parent->parent->right->color = BLACK;
							z->parent->parent->color = RED;
							z = z->parent->parent;
						}
						else
						{
							if ( z == z->parent->left )
							{
								z = z->parent;
								_rotate_right(z);
							}

							z->parent->color = BLACK;
							z->parent->parent->color = RED;
							_rotate_left(z->parent->parent);
						}
					}
				}
				_root->color = BLACK;
			}

			//* Rebalancing the tree after erasing
			void _erase_fix( Node_pointer x )
			{
				while ( x && x != _root && x->color == BLACK )
				{
					if ( x == x->parent->left )
					{
						Node_pointer w = x->parent->right;
						if ( w->color == RED )
						{
							w->color = BLACK;
							x->parent->color = RED;
							_rotate_left(x->parent);
							w = x->parent->right;
						}
						if ( (!w->right || w->right->color == BLACK) && (!w->left || w->left->color == BLACK ))
						{
							w->color = RED;
							x = x->parent; 
						}
						else
						{
							if ( w->right->color == BLACK || !w->right )
							{
								w->left->color = BLACK;
								w->color = RED;
								_rotate_right(w);
								w = x->parent->right;
							}
							w->color = x->parent->color;
							if ( x->parent->parent )
								x->parent->parent->color = BLACK;
							if ( w->right )
								w->right->color = BLACK;
							_rotate_left(x->parent);
							x = _root;		
						}
					}
					else
					{
						Node_pointer w = x->parent->left;
						if ( w->color == RED )
						{
							w->color = BLACK;
							x->parent->color = RED;
							_rotate_right(x->parent);
							w = x->parent->left;
						}
						if ( (!w->right || w->right->color == BLACK) && (!w->left || w->left->color == BLACK ))
						{
							w->color = RED;
							x = x->parent;
						}
						else
						{
							if ( w->left->color == BLACK || !w->left )
							{
								w->right->color = BLACK;
								w->color = RED;
								_rotate_left(w);
								w = x->parent->left;
							}
							w->color = x->parent->color;
							if ( x->parent->parent )
								x->parent->parent->color = BLACK;
							if ( w->left )
								w->left->color = BLACK;
							_rotate_right(x->parent);
							x = _root;		
						}
					}
				}
				if ( x )
					x->color = BLACK;
			}
	};
}


#endif