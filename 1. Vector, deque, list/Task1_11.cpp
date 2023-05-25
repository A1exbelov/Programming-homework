#include <iostream>
#include <list>
#include <algorithm>
#include <numeric>
using namespace std;
bool odd(int n) { // Function that defines odd numbers
    return n%2;
}
bool even(int n) {
    return !(n%2);
}
int main(){
    int n, m;
    cout << "n = "; cin >> n; // Entering the dimension of the first sequence
    cout << "m = "; cin >> m; // Entering the dimension of the second sequence
    list<int> a;             
    list<int> b; int x;
    for (int i = 0; i < n; i++) {   // Entering the first list
        cout << "a[" << i << "] = ";
        cin >> x;
        a.push_back(x);
    }
    for (int i = 0; i < m; i++) {
        cout << "b[" << i << "] = "; // Entering the second list
        cin >> x;
        b.push_back(x);
    } 
    a.remove_if(even);
    b.remove_if(odd); 
    a.sort(); b.sort();                            
    a.merge(b);                                     // Combine them into one sorted sequence
    for (int &c : a) cout << c <<' '; 