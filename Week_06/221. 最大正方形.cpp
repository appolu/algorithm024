//https://leetcode-cn.com/problems/maximal-square/
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int maxsize=0;
        if(matrix.empty() || matrix[0].size()==0){
            return maxsize;
        }
        int row=matrix.size();
        int col=matrix[0].size();
        vector<vector<int>> mat;
        int maxwid=0;
        for(int i=0;i<row;i++){
            vector<int> cols(col,0);
            mat.push_back(cols);
            for(int j=0;j<col;j++){
                if(i==0 || j==0){
                    mat[i][j]=matrix[i][j]=='1'?1:0;

                }else{
                    if(matrix[i][j]=='1')
                        mat[i][j]=min(min(mat[i-1][j-1],mat[i-1][j]),mat[i][j-1])+1;
                }
                maxwid=maxwid>mat[i][j]?maxwid:mat[i][j];

            }
        }
        return maxwid*maxwid;
    }
};