//https://leetcode-cn.com/problems/longest-palindromic-substring/
class Solution {
public:
    string longest="";
    string longestPalindrome(string s) {
        if(s.length()<1){
            return s;
        }
        int maxlen=0,start=0;
        for(int i=0;i<s.length();i++){
            int l1=find(s,i,i+1);
            int l2=find(s,i,i);
            int l=max(l1,l2);
            if(l>maxlen){
                maxlen=l;
                start=i-(l-1)/2;
            }
        }
        longest=s.substr(start,maxlen);
        return longest;
    }

    int find(string s,int low,int high){
        while(low>=0 && high<s.length() && s[low]==s[high]){
            low--;high++;
        }
        
        return high-low-1;
    }
};