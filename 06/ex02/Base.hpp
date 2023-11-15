/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:01:31 by bgrulois          #+#    #+#             */
/*   Updated: 2023/11/15 11:01:34 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

# include <iostream>
# include <stdlib.h>
# include <time.h>

class A;

class Base
{
    public :
        virtual ~Base();
};

Base *generate(void);
void   identify(Base* p);
void   identify(Base& p);

#endif
