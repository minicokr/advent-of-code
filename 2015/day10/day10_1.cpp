#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    // process input
    ifstream input("input.txt");
    string line;
    getline(input, line);
    input.close();

    // repetition
    int rep = 40;

    // look and say
    string look_and_say; 
    for (int i = 0; i < rep; i++) {
        // previous character
        char c_prev = line[0];
        int cnt = 1;

        for (size_t j = 1; j < line.size(); j++) {
            if (c_prev == line[j]) {
                // count up
                cnt++;
            }
            else {
                // update
                look_and_say += (to_string(cnt) + c_prev);

                // initialize
                cnt = 1;
            }
            c_prev = line[j];
        }
        // last update
        look_and_say += (to_string(cnt) + c_prev);

        // update line
        line = look_and_say;
        look_and_say = "";
    }

    cout << line.length() << endl;

    return 0;
}
