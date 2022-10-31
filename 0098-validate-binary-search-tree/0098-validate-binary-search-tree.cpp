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
    int min_val(TreeNode*root)
    {
        if (!root)
            return INT_MIN;
        while(root->left)
            root=root->left;
        return root->val;
    }
    int max_val(TreeNode *root)
    {
        if (!root)
            return INT_MAX;
        while(root->right)
            root=root->right;
        return root->val;
    }
    
    bool isValidBST(TreeNode* root) {
        if (!root)
            return true;
        if ((root->left && max_val(root->left)>=root->val))
            return false;
        if((root->right && min_val(root->right)<=root->val))
            return false;
        if(!isValidBST(root->left) || !isValidBST(root->right))
            return false;
        return true;
    }
};