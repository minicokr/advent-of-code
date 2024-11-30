#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream input("input.txt");

    string line;
    int memory_cnt = 0;
    int literal_cnt = 0;
    while (getline(input, line)) {
        // start by counting " "
        literal_cnt += line.length();
        
        for (size_t i = 1; i < line.length() - 1; i++) {
            // backslash
            if (line[i] == '\\' && i + 1 != line.length() - 1) {
                // case 1: backslash + "
                // case 2: backslash + backslash
                if (line[i + 1] == '"' || line[i + 1] == '\\') {
                    // skip "
                    i++;
                }
                // case 3: backslash + x + two digits
                else if (line[i + 1] == 'x') {
                    // skip x + two digits
                    i += 3;
                }
            }
            memory_cnt++;
        }
    }

    input.close();

    cout << literal_cnt - memory_cnt << endl;
  
    return 0;
}

