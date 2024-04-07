#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void){return;};

PmergeMe::~PmergeMe(void){return;};

PmergeMe::PmergeMe(std::list<int> lSource, std::vector<int>(vSource)) : _lUnsorted(lSource), _vUnsorted(vSource), _straggler(-1) { 
    return ;
};

PmergeMe::PmergeMe(PmergeMe const & copy)
{
    *this = copy;
    return ;
};

PmergeMe & PmergeMe::operator=(PmergeMe const & other)
{
    _lUnsorted = other._lUnsorted;
    _vUnsorted = other._vUnsorted;
    _straggler = other._straggler;
    return *this;
}

std::vector<std::pair<int, int> > PmergeMe::vSortPairs(std::vector<std::pair<int, int> > pairs)
{
    std::vector<std::pair<int, int> >::iterator ita = pairs.begin();
    std::vector<std::pair<int, int> >::iterator itb = pairs.begin()++;
    while (ita != pairs.end())
    {
        if (ita->first < ita->second)
            {
                int tmp = ita->first;
                ita->first = ita->second;
                ita->second = tmp;
            }
            ita++;
    }
    ita = pairs.begin();
    while (ita != pairs.end())
    {
        while (itb != pairs.end())
        {
            if (ita->first < itb->first)
            {
                std::pair<int, int> tmpPair = *ita;
                *ita = *itb;
                *itb = tmpPair;
            }
            itb++;
        }
        ita++;
        itb = ita++;
    }
    return (pairs);
}

std::list<std::pair<int, int> > PmergeMe::lSortPairs(std::list<std::pair<int, int> > pairs)
{
    std::list<std::pair<int, int> >::iterator ita = pairs.begin();
    std::list<std::pair<int, int> >::iterator itb;
    while (ita != pairs.end())
    {
        if (ita->first < ita->second)
            {
                int tmp = ita->first;
                ita->first = ita->second;
                ita->second = tmp;
            }
            ita++;
    }
    ita = pairs.begin();
    while (ita != pairs.end())
    {
        itb = ita;
        itb++;
        while (itb != pairs.end())
        {
            if (ita->first < itb->first)
            {
                std::pair<int, int> tmpPair = *ita;
                *ita = *itb;
                *itb = tmpPair;
            }
            itb++;
        }
        ita++;
    }
    return (pairs);
}

std::list<std::pair<int, int> > PmergeMe::makeLPairs()
{
    std::list<std::pair<int, int> > pairs;
    std::pair<int, int> pairToPush;
    if (_lUnsorted.size() % 2 != 0)
    {
        _straggler = _lUnsorted.back();
        _lUnsorted.remove(_lUnsorted.back());
        std::cout << "straggler = " << _straggler << std::endl;
        std::cout << "straggler cmp = " << _lUnsorted.back() << std::endl;
    }
    std::list<int>::iterator it = _lUnsorted.begin();
    while (it != _lUnsorted.end())
    {
        pairToPush.first = *it;
        it++;
        pairToPush.second = *it;
        it++;
        pairs.push_back(pairToPush);
    }
    return (lSortPairs(pairs));
}

std::vector<std::pair<int, int> > PmergeMe::makeVPairs()
{
    std::vector<std::pair<int, int> > pairs;
    std::pair<int, int> pairToPush;
    if (_vUnsorted.size() % 2 != 0)
    {
        _straggler = _vUnsorted.back();
        std::cout << "straggler = " << _straggler << std::endl;
        std::cout << "straggler cmp = " << _vUnsorted.back() << std::endl;
    }
    std::vector<int>::iterator it = _vUnsorted.begin();
    while (it != _vUnsorted.end())
    {
        pairToPush.first = *it;
        it++;
        pairToPush.second = *it;
        it++;
        pairs.push_back(pairToPush);
    }
    return (pairs);
}

/////UTILS (Remove Before Flight)//////
void printListb(std::list<int> list)
{
    std::list<int>::iterator it = list.begin();
    while (it != list.end())
    {
        std::cout << *it << " ";
        it++; 
    }
    return ;
}
///////////////////////////////////////

std::list<int> PmergeMe::lSort(std::list<std::pair<int, int> > pairs)
{
    std::list<int> sorted;
    std::list<int> pending;
    
    std::list<std::pair<int, int> >::iterator itPairs = pairs.begin();
    while (itPairs != pairs.end())
    {
        sorted.push_back(itPairs->first);
        pending.push_back(itPairs->second);
        itPairs++;
    }
    //std::list<int>::iterator itSorted = sorted.begin();
    sorted.push_back(pending.back());
    pending.remove(pending.back());
    //std::list<int>::iterator itPending = pending.begin();
    std::cout << std::endl << "sorted : ";
    printListb(sorted);
    std::cout << std::endl << "pending : ";
    printListb(pending);
    return (std::list<int>());

}

std::vector<int> vSort(std::vector<std::pair<int, int> >);