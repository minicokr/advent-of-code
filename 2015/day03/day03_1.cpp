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
	grid pos = {0, 0};
	grid_bool visited;

	// always visit starting point
	visited.insert({pos, true});

	char c;
	while (input.get(c)) {
		if (c == '<') {
			pos.first--;
		}
		else if (c == '>') {
			pos.first++;
		}
		else if (c == 'v') {
			pos.second--;
		}
		else if (c == '^') {
			pos.second++;
		}

		visited.insert({pos, true});
	}
	
	input.close();

	result = visited.size();

	cout << result << endl;
	
	return 0;
}
