class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int ans=0;
        for(int i=low;i<=high;i++){
            string s=to_string(i);
            int n=s.size();
            if(n%2!=0) continue;
            int mid=n/2, left=0, right=0;
            for(int i=0;i<mid;i++){
                left+=s[i]-'0';
                right+=s[i+mid]-'0';
            }
            if(left==right) ans++;
        }
        return ans;
    }
};

/*
計算時要記得-'0'才是數字加總
不然會變成 ASCII 值相加(就算結果對但是意義不一樣)
*/