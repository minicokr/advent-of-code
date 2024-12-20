#include <iostream>
#include <fstream>
#include <vector>
#include <utility>

using namespace std;

typedef vector<vector<char>> Grid;
typedef vector<vector<bool>> Visited;
typedef pair<int, int> Coord;

bool isFrequency(const char& c) {
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9');
}

Coord getGradient(const Coord& coord1, const Coord& coord2) {
    int x = coord2.first - coord1.first;
    int y = coord2.second - coord1.second;

    return {x, y};
}

void visitAntinodes(Visited& visited, const Coord& coord, const Coord& gradient) {
    int dx = gradient.first;
    int dy = gradient.second;
    int x_max = (int) visited.size();
    int y_max = (int) visited[0].size();

    // self check
    visited[coord.first][coord.second] = true;

    // check all antinodes
    Coord cur_coord = coord;
    while (true) {
        cur_coord.first += dx;
        cur_coord.second += dy;

        if (cur_coord.first >= 0 && cur_coord.first < x_max && cur_coord.second >= 0 && cur_coord.second < y_max)
            visited[cur_coord.first][cur_coord.second] = true;
        else
            break;
    }

    cur_coord = coord;
    while (cur_coord.first >= 0 && cur_coord.first < x_max && cur_coord.second >= 0 && cur_coord.second < y_max) {
        cur_coord.first -= dx;
        cur_coord.second -= dy;

        if (cur_coord.first >= 0 && cur_coord.first < x_max && cur_coord.second >= 0 && cur_coord.second < y_max)
            visited[cur_coord.first][cur_coord.second] = true;
        else
            break;
    }
}

void getAntinodes(const Grid& grid, Visited& visited) {
    int rows = grid.size();
    int cols = grid[0].size();

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            char frequency = grid[i][j];

            if (isFrequency(frequency)) {
                // the coordinates of the first frequency
                Coord coord1 = make_pair(i, j);

                for (int k = 0; k < rows; k++) {
                    for (int l = 0; l < cols; l++) {
                        // same frequency
                        if (i != k && j != l && grid[k][l] == frequency) {
                            // the coordinates of the second frequency  
                            Coord coord2 = make_pair(k, l);

                            // find antinodes
                            Coord gradient = getGradient(coord1, coord2);

                            visitAntinodes(visited, coord1, gradient);
                        }
                    }
                }
            }
        }
    }
}

int getNumAntinode(const Visited& visited) {
    int cnt = 0;

    // count all visited
    for (const auto& row : visited) {
        cnt += count(row.begin(), row.end(), true);
    }

    return cnt;
}

int main() {
    Grid grid;

    ifstream input("input.txt");
    string line;

    while(getline(input, line)) {
        vector<char> row;
        for (char c : line) {
            row.push_back(c);
        }
        grid.push_back(row);
    }

    Visited visited = Visited(grid.size(), vector<bool>(grid[0].size(), false));
    getAntinodes(grid, visited);
    int answer = getNumAntinode(visited);

    cout << answer << endl;

    return 0;
}
