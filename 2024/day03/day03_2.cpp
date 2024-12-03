#include <iostream>
#include <fstream>
#include <sstream>
#include <regex>
#include <string>

using namespace std;

int main() {
    int answer = 0;
    bool enabled = true;

    // pattern
    regex pattern("mul\\((\\d+),(\\d+)\\)|do\\(\\)|don't\\(\\)");
    smatch match;

    // get line
    ifstream input("input.txt");
    string line;

    // iterate per line
    while (getline(input, line)) {
        // find pattern
        while (!line.empty()) {
            if (regex_search(line, match, pattern)) {
                string m = match[0].str();
                if (m.find("don't()") != string::npos) {
                    enabled = false;
                }
                else if (m.find("do()") != string::npos) {
                    enabled = true;
                }
                if (m.find("mul") != string::npos && enabled) {
                    // get numbers
                    int num1 = stoi(match[1].str());
                    int num2 = stoi(match[2].str());

                    answer += (num1 * num2);
                }
            }

            // update line
            line = match.suffix().str();
        }
    }

    input.close();

    cout << answer << endl;

    return 0;
}

