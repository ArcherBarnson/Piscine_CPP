#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <iomanip>
# include <cerrno>
# include <cstring>
# include <stdlib.h>
# include <limits.h>
# include <float.h>

class ScalarConverter {
	public:
		ScalarConverter(void);
		ScalarConverter(ScalarConverter const & copy);
		ScalarConverter &operator=(ScalarConverter const & other);
		~ScalarConverter(void);
		static void	convert(std::string input);
		static int detectType(std::string input);
		static void display(int mode);
		static void displayEval(void);
	private:
		static char _c;
		static long int	_i;
		static float _f;
		static double _d;
		static char *_endbuf;
};

//std::ostream    &operator<<(std::ostream &outfile, ScalarConverter const &f);

#endif