#include <iostream>
#include <fstream>
#include <map>
using namespace std;
int main() {
    map<string, int> words;
    ifstream in("wait.txt");
    if (in.is_open()) {
        string s = "";
        while(getline(in, s, ' ')) {
            if (isalpha(s[0])) {
                words[s]++;
            }
        }
    } 
    in.close();
    for (auto c : words) cout << c.first << ' ' << c.second << '\n';
}