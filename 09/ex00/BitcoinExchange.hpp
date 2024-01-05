#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <algorithm>
# include <map>
# include <iterator>

class BitcoinExchange {
    public:
        BitcoinExchange(void);
        BitcoinExchange(std::string csv_path);
        BitcoinExchange(BitcoinExchange const & copy);
        BitcoinExchange &operator=(BitcoinExchange const & other);
        ~BitcoinExchange(void);
        std::map<std::string, float> makeCsvMap(std::string filename, int offset);
        std::map<std::string, float> getDataMap();

    private:
        std::map<std::string, float> _data;
};

void displayResults(BitcoinExchange db, std::string input);

#endif