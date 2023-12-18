// https://leetcode.com/problems/search-a-2d-matrix/
// #binarysearch
#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i=0;
        for(i=0;i<matrix.size();i++){
            if(target>=matrix[i][0] && target<=matrix[i][matrix[i].size()-1]){
                break;
            }
        }
        if(i>=matrix.size()) return false;
        int l=0,r=matrix[i].size()-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(matrix[i][mid]==target){
                return true;
            }
            if(matrix[i][mid]<target){
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        return false;
    }
};