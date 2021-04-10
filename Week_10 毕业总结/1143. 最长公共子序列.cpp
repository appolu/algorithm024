//https://leetcode-cn.com/problems/longest-common-subsequence/
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int result=0;
        int m=text1.length();
        int n=text2.length();
        vector<vector<int>> matrix(m+1,vector<int>(n+1));
        for(int i=1;i<=m;i++){
            char c1=text1[i-1];
            for(int j=1;j<=n;j++){
                char c2=text2[j-1];
                if(c1==c2){
                    matrix[i][j]=matrix[i-1][j-1]+1;
                }else{
                    matrix[i][j]=max(matrix[i-1][j],matrix[i][j-1]);
                }
            }
        }
        return matrix[m][n];
    }

};