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
{ // дата
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
{ // From line to date
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
{ // Input from a file
    vector<people> x;
    people temp;
    while (in.peek() != EOF)
    {
        in >> temp.Surname;  // Surname
        in >> temp.position; // Position
        string tmp;          // Date of birth
        in >> tmp;
        temp.DateOfBirth = Str_to_Date(tmp);
        in >> temp.experience;
        in >> temp.Salary; // Salary
        x.push_back(temp);
    }
    return x;
}

void print(people x)
{                                          // Output to a file
    out << setw(40) << left << x.Surname;  // On the left edge, 10 positions for the surname
    out << left << setw(40) << x.position; // On the left edge, 10 positions for the position
    if (x.DateOfBirth.dd < 10)
        out << left << '0' << x.DateOfBirth.dd << '.';
    else
        out << left << x.DateOfBirth.dd << '.';
    if (x.DateOfBirth.mm < 10)
        out << '0' << x.DateOfBirth.mm << '.';
    else
        out << x.DateOfBirth.mm << '.';
    out << left << setw(6) << x.DateOfBirth.yy;
    out << left << setw(10) << x.experience;
    out << left << setw(10) << x.Salary << endl; // Salary
}

bool operator<(people a, people b)
{ // Redefining the < operator according to the condition
    if (a.DateOfBirth.yy < b.DateOfBirth.yy)
        return true;
    if (a.DateOfBirth.yy == b.DateOfBirth.yy && a.experience < b.experience)
        return true;
    return false;
}

void brush_sort(vector<people> &x)
{
    int gap = x.size() / 1.247;
    while (gap >= 1)
    {
        if (gap < 1)
            gap = 1;
        for (int i = 0; i < x.size() - gap; i++)
            if (x[i+gap] < x[i])
                swap(x[i], x[i + gap]);
        gap /= 1.247;
    }
}
int main()
{
    vector<people> x;
    x = inFile();
    brush_sort(x);
    for (int i = 0; i < x.size(); i++)
        print(x[i]);
    return 0;
}