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
    void postorder(TreeNode* root, vector<int>& result)
    {
        TreeNode* current = root; 
        if (current == nullptr)
        {
            return; 
        }

        postorder(current->left , result); 
        postorder(current->right , result);
        result.push_back(current->val);  
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result; 

        postorder(root, result); 

        return result;     
    }
};