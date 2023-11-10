#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <time.h>
# include <stdlib.h>

template <class T>
class Array {
    public:
        class oob : public std::exception {
            public:
                virtual const char *what() const throw() {
                    return ("Error: Array index out of bounds");
                };
        };
        Array(void) : _len(0) {
            _array = new T[_len]();  
        };
        Array(unsigned int n) : _len(n) {
            _array = new T[_len]();
        };
        Array(Array const & copy) : _len(copy._len) {
            _array = new T[_len]();
            for (unsigned int i = 0; i < _len; i++)
                _array[i] = copy._array[i];
        };
        Array &operator=(Array const & other) {
            _len = other._len;
            delete [] _array;
            _array = new T[_len]();
            for (unsigned int i = 0; i < _len; i++)
                _array[i] = other._array[i];
            return *this;
        };

        T &operator[](unsigned int index) {
            if (index >= _len)
                throw oob();
            return (_array[index]);
        }

        ~Array(void){
            delete [] _array;
        };

        unsigned int size(void){
            return (_len);
        };
    private:
        T *_array;
        unsigned int _len;
};

#endif