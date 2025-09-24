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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return nullptr;
        auto cmp=[](ListNode* a, ListNode* b){
            return a->val>b->val;
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);
        for(const auto&list:lists){
            if(list)    pq.push(list);
        }
        ListNode* dummyHead=new ListNode();
        ListNode* tail=dummyHead;
        while(!pq.empty()){
            ListNode* curr=pq.top();
            pq.pop();
            tail->next=curr;
            tail=tail->next;
            if(curr->next){
                pq.push(curr->next);
            }
        }
        return dummyHead->next;
    }
};

/*
用 priority_queue 的概念來解題
1. 將每個鏈表的頭節點加入 pq（非空的才加入），
並且進行比較讓 val 較小的 node 排在前面
pq 可以用 ListNode 或是 int 來實現
2. 創立一個 dummyHead 跟 tail(後面加入的點)進行更新
3. 當堆不為空時：
   a. 取出堆頂最小節點 curr。
   b. 將 curr 接到結果鏈表尾部，更新 tail。
   c. 如果 curr 有下一個節點 (curr->next)，將其 push 回堆，保證下一輪仍能選出最小節點。
最後回傳 dummyHead->next
*/