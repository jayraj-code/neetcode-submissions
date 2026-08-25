class Solution {
public:
    bool isPalindrome(ListNode* head) {
        int count = 0; 
        ListNode* curr = head; 
        while (curr != nullptr)
        {
            curr = curr->next; 
            count ++; 
        }

        int new_count = (count + 1) / 2; 

        curr = head; 
        for (int i = 0; i < new_count; i++)
        {
            curr = curr->next; 
        }
        
        ListNode* prev = nullptr;

        while (curr != nullptr)
        {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        ListNode* left = head;
        ListNode* right = prev;
        
        while (right != nullptr)
        {
            if (left->val != right->val)
                return false;

            left = left->next;
            right = right->next;
        }

        return true; 
        
    }
};