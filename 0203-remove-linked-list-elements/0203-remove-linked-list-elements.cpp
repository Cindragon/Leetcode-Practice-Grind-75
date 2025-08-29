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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummyhead=new ListNode();
        dummyhead->next=head;
        ListNode* curr=dummyhead;
        while(curr->next!=NULL){
            if(curr->next->val==val){
                ListNode* temp=curr->next;
                curr->next=curr->next->next;
                delete temp;
            }
            else
                curr=curr->next;
        }
        ListNode* newhead=dummyhead->next;
        delete dummyhead;
        return newhead;
    }
};