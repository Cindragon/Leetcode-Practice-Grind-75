// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        while(1){
            if(!isBadVersion(n)){
                return n+1;
            }
            else
                n=n-1;
        }
    }
};