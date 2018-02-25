#include <iostream>

using namespace std;

int reverseInteger(int x) {
    long long reversed = 0;

    while (x) {
        reversed = reversed * 10 + x % 10;
        x /= 10;
    }

    return (reversed < INT_MIN or reversed > INT_MAX) ? 0 : reversed;
}

int main() {
    int x = -123;
    cout << x << " reversed " << reverseInteger(x) << endl;
    return 0;
}