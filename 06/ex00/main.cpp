#include "ScalarConverter.hpp"

int main()
{
    ScalarConverter sc;
    sc.convert("315431841");
    sc.convert("42.0f");
    sc.convert("-35768");
    return 0;
}