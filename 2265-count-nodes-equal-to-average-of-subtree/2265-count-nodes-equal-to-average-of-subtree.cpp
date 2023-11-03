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
int count=0;
pair<int,int> getsum(TreeNode* root)
{
    if(root==NULL)
    return {0,0};

    

    auto left=getsum(root->left);
    auto right=getsum(root->right);

    int s=left.first+right.first+root->val;
    int n=left.second+right.second+1;
    
    if(root->val==(s/n))
    count++;
    return {s,n};
}

    int averageOfSubtree(TreeNode* root) {
         pair<int,int> t=getsum(root);
         return count;
    }
};