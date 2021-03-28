//https://leetcode-cn.com/problems/number-of-provinces/
class UnionFind{
public:
UnionFind(int count){
    for(int i=0;i<count;i++){
        parent.push_back(i);
    }
}
int find(int i){
    int x=i;
    while(i!=parent[i]){
        i=parent[i];
    }
    while(i!=parent[x]){
        x=parent[x];
        parent[x]=i;
    }
    return i;
}

int unionf(int i,int j){
    int a=find(i);
    int b=find(j);
    if(a==b){
        return a;
    }
    parent[b]=a;
    return a;
}

private:

vector<int> parent;
vector<int> rank;
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int count=isConnected.size();
        UnionFind uFind(count);
        for(int i=0;i<isConnected.size();i++){
            for(int j=0;j<isConnected[i].size();j++){
                if(isConnected[i][j]==1){
                    uFind.unionf(i,j);
                }
            }
        }
        int result=0;
        for(int i=0;i<isConnected.size();i++){
            if(uFind.find(i)==i){
                result++;
            }
        }
        return result;
    }
};