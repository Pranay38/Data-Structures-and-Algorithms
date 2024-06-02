class Solution {
public:
    void reverseString(vector<char>& s) {
        vector<char>t(s.size());
        int j=s.size()-1;
        for(int i=0;i<s.size();i++){
         t[j]=s[i];
         j--;
        }
        s=t;
        
    }
};