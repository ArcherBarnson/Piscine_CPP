#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <algorithm>
# include <map>
# include <iterator>

#define RESET   "\033[0m"
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */

class BitcoinExchange {
    public:
        BitcoinExchange(void);
        BitcoinExchange(std::string csv_path);
        BitcoinExchange(BitcoinExchange const & copy);
        BitcoinExchange &operator=(BitcoinExchange const & other);
        ~BitcoinExchange(void);
        std::map<std::string, float> makeCsvMap(std::string filename);
        std::map<std::string, float> getDataMap();

    private:
        std::map<std::string, float> _data;
};

void displayResults(BitcoinExchange db, std::string input);

#endif