# include "Base.hpp"

int main()
{
    Base base;
    Base * test = generate();           //gen by ptr
    Base & testref = *(generate());     //gen by ref
    identify(test);                     //id by ptr
    identify(testref);                  //if by ref
    delete test;                        //delete Base * test
    delete &(testref);                  //delete Base & testref
    return 0;
}