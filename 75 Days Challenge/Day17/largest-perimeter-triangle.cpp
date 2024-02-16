// https://leetcode.com/problems/largest-perimeter-triangle/
#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end(), greater<int>());
        int a=nums[0],b=nums[1],c=nums[2];
        if(a+b>c && a+c>b && b+c>a){
            return a+b+c;
        }
        for(int i=3;i<nums.size();i++){
            if(a+b>c && a+c>b && b+c>a){
                return a+b+c;
            }
            if(a+b<=c){
                c=nums[i];
                continue;
            }
            if(a+c<=b){
                b=nums[i];
                continue;
            }
            if(b+c<=a){
                a=nums[i];
                continue;
            }
        }
        if(a+b>c && a+c>b && b+c>a){
            return a+b+c;
        }
        return 0;
    }
};