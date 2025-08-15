/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummyHead=new ListNode(0);
        dummyHead->next=head;
        ListNode* fast=dummyHead;
        ListNode* slow=dummyHead;
        while(n--&&fast->next!=NULL){
            fast=fast->next;    
        }
        fast=fast->next;    //fast 再多走一步，slow 最後會走到要刪除的前一個節點
        while(fast!=NULL){
            fast=fast->next;
            slow=slow->next;
        }
        slow->next=slow->next->next;
        return dummyHead->next;

    }
};