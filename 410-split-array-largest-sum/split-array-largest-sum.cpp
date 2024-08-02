class Solution {
public:
bool f(int mid,int k,vector<int>&nums){
    int c=1;
    int n=nums.size();
    int i=0;
    int sum=0;
    while(c<=k&&i<n){
        if(sum+nums[i]<=mid){
            sum+=nums[i];
        }
        else{
            c++;
            sum=nums[i];
        }
        i++;
    }
    return c<=k;

}
    int splitArray(vector<int>& nums, int k) {
        int start=0;
        int end=0;
        for(auto it:nums){
            start=max(it,start);
            end+=it;
        }
        int ans=end;
        while(start<=end){
            int mid=(start+end)/2;
            if(f(mid,k,nums)){
                ans=min(ans,mid);
               end=mid-1;
            }
            else 
            start=mid+1;
        }
        return ans;
    }
};