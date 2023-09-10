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

int solve(TreeNode* root,int &t)
{
        if(root==NULL)
        return 0;
        
        int l=max(0,solve(root->left,t));
        int r= max(0,solve(root->right,t));
        t=max(l+r+root->val,t);


        return max(l,r)+root->val;
}
    int maxPathSum(TreeNode* root) {
        int maxi=INT_MIN;
        int t=solve(root,maxi);
return maxi;
        
    }
};