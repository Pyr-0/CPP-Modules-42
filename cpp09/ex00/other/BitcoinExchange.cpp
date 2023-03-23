#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <mutex> // Add this include statement

// Declare a mutex to protect the btc_data map
std::mutex btc_data_mutex;


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
		        // Lock the mutex to protect the btc_data map
        btc_data_mutex.lock();
        btc_data.insert(std::make_pair(timestamp, price));
        btc_data_mutex.unlock();
    }

    return btc_data;
}


// Calculate the Bitcoin value for each input data point using the BTC price data
void calculate_btc_values(const btc_data_t& btc_data, const input_data_t& input_data)
{
    for (input_data_t::const_iterator it = input_data.begin(); it != input_data.end(); ++it) {
        std::time_t timestamp = it->first;
        float value = it->second;

        btc_data_t::const_iterator btc_it = btc_data.find(timestamp);
        if (btc_it == btc_data.end()) {
            // Find the closest date
            btc_it = btc_data.lower_bound(timestamp);
            if (btc_it == btc_data.begin()) {
                std::cerr << "Error: no BTC price data available for date " << std::put_time(std::gmtime(&timestamp), "%F") << std::endl;
                continue;
            }
            btc_it--;
        }

        std::ostringstream oss;
        oss << std::put_time(std::gmtime(&btc_it->first), "%F");
        std::string date = oss.str();

        float btc_value = btc_it->second;
        float btc_input = value * btc_value;

        std::cout << date << " => " <<(double)value << std::setprecision(2) <<" = " << btc_input <<std::fixed<<std::setprecision(2)<< std::endl;
    }
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
            std::cerr  << "Error: not a positive number."<<std::endl;
            continue;
        }
		else if(value > 1000)
		{
            std::cerr  << "Error: too large number." << std::endl;
            continue;
		}

        std::tm date;
        std::istringstream date_ss(date_str);
        date_ss >> std::get_time(&date, "%Y-%m-%d");
        std::time_t timestamp = std::mktime(&date);
		
        input_data.insert(std::make_pair(timestamp, value));

		// calculate_btc_values(parse_btc_csv("data.csv"), input_data);
    }


    return input_data;
}


bool is_valid_date(const std::string& date_str) {
    struct tm date;
    memset(&date, 0, sizeof(struct tm));
    if (strptime(date_str.c_str(), "%Y-%m-%d", &date) == NULL) {
        return false;
    }
    return true;
}