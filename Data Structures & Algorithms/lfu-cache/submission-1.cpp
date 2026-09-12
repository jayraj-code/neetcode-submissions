class LFUCache{
public: 
    class Node{
    public: 
        int key; 
        int val; 
        int frequency; 
        Node* prev; 
        Node* next; 

        Node(int key, int val)
        {
            this->key = key; 
            this->val = val; 
            frequency = 1; 
            prev = nullptr; 
            next = nullptr; 
        }        

    }; 

    class freqDll{
    public: 
        int size; 
        Node* dummyhead; 
        Node* dummytail; 

        freqDll()
        {
            dummyhead = new Node(0 , 0); 
            dummytail = new Node(0 , 0); 
            dummytail->prev = dummyhead; 
            dummyhead->next = dummytail; 

            size = 0; 
        }

        void addToFront(Node* node)
        {   
            node->next = dummyhead->next; 
            dummyhead->next->prev = node; 
            node->prev = dummyhead; 
            dummyhead->next = node; 

            size++; 
        }

        void removeNode(Node* node)
        {
            node->next->prev = node->prev; 
            node->prev->next = node->next; 

            size--; 
        }

        Node* removeFromEnd()
        {
            Node* toDelete = dummytail->prev; 
            removeNode(toDelete); 
            return toDelete; 
        }
    }; 

    int minFreq; 
    int capacity; 

    unordered_map<int, Node*> map; 
    unordered_map<int , freqDll*> freqMap; 

    LFUCache(int capacity)
    {
        this->capacity = capacity; 
        minFreq = 1; 
    }

    int get(int key)
    {
        if (!map.count(key))
        {
            return -1; 
        }

        Node* curr = map[key]; 
        int currentFrequency = curr->frequency; 
        freqDll* currentList = freqMap[currentFrequency]; 

        currentList->removeNode(curr); 

        if (currentList->size == 0 && minFreq == currentFrequency)
        {
            minFreq++; 
        }

        int updatedFrequency = ++curr->frequency; 

        if (!freqMap.count(updatedFrequency))
        {
            freqMap[updatedFrequency] = new freqDll; 
        }

        freqMap[updatedFrequency]->addToFront(curr); 
        return curr->val; 
    }

    void put (int key, int value)
    {
        if (capacity == 0)
        {
            return; 
        }

        if (map.count(key))
        {
            Node* curr = map[key]; 
            int currentFrequency = curr->frequency; 
            freqDll* currList = freqMap[currentFrequency]; 

            currList->removeNode(curr); 
            if (currList->size == 0 && minFreq == currentFrequency)
            {
                minFreq++; 
            }

            curr->frequency++; 

            if (!freqMap.count(curr->frequency))
            {
                freqMap[curr->frequency] = new freqDll(); 
            }
            freqMap[curr->frequency]->addToFront(curr); 
            curr->val = value; 
            return; 

        }

        if (map.size() == capacity)
        {
            freqDll* minList = freqMap[minFreq];
            Node* evictedNode = minList->removeFromEnd(); 
            map.erase(evictedNode->key); 
        }

        Node* newNode = new Node(key, value); 
        if(!freqMap.count(1))
        {
            freqMap[1] = new freqDll(); 
        }
        freqMap[1]->addToFront(newNode);
        map[key] = newNode; 
        newNode->frequency = 1; 
        minFreq = 1; 
    }
};