class Solution {
public:
    int pairSum(ListNode* head) {
        vector<int> ll; 

        // copying the elements to the vector
        ListNode* curr = head; 
        while (curr != nullptr)
        {
            ll.push_back(curr->val); 
            curr = curr->next; 
        }

        int n = ll.size(); 
        int sum = 0; 
        int maxSum = 0; 
        for (int i = 0; i < n; i++)
        {
            sum = ll[i] + ll[(n-1-i)];
            maxSum = max(sum , maxSum); 
        }
        return maxSum; 
        
    }
};