#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <iterator>
# include <vector>
# include <list>
# include <cstdlib>

# define INT_MAX 2147483647

class PmergeMe {
    public:
        PmergeMe(void);
        ~PmergeMe(void);
        PmergeMe(std::list<int> lSource, std::vector<int> vSource);
        PmergeMe(PmergeMe const & copy);
        PmergeMe &operator=(PmergeMe const & other);

        std::list<std::pair<int, int> > makeLPairs();
        std::vector<std::pair<int, int> > makeVPairs();
        std::list<int> lSort(std::list<std::pair<int, int> >);
        std::list<std::pair<int, int> > lSortPairs(std::list<std::pair<int, int> > pairs);
        std::list<int> vSort(std::vector<std::pair<int, int> >);
        std::list<int> vSortPairs(std::vector<std::pair<int, int> >);

         

    private:
        std::list<int> _lUnsorted;
        std::vector<int> _vUnsorted;        
        int _straggler;

};

#endif