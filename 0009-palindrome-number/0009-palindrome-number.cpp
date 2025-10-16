class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        if(0<=x && x<10) return true;
        string s=to_string(x);
        int left=0, right=s.size()-1;
        while(left<right){
            if(s[left]==s[right]){
                left++;
                right--;
            }
            else{
                return false;
            }
        }
        return true;
    }
};