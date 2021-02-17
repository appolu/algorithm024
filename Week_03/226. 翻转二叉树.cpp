//https://leetcode-cn.com/problems/invert-binary-tree/
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        Reverse(root);
        return root;
    }

    void Reverse(TreeNode *node){
        if(node==nullptr){
            return;
        }
        TreeNode *tmp=node->left;
        node->left=node->right;
        node->right=tmp;
        Reverse(node->left);
        Reverse(node->right);
    }
};