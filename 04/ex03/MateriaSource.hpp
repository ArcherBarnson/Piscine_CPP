/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 11:37:58 by bgrulois          #+#    #+#             */
/*   Updated: 2023/10/04 11:48:59 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "AMateria.hpp"

class MateriaSource : public IMateriaSource {
	public:
		MateriaSource( void );
		MateriaSource(MateriaSource const & src);
		MateriaSource &operator=(MateriaSource const & src);
		~MateriaSource( void );
	private:
		_*materiaStorage[4];

};

#endif
