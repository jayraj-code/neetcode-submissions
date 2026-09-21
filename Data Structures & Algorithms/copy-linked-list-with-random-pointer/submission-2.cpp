

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr)
        return nullptr; 

        unordered_map<Node* , Node*> map; 

        Node* curr = head; 
        while (curr != nullptr)
        {
            Node* copiedNode = new Node(curr->val); 
            map[curr] = copiedNode; 
            curr = curr->next; 
        }

        curr = head; 
        while (curr->next != nullptr)
        {
            map[curr]->next = map[curr->next];
            curr = curr->next; 
        }

        curr = head; 
        while (curr != nullptr)
        {
            if (curr->random == nullptr)
            {
                map[curr]->random = nullptr; 
            }
            else
            {
                map[curr]->random = map[curr->random]; 
            } 
            curr = curr->next;
        }

        return map[head]; 

    }
};
