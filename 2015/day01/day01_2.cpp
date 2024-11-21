#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	long long int result = 0;
	char up = '(';
	char down = ')';
	int position = 0;
	ifstream input("input.txt");

	char c;
	while (input.get(c)) {
		if (c == up) {
			result++;
		}
		else if (c == down) {
			result--;
		}

		position++;

		if (result == -1) {
			break;
		}
	}
	input.close();

	cout << position << endl;

	return 0;
}
