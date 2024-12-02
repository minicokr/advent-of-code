#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool isIncreasingWithinLimits(const int& cur_num, const int& prev_num) {
    if (prev_num < cur_num && prev_num + 3 >= cur_num)
        return true;
    else
        return false;
}

bool isDecreasingWithinLimits(const int& cur_num, const int& prev_num) {
    if (prev_num > cur_num && prev_num - 3 <= cur_num)
        return true;
    else
        return false;
}

int main() {
    ifstream input("input.txt");

    int answer = 0;

    string line;
    string del = " ";

    // get reports
    while (getline(input, line)) {
        // initialize per report
        bool increasing;
        bool pass = true;

        // first level
        size_t pos = line.find(del);
        int num = stoi(line.substr(0, pos));
        int prev_num = num;
        // cut string
        line.erase(0, pos + del.length());

        // second level
        pos = line.find(del);
        num = stoi(line.substr(0, pos));
        if (isIncreasingWithinLimits(num, prev_num)) {
            increasing = true;
        }
        else if (isDecreasingWithinLimits(num, prev_num)) {
            increasing = false;
        }
        else {
            pass = false;
        }
        prev_num = num;
        // cut string
        line.erase(0, pos + del.length());

        // get all lists from one report
        while (pass) {
            // until reading the all numbers
            if (pos = line.find(del); pos != string::npos) {
                // number
                num = stoi(line.substr(0, pos));

                // increasing
                if (increasing && isIncreasingWithinLimits(num, prev_num)) {
                }
                // decreasing
                else if (!increasing && isDecreasingWithinLimits(num, prev_num)) {
                }
                else {
                    pass = false;
                }

                // cut string
                line.erase(0, pos + del.length());

                // update previous number
                prev_num = num;
            }
            // last level
            else {
                num = stoi(line.substr(pos + del.length()));

                // increasing
                if (increasing && isIncreasingWithinLimits(num, prev_num)) {
                }
                // decreasing
                else if (!increasing && isDecreasingWithinLimits(num, prev_num)) {
                }
                else {
                    pass = false;
                }

                // count results
                if (pass) {
                    answer += 1;
                }
                break;
            }
        }

    }

    input.close();

    cout << answer << endl;
    
    return 0;
}
