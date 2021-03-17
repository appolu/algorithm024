//https://leetcode-cn.com/problems/generate-parentheses/
class Solution {
public:
    vector<string> result;
    vector<string> generateParenthesis(int n) {
        //gp("",0,0,n);
        vector< vector<string>> dp1(n+1);
        dp1[0]={""};
        dp1[1]={"()"};

        for(int i=2;i<=n;i++){
            for(int j=0;j<i;j++){
                for(string s:dp1[j]){
                    for(string p:dp1[i-j-1]){
                        dp1[i].push_back("("+s+")"+p);
                    }
                }     
            }
        }
        return dp1[n];
    }

    void gp(string p,int left,int right,int n){
        if(left>=n && left==right){
            result.push_back(p);
            return;
        }
        if(left<n){
            gp(p+"(",left+1,right,n);
        }

        if(right<left){
            gp(p+")",left,right+1,n);
        }
    }

};