class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n=citations.size();
        vector<int> count(n+1, 0);
        for(const auto&c:citations){
            if(c>=n)    count[n]++;
            else    count[c]++;
        }
        int total=0;
        // 從後往前遍歷，i 代表「至少被引用 i 次」
        for(int i=n;i>=0;--i){
            total+=count[i];
            if(total>=i)    return i;
        }
        return 0;
    }
};

/*
用一個 count 陣列將各篇的引用次數存入
如果引用次數>=n 那統一儲存到count[n]，不然就是count[i]++
0 1 3 5 6 -> count[1 1 0 1 0 2]
接著開始計算 total 引用篇數，由後往前遍歷 count 陣列，累加「引用次數 >= i」的篇數 (total)
total+=count[i]，直到 total>=i 的時候，代表有 i 篇文章至少被引用 i 次
*/