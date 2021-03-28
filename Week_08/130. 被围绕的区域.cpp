//https://leetcode-cn.com/problems/surrounded-regions/
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
                if(grid[i][j]=='O'){
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
    vector<vector<int>> visited;
    void dfs(vector<vector<char>>& board,int x,int y,char str){
        if(x>=board[0].size() || x<0 || y<0 || y>=board.size() || board[y][x]=='X' || visited[y][x]){
            return;
        }

        visited[y][x]=1;

        if(board[y][x]=='O' && str=='B'){
            board[y][x]='B';
        }else{
            return;
        }
        dfs(board,x,y+1,str);
        dfs(board,x,y-1,str);
        dfs(board,x+1,y,str);
        dfs(board,x-1,y,str);
        visited[y][x]=0;
    }
    void solve(vector<vector<char>>& board) {
        
        int m=board.size();
        int n=board[0].size();
        vector<int> cp(n,0);
        vector<vector<int>> tmp(m,cp);
        visited=tmp;
        UnionFind find(board);
        for(int i=0;i<n;i++){
            if(board[0][i]=='O'){
                //board[0][i]='B';
                dfs(board,i,0,'B');
            }
            if(board[m-1][i]=='O'){
                //board[m-1][i]='B';
                dfs(board,i,m-1,'B');
            }
        }
        for(int i=0;i<m;i++){
            if(board[i][0]=='O'){
                //board[i][0]='B';
                dfs(board,0,i,'B');
            }
            if(board[i][n-1]=='O'){
                //board[i][n-1]='B';
                dfs(board,n-1,i,'B');
            }

        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O'){
                    board[i][j]='X';
                }
                if(board[i][j]=='B'){
                    board[i][j]='O';
                }
            }
        }
    }
};