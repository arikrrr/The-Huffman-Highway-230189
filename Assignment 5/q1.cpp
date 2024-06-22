#include <bits/stdc++.h>
#define vi vector<int>
using namespace std;

int solve(vi arrive, vi depart){
    int ans = 0, v = 0;
    int n = arrive.size();

    sort(arrive.begin(), arrive.end());
    sort(depart.begin(), depart.end());

    int i = 0, j = 0;

    while (i < n && j < n){
        if (arrive[i] <= depart[j]){
            v++;
            i++;
        }
        else{
            v--;
            j++;
        }
        ans = max(ans, v);
    }

    return ans;
}

int main()
{
    vi a = {900, 940, 950, 1100, 1500, 1800};
    vi b = {910, 1200, 1120, 1130, 1900, 2000};
    cout << solve(a, b);
    return 0;
}