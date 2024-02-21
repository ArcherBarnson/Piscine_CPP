#ifndef RPN_HPP
# define RPN_HPP

# include <algorithm>
# include <stack>
# include <iostream>

class RPN {
	public:
		RPN(void);
		RPN(std::string expr);
		RPN(RPN const & copy);
		RPN &operator=(RPN const & other);
		int doOperation(int a, int b, char operand);
		bool isValidOperand(char operand);
		bool isDigit(char digit);
		int RPNCalculator(void);
		std::string getExpr(void);
		int getRes(void);
		int getErrState(void);
		~RPN(void);
	private:
		std::string _expr;
		int _res;
		int _err;
};

#endif
