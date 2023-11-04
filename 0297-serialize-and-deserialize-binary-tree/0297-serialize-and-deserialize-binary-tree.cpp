/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
   // TreeNode* temp;
    string serialize(TreeNode* root) {
        if(root==NULL)
        return "";
        string s="";
        queue<TreeNode*> q;
        q.push(root);
        while(q.size())
        {
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                TreeNode* front=q.front();
                q.pop();
                if(front==NULL)
                {
                    s+="#,";
                    continue;
                }
                else{
                s+=to_string(front->val)+",";

              
                    q.push(front->left);
                    q.push(front->right);
                }
            
            }
        }
    // temp=root;   
     return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0)
        return NULL;
 stringstream s(data);
        string str;
        getline(s,str,',');
        TreeNode* root=new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* a=q.front();
            q.pop();
            getline(s,str,',');
            if(str=="#") a->left=NULL;
            else{
                a->left=new TreeNode(stoi(str));
                q.push(a->left);
            }
            getline(s,str,',');
            if(str=="#") a->right=NULL;
            else{
                a->right=new TreeNode(stoi(str));
                q.push(a->right);
            }
        }
        return root;
        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));