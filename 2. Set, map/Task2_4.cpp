#include <iostream>
#include <map>
#include <set>
using namespace std;
bool dvyz(int x) {          // Function that defines two-digit numbers
    if (x > 9 && x < 100) return true;
    return false;
}
bool trez(int x) {          // Function that defines three-digit numbers
    if (x > 99 && x < 1000) return true;
    return false;
}

int main() {
    set<int> exists2;  // Set of digits occurring in two-digit numbers
    set<int> exists3;  // Set of digits occurring in three-digit numbers
    set<int> num;      // Set for all entered numbers
    cout << "n = ";
    int n; cin >> n; int x;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        num.insert(x);
    }
    for (int c : num) { 
        if (dvyz(c)) {      // If the number is two-digit, then we throw its digits into the corresponding sets
            exists2.insert(c%10);
            exists2.insert(c/10);
        }
        if (trez(c)) {      // If the number is three-digit, then we throw its digits into the corresponding sets
            exists3.insert(c%10);
            exists3.insert(c/10%10);
            exists3.insert(c/100);
        }
    }
    cout << "Result: "; 
    for (int c : exists2) {   // Cycle through all digits occurring in two-digit numbers
        if (exists3.find(c) != exists3.end()) {  // If this number occurs in three digits, then we output it
            cout << c << ' ';
        }
    }
}