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
vector<int> ans;
void mostFrequent(vector<int> &arr, int n)
{
    // Insert all elements in hash.
    unordered_map<int, int> hash;
    for (int i = 0; i < n; i++)
        hash[arr[i]]++;
  
    // find the max frequency
    int max_count = 0, res = -1;
    for (auto i : hash) {
        if (max_count < i.second) {
            res = i.first;
            max_count = i.second;
        }
    }
  for(auto i:hash)
  {
      if(i.second==max_count)
      ans.push_back(i.first);
  }
    
}
  
void inorder(TreeNode* root,vector<int>& v)
{
    if(root==NULL)
    return;

    inorder(root->left,v);
    v.push_back(root->val);
    inorder(root->right,v);
}
    vector<int> findMode(TreeNode* root) {
        vector<int> v;
        inorder(root,v);
        
        mostFrequent(v,v.size());
        return ans;
    }
};