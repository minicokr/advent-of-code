#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream input("input.txt");

    string line;
    int encoded_cnt = 0;
    int literal_cnt = 0;
    while (getline(input, line)) {
        // start by counting " "
        literal_cnt += line.length();
        // count " "
        encoded_cnt += 2;
        
        for (size_t i = 0; i < line.length(); i++) {
            // case 1: "
            // case 2: backslash
            if (line[i] == '"' || line[i] == '\\') {
                encoded_cnt++;
            }
            encoded_cnt++;
        }
    }

    input.close();

    cout << encoded_cnt - literal_cnt << endl;
  
    return 0;
}

