#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct Edge {
    string from, to;
    double weight;
    Edge(string from, string to, double weight) : from(from), to(to), weight(weight) {}
};

struct Node {
    string name;
    double distance;
    Node(string name, double distance) : name(name), distance(distance) {}
};

struct CompareNode {
    bool operator()(const Node& n1, const Node& n2) {
        return n1.distance > n2.distance;
    }
};

vector<string> dijkstra(unordered_map<string, vector<pair<string, ll>>>& graph, string start, string goal) {
    priority_queue<Node, vector<Node>, CompareNode> pq;
    unordered_map<string, double> distances;
    unordered_map<string, string> previous;

    for (const auto& node : graph) {
        distances[node.first] = numeric_limits<double>::infinity();
    }
    distances[start] = 0;

    pq.push(Node(start, 0));

    while (!pq.empty()) {
        Node current = pq.top();
        pq.pop();

        if (current.name == goal) {
            break;
        }

        if (current.distance > distances[current.name]) {
            continue;
        }

        for (const auto& neighbor : graph[current.name]) {
            double newDistance = distances[current.name] + neighbor.second;
            if (newDistance < distances[neighbor.first]) {
                distances[neighbor.first] = newDistance;
                previous[neighbor.first] = current.name;
                pq.push(Node(neighbor.first, newDistance));
            }
        }
    }

    vector<string> path;
    string current = goal;
    while (current != start) {
        path.push_back(current);
        if (previous.find(current) == previous.end()) {
            return {};
        }
        current = previous[current];
    }
    path.push_back(start);
    reverse(path.begin(), path.end());

    return path;
}

int main() {
    vector<Edge> edges = {
        {"Hall 11", "Hall 10", 200},
        {"Hall 11", "Events Ground", 160},
        {"Hall 10", "Hall 9", 180},
        {"Hall 10", "p5", 175},
        {"Events Ground", "Hall 8", 80},
        {"Events Ground", "Pronite Ground", 160},
        {"Hall 8", "p5", 50},
        {"Hall 8", "Open Air Theatre", 80},
        {"Hall 9", "p2", 180},
        {"p2", "p3", 170},
        {"Pronite Ground", "New Shopping Complex", 80},
        {"Open Air Theatre", "p6", 160},
        {"Hall 4", "Hall 3", 100},
        {"Hall 4", "p4", 243},
        {"Hall 4", "p6", 140},
        {"Hall 13", "Hall 12", 150},
        {"Hall 13", "p2", 100},
        {"Hall 12", "p1", 280},
        {"Hall 2", "Hall 1", 75},
        {"Hall 2", "p7", 170},
        {"Hall 2", "p1", 180},
        {"Hall 5", "p3", 245},
        {"Hall 5", "p8", 88},
        {"Hall 5", "Hall 1", 89},
        {"Hall 1", "p8", 75},
        {"Hall 3", "p8", 100},
        {"Hall 3", "Girls Hostel 1", 170},
        {"New Shopping Complex", "p6", 80},
        {"New Shopping Complex", "Health Centre", 300},
        {"Kargil Chowk", "p7", 250},
        {"Kargil Chowk", "p9", 250},
        {"Girls Hostel 1", "p7", 250},
        {"Girls Hostel 1", "p9", 250},
        {"Girls Hostel 1", "Health Centre", 345},
        {"Hall 6", "Health Centre", 100},
        {"Hall 6", "p10", 20},
        {"Counselling Services", "p9", 140},
        {"Counselling Services", "p10", 180},
    };

    unordered_map<string, vector<pair<string, ll>>> graph;

    for (auto edge : edges) {
        graph[edge.from].push_back(make_pair(edge.to, edge.weight));
        graph[edge.to].push_back(make_pair(edge.from, edge.weight));
    }

    string start, goal;
    cout << "Enter start node: ";
    getline(cin, start);
    cout << "Enter goal node: ";
    getline(cin, goal);

    vector<string> path = dijkstra(graph, start, goal);

    if (path.empty()) {
        cout << "No path found!" << endl;
    } else {
        cout << "Shortest path: ";
        for (const auto& node : path) {
            cout << node << " ";
        }
        cout << endl;

        // Calculate total distance
        double totalDistance = 0;
        for (int i = 0; i < path.size() - 1; ++i) {
            for (const auto& neighbor : graph[path[i]]) {
                if (neighbor.first == path[i+1]) {
                    totalDistance += neighbor.second;
                    break;
                }
            }
        }
        cout << "Total distance: " << totalDistance << endl;
    }

    return 0;
}