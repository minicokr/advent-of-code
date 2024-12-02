#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
#include <climits>
#include <map>
#include <set>

#define N 8

using namespace std;

typedef pair<string, string> CityPair;
typedef pair<CityPair, int> Route;
typedef vector<Route> RouteVector;
typedef map<string, bool> Visited;

int getMinimum(const RouteVector& routes, Visited& visited, const string& from, const int& dist, int visitedCount) {

    // all visited
    if (visitedCount == N) {
        return dist;
    }

    int minDist = INT_MAX;

    for (const auto& route : routes) {
        CityPair citypair = route.first;

        // to exists & still to visit
        if (citypair.first == from && !visited[citypair.second]) {
            // visit
            visited[citypair.second] = true;

            // recursively call next city
            int temp = getMinimum(routes, visited, citypair.second, dist + route.second, visitedCount + 1);  

            // update minimum 
            minDist = min(temp, minDist);

            // backtrack: unmark the city as visited
            visited[citypair.second] = false;
        }
    }

    return minDist;
}

int DFS(const RouteVector& routes, const string& from) {
    Visited visited;

    // visit the starting point
    visited[from] = true;

    return getMinimum(routes, visited, from, 0, 1);
}

int main() {
    ifstream input("input.txt");

    RouteVector routes;
    set<string> cities;

    string line;

    while (getline(input, line)) {
        stringstream ss(line);
        string from, to, ignore;
        int dist;

        ss >> from >> ignore >> to >> ignore >> dist;

        // add routes
        routes.push_back({{from, to}, dist});
        routes.push_back({{to, from}, dist});

        // collect all unique cities
        cities.insert(from);
        cities.insert(to);
    }

    input.close();

    int answer = INT_MAX;
    for (const string& city : cities) {
        int dist = DFS(routes, city);
        if (dist != INT_MAX) {  // Only consider valid distances
            answer = min(answer, dist);
        }
    }

    cout << answer << endl;

    return 0;
}

