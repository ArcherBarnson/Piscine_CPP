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

void PmergeMe::vSortPairs()
{
    std::vector<std::pair<int, int> >::iterator ita = _vPairs.begin();
    std::vector<std::pair<int, int> >::iterator itb;
    while (ita != _vPairs.end())
    {
        if (ita->first < ita->second)
            {
                int tmp = ita->first;
                ita->first = ita->second;
                ita->second = tmp;
            }
            ita++;
    }
    ita = _vPairs.begin();
    itb = ita;
    itb++;
    //lRecursiveSort(ita, itb);
    while (ita != _vPairs.end())
    {
        itb = ita;
        itb++;
        while (itb != _vPairs.end())
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
    return ;
}

void PmergeMe::lSortPairs()
{
    std::list<std::pair<int, int> >::iterator ita = _lPairs.begin();
    std::list<std::pair<int, int> >::iterator itb;
    while (ita != _lPairs.end())
    {
        if (ita->first < ita->second)
            {
                int tmp = ita->first;
                ita->first = ita->second;
                ita->second = tmp;
            }
            ita++;
    }
    ita = _lPairs.begin();
    itb = ita;
    itb++;
    //lRecursiveSort(ita, itb);
    while (ita != _lPairs.end())
    {
        itb = ita;
        itb++;
        while (itb != _lPairs.end())
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
    /*std::list<std::pair<int, int> >::iterator it = _lPairs.begin();
    std::cout << "PAIR CHANGED : ";
    while (it != _lPairs.end())
    {
        std::cout << "[" << it->first << ":" << it->second << "] ";
        it++; 
    }*/
    return ;
}

/*void PmergeMe::lRecursiveSort(std::list<std::pair<int, int> >::iterator ita, std::list<std::pair<int, int> >::iterator itb)
{
    std::pair<int, int> tmpPair;
    if (*ita == _lPairs.back())
        return ;
    if (*itb == _lPairs.back())
    {
        ita++;
        itb = ita;
        itb++;
        lRecursiveSort(ita, itb);
    }
    if (ita->first > itb->first)
    {
        tmpPair = *ita;
        *ita = *itb;
        *itb = tmpPair;
    }
    itb++;
    lRecursiveSort(ita, itb);
}*/

void PmergeMe::lMakePairs()
{
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
        _lPairs.push_back(pairToPush);
    }
    return;
}

void PmergeMe::vMakePairs()
{
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
        _vPairs.push_back(pairToPush);
    }
    return ;
}

