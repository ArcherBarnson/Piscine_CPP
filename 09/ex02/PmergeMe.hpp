#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <iomanip>
# include <iterator>
# include <vector>
# include <list>
# include <cstdlib>
# include <time.h>

# define INT_MAX 2147483647

class PmergeMe {
    public:
        //CONSTRUCTORS
        PmergeMe(void);
        ~PmergeMe(void);
        PmergeMe(std::list<int> lSource, std::vector<int> vSource);
        PmergeMe(PmergeMe const & copy);
        PmergeMe &operator=(PmergeMe const & other);

        //UTILS 
        int getNextJacobsthal(int n);
        std::list<int> generateJacobsthalSequence(int size);
        int getListIndex(std::list<int> lst, int n);
        bool isListSorted();
        bool isVectorSorted();
        //DISPLAY
        void displayList(bool sorted);
        void displayVector(bool sorted);
        void displayTimes();
        
        //LIST SORTING
        void lMakePairs();
        void lSortPairs();
        std::list<int>::iterator lbsInsert(std::list<int>::iterator L, std::list<int>::iterator R, int size, int n);
        void lSort();
        void lSortMain();
        
        //VECTOR SORTING
        void vMakePairs();
        void vSortPairs();
        std::vector<int>::iterator vbsInsert(std::vector<int>::iterator L, std::vector<int>::iterator R, int size, int n);
        void vSort();
        void vSortMain();         

    private:
        
        std::list<std::pair<int, int> > _lPairs;
        std::list<int> _lUnsorted;
        std::list<int> _lSorted;
        clock_t _lt;
        
        std::vector<std::pair<int, int> > _vPairs;
        std::vector<int> _vUnsorted;
        std::vector<int> _vSorted;
        clock_t _vt;
        
        int _straggler;

};

#endif