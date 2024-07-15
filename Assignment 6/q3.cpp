#include <bits/stdc++.h>

using namespace std;

bool isValid(int x, int y, int z, int X, int Y, int Z, const vector<vector<vector<int>>>& grid) {
    return 0 <= x && x < X && 0 <= y && y < Y && 0 <= z && z < Z && grid[x][y][z] == 0;
}

int shortestPath(int X, int Y, int Z, int xs, int ys, int zs, int xd, int yd, int zd, const vector<vector<vector<int>>>& grid) {
    
    vector<tuple<int, int, int>> directions = {
        make_tuple(-1, 0, 0), make_tuple(1, 0, 0), make_tuple(0, -1, 0), 
        make_tuple(0, 1, 0), make_tuple(0, 0, -1), make_tuple(0, 0, 1)
    };
    
    queue<tuple<int, int, int, int>> q;
    q.push(make_tuple(xs, ys, zs, 0));
    
    set<tuple<int, int, int>> visited;
    visited.insert(make_tuple(xs, ys, zs));
    
    while (!q.empty()) {
        int x = get<0>(q.front());
        int y = get<1>(q.front());
        int z = get<2>(q.front());
        int dist = get<3>(q.front());
        q.pop();


        if (x == xd && y == yd && z == zd) {
            return dist;
        }

        for (const auto& dir : directions) {
            int nx = x + get<0>(dir);
            int ny = y + get<1>(dir);
            int nz = z + get<2>(dir);
            
            if (isValid(nx, ny, nz, X, Y, Z, grid) && visited.find(make_tuple(nx, ny, nz)) == visited.end()) {
                visited.insert(make_tuple(nx, ny, nz));
                q.push(make_tuple(nx, ny, nz, dist + 1));
            }
        }
    }
    
    return -1;
}

int main() {
    int X, Y, Z;
    cin >> X >> Y >> Z;
    
    int xs, ys, zs, xd, yd, zd;
    cin >> xs >> ys >> zs >> xd >> yd >> zd;
    
    vector<vector<vector<int>>> grid(X, vector<vector<int>>(Y, vector<int>(Z)));
    
    for (int i = 0; i < X; ++i) {
        for (int j = 0; j < Y; ++j) {
            for (int k = 0; k < Z; ++k) {
                cin >> grid[i][j][k];
            }
        }
    }

    int result = shortestPath(X, Y, Z, xs, ys, zs, xd, yd, zd, grid);
    cout << result << endl;
    
    return 0;
}