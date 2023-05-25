#include <iostream>
#include <fstream>
#include <set>
#include <string>
using namespace std;
int main() {
    string s;
    set<string> current;        // Set for the current offer
    set<string> narrative;      // Set for words found in narrative sentences
    set<string> exclamation;    // Set for words found in exclamation sentences
    ifstream in("9HP.txt");
    if (in.is_open()) {         
        while (getline(in, s)) { // Reading the lines
            for (int i = 0; i < s.length(); ++i) {  // cycle over all characters
                if (isalpha(s[i])) {     // If the symbol is a letter, then we type the whole word
                    string now = "";
                    while (isalpha(s[i])) {
                        now += s[i]; i++;
                    } 
                    current.insert(now); // Adding a word to the network for the current sentence
                }
                if (s[i] == '.') {       // If there is a dot, we add everything
                    for (auto c : current) {
                        narrative.insert(c);
                    }
                    current.clear();
                }
                if (s[i] == '!') {
                    for (auto c : current) {
                        exclamation.insert(c);
                    }
                    current.clear();
                }
                else if (s[i] == '?') current.clear();
            }
        }
    } 
    in.close();
    for (auto c : narrative) {
       if (exclamation.find(c) != exclamation.end()) {
            cout << c << ' ';
        }
    }
}