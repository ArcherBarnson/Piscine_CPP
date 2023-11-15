/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:00:19 by bgrulois          #+#    #+#             */
/*   Updated: 2023/11/15 11:00:24 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer(void) {
    return ;
}

Serializer::Serializer(Serializer const & copy) {
    (void)copy;
    return ;
}

Serializer & Serializer::operator=(Serializer const & other)
{
    (void)other;
    return *this;
}

Serializer::~Serializer(void){
    return ;
}

uintptr_t Serializer::serialize(Data* ptr)
{
    return(reinterpret_cast<uintptr_t>(ptr));
}

Data*   Serializer::deserialize(uintptr_t raw)
{
    return(reinterpret_cast<Data*>(raw));
}
