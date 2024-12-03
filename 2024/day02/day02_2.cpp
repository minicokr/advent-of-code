#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

bool isSafe(const vector<int>& report) {
    if (report.size() < 2)
        return true;

    auto checkConditions = [](const vector<int>& r) {
        for (size_t i = 1; i < r.size(); ++i) {
            int diff = r[i] - r[i - 1];
            if (abs(diff) < 1 || abs(diff) > 3 || (i > 1 && (r[i - 1] - r[i - 2]) * diff < 0)) {
                return false;
            }
        }
        return true;
    };

    // if the report is already safe, no need to check further
    if (checkConditions(report)) {
        return true;
    }

    // try tolerating by removing one level and checking
    for (size_t i = 0; i < report.size(); ++i) {
        vector<int> modifiedReport = report;
        modifiedReport.erase(modifiedReport.begin() + i);
        if (checkConditions(modifiedReport)) {
            return true;
        }
    }

    return false;
}

int main() {
    ifstream input("input.txt");

    vector< vector<int> > reports;
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

    int answer = 0;
    for (const auto& report : reports) {
        if (isSafe(report)) {
            answer++;
        }
    }

    cout << answer << endl;

    return 0;
}
