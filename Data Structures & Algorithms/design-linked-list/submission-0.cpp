class MyLinkedList {
private:
    struct Node {
        int val; 
        Node* next; 

        Node(int value) {
            val = value; 
            next = nullptr; 
        }     
    }; 

    Node* head;
    int size; 

public:
    MyLinkedList() {
        head = nullptr;
        size = 0;  
    } 

    // Destructor to prevent memory leaks
    ~MyLinkedList() {
        Node* curr = head;
        while (curr != nullptr) {
            Node* temp = curr;
            curr = curr->next;
            delete temp;
        }
    }
    
    int get(int index) {
        if (index < 0 || index >= size) {
            return -1; 
        }

        int count = 0; 
        Node* curr = head; 
        while (count < index) {
            curr = curr->next; 
            count++; 
        }

        return curr->val; 
    }
    
    void addAtHead(int val) {
        Node* newNode = new Node(val); 
        newNode->next = head; 
        head = newNode;  
        size++; 
    }
    
    void addAtTail(int val) {
        Node* newNode = new Node(val); 
        if (head == nullptr) {
            head = newNode; 
            size++; 
            return; 
        }

        Node* curr = head; 
        while (curr->next != nullptr) {
            curr = curr->next; 
        }
        curr->next = newNode; 
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if (index > size || index < 0) {
            return; 
        }
    
        if (index == 0) {
            addAtHead(val);
            return; 
        }

        Node* newNode = new Node(val);   
        int count = 0; 
        Node* curr = head; 
        while (count < index - 1) {
            curr = curr->next;
            count++; 
        } 

        newNode->next = curr->next; 
        curr->next = newNode;
 
        size++;
    }

    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) {
            return;
        }

        if (index == 0) {
            Node* temp = head;
            head = head->next;
            delete temp;
            size--;
            return;
        }

        Node* curr = head;
        int count = 0;

        while (count < index - 1) {
            curr = curr->next;
            count++;
        }

        Node* temp = curr->next;
        curr->next = temp->next;
        delete temp;

        size--;
    }
};