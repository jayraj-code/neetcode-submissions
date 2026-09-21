
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummyNode = new ListNode(0); 
        dummyNode->next = head; 

        ListNode* beforeLeft = dummyNode; 

        for (int i = 1; i < left; i++)
        {
            beforeLeft = beforeLeft->next; 
        }

        ListNode* leftNode = beforeLeft->next; 
        ListNode* rightNode = leftNode; 

        for (int i = left; i < right; i++)
        {
            rightNode = rightNode->next; 
        }

        ListNode* afterRight = rightNode->next; 
        ListNode* prev = afterRight; 
        ListNode* curr = leftNode; 

        for (int i = 0 ; i < right - left + 1; i++)
        {
            ListNode* temp = curr->next; 
            curr->next = prev; 
            prev = curr; 
            curr = temp; 
        }

        beforeLeft->next = prev; 
        return dummyNode->next; 
        
    }
};