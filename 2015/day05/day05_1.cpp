#include <iostream>
#include <fstream>
#include <unordered_set>
#include <string>

using namespace std;

int main() {
	long long int result = 0;
	ifstream input("input.txt");

	static const unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
	static const unordered_set<string> not_allowed = {"ab", "cd", "pq", "xy"};

	string s;
	while (getline(input, s)) {
		int vowel_cnt = 0;
		bool has_double = false;
		bool has_not_allowed = false;

		for (size_t i = 0; i < s.size(); ++i) {
			// Check for vowels
			if (vowels.count(s[i])) {
				vowel_cnt++;
			}

			// Check for double letters
			if (i > 0 && s[i] == s[i - 1]) {
				has_double = true;
			}

			// Check for not allowed strings
			if (i > 0 && not_allowed.count(s.substr(i - 1, 2))) {
				has_not_allowed = true;
				break;
			}
		}

		if (vowel_cnt >= 3 && has_double && !has_not_allowed) {
			result++;
		}
	}

	input.close();

	cout << result << endl;

	return 0;
}
