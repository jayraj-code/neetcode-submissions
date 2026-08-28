class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        int count = 0;
        ListNode* curr = head;

        // Pass 1: count nodes
        while (curr != nullptr)
        {
            count++;
            curr = curr->next;
        }

        // If we need to delete the head
        if (n == count)
        {
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }

        // Pass 2: stop at node BEFORE the node to delete
        curr = head;
        int currPos = 1;

        while (currPos < count - n)
        {
            curr = curr->next;
            currPos++;
        }

        ListNode* temp = curr->next;
        curr->next = temp->next;
        delete temp;

        return head;
    }
};