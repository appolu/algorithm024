//https://leetcode-cn.com/problems/valid-anagram/
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
    vector<int> preorder(Node* root) {
        stack<Node*> m_stack;
        vector<int> results;
        if(root==nullptr){
            return results;
        }
        m_stack.push(root);
        while(!m_stack.empty()){
            Node *tmp=m_stack.top();
            m_stack.pop();
            results.push_back(tmp->val);
            for(int i=tmp->children.size()-1;i>=0;i--){
                Node *t1=tmp->children[i];
                if(t1!=nullptr)
                    m_stack.push(t1);
            }

        }
        return results;
    }
};