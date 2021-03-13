//https://leetcode-cn.com/problems/longest-valid-parentheses/
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> pStatck;
        int xmax=0;
        pStatck.push(-1);
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                pStatck.push(i);
            }else{
                pStatck.pop();
                if(pStatck.empty()){
                    pStatck.push(i);
                }else{

                    int index= pStatck.top();
                     xmax=max(xmax,i-index);
                }
            }            

        }

        return xmax;
    }
};