#include <iostream>
using namespace std;

struct Node{
    int val;
    struct Node* right;
    struct Node* left;
};

bool check_isomorphic(Node* n1, Node* n2){
    if (n1 == NULL && n2 == NULL) return true;
    if (n1 == NULL || n2 == NULL) return false;
    return check_isomorphic(n1->left, n2->left) && check_isomorphic(n1->right, n2->right);
}