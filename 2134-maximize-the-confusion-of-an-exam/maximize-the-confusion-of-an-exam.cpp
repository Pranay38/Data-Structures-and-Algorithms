class Solution {
public:
int f(string answerKey,int k,char c){
    int i=0,j=0,ct=0;
    int n=answerKey.size();
    int ans=0;
    while(j<n){
        if(answerKey[j]==c)
        ct++;
        while(i<n&&ct>k){
            if(answerKey[i]==c)
            ct--;
            i++;
        }
        ans=max(j-i+1,ans);
        j++;
    }
    return ans;
}
    int maxConsecutiveAnswers(string answerKey, int k) {
        int a=f(answerKey,k,'T');
        int b=f(answerKey,k,'F');
        return max(a,b);
    }
};