/////UTILS (Remove Before Flight)//////
void printListb(std::list<int> list)
{
    std::list<int>::iterator it = list.begin();
    while (it != list.end())
    {
        std::cout << *it << ", ";
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
    //std::cout << std::endl;
    if (n < *itMl && *itMl!= *_lSorted.begin())
        return (lbsInsert(L, itM, size / 2 + 1, n));
    if (n > *itMr && *itMr != *itLast)
        return (lbsInsert(itM, R, size / 2 + 1, n));    
    if (n < *itMl && *itMl == *_lSorted.begin())
        return (_lSorted.begin());
    if (n > *itMr && *itMr == *itLast)
        return (_lSorted.end());
    if (n < *itM)
        itM--;
    if (n > *itM)
        itM++;
    return (itM);
}

std::vector<int>::iterator PmergeMe::vbsInsert(std::vector<int>::iterator L, std::vector<int>::iterator R, int size, int n)
{   
    std::vector<int>::iterator itM = L;
    std::vector<int>::iterator itLast = R;
    std::advance(itM, size / 2);
    std::vector<int>::iterator itMl = itM;
    std::vector<int>::iterator itMr = itM;
    itLast--;
    if (*itM != *_vSorted.begin())
        itMl--;
    if (*itM != *itLast)
        itMr++;
    if (itMr == _vSorted.end())
        itMr--;
    
    //std::cout << "n = " << n << " | L = " << *L << " | R = " << *itLast << " | size = " << size << std::endl;
    //std::cout << "_lSorted = ";
    //printListb(_lSorted);
    //std::cout << std::endl;
    if (n < *itMl && *itMl!= *_vSorted.begin())
        return (vbsInsert(L, itM, size / 2 + 1, n));
    if (n > *itMr && *itMr != *itLast)
        return (vbsInsert(itM, R, size / 2 + 1, n));    
    if (n < *itMl && *itMl == *_vSorted.begin())
        return (_vSorted.begin());
    if (n > *itMr && *itMr == *itLast)
        return (_vSorted.end());
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

void PmergeMe::lSort()
{
    std::list<int> pending;
    std::list<int> jacobsthalSequence;
    std::list<std::pair<int, int> >::iterator itPairs = _lPairs.begin();
    
    while (itPairs != _lPairs.end())
    {
        _lSorted.push_front(itPairs->first);
        pending.push_front(itPairs->second);
        itPairs++;
    }
    _lSorted.push_front(pending.front());
    pending.remove(pending.front());
    std::cout << std::endl << "pending : ";
    printListb(pending);
    jacobsthalSequence = generateJacobsthalSequence(pending.size() + 1);
    std::cout << std::endl << "jacobsthalseq : ";
    printListb(jacobsthalSequence);
    std::list<int>::iterator nToInsert = pending.begin();
    while (!pending.empty())
    {
        int counter = 2;                        //used to keep track of indexes after elements have been removed
        while (!jacobsthalSequence.empty())
        {
            std::advance(nToInsert, (*jacobsthalSequence.begin() - counter));
            std::cout << *jacobsthalSequence.begin() << std::endl;
            jacobsthalSequence.remove(*jacobsthalSequence.begin());
            _lSorted.insert(lbsInsert(_lSorted.begin(), _lSorted.end(), _lSorted.size(), *nToInsert), *nToInsert);
            pending.remove(*nToInsert);
            nToInsert = pending.begin();
            counter++;
        }
        _lSorted.insert(lbsInsert(_lSorted.begin(), _lSorted.end(), _lSorted.size(), *nToInsert), *nToInsert);
        pending.remove(*nToInsert);
        nToInsert = pending.begin();
    }
    if (_straggler > 0)
        _lSorted.insert(lbsInsert(_lSorted.begin(), _lSorted.end(), _lSorted.size(), _straggler), _straggler);
    std::cout << "SORTED LIST => ";
    printListb(_lSorted);
    std::cout << std::endl;
    return ;

}

void PmergeMe::printVector(std::vector<int> v)
{
    for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++)
        std::cout << *it << ", ";
    return ;

}

void PmergeMe::vSort()
{
    std::vector<int> pending;
    std::list<int> jacobsthalSequence;
    std::vector<std::pair<int, int> >::iterator itPairs = _vPairs.begin();
    
    while (itPairs != _vPairs.end())
    {
        _vSorted.insert(_vSorted.begin(), itPairs->first);
        pending.insert(pending.begin(), itPairs->second);
        itPairs++;
    }
    _vSorted.insert(_vSorted.begin(), pending.front());
    pending.erase(pending.begin());
    std::cout << std::endl << "pending : ";
    //printListb(pending);
    jacobsthalSequence = generateJacobsthalSequence(pending.size() + 1);
    std::cout << std::endl << "jacobsthalseq : ";
    //printListb(jacobsthalSequence);
    std::vector<int>::iterator nToInsert = pending.begin();
    while (!pending.empty())
    {
        int counter = 2;                        //used to keep track of indexes after elements have been removed
        while (!jacobsthalSequence.empty())
        {
            std::advance(nToInsert, (*jacobsthalSequence.begin() - counter));
            std::cout << *jacobsthalSequence.begin() << std::endl;
            jacobsthalSequence.remove(*jacobsthalSequence.begin());
            _vSorted.insert(vbsInsert(_vSorted.begin(), _vSorted.end(), _vSorted.size(), *nToInsert), *nToInsert);
            pending.erase(nToInsert);
            nToInsert = pending.begin();
            counter++;
        }
        _vSorted.insert(vbsInsert(_vSorted.begin(), _vSorted.end(), _vSorted.size(), *nToInsert), *nToInsert);
        pending.erase(nToInsert);
        nToInsert = pending.begin();
    }
    if (_straggler > 0)
        _vSorted.insert(vbsInsert(_vSorted.begin(), _vSorted.end(), _vSorted.size(), _straggler), _straggler);
    std::cout << "SORTED VECTOR => ";
    printVector(_vSorted);
    std::cout << std::endl;
    return ;
}