class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char, int> mpv, mpc;
        int maxV=0, maxC=0;
        for(const auto&c:s){
            if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'){
                mpv[c]++;
                maxV=max(maxV, mpv[c]);
            }
            else{
                mpc[c]++;
                maxC=max(maxC, mpc[c]);
            }
        }
        return maxV + maxC;
    }
};