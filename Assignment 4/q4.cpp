#include <bits/stdc++.h>

struct Node{
    int val;
    struct Node* next;
};
    int lengthLL(Node* head) {
        int l = 0;
        Node* temp = head;
        while(temp != NULL) {
            l++;
            temp = temp->next;
        }
        return l;
    }
    Node* rotateRight(Node* head, int k) {
        if(head == NULL || head->next == NULL || k == 0) return head;

        int length = lengthLL(head);
        k = k % length;
        if (k == 0) return head;

        Node* temp = head;
        for (int i = 0; i < length - k - 1; i++) {
            temp = temp->next;
        }

        Node* newHead = temp->next;
        temp->next = NULL;
        Node* tail = newHead;
        while (tail->next != NULL) {
            tail = tail->next;
        }
        tail->next = head;

        return newHead;
    }