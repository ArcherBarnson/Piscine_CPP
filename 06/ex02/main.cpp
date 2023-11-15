/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:01:01 by bgrulois          #+#    #+#             */
/*   Updated: 2023/11/15 11:01:55 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Base.hpp"

int main()
{
    Base base;
    Base * test = generate();           //gen by ptr
    Base & testref = *(generate());     //gen by ref
    identify(test);                     //id by ptr
    identify(testref);                  //if by ref
    delete test;                        //delete Base * test
    delete &(testref);                  //delete Base & testref
    return 0;
}
