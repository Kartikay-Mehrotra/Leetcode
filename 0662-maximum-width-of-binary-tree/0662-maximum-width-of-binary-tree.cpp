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
    int widthOfBinaryTree(TreeNode* root) {
        int ans=1;
        queue<pair<int,TreeNode*>> q;
        q.push({1,root});
        while(q.size())
        {
            int a=q.front().first;
            int b=q.back().first;
            int s=q.size();
            ans=max(ans,b-a+1);
            for(int i=0;i<s;i++)
            {
                TreeNode* f=q.front().second;
                int ind=q.front().first-a;
                q.pop();
                if(f->left)
                {
                    q.push({(long long)2*ind+1,f->left});
                }
                if(f->right)
                {
                    q.push({(long long)2*ind+2,f->right});
                }
            }
        }
        return ans;
    }
};