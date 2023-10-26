#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <cerrno>

class ScalarConverter {
	public:
		ScalarConverter(void);
		ScalarConverter(ScalarConverter const & copy);
		ScalarConverter &operator=(ScalarConverter const & other);
		~ScalarConverter(void);
		static void	convert(std::string input);
	private:
		static char _c;
		static int	_i;
		static float _f;
		static double _d;
		static char *_endbuf;
};

#endif