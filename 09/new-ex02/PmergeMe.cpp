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

int PmergeMe::getNextJacobsthal(int n)
{
    if (n == 0)
        return (0);
    if (n == 1)
        return (1);
    return getNextJacobsthal(n - 1) + 2 * getNextJacobsthal(n - 2);
}

std::list<int> PmergeMe::generateJacobsthalSequence(int size)
{
    int i = 3;
    std::list<int> jacobsthalSequence;

    while (getNextJacobsthal(i) < size)
    {
        jacobsthalSequence.push_back(getNextJacobsthal(i));
        i++;
    }
    return (jacobsthalSequence);
}

std::list<int> PmergeMe::lbsInsert(std::list<int>::iterator L, std::list<int>::iterator R, std::list<int> sorted, int size, int n)
{
    std::list<int>::iterator itm = L;
    std::advance(itm, size / 2);
    std::list<int>::iterator itmPrev = itm;
    std::list<int>::iterator itmNext = itm;
    itmNext++;
    itmPrev--;
    if (n > *itmNext)
        return(lbsInsert(itm, R, sorted, size / 2, n));
    else if (n < *itmPrev)
        return(lbsInsert(L, itm, sorted, size / 2, n));
    sorted.insert(itmNext, n);
    return (sorted);
}

int PmergeMe::getListIndex(std::list<int> lst, int n)
{
    std::list<int>::iterator it = lst.begin();
    int i = 0;
    int delta = 0;
    while (it != lst.end() && *it != n)
    {
        it++;
        delta++;
    }
    i = lst.size() - (lst.size() - delta);
    std::cout << "INDEX IS " << i << std::endl;
    return (i);
}

std::list<int> PmergeMe::lSort(std::list<std::pair<int, int> > pairs)
{
    std::list<int> sorted;
    std::list<int> pending;
    std::list<int> jacobsthalSequence;
    std::list<std::pair<int, int> >::iterator itPairs = pairs.begin();
    std::list<int> usedIndexes;

    usedIndexes.push_front(0);
    while (itPairs != pairs.end())
    {
        sorted.push_front(itPairs->first);
        pending.push_front(itPairs->second);
        itPairs++;
    }
    //std::list<int>::iterator itSorted = sorted.begin();
    sorted.push_front(pending.front());
    pending.remove(pending.front());
    std::list<int>::iterator itPending = pending.begin();
    std::cout << std::endl << "sorted : ";
    printListb(sorted);
    std::cout << std::endl << "pending : ";
    printListb(pending);
    jacobsthalSequence = generateJacobsthalSequence(pending.size());
    std::cout << std::endl << "jacobsthalseq : ";
    printListb(jacobsthalSequence);
    while (itPending != pending.end() && !pending.empty())
    {
        std::list<int>::iterator nToInsert = pending.begin();
        if (!jacobsthalSequence.empty())
        {
            std::advance(nToInsert, *jacobsthalSequence.begin());
            std::cout << *jacobsthalSequence.begin() << std::endl;
            usedIndexes.push_front(*jacobsthalSequence.begin());
            jacobsthalSequence.remove(*jacobsthalSequence.begin());
        }
        else
        {
            /*int index = getListIndex(pending, *nToInsert);
            for (std::list<int>::iterator itTmp = usedIndexes.begin(); itTmp != usedIndexes.end(); itTmp++)
            {
                std::cout << "idf:" << index << std::endl;
                if (index == *itTmp)
                {
                    std::cout << "index already used ?" << std::endl;
                    nToInsert++;
                    index++;
                    itTmp = usedIndexes.begin();
                }
            }*/
            std::cout << "idk bro" << std::endl;
        }
        std::cout << "next insert = " <<  *nToInsert << std::endl;
        lbsInsert(sorted.begin(), sorted.end()--, sorted, sorted.size(), *nToInsert);
        std::cout << std::endl << "sorted after bs: ";
        printListb(sorted);
        pending.remove(*nToInsert);
        nToInsert = pending.begin();
        //itPending++;
    }
    return (std::list<int>());

}

std::vector<int> vSort(std::vector<std::pair<int, int> >);