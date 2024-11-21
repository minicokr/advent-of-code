#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	long long int result = 0;
	ifstream input("input.txt");

	string s;
	string del = "x";

	while (getline(input, s)) {
		// find first occurence of the delimiter
		auto pos = s.find(del);

		// extract
		int l = stoi(s.substr(0, pos));

		// erase extracted
		s.erase(0, pos + del.length());

		// find next occurence of the delimiter
		pos = s.find(del);

		// extract
		int w = stoi(s.substr(0, pos));

		// erase extracted
		s.erase(0, pos + del.length());

		// find next occurence of the delimiter
		pos = s.find(del);

		// extract
		int h = stoi(s.substr(0, pos));
			
		int ribbon = 2 * (l + w + h - max({l, w, h}));
		int bow = l * w * h;

		result += (ribbon + bow);

	}
	input.close();

	cout << result <<endl;

	return 0;
}
