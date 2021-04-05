//https://leetcode-cn.com/problems/valid-anagram/
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()) return false;
        vector<int> dic(26);
        for(int i=0;i<s.length();i++){
            dic[s[i]-'a']+=1;
            dic[t[i]-'a']-=1;
        }
        
        for(int i=0;i<26;i++){
            if(dic[i]!=0) return false;
        }
        return true;
    }
};