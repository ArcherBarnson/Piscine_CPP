#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    BitcoinExchange bc("./data.csv");
    if (ac != 2)
    {
        std::cerr << "Bad args, bye bye"  << std::endl;
        return (1);
    }
    displayResults(bc, av[1]);
    std::cout << "Done, closing..." << std::endl;
    return (0);
}