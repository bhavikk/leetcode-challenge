// https://leetcode.com/problems/median-of-two-sorted-arrays/
#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()>nums2.size()){
            return findMedianSortedArrays(nums2,nums1);
        }
        int m=nums1.size();
        int n=nums2.size();
        int l=0,r=m;
        while(l<=r){
            int x1=l+(r-l)/2;
            int y1=(m+n+1)/2-x1;

            int dx1=(x1==0) ? INT_MIN : nums1[x1-1];
            int dy1=(y1==0) ? INT_MIN : nums2[y1-1];
            int dx2=(x1==m) ? INT_MAX : nums1[x1];
            int dy2=(y1==n) ? INT_MAX : nums2[y1];

            if(dy1<=dx2 && dx1<=dy2){
                if((m+n)%2==1){
                    return max(dx1,dy1);
                }
                else{
                    return (max(dx1,dy1)+min(dx2,dy2))/2.0;
                }
            }
            if(dx1>dy2){
                r=x1-1;
            }else{
                l=x1+1;
            }
        }
        return -1;
    }
};