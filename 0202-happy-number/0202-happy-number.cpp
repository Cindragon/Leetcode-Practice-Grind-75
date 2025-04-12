class Solution {
public:
    int getsum(int n){
        int sum=0;
        while(n){
            sum+=(n%10)*(n%10);
            n=n/10;
        }
        return sum;
    }
    bool isHappy(int n) {
        unordered_set<int> ans;
        int sum;
        while(1){
            sum=getsum(n);
            if(sum==1){
                return true;
            }
            if(ans.find(sum)!=ans.end()){
                return false;
            }
            else{
                ans.insert(sum);
            }
            n=sum;
        }
    }
};

/*
用 unordered_set 來儲存每次位元相乘的計算結果
因為有可能會算到重複的，所以需要用一個 hash table(set) 來儲存結果
如果等於 1 就回傳 true
發現有相同的就回傳false
*/