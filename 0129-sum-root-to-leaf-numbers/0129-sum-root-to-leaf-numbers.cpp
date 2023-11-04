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
    void solve(TreeNode* root,int &sum,int ts)
    {
        if(root==NULL)
            return;
        if(root->left==NULL && root->right==NULL)
        {
            sum+=(ts*10+root->val);
            return;
        }
        cout<<root->val;
        ts=ts*10+root->val;
        solve(root->left,sum,ts);
        solve(root->right,sum,ts);
    }
    int sumNumbers(TreeNode* root) {
        if(root==NULL)
            return 0;
        int sum=0;
        int ts=0;
        solve(root,sum,ts);
        return sum;
    }
};