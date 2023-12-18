//https://leetcode.com/problems/daily-temperatures/
// #Stack
/*
    When there is to find next greater, next smaller, prev greater, prev smaller it is probably stack
*/
#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> stack;
        vector<int> result(temperatures.size(),0);
        for(int i=temperatures.size()-1;i>=0;i--){
            if(stack.empty()){
                stack.push(i);
                result[i]=0;
            }
            else{
                if(temperatures[stack.top()]<=temperatures[i]){
                    while( (!stack.empty()) && temperatures[stack.top()]<=temperatures[i]){
                        stack.pop();
                    }
                    if(stack.empty()){
                        result[i]=0;
                        stack.push(i);
                    }else{
                        
                        result[i]=stack.top()-i;
                        stack.push(i);
                    }
                }
                else{
                    result[i]=stack.top()-i;
                    stack.push(i);
                }
            }
        }
        return result;
    }
};