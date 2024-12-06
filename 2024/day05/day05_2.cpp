#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <utility>
#include <string>
#include <algorithm>

using namespace std;

bool reorder(const vector<pair<int, int>>& orders, vector<int>& update) {
    bool reordered = false;

    for (const auto& o: orders) {
        int x = o.first;
        int y = o.second;

        auto it_x = find(update.begin(), update.end(), x);
        auto it_y = find(update.begin(), update.end(), y);

        // x and y exists
        if (it_x != update.end() && it_y != update.end()) {
            if (it_x > it_y) {
                rotate(it_y, it_y + 1, it_x + 1);
                reordered = true;
            }
        }
    } 

    return  reordered;
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

            // order not correct
            int i = 0;
            while (reorder(orders, update)) {
                i++;
            }

            // at least reordered
            if (i > 0) {
                // reorder
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
