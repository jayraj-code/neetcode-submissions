
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* head1, ListNode* head2)
    {
        ListNode* dummyHead = new ListNode(0);
        ListNode* tail = dummyHead;

        while (head1 != nullptr &&  head2 != nullptr)
        {
            if (head1->val <= head2->val)
            {
                tail->next = head1;
                tail = tail->next; 
                head1 = head1->next;  
            }

            else
            {
                tail->next = head2; 
                tail = tail->next; 
                head2 = head2->next; 
            }
            
        } 

        if (head1 != nullptr)
        {
            tail->next = head1; 
        }
        else
        {
            tail->next = head2; 
        }

        return dummyHead->next; 

    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty())
        {
            return nullptr; 
        }

        while (lists.size() > 1)
        {
            vector<ListNode*> merged; 

            for (int i = 0; i < lists.size(); i+= 2)
            {
                if(i+1 < lists.size())
                {
                    merged.push_back(mergeTwoLists(lists[i], lists[i+1])); 
                }

                else
                {
                    merged.push_back(lists[i]); 
                }
            }

            lists = merged;
        }

        return lists[0]; 
        
    }
};
