#ifndef BASE_HPP
# define BASE_HPP

# include <iostream>
# include <stdlib.h>
# include <time.h>

//# include "A.hpp"
//# include "B.hpp"
//# include "C.hpp"

class Base
{
    class bad_cast : public std::exception {
        public:
            virtual const char* what() const throw();
    };
    public :
        virtual ~Base();
        Base * generate(void);
        void   identify(Base* p);
        void   identify(Base& p);
};

class A : public Base{};
class B : public Base{};
class C : public Base{};

#endif