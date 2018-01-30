/*
Random vector things
*/

#include <iostream>
#include <vector>

using namespace std;

#define print(name) cout << #name << ": " << (name) << endl;

ostream& operator <<(ostream &os, const vector<int> &v) {
    os << "[ "; for (auto i : v)  os << i << " "; os << "]";
    return os;
}

int main() {
    vector<int> v1 {1, 2, 3, 4}; print(v1);
    vector<int> v2 {1, 2, 3, 4}; print(v2);

    cout << "v1 == v2: " << equal(v1.begin(), v1.end(), v2.begin()) << endl;
    return 0;
}