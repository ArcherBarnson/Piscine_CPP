/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:00:33 by bgrulois          #+#    #+#             */
/*   Updated: 2023/11/15 11:00:34 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <limits.h>
# include <stdint.h>
# include <iostream>

struct Data
{
    int a;
    int b;
    int c;
};

class Serializer
{
    public:
        Serializer();
        Serializer(Serializer const & copy);
        Serializer &operator=(Serializer const & other);
        ~Serializer();
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);

};

#endif
