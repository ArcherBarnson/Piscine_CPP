#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void) {
    //DO NOT USE
    return;
};

BitcoinExchange::BitcoinExchange(std::string csv_path) {
    _data = makeCsvMap(csv_path, 0);
    return;
};

BitcoinExchange::BitcoinExchange(BitcoinExchange const & copy) {
    *this = copy;
    return ;
};

BitcoinExchange & BitcoinExchange::operator=(BitcoinExchange const & other) {
    _data = other._data;
    return (*this);
};

BitcoinExchange::~BitcoinExchange(void) {
    return ;
};

std::map<std::string, float> BitcoinExchange::makeCsvMap(std::string filename, int offset)
{
    std::map<std::string, float> retmap;
    std::fstream data;
    std::string line = "";
    std::string date;
    float value;

    data.open(filename.c_str());
    for (line; std::getline(data, line); )
    {
        date = line.substr(0, 9);
        value = atof((line.substr(10 + offset)).c_str());
        retmap.insert(std::pair<std::string, float>(date, value));
    }
    data.close();
    return (retmap);
};

std::map<std::string, float> BitcoinExchange::getDataMap()
{
    return (_data);
};

void    displayResults(BitcoinExchange db, std::string input)
{
    std::map<std::string, float>input_map = db.makeCsvMap(input, 1);
    //iterate through inputmap
    //if key no match find closest earlywise
    //if key match display date and db value (price) * input value (quantity)
    return ;
};
