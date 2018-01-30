/*
Find the `n` largest elements in an array
*/

#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

// Initial implementation
vector<int> getTwoLargest(vector<int> nums) {
    if (nums.size() <= 2)
        return nums;

    int first, second = INT_MIN;

    for (auto num : nums) {
        if (num > second) {
            first = second;
            second = num;
        } else if (num > first) {
            first = num;
        }
    }

    return vector<int> {first, second};
}

auto comparator = [](int a, int b) { return a > b; };

// Generalize to N largest
vector<int> getNLargest(vector<int> nums, int n) {
    vector<int> largest;

    for (auto num : nums) {
        if (largest.size() < n) {
            largest.push_back(num);
            if (largest.size() == n)
                make_heap(largest.begin(), largest.end(), comparator);
        } else if (num > largest.front()) {
            pop_heap(largest.begin(), largest.end(), comparator);
            largest.pop_back();
            largest.push_back(num);
            make_heap(largest.begin(), largest.end(), comparator);
        }
    }

    return largest;
}

int main() {
    vector<int> nums {9, 3, 2, 0, 1, -1, 10};
    cout << "Unsorted elements: [ ";
    for (auto num : nums) cout << num << " "; cout << "]\n";

    cout << "Largest n=" << 2 << " elements: [ ";
    vector<int> largestTwo = getTwoLargest(nums);
    for (auto num : largestTwo) cout << num << " "; cout << "]\n";


    int n = 4;
    vector<int> largest = getNLargest(nums, n);
    cout << "Largest n=" << n << " elements: [ ";
    for (auto num : largest) cout << num << " "; cout << "]\n";

    return 0;
}

/*
Unsorted elements: [ 9 3 2 0 1 -1 10 ]
Largest n=4 elements: [ 2 3 9 10 ]
*/