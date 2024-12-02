#include <iostream>
#include <fstream>

using namespace std;

int main() {
	long long int result = 0;
	ifstream input("input.txt");

	char c;
	while (input.get(c)) {
		if (c == '(') {
			result++;
		} else if (c == ')') {
			result--;
		}
	}

	input.close();

	cout << result << endl;

	return 0;
}
