/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 13:26:32 by bgrulois          #+#    #+#             */
/*   Updated: 2024/04/15 13:54:11 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void) {
    return;
};

BitcoinExchange::BitcoinExchange(std::string csv_path) {
    _data = makeCsvMap(csv_path);
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

std::map<std::string, float> BitcoinExchange::makeCsvMap(std::string filename)
{
    std::map<std::string, float> retmap;
    std::fstream data;
    std::string line = "";
    std::string date;
    float value;

    data.open(filename.c_str());
    if (!data)
    {
        std::cout << RED << "Error : data.csv not found" << RESET << std::endl;
        return (retmap);
    }
    for (; std::getline(data, line); )
    {
        if (line.size() < 11)
        {
            _data.clear();
            std::cout << RED << "Error : db entry corrupted" << RESET << std::endl;
            return (retmap);
        }
        date = line.substr(0, 10);
        value = atof((line.substr(12)).c_str());
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
    int magnitude = 10000000;
    std::string digit = "";
    if ((str[5] < '0' || str[5] > '1') || (str[8] < '0' || str[8] > '3'))
        return (0);
    //std::cout << "str is " << str << std::endl;
    while (str[i])
    {
        digit += str[i];
        val += (atoi(digit.c_str())) * magnitude;
        i++;
        if (i != 4 && i != 7)
            magnitude /= 10;
        digit = "";
    }
    return (val);
}

void    displayClosestEntry(std::map<std::string, float> db, std::string date, float value)
{
    std::map<std::string, float>::iterator it = db.begin();
    int string_value = getStringValue(date);
    if (getStringValue(it->first) > string_value)
    {
        std::cout << YELLOW << "[" << date << " : Date entry invalid or before db first entry]" << RESET << std::endl;
        return ;
    }
    while (it != db.end() && getStringValue(it->first) < string_value)
        it++;
    if (it != db.end())
    {
        if (it != db.begin())
            it--;
        if (value >= 0 && value <= 1000)
		{
            std::cout << CYAN << it->first << " => " << value * it->second << " (closest)" << RESET << std::endl;
		}
    }
    else
        std::cout << YELLOW << "[" << date << " : Date entry invalid or after db last entry]" << RESET << std::endl;
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
        if (line.size() >= 14 && line[11] == '|' &&
            ((atof((line.substr(13)).c_str()) == 0 &&
            line.substr(13)[0] == '0') ||
            (atof((line.substr(13)).c_str()) != 0 &&
            line.substr(13)[0] != '0')))
        {
            date = line.substr(0, 10);
            value = atof((line.substr(13)).c_str());
            db_entry_it = db_tmpmap.find(date);
            if (value < 0)
                std::cout << RED << "Error: entry value is negative" << RESET << std::endl;
            else if (value > 1000)
                std::cout << RED <<  "Error: you cannot possibly have that many bitcoins" << RESET << std::endl;
            else 
            {
                if (db_entry_it != db_tmpmap.end())
                    std::cout << GREEN << date << " => " << value * db_entry_it->second << RESET << std::endl;
            else
                displayClosestEntry(db_tmpmap, date, value);
            }
        }
        else
            std::cout << RED << "[FORMATTING ERROR : Format should be YYYY-MM-DD | VALUE]" << RESET << std::endl;
    }
    data.close();
    return ;
};
