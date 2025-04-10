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
        while(curr->next!=NULL&& curr->next->next!=NULL){
            ListNode* temp=curr->next;
            ListNode* temp1=curr->next->next->next;
            curr->next=curr->next->next;
            curr->next->next=temp;
            curr->next->next->next=temp1;
            curr=curr->next->next;
        }
    return dummyHead->next;
    }
};

/*
要用到兩個暫時指針 temp & temp1
設一個dummyhead、curr=head
dummyhead->next=curr
curr->next=temp(第一個要交換的點
curr->next->next->next=temp1
當curr->next!=NULL && curr->next->next!=NULL 時(保證有成對的節點才能安全交換)
每交換一次：
curr->next=curr->next->next(第二個要交換的點，交換後變成新的開頭)
curr->next->next=temp(交換後新的結尾)
curr->next->next->next=temp1(下一組要結尾)
curr=curr->next->next(下一個中間值)

return dummyhead->next
*/