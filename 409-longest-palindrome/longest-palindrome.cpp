class Solution {
public:
    int longestPalindrome(string s) {
        

       int cnt=0;
       set<char> st;
       for(auto ch: s){
        if(st.find(ch) != st.end()){
            st.erase(ch);
            cnt+=2;
        }
        else{
            st.insert(ch);
        }
       }

        if(st.size()>=1) return cnt+1;
        return cnt;
        
    }
};