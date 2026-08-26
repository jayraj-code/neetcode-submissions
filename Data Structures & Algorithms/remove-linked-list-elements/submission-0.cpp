class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        while (head != nullptr && head->val == val)
        {
            ListNode* temp = head;
            head = head->next;
            delete temp;
        }

        if (head == nullptr)
        {
            return nullptr;
        }

        ListNode* prev = head;
        ListNode* curr = head->next;
        while (curr != nullptr)
        {
            if (curr->val == val)
            {
                ListNode* temp = curr;
                prev->next = curr->next;
                curr = curr->next;
                delete temp;
            }
            else
            {
                prev = curr;
                curr = curr->next; 
            }
        }

        return head; 
    }
};