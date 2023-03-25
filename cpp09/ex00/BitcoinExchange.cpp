#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange & origin){*this = origin;}

BitcoinExchange & BitcoinExchange::operator=(const BitcoinExchange & origin){
	this->_map = origin._map;
	return *this;
}

void	BitcoinExchange::init_csv()
{
	std::ifstream csv("data.csv");
	std::string read;
	float nb;
	size_t size;

	while(getline(csv, read))
 	{
		if (read != "date,exchange_rate")
		{
			size = read.find(',');
			std::istringstream(read.substr(size + 1, read.length())) >> nb;
			_map[read.substr(0, size)] = nb;
		}
	}
}

void	BitcoinExchange::execute(char *file)
{
 	std::ifstream configfile(file);
	std::string read;

	while(getline(configfile, read))
		CheckInfo(read);
}

void	BitcoinExchange::CheckInfo(std::string info)
{
	static bool first_line = true;
    
    // Skip the first line of input
    if (first_line && info == "date | value") {
        first_line = false;
        return;
    }
	std::string date, s;
	float	value;
	std::istringstream ss(info);
	int i = 0;

	while (std::getline(ss, s, ' '))
    {
        if (i == 0)
		{
			if (!checkDate(s))
				return ;
			date = s;
		}
		if (i == 1 && s != "|")
		{
			std::cout << "Error: bad input => " << info << std::endl;
			return ;
		}
		if (i == 2)
		{
			if (!checkValue(s))
				return ;
			std::istringstream(s) >> value;
			if (value > 1000)
			{
				std::cout << "Error: too large a number.\n";
				return ;
			}
		}
		i++;
	}
	if (i != 3)
	{
			std::cout << "Error: bad input => " << info << std::endl;
			return ;
	}
	logExchange(date, value);
}

bool BitcoinExchange::checkDate(const std::string & str)
{
    std::istringstream ss(str);
    int year, month, day;
    char sep1, sep2;
    ss >> year >> sep1 >> month >> sep2 >> day;
    if (!ss || sep1 != '-' || sep2 != '-')
    {
        std::cout << "Error: incorrect date\n";
        return false;
    }
    if (year < 2009 || year > 2022)
    {
        std::cout << "Error: incorrect year.\n";
        return false;
    }
    if (month < 1 || month > 12)
    {
        std::cout << "Error: incorrect month.\n";
        return false;
    }
    if (day < 1 || day > 31)
    {
        std::cout << "Error: incorrect day.\n";
        return false;
    }
    if (day == 31 && (month == 2 || month == 4 || month == 6 || month == 9 || month == 11))
    {
        std::cout << "Error: incorrect day.\n";
        return false;
    }
    if (day > 28 && month == 2)
    {
        std::cout << "Error: incorrect day.\n";
        return false;
    }
    return true;
}

bool	is_Num(const std::string &str)
{
	if (!str.empty() && str.find_first_not_of("0123456789.-") != std::string::npos)
		return false;
	return true;
}

bool BitcoinExchange::checkValue(const std::string & str)
{
	if (!is_Num(str) || !str.find('.', 0) || str.find('.', str.length() - 1) != std::string::npos)
	{
		std::cout << "Error: not a Number\n";
		return false; 
	}
	if (str < "0")
	{
		std::cout << "Error: not a positive number.\n";
		return false;
	}
	if (str.length() > 10 || (str.length() == 10 && str > "2147483647"))
	{
		std::cout << "Error: too large a number.\n";
		return false;
	}
	return true;
}

void	BitcoinExchange::logExchange(std::string date, float nb)
{
	float res;

	res = getBitcoinValue(date) * nb;
	std::cout << date << " => " << nb << " = " << res << std::endl;
}

float	BitcoinExchange::getBitcoinValue(std::string date)
{
	std::map<std::string, float>::const_iterator it;

	it  = _map.find(date);
	if (it != _map.end())
		return (it->second);
	else
	{
		it = _map.lower_bound(date);
		return (it->second);
	}
}
