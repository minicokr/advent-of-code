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
	int x = 0, y = 0;
	grid_bool visited;
	ifstream input("input.txt");

	// always visit starting point
	visited.insert({{x, y}, true});

	char c;
	while (input.get(c)) {
		if (c == '<') {
			x--;
		}
		else if (c == '>') {
			x++;
		}
		else if (c == 'v') {
			y--;
		}
		else if (c == '^') {
			y++;
		}

		visited.insert({{x, y}, true});
	}

	result = visited.size();

	cout << result << endl;
	
	return 0;
}
