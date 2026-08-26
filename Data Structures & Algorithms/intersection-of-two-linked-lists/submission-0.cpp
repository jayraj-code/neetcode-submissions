
class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        ListNode* currA = headA;
        ListNode* currB = headB;
        
        int count = 0;
        while (currA != nullptr)
        {
            count++;
            currA = currA->next; 
        }

        int count1 = 0; 
        while (currB != nullptr)
        {
            count1++;
            currB = currB->next; 
        }
        
        int skip = 0; 
        currA = headA;
        currB = headB;
        if (count > count1)
        {
            skip = count - count1; 
            for (int i = 0; i < skip; i++)
            {
                currA = currA->next; 
            }
        }
        else
        {
            skip = count1 - count;
            for (int i = 0; i < skip; i++)
            {
                currB = currB->next; 
            } 
        }
        
        while (currA != nullptr && currB != nullptr)
        {
            if (currA == currB)
            {
                return currA; 
            }
            currA = currA->next; 
            currB = currB->next;
        }

        return nullptr; 
        
    }
};