#include "PmergeMe.hpp"
#include <iostream>
#include <sstream>
#include <algorithm>
#include <ctime>

namespace PmergeMe
{
	// MergeInsertionSort for vector
	bool mergeInsertionSort(std::vector<int>& arr)
	{
		if (arr.empty())
			return false;

		const int n = arr.size();
		for (int i = 1; i < n; ++i)
		{
			int key = arr[i];
			int j = i - 1;

			while (j >= 0 && arr[j] > key)
			{
				arr[j + 1] = arr[j];
				--j;
			}

			arr[j + 1] = key;
		}

		return true;
	}

	// MergeInsertionSort for deque
	bool mergeInsertionSort(std::deque<int>& arr)
	{
		if (arr.empty())
			return false;

		const int n = arr.size();
		for (int i = 1; i < n; ++i)
		{
			int key = arr[i];
			int j = i - 1;

			while (j >= 0 && arr[j] > key)
			{
				arr[j + 1] = arr[j];
				--j;
			}

			arr[j + 1] = key;
		}

		return true;
	}

	// Get formatted time string
	std::string getTimeString(double time)
	{
		std::ostringstream ss;
		ss.precision(6);
		ss << std::fixed << time << " us";
		return ss.str();
	}

} // namespace PmergeMe
