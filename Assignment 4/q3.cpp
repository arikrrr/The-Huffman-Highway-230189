#include <bits/stdc++.h>

using namespace std;

struct Node{
    int val;
    struct Node* next;
};

bool isPalindrome(Node* head) {
        vector<int> a;
        while(head!=NULL){
            a.push_back(head->val);
            head=head->next;
        }
        vector<int> b(a.rbegin(), a.rend());
        return b==a;
    }
// I have created a vector to store the values and used stl to reverse and check palindrome.