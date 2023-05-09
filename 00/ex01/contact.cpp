/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 15:13:12 by bgrulois          #+#    #+#             */
/*   Updated: 2023/04/04 12:23:23 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact( void ) {
	return ;
}

void	Contact::display_contact_info()
{
	std::cout << "First name	:  " << this->first_name << std::endl;
	std::cout << "Last name	:  " << this->last_name << std::endl;
	std::cout << "Nickname	:  " << this->nickname << std::endl;
	std::cout << "Phone number	:  " << this->phone_number << std::endl;
	std::cout << "Darkest secret	:  " << this->darkest_secret << std::endl;
}

Contact::~Contact( void ) {
	return ;
}
