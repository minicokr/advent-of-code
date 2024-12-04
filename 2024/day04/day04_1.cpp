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
            // horizontal
            // xmas
            if (i + 3 < row_num && words[i][j] == 'X' && words[i + 1][j] == 'M' && words[i + 2][j] == 'A' && words[i + 3][j] == 'S')
                answer++;
            // samx
            else if (i + 3 < row_num && words[i][j] == 'S' && words[i + 1][j] == 'A' && words[i + 2][j] == 'M' && words[i + 3][j] == 'X')
                answer++;

            // vertical
            // xmas
            if (j + 3 < col_num && words[i][j] == 'X' && words[i][j + 1] == 'M' && words[i][j + 2] == 'A' && words[i][j + 3] == 'S')
                answer++;
            // samx
            else if (j + 3 < col_num && words[i][j] == 'S' && words[i][j + 1] == 'A' && words[i][j + 2] == 'M' && words[i][j + 3] == 'X')
                answer++;

            // diagonal \
            // xmas
            if (i + 3 < row_num && j + 3 < col_num && words[i][j] == 'X' && words[i + 1][j + 1] == 'M' && words[i + 2][j + 2] == 'A' && words[i + 3][j + 3] == 'S')
                answer++;
            // samx
            else if (i + 3 < row_num && j + 3 < col_num && words[i][j] == 'S' && words[i + 1][j + 1] == 'A' && words[i + 2][j + 2] == 'M' && words[i + 3][j + 3] == 'X')
                answer++;

            // diagonal /
            if (i + 3 < row_num && 0 <= j - 3 && words[i][j] == 'X' && words[i + 1][j - 1] == 'M' && words[i + 2][j - 2] == 'A' && words[i + 3][j - 3] == 'S')
                answer++;
            else if (i + 3 < row_num && 0 <= j - 3 && words[i][j] == 'S' && words[i + 1][j - 1] == 'A' && words[i + 2][j - 2] == 'M' && words[i + 3][j - 3] == 'X')
                answer++;
        }
    }

    cout << answer << endl;

    return 0;
}
