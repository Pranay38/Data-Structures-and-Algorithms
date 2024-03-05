class Solution {
public:
    int minimumLength(string s) {
        if(s.length()==1)
            return 1;
        int i=0;
        int j=s.length()-1;
        int ans;
        while(s[i]==s[j] && i<j) {
            char current=s[i];
            while(i<=j && s[i]==current)
                i++;
            while(i<=j && s[j]==current)
                j--;
            
        }
        ans=j-i+1;
        return ans;
    }
};
