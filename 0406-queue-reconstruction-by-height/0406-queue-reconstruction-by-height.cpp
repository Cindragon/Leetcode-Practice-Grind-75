class Solution {
public:
    static bool cmp(const vector<int>& a, const vector<int>& b){
        if(a[0]==b[0]) return a[1]<b[1];
        return a[0]>b[0];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), cmp);
        vector<vector<int>> queue;
        for(int i=0; i<people.size();i++){
            int position=people[i][1];
            queue.insert(queue.begin()+position, people[i]);
        }
        return queue;
    }
};

/*
貪心算法，先顧好一邊再顧另一邊
先將數列以身高排序！如果身高一樣的話把 k 值高的擺在後面
接著使用迴圈，依序插入，讓每個人剛好站在前面有幾個人比他高或一樣高的位置上。
使用 int position 記錄他應該在哪個位置
在插入的時候會再用到
*/