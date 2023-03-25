#include "PmergeMe.hpp"


namespace PmergeMe
{
	// MergeInsertionSort for vector
// bool mergeInsertionSort(std::vector<int>& arr)
// {
// 	if (arr.empty())
// 		return false;

// 	const int n = arr.size();
// 	for (int i = 1; i < n; ++i)
// 	{
// 		int key = arr[i];
// 		int j = i - 1;

// 		while (j >= 0 && arr[j] > key)
// 		{
// 			arr[j + 1] = arr[j];
// 			--j;
// 		}

// 		arr[j + 1] = key;
// 	}

// 	return true;
// }

// bool mergeInsertionSort(std::vector<int>& arr)
// {
//     if (arr.empty())
//         return false;

//     std::set<int> unique_nums(arr.begin(), arr.end()); // use set to eliminate duplicates
//     arr.assign(unique_nums.begin(), unique_nums.end()); // copy back the unique elements to the vector

//     const int n = arr.size();
//     for (int i = 1; i < n; ++i)
//     {
//         int key = arr[i];
//         int j = i - 1;

//         while (j >= 0 && arr[j] > key)
//         {
//             arr[j + 1] = arr[j];
//             --j;
//         }

//         arr[j + 1] = key;
//     }

//     return true;
// }

// // MergeInsertionSort for deque
// bool mergeInsertionSort(std::deque<int>& arr)
// {
// 	if (arr.empty())
// 		return false;

// 	const int n = arr.size();
// 	for (int i = 1; i < n; ++i)
// 	{
// 		int key = arr[i];
// 		int j = i - 1;

// 		while (j >= 0 && arr[j] > key)
// 		{
// 			arr[j + 1] = arr[j];
// 			--j;
// 		}

// 		arr[j + 1] = key;
// 	}

// 	return true;
// }

// 	// Get formatted time string
// 	std::string getTimeString(double time)
// 	{
// 		std::ostringstream ss;
// 		ss.precision(6);
// 		ss << std::fixed << time << " us";
// 		return ss.str();
// 	}
bool mergeInsertionSort(std::set<int>& arr)
{
    const int n = arr.size();
    std::deque<int> sorted_nums;

    for (std::set<int>::iterator it = arr.begin(); it != arr.end(); ++it)
    {
        sorted_nums.push_back(*it);
    }

    for (int i = 1; i < n; ++i)
    {
        int key = sorted_nums[i];
        int j = i - 1;

        while (j >= 0 && sorted_nums[j] > key)
        {
            sorted_nums[j + 1] = sorted_nums[j];
            --j;
        }

        sorted_nums[j + 1] = key;
    }

    arr.clear();
    for (std::deque<int>::iterator it = sorted_nums.begin(); it != sorted_nums.end(); ++it)
    {
        arr.insert(*it);
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
