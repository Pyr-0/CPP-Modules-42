#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <cstdlib>
#include <ctime>
#include "mergesort.hpp"
#include "insertsort.hpp"

using namespace std;

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " <positive integers>" << endl;
        return 1;
    }

    // Convert input arguments to integers and store them in a vector
    vector<int> input;
    for (int i = 1; i < argc; i++) {
        int num = atoi(argv[i]);
        if (num <= 0) {
            cerr << "Error: Non-positive integer detected." << endl;
            return 1;
        }
        input.push_back(num);
    }

    // Display the unsorted input sequence
    cout << "Before: ";
    for (size_t i = 0; i < input.size(); i++) {
        cout << input[i] << " ";
    }
    cout << endl;

    // Sort the input sequence using merge-insert sort algorithm with vector container
    vector<int> v(input);
    clock_t start = clock();
    mergesort(v.begin(), v.end(), insertsort<vector<int> >());
    double time_v = static_cast<double>(clock() - start) / CLOCKS_PER_SEC;

    // Display the sorted sequence and the time taken by vector container
    cout << "After: ";
    for (size_t i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
    cout << "Time to process a range of " << v.size() << " elements with vector container: " << time_v << " s
