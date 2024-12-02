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
