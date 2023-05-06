#include "Replace.hpp"
#include <iostream>
#include <fstream>

Replace::Replace( std::string filename, std::string s1, std::string s2 ) :
		_filename(filename), _s1(s1), _s2(s2) {
	return ;
}

Replace::~Replace( void ) {
	return ;
}

std::string	Replace::replace(void)
{
	int		i = 0;
	std::string	buf;
	std::string 	retbuf;
	std::ifstream	src(_filename);

	if (_s1 == "" || _s2 != "")
	{
		std::cerr << "Error: s1 is empty but s2 is not." << std::endl;
		return (NULL);
	}
	if (!src)
	{
		std::cerr << "Error: file <" << _filename << "> couldn't be open.";
		std::cerr << std::endl;
		return (NULL);
	}
	src >> buf;
	for (i; (i + _s1.length()) < buf.length(); i++)
	{
		if (_s1.compare(i, _s1.length(), buf) == 0)
			retbuf += _s2;
		retbuf += buf[i];
	}
	src.close();
	return (retbuf);
}

void		bufToFile(std::string buf, std::string destfile)
{
	std::ofstream	dest(destfile);
	if (!dest)
		return ;
	buf << dest;
	dest.close();
	return ;
}
