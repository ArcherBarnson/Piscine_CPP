/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:03:41 by bgrulois          #+#    #+#             */
/*   Updated: 2023/11/15 11:03:43 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <vector>
#include <iterator>

class notFound : public std::exception {
    public:
        virtual const char * what() const throw(){
            return("Error: entry not found");
        }
};

template <typename T>
int easyfind(T container, int n)
{
    std::vector<int>::iterator i = container.begin();
    for(; i != container.end(); i++)
    {
        if (*i == n)
        {
            std::cout << n << " : entry found" << std::endl;
            return (0);
        }
    }
    throw notFound();
    return (*i);
}

#endif
