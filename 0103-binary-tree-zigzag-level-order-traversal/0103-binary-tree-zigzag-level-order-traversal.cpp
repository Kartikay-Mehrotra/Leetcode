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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL)
            return {};
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        q.push(root);
        bool lr=true;
        while(q.size())
        {
            int s=q.size();
            vector<int> mid(s,0);
            for(int i=0;i<s;i++)
            {
                TreeNode* f=q.front();
                if(lr)
                    mid[i]=f->val;
                else
                    mid[s-i-1]=f->val;
                q.pop();
                if(f->left)
                    q.push(f->left);
                if(f->right)
                    q.push(f->right);
            }
            ans.push_back(mid);
            lr=!lr;
        }
        
        return ans;
    }
};