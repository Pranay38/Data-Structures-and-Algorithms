class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n=nums.size();
        long long score=0;

        vector<pair<int,int>>q;
        for(int i=0;i<n;i++){
            q.push_back({nums[i],i});
        }

        sort(q.begin(),q.end());

        vector<bool>visit(n,false);

        for(int i=0;i<n;i++){
            int cur=q[i].first;
            int idx=q[i].second;
            if(!visit[idx]) score+=cur;
            else continue;
            if(idx>0) visit[idx-1]=true;
            if(idx<n-1) visit[idx+1]=true;
        }

        return score;
    }
};