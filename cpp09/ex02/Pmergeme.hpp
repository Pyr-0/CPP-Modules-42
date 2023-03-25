#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>
#include <iostream>
#include <sstream>
#include <set>
#include <ctime>

//============COLORS!=======//
#define						RED "\e[31m"
#define						GREEN "\e[32m"
#define						BLUE "\e[36m"
#define						LILA "\e[35m"
#define						YLLW "\e[33m"
#define						RESET "\e[0m"
namespace PmergeMe
{
    // Merge-insertion sort for vector
    // Sorts the elements of the input vector in non-descending order using a
    // merge-insertion sort algorithm.
    // Returns true if the vector was sorted successfully, false otherwise.
    // bool mergeInsertionSort(std::vector<int>& arr);
	bool mergeInsertionSort(std::set<int>& arr);

    // Merge-insertion sort for deque
    // Sorts the elements of the input deque in non-descending order using a
    // merge-insertion sort algorithm.
    // Returns true if the deque was sorted successfully, false otherwise.
    bool mergeInsertionSort(std::deque<int>& arr);

    // Get formatted time string
    // Formats the input time in microseconds as a string with 6 decimal places
    // and the suffix "us" (microseconds).
    // Returns the formatted time string.
    std::string getTimeString(double time);

} // namespace PmergeMe

#endif // PMERGEME_HPP
