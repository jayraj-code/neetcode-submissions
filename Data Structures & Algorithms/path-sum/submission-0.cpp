class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr)
            return false;

        targetSum = targetSum - root->val;

        if (root->left == nullptr && root->right == nullptr)
        {
            if (targetSum == 0)
                return true;

            return false;
        }

        return hasPathSum(root->left, targetSum) ||
               hasPathSum(root->right, targetSum);
    }
};