//https://leetcode.com/problems/longest-substring-without-repeating-characters/
// #SlidingWindow #Hashing
#include<bits/stdc++.h>

using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0,j=0;
        unordered_map<char,int> map;
        int maxcnt=0,count=0;
        while(j<s.size()){
            if(map.contains(s[j])){
                i=max(map[s[j]]+1,i);
            }
            map[s[j]]=j;
            maxcnt=max(j-i+1,maxcnt);
            j++;
        }
        return maxcnt;
    }
};