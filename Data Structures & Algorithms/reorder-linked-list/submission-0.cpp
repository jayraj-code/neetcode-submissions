class Solution {
public:
    void reorderList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return;

        // 1. Find middle
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // 2. Split the list
        ListNode* second = slow->next;
        slow->next = nullptr;

        // 3. Reverse second half
        ListNode* prev = nullptr;
        ListNode* curr = second;

        while (curr != nullptr) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        second = prev;   // prev is new head of reversed half

        // 4. Merge alternately
        ListNode* first = head;

        while (second != nullptr) {
            ListNode* temp1 = first->next;
            ListNode* temp2 = second->next;

            first->next = second;
            second->next = temp1;

            first = temp1;
            second = temp2;
        }
    }
};