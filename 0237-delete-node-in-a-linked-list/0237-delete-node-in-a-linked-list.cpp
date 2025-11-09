class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* temp=node;
        while(temp->next!=nullptr){
            temp->val=temp->next->val;
            if(temp->next->next==nullptr) break;
            temp=temp->next;
        }
        
        temp->next=nullptr;
    }
};