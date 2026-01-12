/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        Node* curr = head;
        stack<Node*> cont;

        while(curr || !cont.empty()){
            if(curr->child != nullptr){
                if (curr->next) cont.push(curr->next);   
                curr->next = curr->child;
                curr->child->prev = curr;
                curr->child = nullptr;
            }
            if(curr->next == nullptr && !cont.empty()){
                curr->next = cont.top();
                curr->next->prev = curr;
                cont.pop();
            }
            curr = curr->next;
        }
        return head;
    }
};