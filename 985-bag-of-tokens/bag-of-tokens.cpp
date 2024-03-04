class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int c=0,flag=0;
        int i=0,j=tokens.size()-1;
        int n=j+1;
        while(n&&i<=j){
            if(power>=tokens[i]){
            power-=tokens[i];
            flag++;
            i++;
            }
            else if(flag>0){
                flag--;
                power+=tokens[j];
                j--;
            }
            c=max(c,flag);
            n--;
        }
        return c;
    }
};