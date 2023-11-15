/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:03:51 by bgrulois          #+#    #+#             */
/*   Updated: 2023/11/15 11:03:52 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main()
{
    std::vector<int>v;
    int n;
    for(n = 0; n < 1000; n++)
    {
        v.push_back(n);
    }
    try
    {
        easyfind(v, 8);
        easyfind(v, 242);
        easyfind(v, 555);
        easyfind(v, 787458);
    }
    catch(notFound e)
    {
        std::cerr << e.what() << std::endl;
    }
    return (0);
}
