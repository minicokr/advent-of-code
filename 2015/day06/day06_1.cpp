#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <utility>
#include <regex>
#include <numeric>

using namespace std;

typedef vector<vector<bool>> Grid;
typedef pair<int, int> Coordinate;

int m = 1000, n = 1000;

int getInteger(string& s_copy) {
	int num = 0;

	regex rgx("(\\d+)");
    smatch match;
    
    if (regex_search(s_copy, match, rgx)) {
		num = stoi(match.str());
		s_copy = match.suffix();
    }

	return num;
}

void action(Grid& grid, const Coordinate& coord1, const Coordinate& coord2, const string& command) {
	int coord1x = coord1.first;
	int coord1y = coord1.second;
	int coord2x = coord2.first;
	int coord2y = coord2.second;

	for (int i = coord1x; i <= coord2x; i++) {
		for (int j = coord1y; j <= coord2y; j++) {
			if (command == "turn on") {
				grid[i][j] = true;
			}
			else if (command == "turn off") {
				grid[i][j] = false;
			}
			else if (command == "toggle") {
				grid[i][j] = !grid[i][j];
			}
		}
	}
}

int countTrueValues(const Grid& grid) {
    return accumulate(grid.begin(), grid.end(), 0, [](int sum, const vector<bool>& row) {
        return sum + accumulate(row.begin(), row.end(), 0);
    });
}

int main() {
	long long int result = 0;
	ifstream input("input.txt");

	Grid grid(m, vector<bool>(n, false));

	string s;
	while (getline(input, s)) {
		string s_copy = s;

		// coords for begin and end point
		Coordinate begin, end;
		
		begin.first = getInteger(s_copy);
		begin.second = getInteger(s_copy);
		end.first = getInteger(s_copy);
		end.second = getInteger(s_copy);

		// turn light on
		if (s.find("turn on") != string::npos) {
			action(grid, begin, end, "turn on");
		}
		// turn light off
		else if (s.find("turn off") != string::npos) {
			action(grid, begin, end, "turn off");
		}
		// turn light on
		else if (s.find("toggle") != string::npos) {
			action(grid, begin, end, "toggle");
		}
	}

	input.close();

	result = countTrueValues(grid);

	cout << result << endl;



	return 0;
}
