#include "PmergeMe.hpp"

////////////////////////////// DBG FCTS /////////////////////////////
void printList(std::list<int> list)
{
    std::list<int>::iterator it = list.begin();
    while (it != list.end())
    {
        std::cout << *it << " ";
        it++; 
    }
    return ;
}

void printLPairs(std::list<std::pair<int, int> > lPairs)
{
    std::list<std::pair<int, int> >::iterator it = lPairs.begin();
    while (it != lPairs.end())
    {
        std::cout << "[" << it->first << ":" << it->second << "] ";
        it++; 
    }
    return ;
}

void printVector(std::vector<int> vector)
{
    std::vector<int>::iterator it = vector.begin();
    while (it != vector.end())
    {
        std::cout << *it << " ";
        it++; 
    }
    return ;
}
        std::list<int> _lSorted;

void printVPairs(std::vector<std::pair<int, int> > vPairs)
{
    std::vector<std::pair<int, int> >::iterator it = vPairs.begin();
    while (it != vPairs.end())
    {
        std::cout << "[" << it->first << ":" << it->second << "] ";
        it++; 
    }
    return ;
}
/////////////////////////////////////////////////////////////////////

std::list<int> makeLn(char **av)
{
    int i;
    std::list<int> ln;
    for (i = 1; av[i]; i++)
    {
        if (atoi(av[i]) <= 0
            || atoll(av[i]) > INT_MAX)
            return (std::list<int>());
        ln.push_back(atoi(av[i]));
    }
    return (ln);
}

std::vector<int> makeVn(char **av)
{
    int i;
    std::vector<int> vn;
    for (i = 1; av[i]; i++)
    {
        if (atoi(av[i]) <= 0 
            || atoll(av[i]) > INT_MAX)
            return (std::vector<int>());
        vn.push_back(atoi(av[i]));
    }
    return (vn);
}

bool dupCheck(char **av)
{
    for (int i = 1; av[i]; i++)
    {
        for (int j = i + 1; av[j]; j++)
        {
            if (std::string(av[i]) == std::string(av[j]))
                return (true);
        }
    }
    return (false);
}

int main(int ac, char **av)
{
    if (ac < 2)
    {
        std::cout << "./PmergeMe <n1> <n2> <...> <nx>" << std::endl;
        return (1);
    }
    else if (dupCheck(av))
    {
        std::cout << "Error: duplicate numbers are not allowed" << std::endl;
        return (2);
    }
    std::list<int> ln = makeLn(av);
    std::vector<int> vn = makeVn(av);
    if (ln.empty() || vn.empty())
    {
        std::cout << "Error: bad arguments (a valid argument is a positive integer ([1 - INT_MAX])" << std::endl;
        return (3);
    }
    PmergeMe sortNumbers(ln, vn);
    //std::cout << "UNSORTED LIST = ";
    //printList(ln);
    /*std::cout << std::endl << "++++ LIST SORTING ++++" << std::endl;
    sortNumbers.lMakePairs();
    sortNumbers.lSortPairs();
    sortNumbers.lSort();

    std::cout << std::endl << "++++ VECTOR SORTING ++++" << std::endl;
    sortNumbers.vMakePairs();
    sortNumbers.vSortPairs();
    sortNumbers.vSort();*/
    sortNumbers.displayList(false);
    std::cout << std::endl;
    //sortNumbers.displayVector(false);
    sortNumbers.lSortMain();
    //sortNumbers.displayList(true);
    sortNumbers.vSortMain();
    sortNumbers.displayVector(true);
    std::cout << std::endl;
    sortNumbers.displayTimes();
    return (0);
}