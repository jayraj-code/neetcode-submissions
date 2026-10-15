/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void postorder(Node* root, vector<int>& result)
    {
        Node* current = root; 
        if (current == nullptr)
        {
            return; 
        }

        for (int i = 0; i < current->children.size(); i++)
        {
            postorder(current->children[i], result); 
        }

        result.push_back(current->val); 
        
    }


    vector<int> postorder(Node* root) {
        vector<int> result; 
        postorder(root, result); 

        return result;     
    }
};