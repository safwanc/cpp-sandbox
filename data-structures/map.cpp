/*
Random map things
*/

#include <iostream>
#include <map>

using namespace std;

#define print(name) cout << #name << ": " << name << endl;

ostream& operator <<(ostream &os, const map<int, char> &m) {
    os << "{" << "\n";
    for (auto i : m) 
        os << "\t" << i.first << ": " << i.second << "\n";
    os << "}" << "\n";
    return os;
}

int main() {
    map<int, char> m1 = {{1, 'a'}, {2, 'b'}}; print(m1);
    map<int, char> m2 = {{1, 'a'}, {2, 'b'}}; print(m2);

    cout << "m1 == m2: " << equal(m1.begin(), m1.end(), m2.begin()) << endl;
    return 0;
}