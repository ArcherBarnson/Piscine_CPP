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


/////////////////////////////UTILS//////////////////////////////////////

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

int PmergeMe::getListIndex(std::list<int> lst, int n)
{
    std::list<int>::iterator it = lst.begin();
    int i = 0;
    while (it != lst.end() && *it != n)
    {
        it++;
        i++;
    }
    return (i);
}

bool PmergeMe::isListSorted()
{
    std::list<int>::iterator itNext;
    if (_lSorted.empty())
        return (false);
    for (std::list<int>::iterator it = _lSorted.begin(); it != _lSorted.end(); it++)
    {
        itNext = it;
        itNext++;
        if (*it != _lSorted.back() && *it > *itNext)
            return (false);
    }
    return (true);
}

bool PmergeMe::isVectorSorted()
{
    std::vector<int>::iterator itNext;
    if (_vSorted.empty())
        return (false);
    for (std::vector<int>::iterator it = _vSorted.begin(); it != _vSorted.end(); it++)
    {
        itNext = it;
        itNext++;
        if (*it != _vSorted.back() && *it > *itNext)
            return (false);
    }
    return (true);
}

/////////////////////////////DISPLAY//////////////////////////////////

void PmergeMe::displayList(bool sorted)
{
    std::list<int>::iterator it;
    std::list<int>::iterator itEnd;
    std::string msg;

    if (sorted)
    {
        msg = "+++++[SORTED ARRAY]+++++";
        it = _lSorted.begin();
        itEnd = _lSorted.end();
    }
    else
    {
        msg = "+++++[UNSORTED ARRAY]+++++";
        it = _lUnsorted.begin();
        itEnd = _lUnsorted.end();
    }
    std::cout << msg << std::endl; 
    while (it != itEnd)
    {
        std::cout << *it << " ";
        it++; 
    }
    std::cout << std::endl;
    return ;
}

void PmergeMe::displayVector(bool sorted)
{
    std::list<int>::iterator it;
    std::list<int>::iterator itEnd;
    std::string msg;

    if (sorted)
    {
        msg = "+++++[SORTED ARRAY]+++++";
        it = _lSorted.begin();
        itEnd = _lSorted.end();
    }
    else
    {
        msg = "+++++[UNSORTED ARRAY]+++++";
        it = _lUnsorted.begin();
        itEnd = _lUnsorted.end();
    }
    std::cout << msg << std::endl; 
    while (it != itEnd)
    {
        std::cout << *it << " ";
        it++; 
    }
    std::cout << std::endl;
    return ;
}

void PmergeMe::displayTimes()
{
    std::cout.setf(std::ios::fixed);
    std::cout << "Time to process a range of " << _lUnsorted.size() + (_straggler > 0 ? 1 : 0) << " elements with std::list   : " <<  std::setprecision(22) << ((float)_lt)/CLOCKS_PER_SEC << " s" << std::endl;
    std::cout << "Time to process a range of " << _vUnsorted.size() + (_straggler > 0 ? 1 : 0) << " elements with std::vector : " <<  std::setprecision(22) << ((float)_vt)/CLOCKS_PER_SEC << " s" << std::endl;
    return ;
}

/////////////////////////////LIST SORTING////////////////////////////////////////////////////

void PmergeMe::lMakePairs()
{
    std::pair<int, int> pairToPush;
    if (_lUnsorted.size() == 1)
    {
        _lSorted.push_front(_lUnsorted.front());
        _lUnsorted.pop_back();
        return ;
    }
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
    return ;
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

void PmergeMe::lSort()
{
    std::list<int> pending;
    std::list<int> jacobsthalSequence;
    std::list<std::pair<int, int> >::iterator itPairs = _lPairs.begin();
    
    if (_lUnsorted.empty())
        return ;
    while (itPairs != _lPairs.end())
    {
        _lSorted.push_front(itPairs->first);
        pending.push_front(itPairs->second);
        itPairs++;
    }
    _lSorted.push_front(pending.front());
    pending.remove(pending.front());
    jacobsthalSequence = generateJacobsthalSequence(pending.size() + 1);
    std::list<int>::iterator nToInsert = pending.begin();
    while (!pending.empty())
    {
        int counter = 2;                        //used to keep track of indexes after elements have been removed
        while (!jacobsthalSequence.empty())
        {
            std::advance(nToInsert, (*jacobsthalSequence.begin() - counter));
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
    return ;

}

void PmergeMe::lSortMain()
{
    _lt = clock();
    lMakePairs();
    lSortPairs();
    lSort();
    _lt = clock() - _lt;
    if (!isListSorted())
        std::cout << "List sorting error !" << std::endl;
    return ;
}

/////////////////////////////VECTOR SORTING/////////////////////////

void PmergeMe::vMakePairs()
{
    std::pair<int, int> pairToPush;
    if (_vUnsorted.size() == 1)
    {
        _vSorted.push_back(_vUnsorted.front());
        _vUnsorted.pop_back(); 
        return ;
    }
    if (_vUnsorted.size() % 2 != 0)
    {
        _straggler = _vUnsorted.back();
        _vUnsorted.pop_back();
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

void PmergeMe::vSort()
{
    std::vector<int> pending;
    std::list<int> jacobsthalSequence;
    std::vector<std::pair<int, int> >::iterator itPairs = _vPairs.begin();
    
    if (_lUnsorted.empty())
        return ;
    while (itPairs != _vPairs.end())
    {
        _vSorted.insert(_vSorted.begin(), itPairs->first);
        pending.insert(pending.begin(), itPairs->second);
        itPairs++;
    }
    _vSorted.insert(_vSorted.begin(), pending.front());
    pending.erase(pending.begin());
    jacobsthalSequence = generateJacobsthalSequence(pending.size() + 1);
    std::vector<int>::iterator nToInsert = pending.begin();
    while (!pending.empty())
    {
        int counter = 2;                        //used to keep track of indexes after elements have been removed
        while (!jacobsthalSequence.empty())
        {
            std::advance(nToInsert, (*jacobsthalSequence.begin() - counter));
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
    return ;
}

void PmergeMe::vSortMain()
{
    _vt = clock();
    vMakePairs();
    vSortPairs();
    vSort();
    _vt = clock() - _vt;
    if (!isVectorSorted())
        std::cout << "Vector sorting error !" << std::endl;
    return ;
}