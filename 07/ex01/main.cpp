#include "iter.hpp"
#include <iostream>

int main()
{
    int nList[7] = {0, 1, 2, 3, 4, 5, 6};                       //int array
    
    int *nPtrList[7] = {&nList[0], &nList[1], &nList[2],        //int* array pointing to nList elements (addresses)
            &nList[3], &nList[4], &nList[5], &nList[6]};
    
    std::string words[3] = {"I ", "love ", "templates :))"};    //simple string array
    
    std::cout << "Printing nList" << std::endl;
    ::iter(nList, 7, printAsSentence);                          //should print '0 1 2 3 4 5 6 '
    std::cout << std::endl << std::endl;
    
    std::cout << "Printing words (lol)" << std::endl;
    ::iter(words, 3, printAsSentence);                          //should print 'I love templates :)) '
    std::cout << std::endl << std::endl;
    
    std::cout << "Printing nList elements addrs" << std::endl;
    ::iter(nPtrList, 7, printAsList);                           //should print '-ADDR0\n-ADDR1\n-ADDR...
    std::cout << std::endl;                                     //note : we can see that the addrs follow each other,
    return 0;                                                   //  skipping n bytes each time where n is the passed
}                                                               //  type's size in bytes (here 4 by 4 because ptr on x64)