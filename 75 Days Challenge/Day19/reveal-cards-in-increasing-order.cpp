// https://leetcode.com/problems/reveal-cards-in-increasing-order/
#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(),deck.end());
        vector<int> ans(deck.size());
        queue<int> q;
        for(int i=0;i<deck.size();i++)
            q.push(i);
        int flag=0;
        int i=0;
        while(!q.empty()){
            int idx;
            if(flag%2==0){
                idx=q.front();
                q.pop();
                ans[idx]=deck[i];
                i++;
            }
            else{
                idx=q.front();
                q.pop();
                q.push(idx);
            }
            flag++;
        }
        return ans;
    }
};