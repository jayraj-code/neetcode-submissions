
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr)
        {
            return nullptr; 
        }        

        Node* curr = head; 
        while (curr != nullptr)
        {
            Node* temp = curr->next; 
            Node* copyNode = new Node(curr->val); 
            curr->next = copyNode;
            copyNode->next = temp; 

            curr = temp; 
        }

        curr = head; 
        while (curr != nullptr)
        {
            if (curr->random == nullptr)
            {
                curr->next->random = nullptr; 
            }
            else
            {
                curr->next->random = curr->random->next; 
            }

            curr = curr->next->next; 
        }

        curr = head;
        Node* copiedHead = head->next; 
        while (curr != nullptr)
        {
            Node* copy = curr->next; 
            Node* orignalNode = copy->next; 

            curr->next = orignalNode;

            if (orignalNode != nullptr)
            {
                copy->next = orignalNode->next; 
            }

            else
            {
                copy->next = nullptr; 
            }

            curr = orignalNode; 
        }

        return copiedHead;
    }
};
