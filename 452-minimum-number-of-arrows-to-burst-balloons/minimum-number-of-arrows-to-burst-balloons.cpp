class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
       sort(points.begin(),points.end());
       int f=points[0][1];
       int ans=1;
       for(auto it:points){
        if(it[0]>f){
            ans++;
            f=it[1];
        }
        f=min(it[1],f);
       } 
       return ans;
    }
};