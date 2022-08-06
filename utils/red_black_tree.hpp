/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_black_tree.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarouf <cmarouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 17:19:57 by cmarouf           #+#    #+#             */
/*   Updated: 2022/08/06 21:47:22 by cmarouf          ###   ########.fr       */
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

enum    e_RB
{
    RED,
    BLACK  
};

namespace ft
{
    template < class T, class Comp >
    class RBT
    {
        Node *root;
    };
}


#endif