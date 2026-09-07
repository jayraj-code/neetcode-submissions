class Solution {
public:
    ListNode* reverse_half(ListNode* head)
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

    void reorderList(ListNode* head) {
        ListNode* slow = head; 
        ListNode* fast = head; 

        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next; 
            fast = fast->next->next; 
        }

        ListNode* second = reverse_half(slow->next); 
        ListNode* first = head; 
        slow->next = nullptr; 

        while (second != nullptr)
        {
            ListNode* temp1 = first->next; 
            ListNode* temp2 = second->next; 
            first->next = second; 
            second->next = temp1; 
            first = temp1;
            second = temp2; 
        }

    }
};
