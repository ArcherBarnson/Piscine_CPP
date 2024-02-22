#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void){return ;}
PmergeMe::~PmergeMe(void){return ;}
PmergeMe::PmergeMe(std::list<int> lstToSort) {
	_lUnsorted = lstToSort;
	std::list<int>::iterator it = _lUnsorted.begin();
	int a;
	int b = -1;
	while (it != _lUnsorted.end())
	{
		a = *it;
		*it++;
		if (it != _lUnsorted.end())
			b = *it;
		std::pair<int,int> tmp(a, b);
		_lPairs.push_back(tmp);
		if (b == -1)
			break ;
		else
		{
			b = -1;
			*it++;
		}
	}
	/* DISPLAY PAIRS(DGB) ------|
	std::list< std::pair<int,int> >::iterator itl = _lPairs.begin();
	while (itl != _lPairs.end())
	{
		std::cout << itl->first << "-" << itl->second << std::endl;
		itl++;
	}
	--------------------------*/
	return ;
}

PmergeMe::PmergeMe(PmergeMe const & copy) {
	*this = copy;
	return ;
}

PmergeMe & PmergeMe::operator=(PmergeMe const & other) {
	_lUnsorted = other._lUnsorted;
	_lPairs = other._lPairs;
	return (*this);
}

std::list<int> PmergeMe::getUnsorted(void) {return (_lUnsorted);}
std::list< std::pair<int, int> > PmergeMe::getLpairs(void) {return (_lPairs);}
//std::vector< std::list<int> > PmergeMe::getPairs(void) {return (_vPairs);}

std::list<int> PmergeMe::sort(void)
{
	std::list<int> sorted;
	std::list< std::pair<int,int> >::iterator it = _lPairs.begin();
	while (it != _lPairs.end())
	{
		std::cout << "[UNSORTED PAIR]: [" << it->first << " - " << it->second << "]" << std::endl;
		if (it->first < it->second)
		{
			int tmp = it->second;
			it->second = it->first;
			it->first = tmp;
		}
		std::cout << "[SORTED PAIR]: " << "[" << it->first << " - " << it->second << "]" << std::endl;
		it++;
	}
	//faut trier la mais jsp compter
	return (sorted);
}