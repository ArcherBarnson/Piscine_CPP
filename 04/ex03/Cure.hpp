/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 16:29:26 by bgrulois          #+#    #+#             */
/*   Updated: 2023/09/07 16:37:29 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

class Cure : public AMateria {
	Cure( void );
	Cure(Cure const & src);
	Cure &operator=(Cure const & other);
	~Cure( void );
};

#endif
