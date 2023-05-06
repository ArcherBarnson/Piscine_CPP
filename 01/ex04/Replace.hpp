#ifndef REPLACE_H
# define REPLACE_H

#include <iostream>

class Replace {
	public:
		Replace( std::string filename, std::string s1, std::string s2 );
		~Replace( void );
		std::string	replace(void);
		void		bufToFile(std::string buf, std::string destfile);


	private:
		std::string	_filename;
		std::string	_s1;
		std::string	_s2;
};

#endif
