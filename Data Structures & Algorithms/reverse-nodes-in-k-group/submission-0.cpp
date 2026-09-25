class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr) return nullptr;

        ListNode* dummyNode = new ListNode(0);
        dummyNode->next = head;

        ListNode* groupPrev = dummyNode;

        while (true)
        {
            ListNode* kth = groupPrev;

            for (int i = 0; i < k && kth != nullptr; i++)
            {
                kth = kth->next;
            }

            if (kth == nullptr)
            {
                break;
            }

            ListNode* groupFirst = groupPrev->next;
            ListNode* groupNext = kth->next;

            ListNode* curr = groupFirst;
            ListNode* prev = groupNext;

            while (curr != groupNext)
            {
                ListNode* temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }

            groupPrev->next = prev;
            groupPrev = groupFirst;
        }

        return dummyNode->next;
    }
};