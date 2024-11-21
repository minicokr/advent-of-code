#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <utility>

using namespace std;

typedef pair<int, int> grid;
typedef map<grid, bool> grid_bool;

int main() {
	int result = 0;
	ifstream input("input.txt");

	grid start = {0, 0};
	grid posSanta = start; 
	grid posRobot = start; 
	// false -> Santa, true -> Robot
	bool turn = false;

	grid_bool visited;
	visited.insert({start, true});

	char c;
	while (input.get(c)) {
		// santa 
		grid* pos = &posSanta;
		// robot
		if (turn) {
			pos = &posRobot;	
		}

		// take turns
		turn = !turn;

		if (c == '<') {
			pos->first--;
		}
		else if (c == '>') {
			pos->first++;
		}
		else if (c == 'v') {
			pos->second--;
		}
		else if (c == '^') {
			pos->second++;
		}

		visited.insert({*pos, true});
	}

	result = visited.size();

	cout << result << endl;
	
	return 0;
}
