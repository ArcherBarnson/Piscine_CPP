/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 16:29:26 by bgrulois          #+#    #+#             */
/*   Updated: 2023/10/04 17:25:57 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"

class Cure : public AMateria {
	public:
		Cure( void );
		Cure(Cure const & src);
		Cure &operator=(Cure const & other);
		~Cure( void );
		AMateria* clone() const;
		virtual void use(ICharacter& target);


	private:
		std::string _type;
};

#endif
