
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy; 

        int carry = 0; 

        while (l1 != nullptr || l2 != nullptr || carry != 0)
        {
            int digit1 = (l1 != nullptr) ? l1->val : 0; 
            int digit2 = (l2 != nullptr) ? l2->val : 0; 

            int sum = digit1 + digit2 + carry; 
            int new_digit = sum % 10; 
            carry = sum/10; 

            ListNode* newNode = new ListNode(new_digit); 
            tail->next = newNode; 
            tail = newNode; 

            if (l1 != nullptr)
            {
                l1 = l1->next;
            }
            
            if (l2 != nullptr)
            {
                l2 = l2->next;
            }

        } 

        return dummy->next; 

    }
};
