//https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/
class Solution {
public:
    int maxLevel=0;
    int maxDepth(TreeNode* root) {
        return getMaxDepth(root);
        getMaxDep(root,0);

        return maxLevel;
    }

    void getMaxDep(TreeNode *root,int level){
        if(root==nullptr){
            if(level>maxLevel){
                maxLevel=level;
            }
            return;
        }
        getMaxDep(root->left,level+1);
        getMaxDep(root->right,level+1);
    }

    //use queue to simulate recursion
    int getMaxDepth(TreeNode *root){
        if(root==nullptr){
            return 0;
        }
        queue<TreeNode*> qnode;
        qnode.push(root);
        int level=0;
        while(!qnode.empty()){
            int size=qnode.size();
            for(int i=0;i<size;i++){
                TreeNode*tmp= qnode.front();
                qnode.pop();
                if(tmp->left!=nullptr)
                    qnode.push(tmp->left);
                if(tmp->right!=nullptr)
                    qnode.push(tmp->right);
            }
            level++;
        }   
        return level;
    }
};