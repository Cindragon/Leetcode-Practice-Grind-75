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
    bool hasCycle(ListNode *head) {
        if(!head||head->next==NULL) return false;
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(fast!=NULL&&fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast) return true;
        }
        return false;
    }
};

/*
快慢指針
快的走兩步，慢的走一步
在快指針跟快指針的next!=NULL的情況下往下走
最後若是有相遇就有環
*/