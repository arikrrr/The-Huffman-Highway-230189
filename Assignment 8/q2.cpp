#include <bits/stdc++.h>
using namespace std;

int knapsack(int N, int W, vector<int>& weights, vector<int>& values, vector<int>& dependencies, 
             vector<int>& categories, vector<int>& limits) {
    int num_categories = *max_element(categories.begin(), categories.end()) + 1;
    
    vector<vector<vector<int>>> dp(N + 1, vector<vector<int>>(
        W + 1, vector<int>(1 << num_categories, -1)));
    
    function<int(int, int, int)> solve = [&](int i, int w, int c) -> int {
        if (i == N) return 0;
        
        if (dp[i][w][c] != -1) return dp[i][w][c];
        
        int &res = dp[i][w][c];
        res = solve(i + 1, w, c);
        
        if (w >= weights[i] && !(c & (1 << categories[i]))) {
            // Check dependency
            bool can_take = (dependencies[i] == -1 || (c & (1 << categories[dependencies[i]])));
            
            if (can_take) {
                int new_c = c | (1 << categories[i]);
                for (int count = 1; count <= limits[i] && count * weights[i] <= w; ++count) {
                    res = max(res, count * values[i] + solve(i + 1, w - count * weights[i], new_c));
                }
            }
        }
        
        return res;
    };
    
    return solve(0, W, 0);
}

int main() {
    int N = 10;
    int W = 100;
    vector<int> weights = {10, 20, 30, 40, 15, 25, 35, 45, 55, 50};
    vector<int> values = {60, 100, 120, 240, 150, 90, 200, 170, 250, 300};
    vector<int> dependencies = {-1, 0, -1, 2, -1, -1, 1, 4, -1, 7};
    vector<int> categories = {1, 0, 0, 1, 2, 2, 3, 3, 4, 4};
    vector<int> limits = {1, 2, 1, 1, 1, 1, 1, 1, 1, 1};
    
    int result = knapsack(N, W, weights, values, dependencies, categories, limits);
    cout << "Maximum Knapsack Value: " << result << endl;
    return 0;
}