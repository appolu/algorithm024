//https://leetcode-cn.com/problems/valid-palindrome-ii/submissions/
class Solution {
public:
    bool validPalindrome(string s) {
        
        int low=0,high=s.length()-1;
        while(low<high){
            if(s[low]==s[high]){
                low++;
                high--;
            }else{
                return validCheck(s,low,high-1) || validCheck(s,low+1,high);
            }
        }
        return true;
    }

    bool validCheck(string s,int low,int high){
        for(int i=low,j=high;i<j;i++,j--){
            if(s[i]!=s[j]){
                return false;
            }
        }
        return true;
    }
};