#include <iostream>
#include <fstream>
#include <string>
#include <unordered_set>

using namespace std;

int main() {
	long long int result = 0;
	ifstream input("input.txt");

	string s;
	while (getline(input, s)) {
		bool first_condition = false;
		bool second_condition = false;

		unordered_set<string> pairs;
		for (size_t i = 0; i < s.size() - 1; i++) {
			string pair = s.substr(i, 2);
			if (i > 0 && pairs.count(pair) && s.substr(i - 1, 2) != pair) {
				first_condition = true;
			}
			pairs.insert(pair);
		}

		for (size_t i = 0; i < s.size() - 2; i++) {
			if (s[i] == s[i + 2]) {
				second_condition = true;
				break;
			}
		}

		if (first_condition && second_condition) {
			result++;
		}
	}

	input.close();

	cout << result << endl;

	return 0;
}
