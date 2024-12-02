#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
    int answer = 0;

    ifstream input("input.txt");

    vector<int> list1;
    vector<int> list2;
    
    string line;
    string del = "   ";

    while (getline(input, line)) {
        // parse input using istringstream
        istringstream iss(line);
        int loc_id1, loc_id2;
        iss >> loc_id1 >> loc_id2;

        // add entry
        list1.emplace_back(loc_id1);
        list2.emplace_back(loc_id2);
    }

    input.close();
    
    // sort 
    sort(list1.begin(), list1.end());
    sort(list2.begin(), list2.end());

    // calculate the answer using transform and inner_product
    answer = inner_product(list1.begin(), list1.end(), list2.begin(), 0, plus<>(), [](int a, int b) {
        return abs(a - b);
    });

    cout << answer << endl;

    return 0;
}
