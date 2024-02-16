// https://leetcode.com/problems/find-winner-on-a-tic-tac-toe-game/
#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        vector<vector<int>> grid ( 4 , vector<int> (4));
        for(int i=0;i<moves.size();i++){
            if(i%2==0)
                grid[moves[i][0]][moves[i][1]]=1;
            else
                grid[moves[i][0]][moves[i][1]]=2;
        }
        for(int i=0;i<3;i++){
            if(grid[i][0]==grid[i][1] && grid[i][1]==grid[i][2] && grid[i][2]!=0){
                return (grid[i][0]==1?"A":"B");
            }
            if(grid[0][i]==grid[1][i] && grid[1][i]==grid[2][i] && grid[2][i]!=0){
                return (grid[0][i]==1?"A":"B");
            }
        }
        if(grid[0][0]==grid[1][1] && grid[1][1]==grid[2][2] && grid[2][2]!=0){
            return (grid[1][1]==1?"A":"B");
        }
        if(grid[0][2]==grid[1][1] && grid[1][1]==grid[2][0] && grid[2][0]!=0){
            return (grid[1][1]==1?"A":"B");
        }
        if(moves.size()!=9) return "Pending";
        return "Draw";
    }
};