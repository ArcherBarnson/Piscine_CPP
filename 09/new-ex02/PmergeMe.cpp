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

std::list<int> vSort(std::vector<std::pair<int, int> >);

std::list<std::pair<int, int> > PmergeMe::lSortPairs(std::list<std::pair<int, int> > pairs)
{
    std::list<std::pair<int, int> >::iterator ita = pairs.begin();
    std::list<std::pair<int, int> >::iterator itb = pairs.begin()++;
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