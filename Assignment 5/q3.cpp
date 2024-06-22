#include <bits/stdc++.h>
#define vi vector<int>
#define vvi vector<vi>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode():
    val(0),left(nullptr),right(nullptr) {}

    TreeNode(int x):
    val(x),left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode* left, TreeNode* right):
    val(x), left(left), right(right) {}
};
void makeMapping(map<TreeNode*,TreeNode*> &parent,TreeNode* root,TreeNode* &target,int t){
    if(root==nullptr)
        return;
    if(root->val==t)
        target=root;
    if(root->left){
        parent[root->left]=root;
        makeMapping(parent,root->left,target,t);
    }
    if(root->right){
        parent[root->right]=root;
        makeMapping(parent,root->right,target,t);
    }
}

void traverse(TreeNode* start, map<TreeNode*,TreeNode*> &parent, int s, TreeNode* prev, int mn,int mx,int sum, vector<int>& ans){

    if(start==nullptr) return;

    if(start->val == s){
        mn = min(mn, start->val);
        mx = max(mx, start->val);
        sum+=start->val;
        ans.push_back(mn);
        ans.push_back(mx);
        ans.push_back(sum);
        return;
    }

    if(start->left != prev)
    traverse(start->left, parent, s, start, min(mn,start->val), max(mx,start->val), sum+start->val, ans);
    if(start->right != prev)
    traverse(start->right, parent, s, start, min(mn,start->val), max(mx,start->val), sum+start->val, ans);
    if(parent[start] != prev)
    traverse(parent[start], parent, s, start, min(mn,start->val), max(mx,start->val), sum+start->val, ans);
}

vector<int> solve(pair<int,int> p,TreeNode* root){
    map<TreeNode*,TreeNode*> parent;
    parent[root] = nullptr;
    TreeNode* target;
    TreeNode* prev = nullptr;
    makeMapping(parent, root, target, p.first);
    vi v;
    traverse(target, parent, p.second, prev, INT_MAX, INT_MIN, 0, v);
    return v;
}

vvi TreePathQueries(vector<pair<int,int> > p, TreeNode* root){
    vvi answer;
    for(auto it: p){
        vi mkc = solve(it, root);
        answer.push_back(mkc);
    }
    return answer;
}
int main(){
    return 0;
}