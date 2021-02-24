//https://leetcode-cn.com/problems/n-queens/
class Solution {
public:
    vector<vector<int>> result;
    map<int,int> cols,pie,na;
    vector<int> tmp;
    vector<vector<string>> finalres;
    vector<vector<string>> solveNQueens(int n) {

        if(n<1){
            return finalres;;
        }
        DFS(n,0);
        getResult(result);
        return finalres;

    }

    void DFS(int n,int row){
        if(row>=n){
            result.push_back(tmp);
            return;
        }
        for(int i=0;i<n;i++){
            if(cols.count(i) || pie.count(row+i) || na.count(row-i)){
                continue;
            }
            //update flags
            cols.insert(pair<int,int>(i,1));
            pie.insert(pair<int,int>(row+i,1));
            na.insert(pair<int,int>(row-i,1));
            tmp.push_back(i);
            DFS(n,row+1);
            //reverse state;
            tmp.pop_back();
            cols.erase(i);
            pie.erase(row+i);
            na.erase(row-i);
        }
    }
    void getResult(vector<vector<int>> res){
        for(int i=0;i<res.size();i++){
            vector<string> results;
            for(int j=0;j<res[i].size();j++){
                string s="";
                for(int k=0;k<res[i].size();k++){
                    if(res[i][j]==k){
                        s+="Q";
                    }else{
                        s+=".";
                    }
                }
                results.push_back(s);
            }
            finalres.push_back(results);
        }
    }


};