/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarouf <cmarouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 18:26:47 by cmarouf           #+#    #+#             */
/*   Updated: 2022/06/24 18:30:44 by cmarouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <iostream>

int main(void)
{
    std::vector<int> v1;

    std::cout << "size" << v1.size() << std::endl;
    std::cout << "max_size" << v1.max_size() << std::endl;
    std::cout << "capacity" << v1.capacity() << std::endl;
}