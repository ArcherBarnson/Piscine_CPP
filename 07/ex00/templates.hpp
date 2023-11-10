#ifndef TEMPLATES_HPP
# define TEMPLATES_HPP

# include <iostream>

template <typename T>
void swap(T &a, T &b) {
    T tmp = a;
    a = b;
    b = tmp;
    return ;
}

template <typename T>
T min(T a, T b) {
    if (a < b)
        return a;
    if (a > b)
        return b;
    return a;
}

template <typename T>
T max(T a, T b) {
    if (a > b)
        return a;
    if (a < b)
        return b;
    return b;
}

#endif