class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n=customers.size();
        int sum=0;
        for(int i=0;i<n;i++){
            if(grumpy[i]==0)
            sum+=customers[i];
            else
            grumpy[i]*=customers[i];
        }
        int i=0,j=0;
        int ans=0;
        int temp=0;
        while(j<n){
            temp+=grumpy[j];
            if(j-i+1>minutes){
                temp-=grumpy[i];
                i++;
            }
            if(j-i+1==minutes){
                ans=max(ans,temp);
            }
            j++;
        }
        return ans+sum;

    }
};