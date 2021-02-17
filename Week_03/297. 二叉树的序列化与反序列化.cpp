//https://leetcode-cn.com/problems/serialize-and-deserialize-binary-tree/
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        return root==NULL ?"null":to_string(root->val)+","+serialize(root->left)+","+serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        string s="";
        vector<string> datas;
        for(int i=0;i<data.length();i++){
            if(data[i]==','){
                datas.push_back(s);
                s="";
            }else{
                s+=data[i];
            }
        }
        if(s.length()>0){
            datas.push_back(s);
        }
        return getTree(datas);
    }
    int steps=0;
    TreeNode *getTree(vector<string> &data){
        if(steps<data.size()){
            if(data[steps]=="null"){
                return nullptr;
            }
            TreeNode *node=new TreeNode(stoi(data[steps]));
            steps++;
            node->left=getTree(data);
            steps++;
            node->right=getTree(data);
            return node;
        }else{
            return nullptr;
        }

    }
};
