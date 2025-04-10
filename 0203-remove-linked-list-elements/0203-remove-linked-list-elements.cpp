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
        ListNode* dummyhead =new ListNode();
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

/*
ListNode* current 是用來遍歷鏈結串鏈的虛擬節點

要對 head 是否為空或是val等於 val 進行判斷
若是 head=head->next

dummyhead 方式
用一個虛擬dummyhead 節點來統一刪除節點的方式
curr->next不等於NULL的話
我們要刪除的是curr->next
curr->next->val==target
curr->next=curr->next->next;
*/
