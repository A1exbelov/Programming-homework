#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
int X;
bool neKratnoX(int n) {  // Function that defines numbers that are not multiples of X
    return n%X!=0;
}
bool even(int n) { // Function that defines even numbers
    return n%2==0;
}
using namespace std;
int main() {
    cout << "n = ";
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cout << "a[" << i << "] = ";
        cin >> a[i];
    }
    cout <<"X = "; cin >> X;
    vector<int> temp(a); // Copy of vector a
    replace_if(temp.begin(), temp.end(), neKratnoX, 0); // Replacing non-multiple numbers with zeros (in a copy of the vector)
    cout << "Sum of elements, divisible by X = ";
    cout << accumulate(temp.begin(), temp.end(), 0) << '\n'; // The sum of all elements unequal to zero
    cout << "Min element = " << *min_element(a.begin(), a.end()) << '\n'; // Output of the minimum element
    int maxim = *max_element(a.begin(), a.end()); 
    replace_if(a.begin(), a.end(), even, maxim); // Replacing all even elements with the maximum
    cout << "All even elements, replaced with the maximal one:" << '\n';
    for (int c : a) cout << c << ' ';
}