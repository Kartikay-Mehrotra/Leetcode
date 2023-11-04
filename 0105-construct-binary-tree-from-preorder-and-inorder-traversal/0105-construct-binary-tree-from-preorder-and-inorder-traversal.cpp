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
    TreeNode* solve(int ps,int pe,vector<int>& preorder,int is,int ie,vector<int>& inorder,map<int,int>& mp)
    {
        if(ps>pe)
            return nullptr;
        TreeNode* root=new TreeNode(preorder[ps]);
        int ior=mp[preorder[ps]];
        int imr=ior-is;
        root->left=solve(ps+1,ps+imr,preorder,is,ior-1,inorder,mp);
        root->right=solve(ps+1+imr,pe,preorder,ior+1,ie,inorder,mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int> mp;
        for(int i=0;i<preorder.size();i++)
        {
            mp[inorder[i]]=i;
        }
        int size=preorder.size();
        return solve(0,size-1,preorder,0,size-1,inorder,mp);
    }
};