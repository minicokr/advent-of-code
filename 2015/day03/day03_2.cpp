#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <utility>

using namespace std;

typedef pair<int, int> grid;

int main() {
	ifstream input("input.txt");

	grid start = {0, 0};
	grid posSanta = start; 
	grid posRobot = start; 
	// false -> Santa, true -> Robot
	bool turn = false;

	set<grid> visited;
	visited.insert(start);

	char c;
	while (input.get(c)) {
		grid& currentPos = turn ? posRobot : posSanta;

		switch (c) {
            case '<': currentPos.first--; break;
            case '>': currentPos.first++; break;
            case '^': currentPos.second++; break;
            case 'v': currentPos.second--; break;
        }

		visited.insert(currentPos);
		// take turns
		turn = !turn;
	}

	input.close();

	cout << visited.size() << endl;
	
	return 0;
}
