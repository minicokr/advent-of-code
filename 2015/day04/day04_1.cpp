#include <iostream>
#include <fstream>
#include <openssl/md5.h>
#include <iomanip>
#include <sstream>

using namespace std;

string calculateMD5(const string& input) {
	// produce hex hash
    unsigned char result[MD5_DIGEST_LENGTH]; 
    MD5(reinterpret_cast<const unsigned char*>(input.c_str()), input.size(), result);

    // Convert hash to a hex string
    ostringstream oss;
    for (int i = 0; i < MD5_DIGEST_LENGTH; ++i) {
        oss << hex << setw(2) << setfill('0') << static_cast<int>(result[i]);
    }
    return oss.str();
}

int main() {
	ifstream input("input.txt");

	string s;
	while (getline(input, s)) {
		// number to be appended
		unsigned int num = 0;

		// original string
		string original_s = s;

		while (true) {
			// hashed value
			string hashed = calculateMD5(s);

			// starts with 00000
			if (hashed.compare(0, 5, "00000") == 0) {
				break;
			}
			// try with increased value
			else {
				// increase by 1
				// append number
				s = original_s + to_string(++num);
			}
		}
		cout << num << endl;
	}

	input.close();

	return 0;
}
