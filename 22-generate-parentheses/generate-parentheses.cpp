class Solution {
public:
void findparen(int open,int close,string &ds,vector<string>&ans){
    if(open==0&&close==0){
        ans.push_back(ds);
        return;
    }
    if(open!=0){
        string op1=ds;
        op1+="(";
        findparen(open-1,close,op1,ans);
        
    }
    if(close>open){
        string op2=ds;
        op2+=")";
        findparen(open,close-1,op2,ans);
        
    }
    return;
}
    
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string ds="";
        int open=n;
        int close=n;
        findparen(open,close,ds,ans);
        return ans;

    }
};