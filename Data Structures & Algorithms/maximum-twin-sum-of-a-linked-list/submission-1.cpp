class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode* slow = head; 
        ListNode* fast = head; 

        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next; 
            fast = fast->next->next; 
        }
        
        ListNode* prev = nullptr; 
        ListNode* curr = slow; 
        while(curr != nullptr)
        {
            ListNode* temp = curr->next; 
            curr->next = prev; 
            prev = curr; 
            curr = temp; 
        }

        int sum = 0; 
        int maxSum = 0; 
        ListNode* left = head; 
        ListNode* right = prev; 
        while (right != nullptr)
        {
            sum = left->val + right->val; 
            maxSum = max(sum , maxSum);

            left = left->next; 
            right = right->next;  
            
        }

        return maxSum; 
    }
};