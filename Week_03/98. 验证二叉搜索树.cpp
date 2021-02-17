//https://leetcode-cn.com/problems/validate-binary-search-tree/
class Solution {
public:
    bool isvalidTree=true;
    bool isInit=true;
    int previousVal=0;
    bool isValidBST(TreeNode* root) {
        verify(root);
        return isvalidTree;
    }

    void verify(TreeNode *root){
        if(root==nullptr){
            return;
        }
        verify(root->left);
        if(isInit){
            isInit=false;
        }else{
            if(root->val>previousVal){

            }else{
                isvalidTree=false;
                return;
            }
        }
        previousVal=root->val;
        verify(root->right);
    }

};