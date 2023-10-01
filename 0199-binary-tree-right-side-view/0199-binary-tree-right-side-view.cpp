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
    vector<int> rightSideView(TreeNode* root) {
        if(!root)
            return {};
        queue<TreeNode*> q;
        q.push(root);
        vector<int> ans;
        while(q.size())
        {
            int s=q.size();
            ans.push_back(q.front()->val);
            for(int i=0;i<s;i++)
            {
                TreeNode* f=q.front();
                q.pop();
                
                if(f->right)
                    q.push(f->right);
                if(f->left)
                    q.push(f->left);
            }
        }
        return ans;
    }
};