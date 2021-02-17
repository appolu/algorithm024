//https://leetcode-cn.com/problems/generate-parentheses/
class Solution {
public:
    vector<string> results;
    vector<string> generateParenthesis(int n) {
        gp(n,"",0,0);
        return results;
    }

    void gp(int n,string s,int left,int right){
        if(left==n && right==left){
            results.push_back(s);
        }
        if(left<n){
            gp(n,s+"(",left+1,right);
        }
        if(right<left){
            gp(n,s+")",left,right+1);
        }
    }
};