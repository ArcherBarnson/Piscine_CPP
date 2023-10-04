/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 16:09:13 by bgrulois          #+#    #+#             */
/*   Updated: 2023/10/04 12:20:14 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include "ICharacter.hpp"

class AMateria
{
	public:
		AMateria(std::string const & type);
		AMateria(AMateria const & src);
		AMateria &operator=(AMateria const & other);
		virtual ~AMateria() = 0;
		std::string const & getType() const; //Returns the materia type
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
	protected:
		AMateria(void);
		std::string type;
};

#endif
