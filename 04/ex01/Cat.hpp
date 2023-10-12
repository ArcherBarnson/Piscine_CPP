/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 12:56:50 by bgrulois          #+#    #+#             */
/*   Updated: 2023/10/12 15:00:54 by bgrulois         ###   ########.fr       */
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
		std::string	getBrainIdea(int i);
		void		setBrainIdea(int i, std::string idea);
	private:
		Brain	*_brain;
};

#endif
