class Solution {

private:
    unordered_map<TreeNode*,int>memo;
public:
    int rob(TreeNode* root) {
         if (root == NULL) return 0;
        
        if (memo.count(root)){
            return memo[root];
        } 
    
        int ans_including_root = root->val;
    
        if (root->left != NULL) {
              ans_including_root += rob(root->left->left) + rob(root->left->right);
        }
    
        if (root->right != NULL) {
              ans_including_root += rob(root->right->left) + rob(root->right->right);
        }
        
        int ans_excluding_root = rob(root->left) + rob(root->right);
    
        int ans = max(ans_including_root , ans_excluding_root);
        
        memo[root]=ans;
    
        return ans;
    }    
};