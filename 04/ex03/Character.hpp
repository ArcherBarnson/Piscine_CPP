/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 16:26:15 by bgrulois          #+#    #+#             */
/*   Updated: 2023/10/04 13:05:09 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"
# include "Ice.hpp"
# include "Cure.hpp"

class Character : public ICharacter {
	public:
		Character( void );
		Character( std::string name );
		Character(Character const & src);
		Character &operator=(Character const & src);
		~Character( void );
		std::string const & getName() const;
	private:
		AMateria		*_inventory[4];
		std::string const	_name;
};

#endif
