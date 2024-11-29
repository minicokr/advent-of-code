#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <algorithm>
#include <cctype>

using namespace std;

bool isDigits(const string& s) {
	return s.find_first_not_of("0123456789") == string::npos;
}

void operation(map<string, string>& m, map<string, unsigned short>& result) {
	string gate_and = " AND ";
	string gate_or = " OR ";
	string gate_rshift = " RSHIFT ";
	string gate_lshift = " LSHIFT ";
	string gate_not = "NOT ";

	for (auto it = m.begin(); it != m.end(); ) {
		const auto& [key, cmd] = *it;

		// and
		if (auto oper_pos = cmd.find(gate_and); oper_pos != string::npos) {
			string input1 = cmd.substr(0, oper_pos);
			string input2 = cmd.substr(oper_pos + gate_and.length());

			// valid cases
			if (isDigits(input1) && result.count(input2)) {
				result[key] = static_cast<unsigned short>(stoul(input1)) & result[input2];
			}
			else if (result.count(input1) && isDigits(input2)) {
				result[key] = result[input1] & static_cast<unsigned short>(stoul(input2));
			}
			else if (result.count(input1) && result.count(input2)) {
				result[key] = result[input1] & result[input2];
			}
			else {
				++it;
				continue;
			}
		}
		// or 
		else if (auto oper_pos = cmd.find(gate_or); oper_pos != string::npos) {
			string input1 = cmd.substr(0, oper_pos);
			string input2 = cmd.substr(oper_pos + gate_or.length());

			// valid cases
			if (isDigits(input1) && result.count(input2)) {
				result[key] = static_cast<unsigned short>(stoul(input1)) | result[input2];
			}
			else if (result.count(input1) && isDigits(input2)) {
				result[key]= result[input1] | static_cast<unsigned short>(stoul(input2));
			}
			else if (result.count(input1) && result.count(input2)) {
				result[key] = result[input1] | result[input2];
			}
			else {
				++it;
				continue;
			}
		}
		// right shift 
		else if (auto oper_pos = cmd.find(gate_rshift); oper_pos != string::npos) {
			string input1 = cmd.substr(0, oper_pos);
			string input2 = cmd.substr(oper_pos + gate_rshift.length());

			// valid cases
			if (isDigits(input1) && result.count(input2)) {
				result[key] = static_cast<unsigned short>(stoul(input1)) >> result[input2];
			}
			else if (result.count(input1) && isDigits(input2)) {
				result[key] = result[input1] >> static_cast<unsigned short>(stoul(input2));
			}
			else if (result.count(input1) && result.count(input2)) {
				result[key] = result[input1] >> result[input2];
			}
			else {
				++it;
				continue;
			}
		}
		// left shift 
		else if (auto oper_pos = cmd.find(gate_lshift); oper_pos != string::npos) {
			string input1 = cmd.substr(0, oper_pos);
			string input2 = cmd.substr(oper_pos + gate_lshift.length());

			// valid cases
			if (isDigits(input1) && result.count(input2)) {
				result[key] = static_cast<unsigned short>(stoul(input1)) << result[input2];
			}
			else if (result.count(input1) && isDigits(input2)) {
				result[key] = result[input1] << static_cast<unsigned short>(stoul(input2));
			}
			else if (result.count(input1) && result.count(input2)) {
				result[key] = result[input1] << result[input2];
			}
			else {
				++it;
				continue;
			}
		}
		// not 
		else if (auto oper_pos = cmd.find(gate_not); oper_pos != string::npos) {
			string input = cmd.substr(oper_pos + gate_not.length());

			// valid cases
			if (isDigits(input)) {
				result[key] = ~static_cast<unsigned short>(stoul(input));
			}
			else if (result.count(input)) {
				result[key] = ~result[input];
			}
			else {
				++it;
				continue;
			}
		}
		// no operation
		else if (!isDigits(cmd) && result.count(cmd)){
			result[key] = result[cmd];
		}
		else {
			++it;
			continue;
		}
		it = m.erase(it);
	}
}

int main() {
	ifstream input("input.txt");

	// storage for all sequences
	map<string, string> circuit;
	// final result
	map<string, unsigned short> result;

	string line;
	string del = " -> ";

	// input all sequences
	while (getline(input, line)) {
		// split string
		auto pos = line.find(del);

		// input string
		string cmd = line.substr(0, pos);
		// output
		string output = line.substr(pos + del.length());

		// process initialization
		if (isDigits(cmd)) {
			result[output] = static_cast<unsigned short>(stoul(cmd));
		}
		else {
			// initial circuit info
			circuit[output] = cmd;
		}
	}

	while (!circuit.empty()) {
		operation(circuit, result);
	}

	input.close();

	cout << result["a"] << endl;

	return 0;
}
