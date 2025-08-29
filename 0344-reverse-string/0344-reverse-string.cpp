class Solution {
public:
    void reverseString(vector<char>& s) {
        int j=s.size()-1;
        for(int i=0;i<s.size()/2;i++){
            char temp=s[i];
            s[i]=s[j];
            s[j]=temp;
            j--;
        }
    }
};

/*
用swap函數也可以(swap(s[i],s[j]))
*/