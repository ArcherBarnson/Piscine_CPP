/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 12:56:50 by bgrulois          #+#    #+#             */
/*   Updated: 2023/10/12 14:56:30 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class Brain {
	public:
		Brain( void );
		Brain(Brain const & src);
		Brain &operator=(Brain const & other);
		virtual ~Brain( void );
		void	setIdea(int i, std::string idea);
		std::string getIdea(int i);

	protected:
		std::string ideas[100];
};

#endif
