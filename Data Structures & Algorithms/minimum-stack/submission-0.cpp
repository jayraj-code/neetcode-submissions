#include <vector>
#include <algorithm>  // for std::min

class MinStack {
private:
    std::vector<int> mainStack;
    std::vector<int> minStack;

public:
    MinStack() {}
    
    void push(int val) {
        mainStack.push_back(val);
        
        if (minStack.empty()) {
            minStack.push_back(val);
        } else {
            int newMin = std::min(val, minStack.back());
            minStack.push_back(newMin);
        }
    }
    
    void pop() {
        if (!mainStack.empty()) {
            mainStack.pop_back();
            minStack.pop_back();
        }
    }
    
    int top() {
        if (mainStack.empty()) return -1; 
        return mainStack.back();
    }
    
    int getMin() {
        if (minStack.empty()) return -1; 
        return minStack.back();
    }
};