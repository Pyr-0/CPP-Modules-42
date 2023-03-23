#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>

namespace PmergeMe
{
    // Function declarations
    bool mergeInsertionSort(std::vector<int>& arr);
    bool mergeInsertionSort(std::deque<int>& arr);
    std::string getTimeString(double time);

} // namespace PmergeMe

#endif // PMERGEME_HPP
