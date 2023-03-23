#include "BitcoinExchange.hpp"
#include <iostream>
#include <ctime>
#include <stdio.h>

// int main(int argc, char* argv[]) {
//     if (argc != 2) {
//         std::cerr <<RED<< "Error: Could not open file." << RESET<< std::endl;
//         std::cerr << "Usage: " << argv[0] << " <input_file>" << std::endl;
//         return 1;
//     }
//     try {
//         // Parse the input data from the input file
//         parse_input_file(argv[1]);

//     } catch (const std::invalid_argument& e) {
//         std::cerr << e.what() << std::endl;
//         return 1;
//     } catch (const std::runtime_error& e) {
//         std::cerr << e.what() << std::endl;
//         return 1;
//     }


//     return 0;
// }


int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <input_file>" << std::endl;
        return 1;
    }
    try {
        // Parse the BTC data from the CSV file
        btc_data_t btc_data = parse_btc_csv("data.csv");

        // Parse the input data from the input file
        input_data_t input_data = parse_input_file(argv[1]);

        // Calculate the BTC values for the input data
        calculate_btc_values(btc_data, input_data);
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}