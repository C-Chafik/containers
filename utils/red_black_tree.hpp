/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_black_tree.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarouf <cmarouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 17:19:57 by cmarouf           #+#    #+#             */
/*   Updated: 2022/08/10 22:22:17 by cmarouf          ###   ########.fr       */
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
			typedef T_alloc															allocator_type;
			typedef N_alloc															allocator_nodes;
			typedef typename ft::RBT_iterator<Node>									iterator; //! Besoin de rendre les fonctions en const 
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
			}

			//* Operator =
			RBT & operator=( const RBT & src )
			{
				if ( *this != src )
					_root = src._root;
				return *this;
			}
			
			iterator end( void )
			{
				return iterator(maximum(_root));
			}

			const_iterator end( void ) const
			{
				return const_iterator(maximum(_root));
			}
			
			iterator begin( void )
			{
				return iterator(minimum(_root));	
			}

			const_iterator begin( void ) const
			{
				return const_iterator(minimum(_root));	
			}

			//* Find the maximum from a node
			Node_pointer maximum( Node_pointer start )
			{
				while ( start->right != NULL )
					start = start->right;
				if ( start == NULL )
					return NULL;
				return start;
			}

			//* Find the minimum from a node
			Node_pointer minimum( Node_pointer start )
			{
				while ( start->left != NULL )
					start = start->left;
				if ( start == NULL )
					return NULL;
				return start;
			}

			//? Lets begin with the rotation function, in order to prepare the field for the insertion / erasing

			//* Left Rotation
			void rotate_left( Node_pointer x )
			{
				Node_pointer y = x->right;
				
				x->right = y->left;
				if ( y->left )
					y->left->parent = x;
				y->parent = x->parent;
				if ( x->parent == NULL )
					_root = y;
				else if ( x == x->parent->left )
					y = x->parent->left;
				else
					y = x->parent->right;
				y->left = x;
				x->parent = y;	
			}

			//* Right Rotation
			void rotate_right( Node_pointer x )
			{
				Node_pointer y = x->left;

				x->left = y->right;
				if ( y->right )
					y->right->parent = x;
				y->parent = x->parent;
				if ( x->parent == NULL )
					_root = y;
				else if ( x == x->parent->right )
					y = x->parent->right;
				else
					y = x->parent->left;
				y->right = x;
				x->parent = y;	
			}

			//* Transplant
			void transplant( Node_pointer u, Node_pointer v)
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

			//* Insertion

			ft::pair<iterator,bool> insert( const value_type & data )
			{
				Node_pointer x = _root;

				if ( x == NULL ) //* If the tree is empty or not
				{
					x = _alloc.allocate(sizeof(value_type) * 1);
					_alloc.construct(x, Node(data));
					x->color = BLACK;
					_root = x;
					return ft::make_pair<iterator, bool>(iterator(x), true);
				}
				else
				{
					Node_pointer y;
					while ( x )
					{
						y = x;
						if (_cmp(x->data.first, data.first))
							x = x->right;
						else if (_cmp(data.first, x->data.first))
							x = x->left;
					}
					x = _alloc.allocate(sizeof(value_type) * 1);
					_alloc.construct(x, Node(data));
					x->parent = y;
					if (_cmp(y->data.first, x->data.first))
						y->right = x;
					else
						y->left = x;
					insert_fix(y);
					return ft::make_pair<iterator, bool>(iterator(x), true);
				}
			}

			//* Rebalancing the tree after insertion
			void insert_fix( Node_pointer z )
			{
				while ( z->parent &&  z->parent->color == RED )
				{
					if ( z->parent == z->parent->parent->left )
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
								z = z->parent->right;
								rotate_left(z);
							}
							z->parent->color = BLACK;
							z->parent->parent->color = RED;
							rotate_right(z->parent->parent);
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
						else if ( z == z->parent->left)
						{
							z = z->parent;
							rotate_right(z);
						}
						z->parent->color = BLACK;
						z->parent->parent->color = RED;
						rotate_left(z->parent->parent);
					}
				}
				_root->color = BLACK;
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
				}
				if ( del == NULL )
					return ft::make_pair<iterator, bool>(NULL, false);

				Node_pointer x;
				Node_pointer y = del;
				int	old_color = y->color;
							
				if ( del->left == NULL )
				{
					x = del->right;
					transplant(del, del->right);
				}
				else if ( del->right == NULL )
				{
					x = del->left;
					transplant(del, del->left);
				}
				else
				{
					y = minimum(del->right);
					old_color = y->color;
					x = y->right;
					if ( x && y->parent == del )
						x->parent = y;
					else
					{
						transplant(y, y->right);
						y->right = del->right;
						if (y->right)
							y->right->parent = y;
					}
					transplant(del, y);
					y->left = del->left;
					if (y->left)
						y->left->parent = y;
					y->color = del->color;
				}
				_alloc.destroy(del);
				_alloc.deallocate(del, sizeof(value_type) * 1);
				if ( old_color == BLACK )
					erase_fix(x);
				return ft::make_pair<iterator, bool>(iterator(x), true);
			}
			
			//* Rebalancing the tree after erasing
			void erase_fix( Node_pointer x )
			{
				while ( x != _root && x->color == BLACK )
				{
					if ( x == x->parent->left )
					{
						Node_pointer w = x->parent->right;
						if ( x->parent->right->color == RED )
						{
							x->parent->right->color = BLACK;
							x->parent->color = RED;
							rotate_left(x->parent);
							w = x->parent->right;
						}
						if ( w->right->color == BLACK && w->left->color == BLACK )
						{
							w->color = RED;
							x = x->parent;
						}
						else if ( w->right->color == BLACK )
						{
							w->left->color = BLACK;
							w->color = RED;
							rotate_right(w);
							w = x->parent->right;
						}
						else
						{
							w->color = x->parent->color;
							x->parent->color = BLACK;
							w->right->color = BLACK;
							rotate_left(x->parent);
							_root = x;		
						}
					}
					else
					{
						Node_pointer w = x->parent->left;
						if ( x->parent->left->color == RED )
						{
							x->parent->left->color = BLACK;
							x->parent->color = RED;
							rotate_right(x->parent);
							w = x->parent->left;
						}
						if ( w->right->color == BLACK && w->right->color == BLACK )
						{
							w->color = RED;
							x = x->parent;
						}
						else if ( w->left->color == BLACK )
						{
							w->right->color = BLACK;
							w->color = RED;
							rotate_left(w);
							w = x->parent->left;
						}
						else
						{
							w->color = x->parent->color;
							x->parent->color = BLACK;
							w->left->color = BLACK;
							rotate_right(x->parent);
							_root = x;		
						}
					}
				}
				x->color = BLACK;
			}

		private:
			Node_pointer		_root;
			key_compare			_cmp;
			allocator_nodes		_alloc;
			allocator_type		_talloc;
	};
}


#endif