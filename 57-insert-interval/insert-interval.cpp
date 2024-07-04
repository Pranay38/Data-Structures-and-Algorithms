class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        vector<vector<int>>ans;
        sort(intervals.begin(),intervals.end());
        int n=intervals.size();
        for(int i=0;i<n;i++){
            int f=intervals[i][0];
            int s=intervals[i][1];
            if(ans.empty()||ans.back()[1]<f)
            ans.push_back({f,s});
            else if(ans.back()[1]>=f&&ans.back()[1]<s)
            ans.back()[1]=s;


        }
        return ans;
    }
};