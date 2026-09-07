class BrowserHistory {
private: 
    struct Node
    {
        string url; 
        Node* next; 
        Node* prev; 

        Node(string url)
        {
            this->url = url; 
            next = nullptr; 
            prev = nullptr;  
        }
    };

    Node* current_page; 


public:
    BrowserHistory(string homepage) {
        current_page = new Node(homepage);     
    }
    
    void visit(string url) {
        Node* newNode = new Node(url); 
        newNode->prev = current_page; 
        current_page->next = newNode; 
        current_page = newNode; 
    }
    
    string back(int steps) {
        while (current_page->prev != nullptr && steps > 0)
        {
            current_page = current_page->prev; 
            steps--; 
        }

        return current_page->url; 
        
    }
    
    string forward(int steps) {
        while (current_page->next != nullptr && steps > 0)
        {
            current_page = current_page->next; 
            steps--; 
        }
        
        return current_page->url; 
        
    }
};
