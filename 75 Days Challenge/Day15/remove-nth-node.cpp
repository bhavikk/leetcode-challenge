// https://leetcode.com/problems/remove-nth-node-from-end-of-list/
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next==NULL && n==1){
            return NULL;
        }
        ListNode* slow=head;
        ListNode* fast=head;
        while(n--){
            fast=fast->next;
        }        
        ListNode* prev;
        while(fast!=NULL){
            prev=slow;
            slow=slow->next;
            fast=fast->next;
        }
        if(slow==head){
            return slow->next;
        }
        prev->next=slow->next;
        return head;
    }
};