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
    for (; std::getline(data, line); )
    {
        date = line.substr(0, 10);
        value = atof((line.substr(11 + offset)).c_str());
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
    std::map<std::string, float>input_map = db.makeCsvMap(input, 0);
    std::map<std::string, float>db_tmpmap = db.getDataMap();
    std::map<std::string, float> retmap;
    std::fstream data;
    std::string line = "";
    std::string date = "";
    float value = 0;
    //iterate through inputmap
    std::map<std::string, float>::iterator tmp_it = db_tmpmap.begin();
    std::map<std::string, float>::iterator db_entry_it = db_tmpmap.begin();
    data.open(input.c_str());
    for (; std::getline(data, line); )
    {
        date = line.substr(0, 10);
        value = atof((line.substr(13)).c_str());
        tmp_it = db_entry_it;
        db_entry_it = db_tmpmap.find(date);
        //std::cout << "d=" << date << " - v=" << value;
        //std::cout << "dbdbg: " << db_tmpmap[db_entry_it->first] << std::endl;
        if (db_entry_it != db_tmpmap.end())
            std::cout << date << " => " << value * db_entry_it->second << std::endl;
        else
            std::cout << "Good luck coding the closest entry finding function ! Fuck you !" << std::endl;
        db_entry_it = tmp_it;
    }
    data.close();
    //if key no match find closest earlywise
    //if key match display date and db value (price) * input value (quantity)
    return ;
};
