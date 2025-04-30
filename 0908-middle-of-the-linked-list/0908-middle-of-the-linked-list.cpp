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
    ListNode* middleNode(ListNode* head) {
        int size=0;
        ListNode* curr=head;
        while(curr!=NULL){
            curr=curr->next;
            size++;
        }
        size=size/2;
        while(size!=0){
            head=head->next;
            size--;
        }
        return head;
    }
};