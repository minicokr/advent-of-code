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

		int area1 = l * w;
		int area2 = l * h;
		int area3 = w * h;

		int wrapper = 2 * (area1 + area2 + area3) + min({area1, area2, area3});
		result += wrapper;
	}
	input.close();

	cout << result <<endl;

	return 0;
}
