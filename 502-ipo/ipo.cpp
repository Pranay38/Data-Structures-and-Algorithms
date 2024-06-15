class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<int> pq;
        vector<pair<int, int>> v;
        for(int i = 0; i < profits.size(); i++) {
            v.push_back({capital[i], profits[i]});
        }
        sort(v.begin(), v.end());
        int i = 0;
        while(k--) {
            while(i < v.size() && v[i].first <= w) {
                pq.push(v[i].second);
                i++;
            }
            if(pq.empty()) break;
            w += pq.top();
            pq.pop();
        }
        return w;
    }
};
