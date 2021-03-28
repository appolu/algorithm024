//https://leetcode-cn.com/problems/word-search-ii/
class Trie{
    struct TrieNode{
        map<char,TrieNode*>child;
        int end;
        TrieNode():end(0){}
    };

    TrieNode *root;
public:
    bool find(string s,int match){
        TrieNode* cur=root;
        for(int i=0;i<s.size();i++){
            if(cur->child.count(s[i])==0){
                return false;
            }
            cur=cur->child[s[i]];
        }
        if(match){
            return cur->end==1;
        }
        return true;
    }

    Trie(){
        root=new TrieNode();
    }

    void insert(string s){
        TrieNode *cur=root;
        for(int i=0;i<s.size();i++){
            if(cur->child.count(s[i])==0){
                cur->child[s[i]]=new TrieNode();
            }
            cur=cur->child[s[i]];
        }
        cur->end=1;
    }

    bool search(string s){
        return find(s,1);
    }

    bool startWith(string s){
        return find(s,0);
    }
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie tie;
        for(int i=0;i<words.size();i++){
            tie.insert(words[i]);
        }
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                // if(tie.startWith(board[i][j])){

                // }
            }
        }
        return words;
    }
};