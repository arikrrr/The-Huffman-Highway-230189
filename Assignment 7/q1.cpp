#include <bits/stdc++.h>
using namespace std;

int maxProjectValue(int N, vector<int>& values, vector<vector<string>>& required_languages, set<string>& known_languages) {
    vector<int> dp(1 << N, 0);
    for (int mask = 1; mask < (1 << N); mask++) {
        for (int i = 0; i < N; i++) {
            if (mask & (1 << i)) {  
                bool can_do_project = true;
                for (const string& lang : required_languages[i]) {
                    if (known_languages.find(lang) == known_languages.end()) {
                        can_do_project = false;
                        break;
                    }
                }
                if (can_do_project) {
                    int prev_mask = mask ^ (1 << i); 
                    dp[mask] = max(dp[mask], dp[prev_mask] + values[i]);
                }
            }
        }
    }
    return dp[(1 << N) - 1];
}

int main() {
    int N = 10;
    vector<int> values = {50, 30, 70, 20, 90, 10, 60, 40, 80, 100};
    vector<vector<string>> required_languages = {
        {"Python", "C++"}, {"Java", "Python"}, {"C++", "Java", "Python"},
        {"Python"}, {"Java", "Go"}, {"C++"}, {"Python", "Go"},
        {"C++", "Python"}, {"Java", "Python", "Go"}, {"C++", "Java", "Go"}
    };
    set<string> known_languages = {"Python", "C++", "Java"};
    
    int result = maxProjectValue(N, values, required_languages, known_languages);
    cout << "Maximum Project Value: " << result << endl;
    return 0;
}