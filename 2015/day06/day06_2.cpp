#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <utility>
#include <numeric>

using namespace std;

typedef vector<vector<int>> Grid;
typedef pair<int, int> Coordinate;

const int m = 1000, n = 1000;

void action(Grid& grid, const Coordinate& coord1, const Coordinate& coord2, const string& command) {
	for (int i = coord1.first; i <= coord2.first; i++) {
		for (int j = coord1.second; j <= coord2.second; j++) {
			if (command == "on") {
				grid[i][j]++;
			}
			else if (command == "off") {
				if (grid[i][j] > 0) {
					grid[i][j]--;
				}
			}
			else if (command == "toggle") {
				grid[i][j] += 2;
			}
		}
	}
}

int countTrueValues(const Grid& grid) {
    return accumulate(grid.begin(), grid.end(), 0, [](int sum, const vector<int>& row) {
        return sum + accumulate(row.begin(), row.end(), 0);
    });
}

int main() {
	ifstream input("input.txt");

	Grid grid(m, vector<int>(n, 0));

	string line;
	while (getline(input, line)) {
		stringstream ss(line);
		string command, ignore;
		Coordinate begin, end;

		ss >> command;
		if (command == "turn") {
			ss >> command;
		}
		
		ss >> begin.first;
		ss.ignore(1, ',');
		ss >> begin.second >> ignore >> end.first;
		ss.ignore(1, ',');
		ss >> end.second;

		action(grid, begin, end, command);
	}

	input.close();

	cout << countTrueValues(grid) << endl;

	return 0;
}
