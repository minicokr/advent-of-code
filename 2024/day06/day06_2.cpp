#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

typedef vector<vector<char>> Grid;
typedef pair<size_t, size_t> Coord;

const vector<Coord> directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

bool doesGuardLoop(Grid &grid, Coord start, int start_dir) {
    set<pair<Coord, int>> visited;
    Coord cur = start;
    int dir = start_dir;

    while (true) {
        if (visited.count({cur, dir})) return true;
        visited.insert({cur, dir});

        Coord next = {cur.first + directions[dir].first, cur.second + directions[dir].second};

        // check bounds
        if (next.first < 0 || next.first >= grid.size() || next.second < 0 || next.second >= grid[0].size()) 
            return false;

        // turn if there's an obstacle
        if (grid[next.first][next.second] == '#') {
            dir = (dir + 1) % 4; // Turn right
        } else {
            cur = next; // move forward
        }
    }
}

int findLoopingPositions(Grid &grid, Coord start, int start_dir) {
    int loopCount = 0;

    for (size_t i = 0; i < grid.size(); i++) {
        for (size_t j = 0; j < grid[0].size(); j++) {
            if (grid[i][j] == '.' && (i != start.first || j != start.second)) {
                // temporarily place an obstruction
                grid[i][j] = '#';

                // check if this causes a loop
                if (doesGuardLoop(grid, start, start_dir)) {
                    loopCount++;
                }

                // remove the obstruction
                grid[i][j] = '.';
            }
        }
    }

    return loopCount;
}

int main() {
    ifstream input("input.txt");
    Grid grid;
    Coord start;
    int start_dir;

    std::unordered_map<char, int> dir_map = {
        {'^', 0},
        {'>', 1},
        {'v', 2},
        {'<', 3}
    };

    string line;
    for (int i = 0; getline(input, line); i++) {
        vector<char> row(line.begin(), line.end());

        for (size_t j = 0; j < row.size(); j++) {
            if (dir_map.count(row[j])) {
                start = {i, j};
                start_dir = dir_map[row[j]];
                // replace starting point with empty space
                row[j] = '.';
            }
        }

        grid.push_back(row);
    }

    int answer = findLoopingPositions(grid, start, start_dir);
    cout << answer << endl;

    return 0;
}
