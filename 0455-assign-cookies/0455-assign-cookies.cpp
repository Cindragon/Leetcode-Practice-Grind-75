class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        if(s.empty()) return 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int index=s.size()-1;
        int res=0;
        for(int i=g.size()-1;i>=0;i--){
            if(index>=0&&s[index]>=g[i]){
                res++;
                index--;
            }
        }
        return res;
    }
};

/*
本題要用貪心算法來解決
將陣列g跟s進行排列(如果s為空代表沒有餅乾，沒辦法滿足任何小朋友)
接下來從陣列尾端開始進行for迴圈(i大於等於 0 的情況)：
讓最大塊的餅乾給胃口最大的小朋友(不會浪費)，同時將res++並且index--(繼續匹配下一塊餅乾)
最後回傳res
*/