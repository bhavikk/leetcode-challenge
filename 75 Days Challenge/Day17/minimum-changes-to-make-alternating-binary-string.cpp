// https://leetcode.com/problems/minimum-changes-to-make-alternating-binary-string/
#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    int minOperations(string s) {
        int ans0=0,ans1=0;
        for(int i=0;i<s.size();i++){
            if(i%2==0 && s[i]=='1'){
                ans0++;
            }
            if(i%2!=0 && s[i]=='0'){
                ans0++;
            }
            
        }
        //even1 and odd0
        for(int i=0;i<s.size();i++){
            if(i%2==0 && s[i]=='0'){
                ans1++;
            }
            if(i%2!=0 && s[i]=='1'){
                ans1++;
            }
            
        }
        return min(ans0,ans1);
    }
};