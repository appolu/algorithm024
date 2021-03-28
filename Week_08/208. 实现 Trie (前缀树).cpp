//https://leetcode-cn.com/problems/implement-trie-prefix-tree/
class Trie {
    struct TrieNode{
        map<char,TrieNode*> child;
        int end;
        TrieNode():end(0){}
    };
public:
    /** Initialize your data structure here. */
    TrieNode *root;
    bool find(string s,int match){
        TrieNode* cur=root;
        for(int i=0;i<s.size();i++){
            if(cur->child.count(s[i])==0){
                return false;
            }else{
                cur=cur->child[s[i]];
            }
        }
        if(match){
            return cur->end==1;
        }
        return true;
    }

    Trie() {
        root=new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *cur=root;
        for(int i=0;i<word.size();i++){
            if(cur->child.count(word[i])==NULL){
                TrieNode *node=new TrieNode();
                cur->child[word[i]]=node;
            }
            cur=cur->child[word[i]];
        }
        cur->end=1;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        return find(word,1);
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return find(prefix,0);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */