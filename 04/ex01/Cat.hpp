/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 12:56:50 by bgrulois          #+#    #+#             */
/*   Updated: 2023/10/05 16:48:26 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal {
	public:
		Cat( void );
		Cat(Cat const & src);
		Cat &operator=(Cat const & other);
		virtual ~Cat( void );
		virtual void	makeSound() const;
	private:
		Brain	*brain;
};

#endif
