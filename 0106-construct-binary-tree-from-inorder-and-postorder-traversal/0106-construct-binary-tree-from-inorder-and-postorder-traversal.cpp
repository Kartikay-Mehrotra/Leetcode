class Solution {
public:
TreeNode* solve(vector<int>& inorder,int is,int ie, vector<int>& postorder,int ps,int pe,unordered_map<int,int> &mp)
    {
        if(ps>pe || is>ie)
        return NULL;

        TreeNode* root=new TreeNode(postorder[pe]);
        int r=mp[postorder[pe]];
        int l=r-is;
        root->left=solve(inorder,is,r-1,postorder,ps,ps+l-1,mp);
        root->right=solve(inorder,r+1,ie,postorder,ps+l,pe-1,mp);

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> mp;
        for(int i=0;i<inorder.size();i++)
        {
            mp[inorder[i]]=i;
        }
        TreeNode *t=solve(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1,mp);

        return t;
    }
};