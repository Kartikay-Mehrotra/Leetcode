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
    vector<TreeNode*> helper(int start,int end)
    {
        if(start>end)
        {
            vector<TreeNode*> e;
            e.push_back(NULL);
            return e;
        }
    vector<TreeNode*> ans;
        for(int o=start;o<=end;o++)
        {
            vector<TreeNode*> lef=helper(start,o-1);
            vector<TreeNode*> righ=helper(o+1,end);
            for(auto l:lef){
                for(auto m:righ)
                {
                    TreeNode *temp=new TreeNode(o);
                    temp->left=l;
                    temp->right=m;
                    ans.push_back(temp);
                }
            }

        }
        return ans;
    }
    vector<TreeNode*> generateTrees(int n) {
        return helper(1,n);
    }
};