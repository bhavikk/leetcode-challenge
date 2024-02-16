// https://leetcode.com/problems/implement-queue-using-stacks/
#include <bits/stdc++.h>

using namespace std;
class MyQueue {
public:
    stack<int> a,b;
    MyQueue() {
        
    }
    
    void push(int x) {
        a.push(x);
    }
    
    int pop() {
        int ans;
        if(!b.empty()){
            ans=b.top();
            b.pop();
        }
        else{
            while(!a.empty())
            {
                b.push(a.top());
                a.pop();
            }
            ans=b.top();
            b.pop();
        }
        return ans;
    }
    
    int peek() {
        int ans;
        if(!b.empty()){
            ans=b.top();
        }
        else{
            while(!a.empty())
            {
                b.push(a.top());
                a.pop();
            }
            ans=b.top();
        }
        return ans;
    }
    
    bool empty() {
        return a.empty() && b.empty() ;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */