#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int answer = 0;

    ifstream input("input.txt");

    vector<int> list1;
    vector<int> list2;
    unordered_map<int, int> countDups;
    
    string line;

    while(getline(input, line)) {
        // parse input
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

    for_each(list2.begin(), list2.end(), [&countDups](int num) {
        countDups[num]++;
    });

    for (const auto& val_to_find : list1) {
        int count = countDups[val_to_find];
        answer += (val_to_find * count);
    }

    cout << answer << endl;

    return 0;
}
