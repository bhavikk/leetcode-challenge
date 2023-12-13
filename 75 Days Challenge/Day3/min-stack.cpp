//https://leetcode.com/problems/min-stack/

#include<bits/stdc++.h>

using namespace std;
class MinStack {
public:
    long min=INT_MAX;
    stack<long> stack;
    MinStack() {
        
    }
    
    void push(int val) {
        if(min<val){
            stack.push(val);
        }
        else{
            stack.push(((long)2*val)-min);
            min=val;
        }
    
    }
    
    void pop() {
        long val=stack.top();
        stack.pop();
        if(val<min){
            min=(long)2*min-val;
        }
    }
    
    int top() {
        long val=stack.top();
        if(val<min){
            return min;
        }
        return val;
    }
    
    int getMin() {
        return min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */