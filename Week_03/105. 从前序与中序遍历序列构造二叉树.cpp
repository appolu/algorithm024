//https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
class Solution {
public:
    map<int,int> indexIn;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0;i<inorder.size();i++){
            indexIn.insert(pair<int,int>(inorder[i],i));
        }
        return build(preorder,inorder,0,preorder.size(),0,inorder.size());
    }
    TreeNode *build(vector<int>& preorder, vector<int>& inorder,int pleft,int pright,int inleft,int inright){
        if(pleft<0 || pleft>=pright){
            return nullptr;
        }
        int rootval=preorder[pleft];
        TreeNode *node=new TreeNode(rootval);

        if(pleft==pright-1){
            return node;
        }

        int insplit= indexIn[rootval];

        int lileft=inleft;
        int liright=insplit;

        int rileft=insplit+1;
        int riright=inright;

        int lpleft=pleft+1;
        int lpright=lpleft+insplit-inleft;

        int rpleft=lpright;
        int rpright=pright;

        node->left=build(preorder,inorder, lpleft,lpright,lileft,liright);
        node->right=build(preorder,inorder,rpleft,rpright,rileft,riright);
        return node;
    }
};