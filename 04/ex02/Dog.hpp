/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 12:56:50 by bgrulois          #+#    #+#             */
/*   Updated: 2023/10/11 16:43:42 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include "Animal.hpp" 
# include "Brain.hpp" 

class Dog : public Animal {
	public:
		Dog( void );
		Dog(Dog const & src);
		Dog &operator=(Dog const & other);
		virtual ~Dog( void );
		virtual void	makeSound() const;
	private:
		Brain	*_brain;
};

#endif
