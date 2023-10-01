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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==NULL)
            return {};
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> ans;
        vector<int> mid;
        while(q.size())
        {
            int s=q.size();
            mid.clear();
            for(int i=0;i<s;i++)
            {
                
                TreeNode* f=q.front();
                q.pop();
                if(f->left)
                    q.push(f->left);
                if(f->right)
                    q.push(f->right);
                mid.push_back(f->val);
            }
            ans.push_back(mid);
        }
        return ans;
    }
};