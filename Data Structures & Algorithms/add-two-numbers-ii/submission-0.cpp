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

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head1 = reverse(l1); 
        ListNode* head2 = reverse(l2); 

        ListNode* dummy = new ListNode(0); 
        ListNode* tail = dummy; 

        int carry = 0; 

        while (head1 != nullptr || head2 != nullptr || carry != 0)
        {
            int digit1 = (head1 != nullptr) ? head1->val : 0; 
            int digit2 = (head2 != nullptr) ? head2->val : 0; 

            int sum = digit1 + digit2 + carry; 
            int new_digit = sum % 10; 
            carry = sum / 10; 

            ListNode* newNode = new ListNode(new_digit); 
            tail->next = newNode; 
            tail = newNode; 

            if (head1 != nullptr)
            {
                head1 = head1->next; 
            }

            if (head2 != nullptr)
            {
                head2 = head2->next; 
            }

        }

        ListNode* ans = reverse(dummy->next); 
        return ans; 

    }
};