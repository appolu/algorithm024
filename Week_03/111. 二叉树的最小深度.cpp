//https://leetcode-cn.com/problems/minimum-depth-of-binary-tree/
class Solution {
public:
    int mini=INT_MAX;
    int minDepth(TreeNode* root) {
        // return getMinDepth(root);
        if(root==nullptr){
            return 0;
        }
        getMinRecur(root,1);
        return mini;
    }

    void getMinRecur(TreeNode *root,int level){
        if(root==nullptr){
            return;
        }
        if(root->left==nullptr && root->right==nullptr){
            if(mini>level){
                mini=level;
            }
        }

        getMinRecur(root->left,level+1);
        getMinRecur(root->right,level+1);        
    }

    int getMinDepth(TreeNode *root){
        if(root==nullptr){
            return 0;
        }
        queue<TreeNode*> qnode;
        qnode.push(root);
        int level=0;
        while(!qnode.empty()){
            int size=qnode.size();
            level++;
            for(int i=0;i<size;i++){
                TreeNode *tmp=qnode.front();
                qnode.pop();
                bool lf=false,rf=false;
                if(tmp->left!=nullptr){
                    qnode.push(tmp->left);
                    lf=true;
                }
                if(tmp->right!=nullptr){
                    qnode.push(tmp->right);
                    rf=true;
                }
                if(!lf && !rf){
                    return level;
                }
            }
        }
        return level;
    }
};