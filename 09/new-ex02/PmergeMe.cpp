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

std::list<int>::iterator PmergeMe::lbsInsert(std::list<int>::iterator L, std::list<int>::iterator R, int size, int n)
{   
    std::list<int>::iterator itM = L;
    std::list<int>::iterator itLast = R;
    std::advance(itM, size / 2);
    std::list<int>::iterator itMl = itM;
    std::list<int>::iterator itMr = itM;
    itLast--;
    if (*itM != *_lSorted.begin())
        itMl--;
    if (*itM != *itLast)
        itMr++;
    if (itMr == _lSorted.end())
        itMr--;
    
    //std::cout << "n = " << n << " | L = " << *L << " | R = " << *itLast << " | size = " << size << std::endl;
    //std::cout << "_lSorted = ";
    //printListb(_lSorted);
    std::cout << std::endl;
    if (n < *itMl && *itMl!= *_lSorted.begin())
        return (lbsInsert(L, itM, size / 2 + 1, n));
    if (n > *itMr && *itMr != *itLast)
        return (lbsInsert(itM, R, size / 2 + 1, n));    
    if (n < *itMl && *itMl == *_lSorted.begin())
        return (_lSorted.begin());
    if (n > *itMr && *itMr == *itLast)
        return (_lSorted.end());
    //std::cout << "itM is : " << *itM << std::endl;
    //std::cout << std::endl;
    if (n < *itM)
        itM--;
    if (n > *itM)
        itM++;
    return (itM);
}

int PmergeMe::getListIndex(std::list<int> lst, int n)
{
    std::list<int>::iterator it = lst.begin();
    int i = 0;
    while (it != lst.end() && *it != n)
    {
        it++;
        //std::cout << *it << "|" << i << "|" << n << std::endl;
        i++;
    }
    return (i);
}

bool nInLst(int n, std::list<int> lst)
{ 
    for (std::list<int>::iterator it = lst.begin(); it != lst.end(); it++)
    {
        if (n == *it)
            return (true);
    }
    return (false);
}

void PmergeMe::lSort(std::list<std::pair<int, int> > pairs)
{
    std::list<int> pending;
    std::list<int> jacobsthalSequence;
    std::list<std::pair<int, int> >::iterator itPairs = pairs.begin();
    std::list<int> usedIndexes;
    
    while (itPairs != pairs.end())
    {
        _lSorted.push_front(itPairs->first);
        pending.push_front(itPairs->second);
        itPairs++;
    }
    //std::list<int>::iterator itPending = pending.begin();
    //std::cout << "itPending is at: " << getListIndex(_lSorted, *itPending) << std::endl;
    _lSorted.push_front(pending.front());
    pending.remove(pending.front());
    usedIndexes.push_back(0);
    std::cout << std::endl << "pending : ";
    printListb(pending);
    jacobsthalSequence = generateJacobsthalSequence(pending.size() + 1);
    std::cout << std::endl << "jacobsthalseq : ";
    printListb(jacobsthalSequence);
    std::list<int>::iterator nToInsert = pending.begin();
    while (!pending.empty())
    {
        //std::cout << "usedIndexes = " << usedIndexes.size() << std::endl;
        int counter = 2;
        while (!jacobsthalSequence.empty())
        {
            std::advance(nToInsert, (*jacobsthalSequence.begin() - counter));
            std::cout << *jacobsthalSequence.begin() << std::endl;
            usedIndexes.push_back(*jacobsthalSequence.begin());
            jacobsthalSequence.remove(*jacobsthalSequence.begin());
            _lSorted.insert(lbsInsert(_lSorted.begin(), _lSorted.end(), _lSorted.size(), *nToInsert), *nToInsert);
            pending.remove(*nToInsert);
            nToInsert = pending.begin();
            counter++;
            //std::cout << "pending: ";
            //printListb(pending);
            //std::cout << std::endl;
        }
        _lSorted.insert(lbsInsert(_lSorted.begin(), _lSorted.end(), _lSorted.size(), *nToInsert), *nToInsert);
        //usedIndexes.push_back(getListIndex(_lSorted, *nToInsert));
        pending.remove(*nToInsert);
        nToInsert = pending.begin();
        //}
        //std::cout << "idk bro" << std::endl;
        //pending.remove(*pending.begin());            
        //printListb(_lSorted);
        //std::cout << std::endl << "pending after bsi: ";
        //printListb(pending);
        //std::cout << std::endl << "_lSorted after bsi: ";
        //printListb(_lSorted);
        //std::cout << "pending size = " << pending.size() << std::endl;
    }
    std::cout << "SORTED LIST => ";
    printListb(_lSorted);
    std::cout << std::endl;
    return ;//printListb(_lSorted);

}

std::vector<int> vSort(std::vector<std::pair<int, int> >);