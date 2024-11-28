#include <iostream>
#include <fstream>
#include <list>
#include <string>

using namespace std;

int main() {
	long long int result = 0;
	ifstream input("input.txt");

	static const list<char> vowels = {'a', 'e', 'i', 'o', 'u'};
	static const list<std::string> not_allowed = {"ab", "cd", "pq", "xy"};

	string s;
	while (getline(input, s)) {
		bool satisfied = false;

		// first condition
		int vowel_cnt = 0;

		for (long unsigned int i = 0; i < s.size(); i++) {
			for (const char& v : vowels) {
				if (s.at(i) == v) {
					vowel_cnt++;
				}
			}	
		}
		
		// bigger than or equal to threshold
		if (vowel_cnt >= 3) {
			satisfied = true;
		}

		// second condition
		long unsigned int i;
		for (i = 0; i < s.size() - 1; i++) {
			// duplicated character found
			if (s.at(i) == s.at(i + 1)) {
				break;
			}
		}

		// not found
		if (i == s.size() - 1) {
			satisfied = false;
		}

		// third condition
		for (const auto& i : not_allowed) {
			// contains not allowed strings
			if (s.find(i) != string::npos) {
				satisfied = false;
				break;
			}
		}
		
		// satisfied
		if (satisfied) {
			result++;
		}
	}

	input.close();

	cout << result << endl;

	return 0;
}
