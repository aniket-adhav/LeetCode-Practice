
    class Solution {
    public:
    ListNode* merge(ListNode* list1, ListNode* list2) {
            ListNode* C = new ListNode(100) ;
            ListNode* temp = C ;
            while(list1!= NULL && list2!=NULL){
                if(list1->val <= list2->val){
                    temp->next = list1 ;
                    list1 = list1->next ;
                    temp = temp ->next ;
                }
                else{
                    temp->next = list2 ;
                    list2 = list2->next ;
                    temp = temp->next ;

                }

            }
            if(list1 == NULL )temp->next = list2 ;
            if(list2==NULL) temp->next = list1 ;
        return C->next ;
        }
        ListNode* sortList(ListNode* head) {
            if(head==NULL || head->next == NULL)return head ;
            // to find the middle of the linked list 
            ListNode* slow = head ;
            ListNode* fast = head ;
            while(fast->next!=NULL && fast->next->next!=NULL){
                slow = slow->next ;
                fast = fast->next->next ;

            }
            // now slow is at left middle of the list 
            // we've created two new lists 

            ListNode* a = head ;
            ListNode* b = slow->next ;
            slow->next  = NULL ;
            a = sortList(a) ;
            b = sortList(b) ;
            ListNode* c = merge(a,b) ;
            return c ;
        }
    };