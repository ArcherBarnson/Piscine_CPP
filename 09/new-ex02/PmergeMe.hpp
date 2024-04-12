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

        int getNextJacobsthal(int n);
        std::list<int> generateJacobsthalSequence(int size);
        
        std::list<int>::iterator lbsInsert(std::list<int>::iterator L, std::list<int>::iterator R, int size, int n);
        int getListIndex(std::list<int> lst, int n);


        void lMakePairs();
        void lSort();
        void lSortPairs();
        //void lRecursiveSort(std::list<std::pair<int, int> >::iterator ita, std::list<std::pair<int, int> >::iterator itb);

        void vMakePairs();
        void vSort();
        void vSortPairs();
        std::vector<int>::iterator vbsInsert(std::vector<int>::iterator L, std::vector<int>::iterator R, int size, int n);         
        void printVector(std::vector<int> v);

    private:
        std::list<std::pair<int, int> > _lPairs;
        std::list<int> _lUnsorted;
        std::list<int> _lSorted;
        std::vector<std::pair<int, int> > _vPairs;
        std::vector<int> _vUnsorted;
        std::vector<int> _vSorted;
        int _straggler;

};

#endif