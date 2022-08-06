/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBT_Nodes.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarouf <cmarouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 19:48:38 by cmarouf           #+#    #+#             */
/*   Updated: 2022/08/06 21:54:57 by cmarouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBT_NODES_HPP
# define RBT_NODES_HPP

# include "red_black_tree.hpp"

namespace ft
{
    enum    e_RB
    {
        RED,
        BLACK  
    };
    
    template < class T >
    struct Node
    {
        typedef T               value_type;
        typedef Node*           Node_pointer;
        typedef const Node*     const_Node_pointer;
        typedef Node&           reference_Node;
        typedef const Node&     const_reference_Node;
        
        Node_pointer*       parent;
        Node_pointer*       left;
        Node_pointer*       right;
        value_type          data;
        int                 color;

        Node( void ) 
        :   parent(NULL),
            left(NULL),
            right(NULL),
            data(NULL),
            color(RED)
        {

        }

        Node( value_type new_data ) 
        :   parent(NULL),
            left(NULL),
            right(NULL),
            data(new_data),
            color(RED)
        {

        }

        Node( const Node & x )
        :   parent(NULL),
            left(NULL),
            right(NULL),
            data(NULL),
            color(0)
        {
            *this = x;
        }
        
        ~Node ( void )
        {
            
        }

        Node & operator=( const Node & x )
        {
            if (*this != x)
            {
                parent = x.parent;
                left = x.left;
                right = x.right;
                data = x.data;
                color = x.color;
            }
            
            return *this;
        }

        Node *get_uncle( void )
        {
            if (!parent || !parent->parent)
                return NULL;
            if (parent->parent->right)
        }

    };
}

#endif