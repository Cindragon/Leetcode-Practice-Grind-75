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
                left+=s[i];
                right+=s[i+mid];
            }
            if(left==right) ans++;
        }
        return ans;
    }
};