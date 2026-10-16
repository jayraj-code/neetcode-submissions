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
    int maxHeight (TreeNode* root)
    {
        if (root == nullptr)
        {
            return 0; 
        }

        int leftPath = maxHeight(root->left);   
        int rightPath = maxHeight(root->right); 

        if (abs(leftPath - rightPath) > 1)
        {
            return -1; 
        }

        if (leftPath == -1 || rightPath == -1)
        {
            return -1; 
        }


        return 1 + max(leftPath , rightPath); 

    }

    bool isBalanced(TreeNode* root) {
        if (root == nullptr)
        {
            return true; 
        }

        int height = maxHeight(root); 
        if (height == -1)
        {
            return false; 
        }

        return true; 

    }
};
