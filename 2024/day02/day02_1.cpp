#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

bool isWithinIncreasingLimits(const int& cur_num, const int& prev_num) {
    return prev_num < cur_num && prev_num + 3 >= cur_num;
}

bool isWithinDecreasingLimits(const int& cur_num, const int& prev_num) {
    return prev_num > cur_num && prev_num - 3 <= cur_num;
}

bool isWithinLimits(const int& cur_num, const int& prev_num, bool increasing) {
    if (increasing) {
        return isWithinIncreasingLimits(cur_num, prev_num);
    } else {
        return isWithinDecreasingLimits(cur_num, prev_num);
    }
}

int main() {
    ifstream input("input.txt");

    int answer = 0;
    string line;

    while (getline(input, line)) {
        istringstream iss(line);
        int num, prev_num;
        bool increasing, pass = true;

        // read the first number
        iss >> prev_num;

        // read the second number
        if (!(iss >> num)) {
            continue;
        }

        if (isWithinIncreasingLimits(num, prev_num)) {
            increasing = true;
        } else if (isWithinDecreasingLimits(num, prev_num)) {
            increasing = false;
        } else {
            pass = false;
        }

        prev_num = num;

        // process the rest of the numbers
        while (pass && (iss >> num)) {
            if (!isWithinLimits(num, prev_num, increasing)) {
                pass = false;
            }
            prev_num = num;
        }

        if (pass) {
            answer++;
        }
    }

    input.close();
    cout << answer << endl;

    return 0;
}
