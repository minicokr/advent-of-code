#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    int answer = 0;

    ifstream input("input.txt");

    vector<int> list1;
    vector<int> list2;
    
    string line;
    string del = "   ";

    while(getline(input, line)) {
        // parse input
        auto pos = line.find(del);
        int loc_id1 = stoi(line.substr(0, pos));
        int loc_id2 = stoi(line.substr(pos + del.length()));

        // add entry
        list1.push_back(loc_id1);
        list2.push_back(loc_id2);
    }

    input.close();
    
    // sort 
    sort(list1.begin(), list1.end());
    sort(list2.begin(), list2.end());

    for (size_t i = 0; i < list1.size(); i++) {
        answer += abs(list1[i] - list2[i]);
    }

    cout << answer << endl;

    return 0;
}
