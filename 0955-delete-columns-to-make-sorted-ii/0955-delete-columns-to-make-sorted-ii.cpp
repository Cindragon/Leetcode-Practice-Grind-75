class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int m=strs.size();
        int n=strs[0].size();
        int ans=0;
        vector<bool> sorted(m, false);
        for(int j=0;j<n;++j){
            bool flag=false;
            for(int i=1;i<m;++i){
                if(!sorted[i] && strs[i-1][j]>strs[i][j]){
                    flag=true;
                    break;
                }
            }
            if(flag==true){
                ans++;
                continue;
            }
            for(int i=1;i<m;++i){
                if(!sorted[i] && strs[i-1][j]<strs[i][j]){
                    sorted[i]=true;
                }
            }
        }
        return ans;
    }
};