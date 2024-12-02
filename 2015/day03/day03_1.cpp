#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <utility>

using namespace std;

typedef pair<int, int> grid;

int main() {
	ifstream input("input.txt");
	grid pos = {0, 0};
	set<grid> visited;

	// always visit starting point
	visited.insert(pos);

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

		visited.insert(pos);
	}
	
	input.close();

	cout << visited.size() << endl;
	
	return 0;
}
