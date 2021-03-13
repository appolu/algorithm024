//https://leetcode-cn.com/problems/decode-ways/
class Solution {
public:
    int numDecodings(string s) {
        if(s[0]=='0'){
            return 0;
        }
        int result=1;
        int prev=1;
        for(int i=1;i<s.length();i++){
            int tmp=result;
            if(s[i]=='0'){
                if(s[i-1]<='2' && s[i-1]>'0')
                {
                    result=prev;
                    continue;
                }else{
                    result=0;
                    break;
                }         
            }
            if(s[i-1]=='1'){
                result=result+prev;
            }
            if(s[i-1]=='2' && s[i]<='6'){
                result=result+prev;
            }

            prev=tmp;
        }
        return result;
    }
};