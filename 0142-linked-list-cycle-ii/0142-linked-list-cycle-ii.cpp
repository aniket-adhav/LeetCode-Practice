/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        bool flag = false;
        //find cycle is present or not
        while(fast!=nullptr && fast->next!=nullptr){
            slow = slow -> next;
            fast = fast->next->next;
            if(slow==fast){
                flag=true;
                break;
            }
        }

        if(flag==true){
            slow=head;
            while(slow!=fast){
                slow=slow->next;
                fast=fast->next;
            }
        }
        else return nullptr;
        return slow;
    }
};