#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cstring>


// Parse a CSV file containing Bitcoin price data and return it as a map
btc_data_t parse_btc_csv(const std::string& filename)
{
	std::ifstream file(filename.c_str());
	if (!file) {
		throw std::runtime_error("Error: could not open file " + filename);
	}

	btc_data_t btc_data;
	std::string line;
	bool first_line = true; // flag to skip the first line
	while (std::getline(file, line)) {
		if (first_line && line == "date | value") {
			first_line = false;
			continue;
		}
		std::istringstream iss(line);
		std::string date_str, price_str;
		std::getline(iss, date_str, '|');
		std::getline(iss, price_str, '|');

		std::tm date;

		std::istringstream date_ss(date_str);
		date_ss >> std::get_time(&date, "%Y-%m-%d");

		if (date_ss.fail()) {
			throw std::runtime_error("Error: invalid date format in " + filename);
		}

		float price = std::atof(price_str.c_str());
		if (price < 0) {
			throw std::runtime_error("Error: invalid price in " + filename);
		}

		std::time_t timestamp = std::mktime(&date);
		btc_data.insert(std::make_pair(timestamp, price));
	}

	return btc_data;
}

// Parse an input file containing dates and values and return it as a map
// of Bitcoin values, keyed by timestamp
input_data_t parse_input_file(const std::string& filename)
{
	std::ifstream file(filename.c_str());
	if (!file) {
		throw std::runtime_error("Error: could not open file " + filename);
	}

	input_data_t input_data;
	std::string line;
	bool first_line = true; // flag to skip the first line
	while (std::getline(file, line)) {
		if (first_line && line == "date | value") {
			first_line = false;
			continue;
		}
		std::istringstream iss(line);
		std::string date_str, value_str;
		std::getline(iss, date_str, '|');
		std::getline(iss, value_str, '|');
		//Date check
		if (!is_valid_date(date_str)) {
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}
		//Max num check
		float value = std::atof(value_str.c_str());
		if (value < 0) {
			std::cerr << "Error: not a positive number." << line << std::endl;
			continue;
		}
		else if(value > 1000)
		{
			std::cerr << "Error: too large a number."<< std::endl;
			continue;
		}

		std::tm date;
		std::istringstream date_ss(date_str);
		date_ss >> std::get_time(&date, "%Y-%m-%d");

		std::time_t timestamp = std::mktime(&date);
		
		input_data.insert(std::make_pair(timestamp, value));
	}

	return input_data;
}

// Calculate the Bitcoin value for each input data point using the BTC price data
void calculate_btc_values(const btc_data_t& btc_data, const input_data_t& input_data)
{
	for (input_data_t::const_iterator it = input_data.begin(); it != input_data.end(); ++it) {
		std::time_t timestamp = it->first;
		float value = it->second;


		btc_data_t::const_iterator btc_it = btc_data.find(timestamp);
		if (btc_it == btc_data.end()) {
			std::cerr << "Warning: no BTC price data for date " << std::put_time(std::gmtime(&timestamp), "%F") << std::endl;
			continue;
		}

		float btc_price = btc_it->second;
		float btc_value = value / btc_price;
		std::cout << std::put_time(std::gmtime(&timestamp), "%F") << "|" << std::fixed << std::setprecision(2) << btc_value << std::endl;
	}
}


bool is_valid_date(const std::string& date_str) {
	struct tm date;
	memset(&date, 0, sizeof(struct tm));
	if (strptime(date_str.c_str(), "%Y-%m-%d", &date) == NULL) {
		return false;
	}
	return true;
}