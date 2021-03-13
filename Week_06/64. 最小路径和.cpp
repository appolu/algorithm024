//https://leetcode-cn.com/problems/minimum-path-sum/
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> results=grid;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(i==0){
                    if(j==0){
                        results[i][j]=grid[i][j];
                    }else{
                        results[i][j]=results[i][j-1]+grid[i][j];
                    }
                    continue;
                }
                if(j==0){
                    results[i][j]=results[i-1][j]+grid[i][j];
                    continue;
                }
                results[i][j]=min(results[i-1][j]+grid[i][j],results[i][j-1]+grid[i][j]);
            }
        }
        int result=results[grid.size()-1][grid[0].size()-1];
        return result;
    }
};