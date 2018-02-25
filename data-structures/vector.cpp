/*
Random vector things
*/

#include <iostream>
#include <vector>

using namespace std;

#define print(name) cout << #name << ": " << name << endl;

ostream& operator <<(ostream &os, const vector<int> &v) {
    os << "[ "; for (auto i : v)  os << i << " "; os << "]";
    return os;
}

int main() {
    vector<int> v1 {1, 2, 3, 4}; print(v1);
    vector<int> v2 {1, 2, 3, 4}; print(v2);

    cout << "v1 == v2: " << equal(v1.begin(), v1.end(), v2.begin()) << endl;

    vector<vector<int>> vec2d;
    vec2d.push_back(vector<int> {1, 2, 3});
    vec2d.push_back(vector<int> {4, 5});

    vector<int> temp;
    temp.push_back(6);
    vec2d.push_back(temp);

    for (auto vec : vec2d) {
        cout << "[ ";
        for (auto i : vec)
            cout << i << " ";
        cout << "]\n";
    }

    return 0;
}