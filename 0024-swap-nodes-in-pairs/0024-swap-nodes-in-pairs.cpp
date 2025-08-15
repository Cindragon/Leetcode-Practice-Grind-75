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
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummyHead=new ListNode(0);
        dummyHead->next=head;
        ListNode* curr=dummyHead;
        while(curr->next!=NULL&&curr->next->next!=NULL){
            ListNode* first=curr->next;
            ListNode* second=curr->next->next;
            curr->next=second;
            first->next=second->next;
            second->next=first;
            curr=first;
        }
        return dummyHead->next;
    }
};