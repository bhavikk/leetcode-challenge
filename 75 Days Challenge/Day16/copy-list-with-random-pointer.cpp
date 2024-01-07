// https://leetcode.com/problems/copy-list-with-random-pointer/
#include <bits/stdc++.h>

using namespace std;
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* tempHead = head;
        map<Node* , Node*> map;
        Node* prev=NULL;
        Node* curr;
        Node* newHead=NULL;
        for(int i=0;head!=NULL;i++){
            curr = new Node(head->val);
            if(prev!=NULL) prev->next = curr;
            else newHead=curr;
            map[head]=curr;
            prev=curr;
            head=head->next;
        }
        head=tempHead;
        Node* result= newHead;
        for(int
         i=0;newHead!=NULL;i++){
            if(head->random!=NULL){
                cout<<head->val<<endl;
                newHead->random = map[head->random];
            }
            head=head->next;
            newHead=newHead->next;
        }
        return result;
    }
};