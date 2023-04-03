/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 11:56:35 by bgrulois          #+#    #+#             */
/*   Updated: 2023/04/03 16:11:32 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <string>

class	Contact
{
public:
	void		format_str(std::string str, std::string tr);
	void		display_contact_info();
	int		is_init;
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	phone_number;
	std::string	darkest_secret;
	std::string	trunc_first_name;
	std::string	trunc_last_name;
	std::string	trunc_nickname;
	std::string	trunc_phone_number;
	std::string	trunc_darkest_secret;
};

#endif
