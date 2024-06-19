class Solution {
public:
int f(vector<int>&bloomDay,int mid,int k){
    int c=0;
    int nb=0;

    for(int i=0;i<bloomDay.size();i++){
        if(bloomDay[i]<=mid)
        c++;
        else
        c=0;
        if(c==k){
         nb++;
         c=0;
        }
    }
    return nb;
}
    int minDays(vector<int>& bloomDay, int m, int k) {
        int start=0;
        int end=0;
        for(auto it:bloomDay)
        end=max(it,end);
        int ans=-1;
        while(start<=end){
            int mid=(start+end)/2;
            if(f(bloomDay,mid,k)>=m){
              ans=mid;
              end=mid-1;
            }
            
            else
            start=mid+1;
        }
        return ans;
    }
};