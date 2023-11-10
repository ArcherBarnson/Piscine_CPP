# include "Base.hpp"

int main()
{
    Base base;
    Base * test = base.generate();
    Base & testref = *(base.generate());
    base.identify(test);
    base.identify(testref);
    delete test;
    delete &(testref);
    return 0;
}    