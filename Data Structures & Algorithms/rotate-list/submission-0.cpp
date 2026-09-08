class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr || k == 0)
            return head;

        // 1. Find length and old tail
        int n = 1;
        ListNode* tail = head;

        while (tail->next != nullptr) {
            tail = tail->next;
            n++;
        }

        // 2. Remove useless full rotations
        k = k % n;

        if (k == 0)
            return head;

        // 3. Find new tail
        int stepsToNewTail = n - k - 1;

        ListNode* newTail = head;

        for (int i = 0; i < stepsToNewTail; i++) {
            newTail = newTail->next;
        }

        // 4. Save new head
        ListNode* newHead = newTail->next;

        // 5. Cut and reconnect
        newTail->next = nullptr;
        tail->next = head;

        return newHead;
    }
};