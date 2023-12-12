//https://leetcode.com/problems/longest-repeating-character-replacement/
// #SlidingWindow #Hashing
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxFreq=0,l=0,r=0,maxlen=0;
        unordered_map<char,int> map;
        while(r<s.size()){
            map[s[r]]++;
            maxFreq=max(maxFreq,map[s[r]]);
            while(((r-l+1)-maxFreq)>k ){
                map[s[l]]--;
                l++;
            }
            maxlen = max(maxlen,(r-l+1));
            r++;
        }
        return maxlen;
    }

};