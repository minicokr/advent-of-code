#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	long long int result = 0;
	ifstream input("input.txt");

	string s;

	while (getline(input, s)) {
		stringstream ss(s);
		string token;
		int dimensions[3];
		int i = 0;

		while (getline(ss, token, 'x')) {
			dimensions[i++] = stoi(token);
		}

		int l = dimensions[0];
		int w = dimensions[1];
		int h = dimensions[2];
			
		int ribbon = 2 * (l + w + h - max({l, w, h}));
		int bow = l * w * h;

		result += (ribbon + bow);

	}
	input.close();

	cout << result <<endl;

	return 0;
}
