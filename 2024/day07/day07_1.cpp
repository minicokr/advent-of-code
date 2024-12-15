#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

bool foundResult(const vector<int>& numbers, const long long int& result, const long long int& cur_result, const int& index) {
    if (numbers.size() == 1) {
        if (cur_result == result)
            return true;
        else
            return false;
    }
    else if (index == (int) numbers.size()) {
        if (cur_result == result)
            return true;
        else
            return false;
    }

    // plus
    bool plus_check = foundResult(numbers, result, cur_result + numbers[index], index + 1);

    // multiply
    bool multiply_check = foundResult(numbers, result, cur_result * numbers[index], index + 1);

    return plus_check || multiply_check;
}

int main() {
    long long int answer = 0;

    ifstream input("input.txt");

    string line;
    while (getline(input, line)) {
        istringstream iss(line);
        long long int result;
        int num;
        char ignore;

        iss >> result >> ignore;

        vector<int> numbers;

        while (iss >> num) {
            numbers.push_back(num);
        }

        if(foundResult(numbers, result, numbers[0], 1)) {
            answer += result;
        }
    }

    cout << answer << endl;

    return 0;
}
