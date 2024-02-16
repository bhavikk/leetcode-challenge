// https://leetcode.com/problems/time-needed-to-buy-tickets/
#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int count=0;
        while(tickets[k]!=0){
            for(int i=0;i<tickets.size();i++) {
                if(tickets[i]!=0){
                    tickets[i]--;
                    count++;
                }
                if(i==k && tickets[i]==0){
                    return count;
                }
            } 
        }
        return 0;
    }
};