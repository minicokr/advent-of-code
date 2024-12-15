#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
#include <cmath>

using namespace std;

typedef pair<int, int> Coord;

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

void move(Coord& pos, int& dir, const char& turn, const int& steps) {
    dir = newDir(dir, turn);
    pos.first += offsets[dir].first * steps;
    pos.second += offsets[dir].second * steps;
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

        stringstream ss(line);
        string token;

        while (getline(ss, token, ',')) {
            stringstream ts(token);
            char turn;
            int steps;

            ts >> turn >> steps;

            move(pos, dir, turn, steps);
        }
        cout << getDistance(pos) << endl;
    }

    file.close();
    return 0;
}
