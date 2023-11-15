/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:02:31 by bgrulois          #+#    #+#             */
/*   Updated: 2023/11/15 11:02:32 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_H
# define ITER_H

# include <iostream>

template <typename T>
void    iter(T array[], int len, void(*f)(T))
{
    int i;
    for (i = 0; i < len; i++)
        f(array[i]);
}

//template functions

/*template <typename T>
void    increment(T obj)
{
    obj++;
    return ;
}

template <typename T>
void    decrement(T obj)
{
    obj--;
    return ;
}*/

template <typename T>
void    printAsList(T e)
{
    std::cout << "-" << e << std::endl;
    return ;
}

template <typename T>
void    printAsSentence(T e)
{
    std::cout << " " << e;
    return ;
}

#endif
