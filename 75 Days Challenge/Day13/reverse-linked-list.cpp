// https://leetcode.com/problems/reverse-linked-list/
#include <bits/stdc++.h>

using namespace std;
//  Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:

    ListNode* reverse(ListNode* node){
        if(node == NULL){
            return node;
        }
        if(node->next == NULL){
            return node;
        }
        ListNode* n=reverse(node->next);
        node->next->next = node;
        node->next=NULL;
        return n;
    }

    ListNode* reverseList(ListNode* head) {
        return reverse(head);
    }
};