#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <iomanip>
using namespace std;

ifstream in("testENG.txt");
ofstream out("output.txt");

struct date
{ // Date
    int dd, mm, yy;
};

struct people
{                   // Data about a person
    string Surname; // Surname
    string position;
    date DateOfBirth; // Date of birth
    int experience;
    int Salary; // Salary
};

date Str_to_Date(string str)
{ // из строки в дату
    date x;
    string temp = str.substr(0, 2); // Day
    x.dd = atoi(temp.c_str());
    temp = str.substr(3, 2); // Month
    x.mm = atoi(temp.c_str());
    temp = str.substr(6, 4); // Year
    x.yy = atoi(temp.c_str());
    return x;
}

vector<people> inFile()
{ // ввод из файла
    vector<people> x;
    people temp;
    while (in.peek() != EOF)
    {
        in >> temp.Surname; 
        in >> temp.position; 
        string tmp;          
        in >> tmp;
        temp.DateOfBirth = Str_to_Date(tmp);
        in >> temp.experience;
        in >> temp.Salary;
        x.push_back(temp);
    }
    return x;
}

void print(people x)
{                                          // Output to a file
    out << setw(40) << left << x.Surname;  // On the left edge, 10 positions for the surname
    out << setw(40) << left << x.position; // On the left edge, 10 positions for the position
    if (x.DateOfBirth.dd < 10)
        out << left << '0' << x.DateOfBirth.dd << '.';
    else
        out << left << x.DateOfBirth.dd << '.';
    if (x.DateOfBirth.mm < 10)
        out << '0' << x.DateOfBirth.mm << '.';
    else
        out << x.DateOfBirth.mm << '.';
    out << left << setw(6) << x.DateOfBirth.yy;
    out << setw(10) << left << x.experience;
    out << left << setw(10) << x.Salary << endl;
}

bool operator<(people a, people b)
{ // Redefining the < operator according to the condition
    if (a.DateOfBirth.yy < b.DateOfBirth.yy)
        return true;
    return false;
}

void counter_sort(vector<people> &x)
{
    people min1 = x[0];
    people max1 = x[0];
    for (int i = 0; i < x.size(); i++)
    {
        if (max1 < x[i])
            max1 = x[i];
        if (x[i] < min1)
            min1 = x[i];
    }
    int k = abs(max1.DateOfBirth.yy - min1.DateOfBirth.yy + 1);
    vector<vector<people>> B2 (max1.DateOfBirth.yy + 1);
    int temp = min1.DateOfBirth.yy;
    while (temp <= max1.DateOfBirth.yy)
    {
        for (int i = 0; i < x.size(); i++) {
            if (x[i].DateOfBirth.yy == temp)
                B2[temp].push_back(x[i]); }
        temp++; 
    }
    for (auto c : B2) {
        for (people r : c) {
            print(r);
        }
    } 
}

int main()
{
    vector<people> x;
    x = inFile();
    counter_sort(x);
    return 0;
}