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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1&&!list2) return NULL;
        ListNode* dummyHead=new ListNode(0);
        ListNode* curr=dummyHead;
        while(list1&&list2){
            if(list1->val<list2->val){
                curr->next=list1;
                curr=curr->next;
                list1=list1->next;
            }
            else{
                curr->next=list2;
                curr=curr->next;
                list2=list2->next;
            }
        }
        if(list1) curr->next=list1;
        if(list2) curr->next=list2;
        return dummyHead->next;
    }
};

/*
dummy head 是「固定的起點」，而 curr 是「動態的建構者」
每次加上一個節點，會是從curr去接下一個節點
若最後接完要檢查list1 & list2 是否到終點
若不是要再接上其中一條
最後要回傳的是dummyHead->next
*/