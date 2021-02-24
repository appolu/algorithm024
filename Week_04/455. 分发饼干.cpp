//https://leetcode-cn.com/problems/assign-cookies/description/
class Solution {
public:
    int size=0;
    int findContentChildren(vector<int>& g, vector<int>& s) {
        if(g.size()==0|| s.size()==0){
            return size;
        }
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        find(g,s,0,0);
        return size;
    }

    void find(vector<int> &g, vector<int> &s,int l,int m){
        if(l>=g.size() || m>=s.size()){
            return;
        }
        if(g[l]<=s[m]){
            size++;
            find(g,s,l+1,m+1);
        }else{
            find(g,s,l,m+1);
        }
    }
};