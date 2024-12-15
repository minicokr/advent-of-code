#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

typedef pair<int, int> Coord;
typedef vector<pair<int, int>> Visited;

// directions: north, east, south, west
vector<Coord> offsets = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int newDir(const int& curDir, const char& turn) {
    // turn right
    if (turn == 'R')
        return (curDir + 1) % 4;
    // turn left
    else
        return (curDir + 4 - 1) % 4;
}

// true if duplicated
bool move(Coord& pos, int& dir, const char& turn, const int& steps, Visited& visited) {
    dir = newDir(dir, turn);

    for (int i = 0; i < steps; i++) {
        pos.first += offsets[dir].first;
        pos.second += offsets[dir].second;

        // check if already visited
        auto it = find(visited.begin(), visited.end(), pos);

        // already visited
        if (it != visited.end()) {
            return true;
        }
        // not yet visited
        else {
            // visit
            visited.emplace_back(pos);
        }
    }

    return false;
}

int getDistance(Coord& pos) {
    return abs(pos.first) + abs(pos.second);
}

int main() {
    ifstream file("input.txt");
    
    string line;
    while (getline(file, line)) {
        // starting position and direction
        Coord pos = {0, 0};
        int dir = 0; // 0 = north, 1 = east, 2 = south, 3 = west
        Visited visited = {pos};

        stringstream ss(line);
        string token;

        while (getline(ss, token, ',')) {
            stringstream ts(token);
            char turn;
            int steps;

            ts >> turn >> steps;

            bool duplicated = move(pos, dir, turn, steps, visited);

            if (duplicated) {
                break;
            }
        }
        cout << getDistance(pos) << endl;
    }

    file.close();
    return 0;
}
