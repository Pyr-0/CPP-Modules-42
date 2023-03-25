#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <sstream>
#include <ctime>
#include <set>
#include "PmergeMe.hpp"

int main(int argc, char** argv)
{
    if (argc <= 1) {
        std::cout << "Usage: " << argv[0] << " num1 num2 num3 ... numN" << std::endl;
        return 0;
    }

    // Parse input arguments
    std::set<int> set;
    std::deque<int> deq;
    bool valid_input = true;
    for (int i = 1; i < argc; ++i) {
        int num;
        std::istringstream iss(argv[i]);
        if (iss >> num) {
            if (num < 0) {
                std::cerr << "Error: Input cannot be negative." << std::endl;
                valid_input = false;
                break;
            }
            set.insert(num);
            deq.push_back(num);
        } else {
            std::cerr << "Error: Invalid input. Input must be a positive integer." << std::endl;
            valid_input = false;
            break;
        }
    }

    if (!valid_input) {
        return 1;
    }

    // Print input set
    std::cout<<GREEN << "Unsorted Set: "<<RESET;
    for (std::set<int>::iterator it = set.begin(); it != set.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Sort using set and print time
    std::clock_t start_time = std::clock();
    PmergeMe::mergeInsertionSort(set);
    std::clock_t end_time = std::clock();
    std::cout << GREEN<<"Time to process set with PmergeMe::mergeInsertionSort: "
              << RED<<PmergeMe::getTimeString((end_time - start_time) / (double) (CLOCKS_PER_SEC / 1000000))
              << std::endl;

    // Print sorted set
    std::cout <<GREEN<< "Sorted Set: "<<RESET;
    for (std::set<int>::iterator it = set.begin(); it != set.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Print input deque
    std::cout <<YLLW<< "Unsorted Deque: "<<RESET;
    for (std::deque<int>::iterator it = deq.begin(); it != deq.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Sort using deque and print time
    start_time = std::clock();
    PmergeMe::mergeInsertionSort(deq);
    end_time = std::clock();
    std::cout <<YLLW<< "Time to process deque with PmergeMe::mergeInsertionSort: "
              <<RED<< PmergeMe::getTimeString((end_time - start_time) / (double) (CLOCKS_PER_SEC / 1000000))
              << std::endl;

    // Print sorted deque
    std::cout << YLLW<<"Sorted Deque: "<<RESET;
    for (std::deque<int>::iterator it = deq.begin(); it != deq.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}
