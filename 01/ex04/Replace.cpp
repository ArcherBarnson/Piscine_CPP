#include "Replace.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

Replace::Replace( std::string filename, std::string s1, std::string s2 ) :
		_filename(filename), _s1(s1), _s2(s2) {
	return ;
}

Replace::~Replace( void ) {
	return ;
}

std::string	Replace::replace(void)
{
	int			i;
	std::ostringstream	gee;
	std::string		buf;
	std::string 		retbuf;
	std::ifstream		src(_filename.c_str());

	if (_s1 == "" && _s2 != "")
	{
		std::cerr << "Error: s1 is empty but s2 is not." << std::endl;
		return ("");
	}
	if (!src)
	{
		std::cerr << "Error: file <" << _filename << "> couldn't be open.";
		std::cerr << std::endl;
		return ("");
	}
	gee << src.rdbuf();
	buf = gee.str();
	for (i = 0; (i + _s1.length()) < buf.length(); i++)
	{
		if (buf.compare(i, _s1.length(), _s1) == 0)
		{
			retbuf += _s2;
			i += _s1.length();
		}
		retbuf += buf[i];
	}
	src.close();
	return (retbuf);
}

void		Replace::bufToFile(std::string buf, char *destfile)
{
	std::string	formatDestfile = "";
	formatDestfile = formatDestfile.append(destfile);
	std::ofstream	dest(("replace." + formatDestfile).c_str());
	if (!dest)
		return ;
	dest << buf;
	dest.close();
	return ;
}
