#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	long long int result = 0;
	int position = 0;
	ifstream input("input.txt");

	char c;
	while (input.get(c)) {
		if (c == '(') {
			result++;
		}
		else if (c == ')') {
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
