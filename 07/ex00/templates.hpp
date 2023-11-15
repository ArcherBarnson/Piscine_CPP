/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   templates.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:02:16 by bgrulois          #+#    #+#             */
/*   Updated: 2023/11/15 11:02:18 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEMPLATES_HPP
# define TEMPLATES_HPP

# include <iostream>

template <typename T>
void swap(T &a, T &b) {
    T tmp = a;
    a = b;
    b = tmp;
    return ;
}

template <typename T>
T min(T a, T b) {
    if (a < b)
        return a;
    if (a > b)
        return b;
    return a;
}

template <typename T>
T max(T a, T b) {
    if (a > b)
        return a;
    if (a < b)
        return b;
    return b;
}

#endif
