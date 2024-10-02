class Solution {
public:
    double f(int x1, int y1, int x2, int y2) {
        long double d = sqrtl(1LL * (x1 - x2) * (x1 - x2) + 1LL * (y1 - y2) * (y1 - y2));
        return d;
    }

    void dfs(int node, vector<int>& vis, int& c, vector<vector<int>>& graph) {
        vis[node] = 1;
        c++;
        for (int i = 0; i < graph[node].size(); i++) {
            int it = graph[node][i];
            if (vis[it] == -1) {
                dfs(it, vis, c, graph);
            }
        }
    }

    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<vector<int>> graph(n);
        int ans = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                double d = f(bombs[i][0], bombs[i][1], bombs[j][0], bombs[j][1]);
                double d1 = bombs[i][2] * 1.0;
                double d2 = bombs[j][2] * 1.0;
                
                if (d <= d1)
                    graph[i].push_back(j);
                if (d <= d2)
                    graph[j].push_back(i);
            }
        }
        
        for (int i = 0; i < n; i++) {
            int c = 0;
            vector<int> vis(n, -1);
            dfs(i, vis, c, graph);
            ans = max(ans, c);
        }
        
        return ans;
    }
};
