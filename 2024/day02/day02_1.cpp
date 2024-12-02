#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ifstream input("input.txt");

    vector<vector<int>> reports;
    int report_i = 0;

    // process inputs
    string line;
    while (getline(input, line)) {
        istringstream iss(line);
        int level;

        vector<int> report;
        reports.push_back(report);

        while (iss >> level) {
            reports[report_i].push_back(level);
        }
        report_i++;
    }
    input.close();

    // count
    int answer = 0;
    for (const auto& report : reports) {
        bool consistent_condition = true;
        bool differ_condition = true;
        int prev_sub;
        
        for (size_t i = 1; i < report.size(); i++) {
            int sub = report[i - 1] - report[i];

            if (i == 1) {
                prev_sub = sub;
            }

            if (abs(sub) > 3) {
                differ_condition = false;
            }
            else if (sub == 0) {
                consistent_condition = false;
            }
            else if (sub * prev_sub <= 0) {
                consistent_condition = false;
            } 
        }

        if (consistent_condition && differ_condition) {
            answer++;
        }
    }

    cout << answer << endl;

    return 0;
}
