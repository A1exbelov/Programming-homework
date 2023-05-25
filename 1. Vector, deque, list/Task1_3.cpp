#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool odd(int n) {  // a Function that defines odd numbers
    return n % 2;
}

int main() {
    cout << "n = ";
    int n; cin >> n;   // Entering the number of elements
    vector<int> a; int x;
    for (int i = 0; i < n; i++) {
        cout << "a[" << i << "] = ";  // Entering numbers into a vector
        cin >> x;
        a.push_back(x);
    }
    replace_if(a.begin(), a.end(), odd, 0); // Replacing odd ones with zero
    cout << "Result: ";
    for (int c : a) {   
        cout << c << " ";
    }
}