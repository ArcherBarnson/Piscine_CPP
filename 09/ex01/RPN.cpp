#include "RPN.hpp"

RPN::RPN(void){return ;};

RPN::RPN(std::string expr) : _expr(expr), _res(0), _err(0)
{
	return ;
}

RPN::RPN(RPN const & copy)
{
	*this = copy;
	return ;
}

RPN & RPN::operator=(RPN const & other)
{
	_expr = other._expr;
	_res = other._res;
	return (*this);
}

RPN::~RPN(void){return ;}

std::string RPN::getExpr(void) {return _expr;}

int RPN::getRes(void){return _res;}

int RPN::getErrState(void) {return _err;}

int RPN::doOperation(int a, int b, char operand)
{
	int res = -1;
	std::cout << "op is|" << a << operand << b << std::endl;
	switch (operand)
	{
		case '+':
			res = a + b;
			break ;
		case '-':
			res = b - a;
			break ;
		case '/':
			if (b == 0)
				res = 0;
			else
				res = a / b;
			break ;
		case '*':
			res = a * b;
			break ;
		default:
			return (res);
	}
	return (res);
}

bool RPN::isValidOperand(char operand)
{
	if (operand != '+' && operand != '-' &&
		operand != '*' && operand != '/')
		return (false);
	return (true);
}

bool RPN::isDigit(char digit)
{
	if (digit < '0' || digit > '9')
		return (false);
	return (true);
}

int RPN::RPNCalculator(void)
{
	int a,b = 0;
	std::stack<int> opStack;

	for (int i = 0; _expr[i]; i += 2)
	{
		if (_expr[i + 1] && (!isDigit(_expr[i]) || isValidOperand(_expr[i])))
		{
			_err = 1;
			return (0);
		}
		if (_expr[i + 1] && _expr[i + 1] != ' ')
		{
			_err = 2;
			return (0);
		}
		while (isDigit(_expr[i]))
		{
			opStack.push(_expr[i] - 48);
			i += 2;
		}
		a = opStack.top();
		opStack.pop();
		b = opStack.top();
		opStack.pop();
		if (isValidOperand(_expr[i]))
			_res = doOperation(a, b, _expr[i]);
		opStack.push(_res);
	}
	return (_res);
}
