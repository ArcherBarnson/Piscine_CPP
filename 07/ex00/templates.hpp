#ifndef TEMPLATES_HPP
# define TEMPLATES_HPP

# include <iostream>

template <class type>
void swap(type &a, type &b) {
    type tmp = a;
    a = b;
    b = tmp;
    return ;
}

template <class type>
type min(type a, type b) {
    if (a < b)
        return a;
    if (a > b)
        return b;
    return a;
}

template <class type>
type max(type a, type b) {
    if (a > b)
        return a;
    if (a < b)
        return b;
    return b;
}

#endif