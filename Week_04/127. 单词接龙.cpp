//https://leetcode-cn.com/problems/word-ladder/
class Solution {
public:
    map<string,int> wordID;
    vector<vector<int>> edge;
    int nodeNum=0;
    
    void addWord(string &word){
        if(!wordID.count(word)){
            wordID[word]=nodeNum++;
            edge.emplace_back();
        }
    }

    void addEdge(string &word){
        addWord(word);
        int id1=wordID[word];
        for(char & it:word){
            char tmp=it;
            it='*';
            addWord(word);
            int id2=wordID[word];
            edge[id1].push_back(id2);
            edge[id2].push_back(id1);
            it=tmp;
        }
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        for(string &word :wordList){
            addEdge(word);
        }
        addEdge(beginWord);
        if(!wordID.count(endWord)){
            return 0;
        }
        vector<int> dis(nodeNum,INT_MAX);
        int beginID=wordID[beginWord],endID=wordID[endWord];
        dis[beginID]=0;
        queue<int> que;
        que.push(beginID);
        while(!que.empty()){
            int x=que.front();
            que.pop();
            if(x==endID){
                return dis[endID]/2+1;
            }
            for(int & it:edge[x]){
                if(dis[it]==INT_MAX){
                    dis[it]=dis[x]+1;
                    que.push(it);
                }
            }
        }
        return 0;
    }
};