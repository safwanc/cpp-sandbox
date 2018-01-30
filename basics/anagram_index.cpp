/*
Implement "abcdefg".anagramIndexOf("gfe") -> 4
*/

#include <iostream>
#include <string>
#include <map>
#include <cassert>

using namespace std;

int anagramIndex(string input, string arg) 
{
    if (arg.size() >= input.size())
    {
        int windowSize = arg.size();
        int low = 0, high = low + windowSize;

        map<char, int> requiredCharCounts;
        for (auto c : arg) {
            if (requiredCharCounts.find(c) == requiredCharCounts.end())
                requiredCharCounts[c] = 0;
            requiredCharCounts[c]++;
        }

        map<char, int> charCounts;
        while (high < input.size()) {
            charCounts.clear();

            for (int i = low; i < high; i++) {
                char c = input[i];
                if (charCounts.find(c) == charCounts.end())
                    charCounts[c] = 0;
                charCounts[c]++;
            }

            if (equal(requiredCharCounts.begin(), requiredCharCounts.end(), charCounts.begin())) {
                return low;
            }

            high++;
            low++;
        }
    }

    return -1;
}

int main() {
    auto test = "abcdefg";
    auto arg = "gfeg";

    auto index = anagramIndex(test, arg);
    assert(index == 4);

    cout << "Anagram index of '" << arg << "' from '" << test << "': " << index << endl;
    return 0;
}