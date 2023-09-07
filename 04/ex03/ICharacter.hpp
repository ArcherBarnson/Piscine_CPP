/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 16:21:10 by bgrulois          #+#    #+#             */
/*   Updated: 2023/09/07 16:24:38 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class ICharacter
{
	public:
		virtual ~ICharacter( void ) {}
		virtual std::string const & getName() const = 0;
		virtual void equip(AMateria* m) = 0;
		virtual void unequip(int idx) = 0;
		virtual void use(int idx, ICharacter& target) = 0;
	protected:
		ICharacter(std::string name);
		std::string name;
};
