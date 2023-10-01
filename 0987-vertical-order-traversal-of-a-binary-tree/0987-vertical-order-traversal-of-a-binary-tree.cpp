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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        
       map<int,map<int,multiset<int>>>  mp;
        queue<pair<int,pair<int,TreeNode*>>> q;
        q.push({0,{0,root}});//hd,lev,node
        
        while(q.size())
        {
            int s=q.size();
            for(int i=0;i<s;i++)
            {
                TreeNode* f=q.front().second.second;
                int lev=q.front().second.first;
                int hd=q.front().first;
                q.pop();
                mp[hd][lev].insert(f->val);
                if(f->left)
                {
                    q.push({hd-1,{lev+1,f->left}});
                }
                if(f->right)
                {
                    q.push({hd+1,{lev+1,f->right}});
                }
            }
        }
        vector<int> mid;
        for(auto hd:mp)
        {
            for(auto lev:hd.second)
            {
                for(auto va:lev.second)
                mid.push_back(va);
            }
            ans.push_back(mid);
            mid.clear();
        }
        
        return ans;
    }
};