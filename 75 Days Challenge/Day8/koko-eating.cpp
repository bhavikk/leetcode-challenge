//https://leetcode.com/problems/koko-eating-bananas/
// #binarysearch
#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    int calHours(vector<int>& piles,long k){
        long h=0;
        for(int i: piles){
            h+=ceil((double)i/(double)k);
        }
        return h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        long sum=0;
        for( int i : piles){
            sum+=i;
        }
        long l=1,r=sum;
        while(l<r){
            long mid=l+(r-l)/2;
            long nh=calHours(piles,mid);
            if(nh>h){
                l=mid+1;
            }else{
                r=mid;
            }
            
        }
        return r;
    }
};
