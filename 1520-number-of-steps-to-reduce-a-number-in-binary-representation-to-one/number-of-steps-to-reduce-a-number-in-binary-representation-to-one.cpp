class Solution {
public:
     
     void f(string &s ){
        int n=s.length();
       int i=n-1;
       while(i>=0 && s[i]=='1'){
        s[i]='0';
        i--;
       }
       if(i<0){
        s='1'+s;
       }else{
        s[i]='1';
       }

     }
    int numSteps(string s) {
        
        
        int ans=0;
        while(s.length()>1){
            int n=s.length();
            if(s[n-1]=='1'){
                f(s);
              
            }else{
                s.pop_back();
            }
              ans++;
        }
        
        return ans;
    }
};