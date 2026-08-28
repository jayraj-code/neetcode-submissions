class Solution {
public:
    ListNode* reverse(ListNode* head)
    {
        ListNode* prev = nullptr; 
        ListNode* curr = head; 

        while (curr != nullptr)
        {
            ListNode* temp = curr->next; 
            curr->next = prev; 
            prev = curr; 
            curr = temp; 

        }

        return prev; 
    }


    int pairSum(ListNode* head) {
        ListNode* slow  = head; 
        ListNode* fast = head; 

        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next; 
            fast = fast->next->next; 
        }

        ListNode* right = reverse(slow); 
        ListNode* left = head; 

        int sum = 0; 
        int maxSum = 0; 
        while (right != nullptr)
        {
            sum = left->val + right->val; 
            maxSum = max(sum, maxSum); 

            left = left->next; 
            right = right->next; 
        }

        return maxSum; 
    }
};