#ifndef BITCOINEXCHANGE_H
# define BITCOINEXCHANGE_H

#include <map>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>

class BitcoinExchange
{
private:
	std::map<std::string, float> _map;

public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange & origin);
	BitcoinExchange & operator=(const BitcoinExchange & origin);
	~BitcoinExchange();

	void	init_csv();
	void	execute(char *file);
	void	CheckInfo(std::string info);

	bool checkDate(const std::string & str);
	bool checkValue(const std::string & str);

	void	logExchange(std::string date, float nb);

	float	getBitcoinValue(std::string date);
};

#endif
