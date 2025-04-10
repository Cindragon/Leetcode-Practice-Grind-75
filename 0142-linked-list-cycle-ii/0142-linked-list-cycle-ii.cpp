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
        if(!head||head->next==nullptr) return nullptr;
        ListNode* fast=head;
        ListNode* slow=head;
        ListNode* curr=head;
        while(fast!=nullptr&&fast->next!=nullptr){
            fast=fast->next->next;
            slow=slow->next;
            if(slow==fast){
                while(curr!=slow){
                    curr=curr->next;
                    slow=slow->next;
                }
                return curr;
            }
        }
    return nullptr;
    }
};