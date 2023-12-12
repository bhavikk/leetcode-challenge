//https://leetcode.com/problems/sliding-window-maximum/
// #SlidingWindow #HARD #MonotoneousDecreasing
#include<bits/stdc++.h>

using namespace std;
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> maxArr;
        deque<int> dq;
        for(int i=0;i<nums.size();i++){
            while(!dq.empty() && dq.front()<(i-k+1)) dq.pop_front();
            while(!dq.empty() && nums[dq.back()]<nums[i]) dq.pop_back();
            dq.push_back(i);
            if(i>=k-1) maxArr.push_back(nums[dq.front()]);
        }
        return maxArr;
    }
};