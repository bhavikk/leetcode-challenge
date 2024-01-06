// https://leetcode.com/problems/reorder-list/
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
    ListNode* reverse(ListNode* head){
        
        ListNode* curr=head;
        ListNode* prev=NULL;
        ListNode* nxt=curr->next;
        while(curr!=NULL){
            nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        if(head->next==NULL){
            return;
        }
        ListNode* fast=head->next;
        ListNode* slow=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* first=head;
        ListNode* second=slow->next;
        second=reverse(second);
        slow->next=NULL;

        while(second!=NULL){
            ListNode* temp1=first->next;
            first->next=second;
            ListNode* temp2=second->next;
            second->next=temp1;
            first=temp1;
            second=temp2;
        }
    }
};