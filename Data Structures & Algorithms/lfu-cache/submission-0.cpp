class LFUCache {
private:
    class Node {
    public:
        int key;
        int val;
        int frequency;

        Node* prev;
        Node* next;

        Node(int key, int val) {
            this->key = key;
            this->val = val;
            frequency = 1;

            prev = nullptr;
            next = nullptr;
        }
    };

    class freqDll {
    public:
        Node* dummyhead;
        Node* dummytail;
        int size;

        freqDll() {
            dummyhead = new Node(0, 0);
            dummytail = new Node(0, 0);

            dummyhead->next = dummytail;
            dummytail->prev = dummyhead;

            size = 0;
        }

        void addToFront(Node* node) {
            node->next = dummyhead->next;
            dummyhead->next->prev = node;

            dummyhead->next = node;
            node->prev = dummyhead;

            size++;
        }

        void removeNode(Node* node) {
            node->prev->next = node->next;
            node->next->prev = node->prev;

            size--;
        }

        Node* removeLast() {
            if (size == 0) {
                return nullptr;
            }

            Node* node = dummytail->prev;
            removeNode(node);

            return node;
        }
    };

    int capacity;
    int minFreq;

    unordered_map<int, Node*> map;
    unordered_map<int, freqDll*> freqMap;

public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        minFreq = 0;
    }

    int get(int key) {
        if (!map.count(key)) {
            return -1;
        }

        Node* curr = map[key];

        int currFrequency = curr->frequency;
        freqDll* currList = freqMap[currFrequency];

        currList->removeNode(curr);

        if (currList->size == 0 && currFrequency == minFreq) {
            minFreq++;
        }

        curr->frequency++;

        if (!freqMap.count(curr->frequency)) {
            freqMap[curr->frequency] = new freqDll();
        }

        freqMap[curr->frequency]->addToFront(curr);

        return curr->val;
    }

    void put(int key, int value) {
        if (capacity == 0) {
            return;
        }

        // Key already exists
        if (map.count(key)) {
            Node* curr = map[key];

            int currFrequency = curr->frequency;
            freqDll* currList = freqMap[currFrequency];

            currList->removeNode(curr);

            if (currList->size == 0 && currFrequency == minFreq) {
                minFreq++;
            }

            curr->val = value;
            curr->frequency++;

            if (!freqMap.count(curr->frequency)) {
                freqMap[curr->frequency] = new freqDll();
            }

            freqMap[curr->frequency]->addToFront(curr);

            return;
        }

        // New key, but cache is full
        if (map.size() == capacity) {
            freqDll* minFreqList = freqMap[minFreq];

            Node* evicted = minFreqList->removeLast();

            map.erase(evicted->key);
            delete evicted;
        }

        // Insert new key
        Node* newNode = new Node(key, value);

        if (!freqMap.count(1)) {
            freqMap[1] = new freqDll();
        }

        freqMap[1]->addToFront(newNode);

        map[key] = newNode;

        minFreq = 1;
    }
};