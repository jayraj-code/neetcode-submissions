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
    void preorder(TreeNode* root, vector<int>& result)
    {
        TreeNode* current = root; 
        if (current == nullptr)
        {
            return; 
        }

        result.push_back(current->val); 
        preorder(current->left, result); 
        preorder(current->right, result); 
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result; 
        preorder(root, result); 

        return result;     
    }
};