#include <bits/stdc++.h>
using namespace std;

void PathExist(map<int , vector<int>>& graph, int size, vector<int>& path, int curr, bool& truth) {
    path.push_back(curr);
    if (path.size() == size) {
        truth = true;
    } else {
        for (auto temp : graph[curr]) {
            if (find(path.begin(), path.end(), temp) == path.end()) {
                PathExist(graph, size, path, temp, truth);
                if (truth) return;
            }
        }
    }
    path.pop_back();
}

bool HamilPathExist(map<int , vector<int>>& graph) {
    int size = graph.size();
    for (auto it : graph) {
        bool truth = false;
        vector<int> path;
        PathExist(graph, size, path, it.first, truth);
        if (truth) return true;
    }
    return false;
}

void CycleExist(map<int , vector<int>>& graph, int size, vector<int>& path, int curr, bool& truth, int end, int check) {
    path.push_back(curr);
    for (int temp : graph[curr]) {
        if (temp == end && curr != check) {
            truth = true;
            return;
        }
        if (find(path.begin(), path.end(), temp) == path.end()) {
            CycleExist(graph, size, path, temp, truth, end, check);
            if (truth) return;
        }
    }
    path.pop_back();
}

bool HamilCycleExist(map<int , vector<int>>& graph) {
    int size = graph.size();
    for (auto it : graph) {
        bool truth = false;
        vector<int> path;
        path.push_back(it.first);
        for (auto v : graph[it.first]) {
            CycleExist(graph, size, path, v, truth, it.first, v);
            if (truth) return true;
        }
    }
    return false;
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

    // graph[0] = {1,2};
    // graph[1] = {0,2,3};
    // graph[2] = {0,1};
    // graph[3] = {1};

    if (HamilPathExist(graph)) {
        cout << "Hamiltonian Path exist" << endl;
    } else {
        cout << "Hamiltonian Path does not exist" << endl;
    }

    if (HamilCycleExist(graph)) {
        cout << "Hamiltonian Circuit/Cycle exist" << endl;
    } else {
        cout << "Hamiltonian Circuit/Cycle does not exist" << endl;
    }

    return 0;
}
