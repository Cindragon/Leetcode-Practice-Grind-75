class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        const int MOD=1e9+7;
        hFences.insert(hFences.begin(), 1);
        hFences.push_back(m);
        vFences.insert(vFences.begin(), 1);
        vFences.push_back(n);
        sort(hFences.begin(), hFences.end());
        sort(vFences.begin(), vFences.end());
        unordered_set<int> hDist;
        for(int i=0;i<hFences.size();++i){
            for(int j=i+1;j<hFences.size();++j)
            hDist.insert(hFences[j]-hFences[i]);
        }
        int len=-1;
        for(int i=0;i<vFences.size();++i){
            for(int j=i+1;j<vFences.size();++j){
                int dist=vFences[j]-vFences[i];
                if(hDist.count(dist)){
                    len=max(len, dist);
                }
            }
        }
        if(len==-1) return len;
        else return (1LL * len * len) % MOD;
    }
};

/*
這題跟2943很像
但是這次要找的不是相鄰的最大邊長，而是要找任意兩個邊的最大距離
將起點跟終點的數各自加到陣列中並且排序
透過 unordered_set 將其中一邊所有的邊長間距加入 set
再計算另一邊的邊長間距，並且查看是否有在 set 裡面
如果有，代表可以組成一個正方形
如果沒有，回傳 -1

*/