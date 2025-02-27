#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>

class   BitcoinExchange
{
    private:
        std::map<std::string, float>    _database;
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &copy);
        BitcoinExchange &operator=(const BitcoinExchange &copy);
        ~BitcoinExchange();

        void    readDatabase();
        void    printDatabase();
        void    readInput();

    // methods to make
    // read date, read price, read file to get the input
    // ashdui

    //i use map cuz key and value :thumbs_up:
};
