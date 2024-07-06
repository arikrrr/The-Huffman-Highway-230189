#include <bits/stdc++.h>

using namespace std;

void findAllPathsV(map<int, vector<int>>& graph, int start, int end, vector<int>& path, vector<vector<int>>& allPaths) {
    path.push_back(start);
    
    if (start == end) {
        allPaths.push_back(path);
    } else {
        for (int temp : graph[start]) {
            if (find(path.begin(), path.end(), temp) == path.end()) {
                findAllPathsV(graph, temp, end, path, allPaths);
            }
        }
    }
    path.pop_back();
}

int main() {
    map<int, vector<int>> graph;
    graph[0] = {1, 2, 4};
    graph[1] = {3};
    graph[2] = {3, 4, 6};
    graph[3] = {6};
    graph[4] = {2, 5};
    graph[5] = {2};
    graph[6] = {2, 7, 9};
    graph[7] = {9};
    graph[8] = {7};
    graph[9] = {8, 10};
    graph[10] = {9};

    int startNode = 0;
    int endNode = 0;

    vector<int> path;
    vector<vector<int>> allPaths;
    findAllPathsV(graph, startNode, endNode, path, allPaths);
    
    cout << "All paths from " << startNode << " to " << endNode << ":" << endl;
    for (auto path : allPaths) {
        for (auto node : path) {
            cout << node << " ";
        }
        cout << endl;
    }
    
    return 0;
}
