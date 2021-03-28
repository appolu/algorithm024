//https://leetcode-cn.com/problems/word-search-ii/
struct TrieNode{
    map<char,TrieNode*> child;
    string word;

    TrieNode() {
    }

    void insert( string s ){
        TrieNode *triePtr = this;
        for( char c : s ){
            if( triePtr->child.count(c) == 0 )
                triePtr->child[c] = new TrieNode();
            triePtr = triePtr->child[c];
        }
        triePtr->word = s; 
    }

    bool match(string word,int match){
        TrieNode *cur=this;
        for(char c:word){
            cur=cur->child[c];
            if(cur==nullptr){
                return false;
            }
        }
        if(match){
            return cur->word.size()>0;
        }
        return true;
    }

    bool search(string word){
        return match(word,1);
    }
    void find( vector<vector<char>>& board, vector<vector<bool>> &mark, int x,int y, 
    TrieNode *triePtr, vector<string> &ans ){
        if( x<0 || x>=board.size() || y<0 || y>=board[0].size() || mark[x][y] || triePtr->child[board[x][y]]==nullptr )
            return;

        triePtr = triePtr->child[board[x][y]];
        mark[x][y] = true;

        if( triePtr->word.size() ){
            ans.push_back(triePtr->word);
            triePtr->word = ""; 
        }

        find(board, mark, x-1,y, triePtr, ans);
        find(board, mark, x+1,y, triePtr, ans);
        find(board, mark, x,y-1, triePtr, ans);
        find(board, mark, x,y+1, triePtr, ans);

        mark[x][y] = false;
    }
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> ans;
        TrieNode *root = new TrieNode();        
        
        for( string word : words )
            root->insert(word);

        int x=board.size(), y=board[0].size();
        vector<vector<bool>> mark(x, vector<bool>(y, false));
        for( int i=0; i<x; i++ ){
            for( int j=0; j<y; j++ ){
                root->find(board, mark, i,j, root, ans);
            }
        }

        return ans;
    }
};