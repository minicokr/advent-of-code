#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int answer = 0;
    vector<vector<char>> words;

    // get inputs
    ifstream input("input.txt");
    string line;
    while (getline(input, line)) {
        vector<char> row(line.begin(), line.end());
        words.push_back(row);
    }
    input.close();

    size_t row_num = words.size();
    size_t col_num = words[0].size();
        
    for (size_t i = 0; i < row_num; i++) {
        for (size_t j = 0; j < col_num; j++) {
            if (i + 2 < row_num && j + 2 < col_num) {
                // M M
                //  A
                // S S
                if (words[i][j] == 'M' && words[i][j + 2] == 'M' && words[i + 1][j + 1] == 'A' && words[i + 2][j] == 'S' && words[i + 2][j + 2] == 'S')  
                    answer++;
                // M S
                //  A
                // M S
                else if (words[i][j] == 'M' && words[i][j + 2] == 'S' && words[i + 1][j + 1] == 'A' && words[i + 2][j] == 'M' && words[i + 2][j + 2] == 'S')  
                    answer++;
                // S M
                //  A
                // S M
                else if (words[i][j] == 'S' && words[i][j + 2] == 'M' && words[i + 1][j + 1] == 'A' && words[i + 2][j] == 'S' && words[i + 2][j + 2] == 'M')  
                    answer++;
                // S S
                //  A
                // M M
                else if (words[i][j] == 'S' && words[i][j + 2] == 'S' && words[i + 1][j + 1] == 'A' && words[i + 2][j] == 'M' && words[i + 2][j + 2] == 'M')  
                    answer++;
            }
        }
    }

    cout << answer << endl;

    return 0;
}
