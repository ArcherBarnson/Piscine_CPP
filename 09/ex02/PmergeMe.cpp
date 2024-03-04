#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void){return ;}
PmergeMe::~PmergeMe(void){return ;}
PmergeMe::PmergeMe(std::list<int> lstToSort) {
	_lUnsorted = lstToSort;
	std::list<int>::iterator it = _lUnsorted.begin();
	int a;
	int b = -1;
	if (_lUnsorted.size() % 2 != 0) {
		_odd = *it;
		it++;
		_lUnsorted.remove(*(_lUnsorted.begin()));
	}
	else
		_odd = -1;
	std::cout << "odd? : " << _odd << std::endl;
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

int PmergeMe::getNextJNumber(std::list<int> pending)
{
	int jacobsthal[22] = {0, 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923, 21845, 43691, 87381, 174763, 349525, 699051, 1398101};
	int i = 0;
	std::list<int>::iterator it = pending.begin();
	while (jacobsthal[i])
	{
		while (it != pending.end())
		{
			if (*it == jacobsthal[i])
				return (*it);
			it++;
		}
		i++;
		it = pending.begin();
	}
	return (-1);

}

std::list<int> PmergeMe::insertSort(std::list<int> pending, std::list<int> sorted)
{
	std::list<int>::iterator itp = pending.end();
	std::list<int>::iterator its;
	int best = -1;

	sorted.push_front(*itp);
	itp--;
	pending.remove(*(pending.end()));
	while (!pending.empty())
	{
		best = getNextJNumber(pending);
		if (best != -1)
			pending.remove(best);
		else
		{
			best = *(pending.begin());
			pending.remove(best);
		}
		for (its = sorted.begin();
		 its != sorted.end() && *its > best; 
		 its++)
			;
		sorted.insert(its, best);
		itp = pending.end();
	}
	return (sorted);
}

std::list<int> PmergeMe::sort(void)
{
	std::list<int> sorted;
	std::list<int> pending;
	std::list< std::pair<int,int> >::iterator it = _lPairs.begin();
	while (it != _lPairs.end())
	{
		std::cout << "[UNSORTED PAIR]: [" << it->first << " - " << it->second << "]" << std::endl;
		if (it->first > it->second)
		{
			int tmp = it->second;
			it->second = it->first;
			it->first = tmp;
		}
		std::cout << "[SORTED PAIR]: " << "[" << it->first << " - " << it->second << "]" << std::endl;
		it++;
	}
	it = _lPairs.begin();
	std::list< std::pair<int,int> >::iterator itb = _lPairs.begin();
	itb++;
	while (it != _lPairs.end())
	{
		while (itb != _lPairs.end())
		{
			if (it->second > itb->second)
			{
				int tmp = it->second;
				it->second = itb->second;
				itb->second = tmp;
				tmp = it->first;
				it->first = itb->first;
				itb->first = tmp;
			}
			itb++;
		}
		it++;
		itb = it;
		itb++;
	}
	it = _lPairs.begin();
	while (it != _lPairs.end())
	{
		std::cout << "[DBG]: " << "[" << it->first << " - " << it->second << "]" << std::endl;
		it++;
	}
	it = _lPairs.begin();
	while (it != _lPairs.end())
	{
		pending.push_back(it->first);
		sorted.push_back(it->second);
		it++;
	}
	/*std::list<int>::iterator its = sorted.begin();
	while (its != sorted.end())
	{
		std::cout << "[DBG]: [" << *its << "]" << std::endl;
		its++;
	}*/
	//faut trier la mais jsp compter
	return (insertSort(pending, sorted));
}
