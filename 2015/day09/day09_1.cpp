#include <iostream>
#include <fstream>
#include <limits.h>
#include <string>

using namespace std;

int main() {
    ifstream input("input.txt");

    string line;
    string del_to = " to ";
    string del_eq = " = ";

    while (getline(input, line)) {
        // departure
        auto pos = line.find(del_to);
        string departure = line.substr(0, pos);
		line.erase(0, pos + del_to.length());

        // arrival
        pos = line.find(del_eq);
        string arrival = line.substr(0, pos);
        line.erase(0, pos + del_eq.length());

        // distance
        int distance = stoi(line);
    }

    input.close();

    return 0;
}

