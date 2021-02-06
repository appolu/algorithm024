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
    vector<int> postorder(Node* root) {
        stack<Node*> m_stack;
        vector<int> results;
        if(root==nullptr){
            return results;
        }
        m_stack.push(root);

        while(!m_stack.empty()){
            Node* node=m_stack.top();
            m_stack.pop();
            results.push_back(node->val);
            for(int i=0;i<node->children.size();i++){
                if(node->children[i]!=nullptr)
                    m_stack.push(node->children[i]);
            }
        }
        reverse(results.begin(),results.end());
        return results;
    }
};