#include <iostream>
#include <fstream>
#include <sstream>
#include <regex>
#include <string>

using namespace std;

int main() {
    int answer = 0;

    // pattern
    regex pattern("mul\\((\\d+),(\\d+)\\)");
    smatch match;

    // get line
    ifstream input("input.txt");
    string line;

    // iterate per line
    while (getline(input, line)) {
        // find pattern
        while (regex_search(line, match, pattern)) {
            // get numbers
            int num1 = stoi(match[1].str());
            int num2 = stoi(match[2].str());

            answer += (num1 * num2);

            // update line
            line = match.suffix().str();
        }
    }

    input.close();

    cout << answer << endl;

    return 0;
}

