class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int ans=target[0];
        int n=target.size();
        for(int i=1;i<n;++i){
            if(target[i]>target[i-1]){
                ans+=target[i]-target[i-1];
            }
        }
        return ans;
    }
};

/*
用貪心算法的構造來算，我們從第一個元素開始計算，從左到右開始遍歷
先設 ans=target[0](至少要到這個數值)
如果說 target[i]>target[i-1]，那就讓 ans+= 其差值
若是<= 則不用加總(因為已到達其數值)
最後回傳 ans
*/