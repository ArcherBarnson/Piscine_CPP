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

int     getStringValue(std::string str)
{
    int i = 0;
    int val = 0;
    int len = 10000000;
    std::string strlol = "";
    if ((str[5] < '0' || str[5] > '1') || (str[8] < '0' || str[8] > '3'))
        return (0);
    //std::cout << "str is " << str << std::endl;
    while (str[i])
    {
        strlol += str[i];
        val += (atoi(strlol.c_str())) * len;
        i++;
        if (i != 4 && i != 7)
            len /= 10;
        strlol = "";
    }
    return (val);
}

void    displayClosestEntry(std::map<std::string, float> db, std::string date, float value)
{
    std::map<std::string, float>::iterator it = db.begin();
    int string_value = getStringValue(date);
    //std::cout << "string value = " << string_value << std::endl;
    //std::cout << "dbg--->" << getStringValue("2010-01-03") << std::endl;
    if (getStringValue(it->first) > string_value)
    {
        std::cout << "Date entry before db first entry or formatting error" << std::endl;
        return ;
    }
    while (it != db.end() && getStringValue(it->first) < string_value)
        it++;
    if (it != db.end())
    {
        if (it != db.begin())
            it--;
        if (value >= 0 && value <= 1000)
            std::cout << it->first << " => " << value * it->second << std::endl;
    }
    else
        std::cout << "Date entry after db last entry or formatting error" << std::endl;
    return ;


}

void    displayResults(BitcoinExchange db, std::string input)
{
    std::map<std::string, float>db_tmpmap = db.getDataMap();
    std::fstream data;
    std::string line = "";
    std::string date = "";
    float value = 0;
    std::map<std::string, float>::iterator db_entry_it = db_tmpmap.begin();
    data.open(input.c_str());
    for (; std::getline(data, line); )
    {
        date = line.substr(0, 10);
        value = atof((line.substr(13)).c_str());
        db_entry_it = db_tmpmap.find(date);
        if (value < 0)
            std::cerr << "Error: entry value is negative" << std::endl;
        else if (value > 1000)
            std::cerr << "Error: you cannot possibly have that many bitcoins" << std::endl;
        else 
        {
            if (db_entry_it != db_tmpmap.end())
                std::cout << date << " => " << value * db_entry_it->second << std::endl;
            else
                displayClosestEntry(db_tmpmap, date, value);
        }
    }
    data.close();
    //if key no match find closest earlywise
    //if key match display date and db value (price) * input value (quantity)
    return ;
};
