/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 12:56:50 by bgrulois          #+#    #+#             */
/*   Updated: 2023/10/05 16:48:10 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

class WrongAnimal {
	public:
		WrongAnimal( void );
		WrongAnimal(WrongAnimal const & src);
		WrongAnimal &operator=(WrongAnimal const & other);
		virtual ~WrongAnimal( void );
		std::string const & getType() const;
		void		makeSound() const;

	protected:
		std::string type;
};

#endif
