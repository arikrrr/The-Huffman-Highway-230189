#include <bits/stdc++.h>
#define vi vector<int>
using namespace std;

int solve(vi a){
    int n = a.size();
    priority_queue<int,vi,greater<int>> pq;
    for(auto it: a) pq.push(it);
    int cost = 0;
    while(pq.size()>1){
        int x = pq.top();
        pq.pop();
        int y = pq.top();
        pq.pop();
        pq.push(x+y);
        cost+=x+y;
    }
    return cost;
}

int main(){
    vi a = {4,3,2,6};
    cout << solve(a);
    return 0;
}