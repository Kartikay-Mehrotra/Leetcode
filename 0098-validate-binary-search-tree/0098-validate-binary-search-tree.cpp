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
    bool solve(TreeNode* root,long min_val,long max_val)
    {
        if(root==NULL)
            return true;
        if(root->val <=min_val || root->val >= max_val)
            return false;
        return solve(root->left,min_val,root->val) && solve(root->right,root->val,max_val);
    }
    bool isValidBST(TreeNode* root) {
        if(root->left==NULL && root->right==NULL)
            return true;
        return solve(root,LONG_MIN,LONG_MAX);
        
    }
};