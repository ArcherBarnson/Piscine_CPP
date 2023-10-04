/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 11:37:58 by bgrulois          #+#    #+#             */
/*   Updated: 2023/10/04 16:55:09 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"
# include "AMateria.hpp"
# include "Ice.hpp"
# include "Cure.hpp"

class MateriaSource : public IMateriaSource {
	public:
		MateriaSource( void );
		MateriaSource(MateriaSource const & src);
		MateriaSource &operator=(MateriaSource const & src);
		~MateriaSource( void );
		void learnMateria(AMateria*);
		AMateria* createMateria(std::string const & type);
	private:
		AMateria *_materiaStorage[4];

};

#endif
