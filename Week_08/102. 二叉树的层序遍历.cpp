//https://leetcode-cn.com/problems/binary-tree-level-order-traversal/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> levelOrder(TreeNode* root) {
        find(root);
        return result;
    }

    void find(TreeNode *root){
        if(root==nullptr){
            return;
        }
        deque<TreeNode*> nodes;
        nodes.push_back(root);
        vector<int> ts;
        ts.push_back(root->val);
        result.push_back(ts);
        while(!nodes.empty()){
            int size=nodes.size();
            vector<int> ts;
            for(int i=0;i<size;i++){
                TreeNode* tmp= nodes.front();
                nodes.pop_front();
                if(tmp->left!=nullptr){
                    nodes.push_back(tmp->left);
                    ts.push_back(tmp->left->val);
                }
                if(tmp->right!=nullptr){
                    nodes.push_back(tmp->right);
                    ts.push_back(tmp->right->val);
                }
                

            }
            if(ts.size()>0)
                result.push_back(ts);

        }
    }
};