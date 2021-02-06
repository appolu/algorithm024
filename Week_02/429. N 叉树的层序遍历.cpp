//https://leetcode-cn.com/problems/n-ary-tree-level-order-traversal/
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> results;
    //利用deque进行先入先出的操作。
    vector<vector<int>> levelOrder(Node* root) {
        if(root==nullptr){
            return results;
        }
        deque<Node*> queue;
        queue.push_back(root);
        while(!queue.empty()){
            vector<int> t1;
            int size=queue.size();
            for(int i=0;i<size;i++){
                Node * tmp= queue.front();
                t1.push_back(tmp->val);
                queue.pop_front();
                for(int x=0;x<tmp->children.size();x++){
                    if(tmp->children[x]!=nullptr){
                        queue.push_back(tmp->children[x]);
                    }
                }
            }
            for(int i=0;i<size;i++){
            }
            results.push_back(t1);

        }
        return results;
    }
    //递归实现，时间较长
    vector<vector<int>> levelOrder1(Node* root) {
        if(root==nullptr){
            return results;
        }
        TreeLevel(root,0);
        return results;
    }

    void TreeLevel(Node* root,int level){
        cout<<"size:"<<level<<":"<<results.size();
        if(results.size()<=level){
            vector<int> cur;
            results.push_back(cur);
        }
        vector<int> tmp=results[level];
        tmp.push_back(root->val);
        results[level]=tmp;
        for(int i=0;i<root->children.size();i++){
            if(root->children[i]!=nullptr)
                TreeLevel(root->children[i],level+1);
        }
    }       
};