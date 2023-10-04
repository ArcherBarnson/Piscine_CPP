/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 11:43:37 by bgrulois          #+#    #+#             */
/*   Updated: 2023/10/04 11:58:35 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateriaSource"

AMateriaSource::AMateriaSource( void ) {
	return ;
}

AMateriaSource::AMateriaSource(AMateriaSource const & src) {
	*this = src;
	return ;
}

AMateriaSource & AMateriaSource operator=(AMateriaSource const & other) {
	if (other != &src)
		_name = _name.other; //attention a ca
	return *this;
}

AMateriaSource::~AMateriaSource( void ) {
	return ;
}

void		AMateriaSource::learnMateria(AMateria* m)
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

AMateria*	AMateriaSource::createMateria(std::string const & type)
{
	int	i = 0;

	AMateria* cpy = new AMateria(type);
	while (i < 4)
	{
		if (type.compare(_materiaStorage[i]) == 0)
		{
			cpy = &_materiaStorage[i];
			return cpy;
		}
		i++;
	}
	return 0;
}
