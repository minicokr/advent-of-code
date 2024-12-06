#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <utility>
#include <string>
#include <algorithm>

using namespace std;

bool checkUpdate(const vector<pair<int, int>>& orders, const vector<int>& update) {
    for (const auto& o: orders) {
        int x = o.first;
        int y = o.second;

        auto it_x = find(update.begin(), update.end(), x);
        auto it_y = find(update.begin(), update.end(), y);

        // x and y exists
        if (it_x != update.end() && it_y != update.end())
            if (it_x > it_y)
                return false;
    } 
    return true;
}

int getMiddle(const vector<int>& v) {
    return v.at(v.size() / 2);
}

int main() {
    int answer = 0;
    // orders
    vector<pair<int, int>> orders;

    // input
    ifstream input("input.txt");
    string line;

    // input mode
    bool update = false;

    // read until new line
    while (getline(input, line)) {
        stringstream ss(line);

        // orders
        if (!update) {
            // get numbers
            int x, y;
            char ignore;
            ss >> x >> ignore >> y;

            // add order
            orders.emplace_back(x, y);
        }
        // updates
        else {
            vector<int> update;

            // save update
            string number;
            while (getline(ss, number, ',')) {
                update.push_back(stoi(number));
            }

            // check orders
            if (checkUpdate(orders, update)) {
                answer += getMiddle(update);
            }
        }

        // change mode to orders to updates
        if (line.empty())
            update = true;
    }

    cout << answer << endl;

    return 0;
}
