//https://leetcode-cn.com/problems/number-of-islands/
class UnionFind{
public:
    UnionFind(int size){
        for(int i=0;i<size;i++){
            parent.push_back(-1);
            val.push_back(0);
        }
        count=0;
    }
    UnionFind(vector<vector<char>>& grid){
        int size=grid.size()*grid[0].size();
        vector<int> pa(size,-1);
        
        parent=pa;
        count=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]=='1'){
                    parent[i*grid[i].size()+j]=i*grid[i].size()+j;
                    count++;
                }
            }
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

    int equal(int i){
        return val[i]==1;
    }

    int getCount(){
        return count;
    }

    int Union(int i,int j){
        int a=find(i);
        int b=find(j);
        if(a==b){
            return a;
        }
        count--;
        parent[b]=a;
        return a;
    }

private:
vector<int> parent;
vector<int> val;
int count;
};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {

        int m=grid.size();
        if(m==0){
            return 0;
        }
        int n=grid[0].size();

        UnionFind find(grid);

        int result=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    if(i+1<m && grid[i+1][j]=='1'){
                        find.Union(i*n+j,(i+1)*n+j);
                    }
                    if(j+1<n && grid[i][j+1]=='1'){
                       find.Union(i*n+j,i*n+j+1);
                    }
                }
            }
        }
        result=find.getCount();
        return result;
    }
};