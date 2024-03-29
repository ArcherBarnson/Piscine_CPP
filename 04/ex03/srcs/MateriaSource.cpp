/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 11:43:37 by bgrulois          #+#    #+#             */
/*   Updated: 2023/10/05 14:57:27 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource( void ) {
	int i;
	for (i = 0; i < 4; i++)
		_materiaStorage[i] = NULL;
	return ;
}

MateriaSource::MateriaSource(MateriaSource const & src) {
	*this = src;
	return ;
}

MateriaSource & MateriaSource::operator=(MateriaSource const & other) {
	(void)other;
	return *this;
}

MateriaSource::~MateriaSource( void ) {
	int i;
	for (i = 0; i < 4; i++)
	{
		if (_materiaStorage[i] != NULL)
			delete _materiaStorage[i];
	}
	return ;
}

void		MateriaSource::learnMateria(AMateria* m)
{
	int	i = 0;
	while (i < 4)
	{
		if (!_materiaStorage[i])
		{
			_materiaStorage[i] = m;
			return ;
		}
		i++;
	}
	std::cout << "Cannot learn more materias, storage full." << std::endl;
	return ;
}

AMateria*	MateriaSource::createMateria(std::string const & type)
{
	int	i = 0;

	while (i < 4)
	{
		if (_materiaStorage[i] != NULL && type == _materiaStorage[i]->getType())
		{
			return (_materiaStorage[i]->clone());
		}
		i++;
	}
	return 0;
}
