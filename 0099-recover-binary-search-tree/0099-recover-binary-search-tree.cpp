/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * }
 */
class Solution {
public:
    TreeNode* f,*s,*pre;
    void solve(TreeNode* root)
    {
        if(root==NULL)
            return ;
        solve(root->left);
        if(f==nullptr && root->val<pre->val)
            f=pre;
        if(f!=nullptr && root->val <pre->val)
            s=root;
        pre=root;
        solve(root->right);
    }
    void recoverTree(TreeNode* root) {
        pre=new TreeNode(INT_MIN);
        solve(root);
        swap(f->val,s->val);
    }
};