#include "Base.hpp"
# include "A.hpp"
# include "B.hpp"
# include "C.hpp"

Base::~Base(){
    return ;
}

Base *generate(void)
{
    char types[3] = {'A', 'B', 'C'};
    srand(time(NULL));
    unsigned int r = rand() % 3;
    std::cout << types[r] << " type generated" << std::endl;
    switch (r){
        case 0:
            return (new A());
        case 1:
            return (new B());
        case 2:
            return (new C());
    }
    return NULL;
}

void    identify(Base *p)
{
    A* a = dynamic_cast<A*>(p);
    B* b = dynamic_cast<B*>(p);
    C* c = dynamic_cast<C*>(p);
    if (a != NULL)
        std::cout << "Pointed class type is A" << std::endl;
    if (b != NULL)
        std::cout << "Pointed class type is B" << std::endl;
    if (c != NULL)
        std::cout << "Pointed class type is C" << std::endl;
    return ;
}

void    identify(Base &p)
{
    try {
        (void) dynamic_cast<A&>(p);
        std::cout << "Referenced class type is A" << std::endl;
    }
    catch(std::exception const &e){}
    try {
        (void) dynamic_cast<B&>(p);
        std::cout << "Referenced class type is B" << std::endl;
    }
    catch(std::exception const &e){}
    try {
        (void) dynamic_cast<C&>(p);
        std::cout << "Referenced class type is C" << std::endl;
    }
    catch(std::exception const &e){}
    return ;
}