class Solution {
public:

    TreeNode* build(vector<int>& nums, int left, int right)
    {
        if (left > right)
        {
            return nullptr;
        }
            

        int mid = left + (right - left) / 2;

        TreeNode* node = new TreeNode(nums[mid]);

        node->left = build(nums, left , mid-1);
        node->right = build(nums, mid + 1, right);

        return node;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums)
    {
        int left = 0; 
        int right = nums.size()-1; 
        return build(nums, left , right);

    }
};