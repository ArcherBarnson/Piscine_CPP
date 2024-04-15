#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cerr << RED << "./btc <input_file>"<< RESET << std::endl;
        return (1);
    }
    BitcoinExchange bc("./input.csv");
    if (bc.getDataMap().empty())
    {
        std::cerr << RED << "FATAL : Failed to build db, exiting" << RESET << std::endl;
        return (2);
    }
    displayResults(bc, av[1]);
    std::cout << "Done, closing..." << std::endl;
    return (0);
}
