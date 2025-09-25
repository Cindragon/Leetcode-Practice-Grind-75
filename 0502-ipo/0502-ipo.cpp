class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        auto cmp=[](const pair<int, int>&a, const pair<int, int>&b){
            return a.second>b.second;
        };
        priority_queue<pair<int,int>, vector<pair<int, int>>, decltype(cmp)> pqC(cmp); //captial 小的排前面

        priority_queue<pair<int, int>> pqP; //profits 大的排前面

        for(int i=0;i<profits.size();i++){
            pqC.push({profits[i], capital[i]});
        }

        int currentMoney=w;
        for(int i=0;i<k;i++){
            while(!pqC.empty()&& pqC.top().second<=currentMoney){
                auto project=pqC.top();
                pqC.pop();
                pqP.push(project);
            }
            if(pqP.empty()) break;
            currentMoney+=pqP.top().first;
            pqP.pop();
        }
        return currentMoney;
    }
};

/* 
這題同樣用到兩個 pq，其中一個 pqC 將 captial 越小的放進來，另一個 pqP 則是把 profit 最大的往前放(預設的大頂堆)
1. 先將所有組合丟進 pqC
2. 在 pqC 不為空且 pqC.top().second<=currentMoney(原有資本) 的情況下把組合丟進 pqP (K次操作)
3. 如果 pqP 為空，代表沒有 project 可以運行，直接 break 迴圈
若是有組合，則直接將現有的 currentMoney+=pqP.top().first，最後回傳 currentMoney
*/