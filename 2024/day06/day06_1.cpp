#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <unordered_map>

using namespace std;

typedef vector<vector<char>> Grid;
typedef pair<size_t, size_t> Coord;

bool changePosDir(Grid& grid, const Coord& cur_pos, int& cur_dir) {
    bool obstacle = false;

    // no obstacle
    if (grid[cur_pos.first][cur_pos.second] != '#') {
        // visit
        grid[cur_pos.first][cur_pos.second] = 'X';
    }
    // obstacle
    else {
        // change direction
        cur_dir = (cur_dir + 1) % 4;
        obstacle = true;
    }

    return obstacle;
}

void move(Grid& grid, Coord& cur_pos, int& cur_dir) {
    // up
    if (cur_dir == 0) {
        for (; 0 <= cur_pos.first; cur_pos.first--) {
            if (changePosDir(grid, cur_pos, cur_dir)) {
                cur_pos.first++;
                break;
            }
        }
    }
    // right 
    else if (cur_dir == 1) {
        for (; cur_pos.second < grid[0].size(); cur_pos.second++) {
            if (changePosDir(grid, cur_pos, cur_dir)) {
                cur_pos.second--;
                break;
            }
        }
    }
    // down 
    else if (cur_dir == 2) {
        for (; cur_pos.first < grid.size(); cur_pos.first++) {
            if (changePosDir(grid, cur_pos, cur_dir)) {
                cur_pos.first--;
                break;
            }
        }
    }
    // left
    else if (cur_dir == 3) {
        for (; 0 <= cur_pos.second; cur_pos.second--) {
            if (changePosDir(grid, cur_pos, cur_dir)) {
                cur_pos.second++;
                break;
            }
        }
    }
}

int main() {
    Grid grid;
    Coord cur_pos;
    int cur_dir;
    std::unordered_map<char, int> dirCharToInt = {
        {'^', 0},
        {'>', 1},
        {'v', 2},
        {'<', 3}
    };

    ifstream input("input.txt");
    string line;

    int i = 0;
    while (getline(input, line)) {
        vector<char> grid_line;

        int j = 0;
        for (const char& c: line) {
            grid_line.push_back(c);

            // save current position and direction
            if (c == '^' || c == '>' || c == 'v' || c == '<') {
                cur_pos = {i, j};
                cur_dir = dirCharToInt[c];
            }
            j++;
        }
        grid.push_back(grid_line);

        i++;
    }

    // move until out
    while (0 <= cur_pos.first && cur_pos.first < grid.size() && 0 <= cur_pos.second && cur_pos.second < grid[0].size()) {
        // move
        move(grid, cur_pos, cur_dir);
    }

    int answer = 0;
    // count all visited
    for (const auto& row : grid) {
        answer += count(row.begin(), row.end(), 'X');
    }

    cout << answer << endl;

    return 0;
}
