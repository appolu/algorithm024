//https://leetcode-cn.com/problems/valid-anagram/
class Solution {
public:
    map<char,int> mapping;
    //数组保存字母索引值。
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()){
            return false;
        }
        int dic[26];
        memset(dic,0,sizeof(dic));
        for(int i=0;i<s.length();i++){
            dic[s[i]-'a']+=1;
            dic[t[i]-'a']-=1;
        }
        for(int i=0;i<26;i++){
            if(dic[i]!=0){
                return false;
            }
        }
        return true;
    }
    //map 保存字母值。
    bool isAnagram1(string s, string t) {
        if(s.length()==t.length()){
            for(int i=0;i<s.length();i++){
                int cnt=find(s[i]);
                if(cnt==-1){
                    mapping.insert(pair<char,int>(s[i],1));
                }else{
                    mapping[s[i]]++;
                }
            }
            for(int i=0;i<t.length();i++){
                int cnt=find(t[i]);
                if(cnt==-1){
                    return false;
                }else{
                    mapping[t[i]]--;
                }
            }
            map<char,int>::iterator iter;
            for(iter=mapping.begin();iter!=mapping.end();iter++){
                if(iter->second!=0){
                    return false;
                }
            }
            return true;
        }
        return false;
    }

    int find(char& c){
        map<char,int>::iterator iter=mapping.find(c);
        if(iter!=mapping.end()){
            return iter->second;
        }
        return -1;
    }
};