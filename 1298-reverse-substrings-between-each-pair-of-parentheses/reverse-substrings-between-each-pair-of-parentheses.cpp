class Solution {
public:
    string reverseParentheses(string s) {
        vector<int>st;
        //vector<char>ans;
        string ans="";
        for(auto it:s){
            if(it=='(')
            st.push_back(ans.size());
            else if(it==')'){
                int ind=st.back();
                st.pop_back();
                reverse(ans.begin()+ind,ans.end());

            }
            else
            ans+=it;
        }
        return ans;

    }
};