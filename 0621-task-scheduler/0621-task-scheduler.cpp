class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if(n==0)    return tasks.size();
        vector<int> count(26,0);
        for(const auto&t:tasks){
            count[t-'A']++;
        }
        sort(count.begin(),count.end());
        int chunk=count[25]-1;
        int emptySpace=chunk*n;

        for(int i=24;i>=0;i--){
            emptySpace-=min(count[i], chunk);
        }
        if(emptySpace<=0)    return tasks.size();
            // 如果空格全被填滿 (甚至超過)，不用 idle
            // 所需時間 = 總任務數
        else    return tasks.size()+emptySpace;
            // 如果還有剩餘的空格，代表需要 idle
            // 總時間 = 任務數 + idle 空格數
    }
};

/*
這題透過 greedy 的方式來解題：
1. n==0(不用休息)，直接回傳 tasks 陣列大小
2. 用 count 來算各個任務出現的頻率，並且進行排序。
3. 設計排程骨架：
   - chunk = (最大頻率 - 1)，代表要形成多少區塊。
   - 每個區塊有 n 個空格，總共 emptySpace = chunk * n。
4. 遍歷 count 陣列，
   - 每個任務最多只能分散填滿 chunk 個位置。
   - emptySpace -= min(count[i], chunk)。
5. 最後：
   - 若 emptySpace <= 0 → 任務足夠填滿，結果 = tasks.size()。
   - 若 emptySpace > 0 → 還需要 idle 來補齊，結果 = tasks.size() + emptySpace。
*/