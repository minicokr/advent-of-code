#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	long long int result = 0;
	char up = '(';
	char down = ')';
	ifstream input("input.txt");

	char c;
	while (input.get(c)) {
		if (c == up) {
			result++;
		}
		else if (c == down) {
			result--;
		}
	}
	input.close();

	cout << result << endl;

	return 0;
}
