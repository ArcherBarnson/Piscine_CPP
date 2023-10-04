/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 16:26:15 by bgrulois          #+#    #+#             */
/*   Updated: 2023/10/04 17:26:11 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"

class Ice : public AMateria {
	public:
		Ice( void );
		Ice(Ice const & src);
		Ice &operator=(Ice const & src);
		~Ice( void );
		AMateria* clone() const; 
		virtual void use(ICharacter& target);
};

#endif
