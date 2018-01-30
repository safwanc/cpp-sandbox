/*
Find the `n` largest elements in an array
*/

#include <iostream>
#include <tuple>
#include <vector>
#include <limits>

using namespace std;

vector<int> getTwoLargest(vector<int> nums) {
    if (nums.empty() || nums.size() == 1)
        return nums;

    int first = INT_MIN; 
    int second = INT_MIN;

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

vector<int> getNLargest(vector<int> nums, int n) {
    vector<int> largest;

    for (auto num : nums) {
        if (largest.size() < n) {
            largest.push_back(num);
            if (largest.size() == n)
                make_heap(largest.begin(), largest.end());
        } else {
            if (num > largest.back()) {
                swap(largest.back(), num);
                make_heap(largest.begin(), largest.end());
            }
        }
    }

    return largest;
}

int main() {
    vector<int> nums {9, 8, 10, -1};

    for (auto num : getTwoLargest(nums)) {
        cout << num << endl;
    }

    for (auto num : getNLargest(nums, 3)) {
        cout << num << endl;
    }

    return 0;
}