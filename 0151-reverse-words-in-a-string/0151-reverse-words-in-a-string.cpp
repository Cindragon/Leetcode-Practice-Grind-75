class Solution {
public:
    string reverseWords(string s) {
        int n=s.size();
        int slow=0;
        for(int fast=0;fast<n;fast++){
            if(s[fast]!=' '){
                if(slow!=0){
                    s[slow]=' ';
                    slow++;
                }
                while(fast<n&&s[fast]!=' '){
                    s[slow]=s[fast];
                    slow++;
                    fast++;
                }
            }
        }
        s.resize(slow);
        n=s.size();
        cout<<s;
        reverse(s.begin(),s.end());
        int start=0;
        for(int end=0;end<=n;end++){
            if(end==n||s[end]==' '){
                reverse(s.begin()+start, s.begin()+end);
                start=end+1;
            }
        }
        return s;
    }
};