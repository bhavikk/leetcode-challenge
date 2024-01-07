// https://leetcode.com/problems/add-two-numbers/description/
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum=0,rem=0,carry=0;
        ListNode* dummy = new ListNode(0);
        ListNode* prev=dummy;
        // ListNode* result=prev;
        while(l1!=NULL || l2!=NULL){
            if(l1!=NULL && l2!=NULL){
                sum=l1->val+l2->val+carry;
                rem=sum-10;
                ListNode* newNode;
                if(rem>=0){
                    carry=1;
                    newNode = new ListNode(rem);
                }else{
                    carry=0;
                    newNode = new ListNode(sum);
                }
                prev->next = newNode;
                prev=newNode;
                // cout<<prev->next->val<<endl;
                l1=l1->next;
                l2=l2->next;
            }else{
                if(l1!=NULL){
                    sum=l1->val+carry;
                    rem=sum-10;
                    ListNode* newNode;
                    if(rem>=0){
                        carry=1;
                        newNode = new ListNode(rem);
                    }else{
                        carry=0;
                        newNode = new ListNode(sum);
                    }
                    prev->next = newNode;
                    prev=newNode;
                    l1=l1->next;
                }
                if(l2!=NULL){
                    sum=l2->val+carry;
                    rem=sum-10;
                    ListNode* newNode;
                    if(rem>=0){
                        carry=1;
                        newNode = new ListNode(rem);
                    }else{
                        carry=0;
                        newNode = new ListNode(sum);
                    }
                    prev->next = newNode;
                    prev=newNode;
                    l2=l2->next;
                }
            }
        }
        if(carry){
            prev->next = new ListNode(carry);
        }
        return dummy->next;
    }
};