class MyCircularQueue {
public:
    vector<int> q; 
    int size; 
    int front;
    int rear; 
    int capacity; 

    MyCircularQueue(int k) {
        q.resize(k); 
        capacity = k; 

        size = 0; 
        front = 0; 
        rear = 0; 
    }
    
    bool enQueue(int value) {
        if (size == capacity)
        {
            return false; 
        }
        
        q[rear] = value; 
        rear = (rear + 1) % capacity; 
        size++; 

        return true;  
    }
    
    bool deQueue() {
        if (size == 0)
        {
            return false; 
        }

        front = (front + 1) % capacity; 
        size--; 
        
        return true; 
    }
    
    int Front() {
        if (size == 0)
        {
            return -1; 
        }

        return q[front]; 
    }
    
    int Rear() {
        if (size == 0)
        {
            return -1; 
        }
        int returnIndex = (rear - 1 + capacity) % capacity; 
        return q[returnIndex]; 
        
    }
    
    bool isEmpty() {
        return size == 0; 
    }
    
    bool isFull() {
        return size == capacity; 
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */