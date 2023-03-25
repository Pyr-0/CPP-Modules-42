#include <iostream>
#include <fstream>
#include <stdexcept>
#include "BitcoinExchange.hpp"

int main(int argc, char* argv[]) {
	if (argc != 2) {
		std::cerr << "Usage: " << argv[0] << " <input_file>" << std::endl;
		return 1;
	}

	std::ifstream input_file(argv[1]);
	if (!input_file.is_open()) {
		std::cerr << "Error: Failed to open input file." << std::endl;
		return 1;
	}

	try {
		// Parse the BTC data from the CSV file
		BitcoinExchange bit;
		bit.init_csv();
		bit.execute(argv[1]);

	} catch (std::ios_base::failure& e) {
		std::cerr << "Error: Failed to read input file: " << e.what() << std::endl;
		return 1;
	} catch (std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}

	return 0;
}
