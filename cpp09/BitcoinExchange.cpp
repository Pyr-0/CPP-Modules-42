/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 21:44:47 by mrojas-e          #+#    #+#             */
/*   Updated: 2023/03/22 19:56:32 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <stdexcept>

using namespace std;

struct Date {
    int year, month, day;
};

class BitcoinExchange {
public:
    BitcoinExchange(const string& price_file) {
        ifstream file(price_file);
        if (!file) {
            throw runtime_error("Error: could not open file.");
        }
        string line;
        while (getline(file, line)) {
            istringstream iss(line);
            string date_str, price_str;
            if (getline(iss, date_str, ',') && getline(iss, price_str)) {
                try {
                    Date date = parse_date(date_str);
                    float price = stof(price_str);
                    prices_[date] = price;
                } catch (const exception& e) {
                    cerr << "Warning: " << e.what() << endl;
                }
            } else {
                cerr << "Warning: bad input line: " << line << endl;
            }
        }
    }

    void convert(const string& input_file) {
        ifstream file(input_file);
        if (!file) {
            throw runtime_error("Error: could not open file.");
        }
        string line;
        while (getline(file, line)) {
            istringstream iss(line);
            string date_str, value_str;
            if (getline(iss, date_str, '|') && getline(iss, value_str)) {
                try {
                    Date date = parse_date(date_str);
                    float value = stof(value_str);
                    if (value < 0 || value > 1000) {
                        throw runtime_error("not a positive number.");
                    }
                    float exchange_rate = get_exchange_rate(date);
                    float result = value * exchange_rate;
                    cout << date_str << " => " << value_str << " = " << result << endl;
                } catch (const exception& e) {
                    cerr << "Error: " << e.what() << endl;
                }
            } else {
                cerr << "Error: bad input line: " << line << endl;
            }
        }
    }

private:
    unordered_map<Date, float> prices_;

    Date parse_date(const string& date_str) const {
        int year, month, day;
        char sep1, sep2;
        istringstream iss(date_str);
        if (!(iss >> year >> sep1 >> month >> sep2 >> day) || sep1 != '-' || sep2 != '-') {
            throw runtime_error("bad date format: " + date_str);
        }
        return {year, month, day};
    }

    float get_exchange_rate(const Date& date) const {
        auto it = prices_.find(date);
        if (it == prices_.end()) {
            throw runtime_error("no bitcoin price data for date: " + to_string(date.year) + "-" + to_string(date.month) + "-" + to_string(date.day));
        }
        return it->second;
    }
};
int main(int argc, char* argv[]) {
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " input_file" << endl;
        return 1;
    }
    try {
        BitcoinExchange exchange("bitcoin_prices.csv");
        exchange.convert(argv[1]);
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }
    return 0;
}
