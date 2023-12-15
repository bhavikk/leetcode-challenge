//https://leetcode.com/problems/evaluate-reverse-polish-notation/description/
#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stack;
        for(int i=0;i<tokens.size();i++){
            int f=0;
            if(!(tokens[i]=="+" || tokens[i]=="*" ||tokens[i]=="-" ||tokens[i]=="/")){
                stack.push(stoi(tokens[i]));
            }
            else{
                int b=stack.top();
                stack.pop();
                int a=stack.top();
                stack.pop();
                if(tokens[i]=="+"){
                    stack.push(a+b);
                }
                if(tokens[i]=="*"){
                    stack.push(a*b);
                }
                if(tokens[i]=="/"){
                    stack.push(a/b);
                }
                if(tokens[i]=="-"){
                    stack.push(a-b);
                }
            }
            
        }
        return stack.top();
    }
};