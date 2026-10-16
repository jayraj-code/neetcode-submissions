class Solution {
public:
    int heightOfNode(TreeNode* node, int& diameter)
    {
        if (node == nullptr)
        {
            return 0;
        }

        int leftHeight = heightOfNode(node->left, diameter);
        int rightHeight = heightOfNode(node->right, diameter);

        diameter = max(diameter, leftHeight + rightHeight);

        return 1 + max(leftHeight, rightHeight);
    }

    int diameterOfBinaryTree(TreeNode* root)
    {
        int diameter = 0;

        heightOfNode(root, diameter);

        return diameter;
    }
};