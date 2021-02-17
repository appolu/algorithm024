//https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree/
class Solution {
public:
    map<TreeNode*,TreeNode*> maps;
    map<TreeNode*,bool>visited;
    TreeNode *result;

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // dfs(root);
        // while(p!=NULL){
        //     visited[p]=true;
        //     p=maps[p];
        // }
        // while(q!=NULL){
        //     if(visited[q]){
        //         result=q;
        //     }
        //     q=maps[q];
        // }
        dfs1(root,p,q);
        return result;
    }

    bool dfs1(TreeNode *root,TreeNode *p,TreeNode *q){
        if(root==NULL){
            return false;
        }
        bool lf=dfs1(root->left,p,q);
        bool rf=dfs1(root->right,p,q);
        if((lf && rf) || (root->val==p->val || root->val==q->val && (lf || rf))){
            result=root;
        }
        return lf || rf || root->val==p->val || root->val==q->val ;

    }
    void dfs(TreeNode *root){
        if(root!=NULL){
            if(root->left!=NULL){
                maps.insert(pair<TreeNode*,TreeNode*>(root->left,root));
                dfs(root->left);
            }
            if(root->right!=NULL){
                maps.insert(pair<TreeNode*,TreeNode*>(root->right,root));
                dfs(root->right);
            }
        }else{
            return;
        }
    }
};