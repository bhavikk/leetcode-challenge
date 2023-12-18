//https://leetcode.com/problems/largest-rectangle-in-histogram/
//#stack
#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> stack;
        vector<int> left,right;
        int maxA=0;
        for(int i=0;i<heights.size();i++){
            if(stack.empty()){
                left.push_back(0);
            }
            else{
                if(heights[stack.top()]<heights[i]){
                    left.push_back(stack.top()+1);
                }else{
                    while(!(stack.empty()) && heights[stack.top()]>=heights[i]){
                        stack.pop();
                    }
                    if(stack.empty())
                        left.push_back(0);
                    else
                        left.push_back(stack.top()+1);
                }
            }
            stack.push(i);
        }
        while(!stack.empty())
            stack.pop();
        for(int i=heights.size()-1;i>=0;i--){
            if(stack.empty()){
                right.push_back(heights.size()-1);
            }
            else{
                if(heights[stack.top()]<heights[i]){
                    right.push_back(stack.top()-1);
                }else{
                    while( !(stack.empty()) && heights[stack.top()]>=heights[i]){
                        stack.pop();
                    }
                    if(stack.empty())
                        right.push_back(heights.size()-1);
                    else
                        right.push_back(stack.top()-1);
                }
            }
            stack.push(i);        
        }
        for(int i=0;i<heights.size();i++){
            maxA= max(maxA,heights[i]*(abs(left[i]-right[heights.size()-1-i])+1));
        }
        return maxA;
    }
};