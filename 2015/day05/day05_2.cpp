#include <iostream>
#include <fstream>
#include <list>
#include <string>

using namespace std;

int main() {
	long long int result = 0;
	ifstream input("input.txt");

	string s;
	while (getline(input, s)) {
		bool satisfied = false;

		// first condition
		for (int i = 0; i < s.size() - 1 - 2; i++) {
			auto s1 = s.substr(i, 2);

			for (int j = i + 2; j < s.size() - 1; j++) {
				auto s2 = s.substr(j, 2);

				if (s1 == s2) {
					satisfied = true;
					break;
				}
			}
			
			if (satisfied) {
				break;
			}
		}

		if (!satisfied) {
			continue;
		}

		// second condition
		for (int i = 0; i < s.size() - 2; i++) {
			auto s1 = s.at(i);
			auto s2 = s.at(i + 2);

			if (s1 == s2) {
				satisfied = true;
				break;
			}
			else {
				satisfied = false;
			}
		}

		if (satisfied) {
			result++;
		}
	}

	input.close();

	cout << result << endl;

	return 0;
}
