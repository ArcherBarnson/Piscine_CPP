#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <list>
# include <vector>
# include <iostream>
# include <cstdlib>

class PmergeMe {
	public:
		PmergeMe(void);
		PmergeMe(std::list<int> lstToSort);
		PmergeMe(PmergeMe const & copy);
		PmergeMe &operator=(PmergeMe const & other);
		~PmergeMe(void);
		std::list<int> getUnsorted(void);
		//std::vector< std::list<int> > getPairs(void);
		std::list< std::pair<int, int> > getLpairs(void);
		std::list<int> sort(void);
	private:
		std::list<int> _lUnsorted;
		std::list< std::pair<int, int> > _lPairs;
		std::list<int> _lS;
		//std::vector<int> _vUnsorted;
		//std::vector< std::pair<int, int> > _vPairs;
		//std::vector<int> _vS;
};

#endif