class Solution {
#define pb push_back

public:
    void bfs(int node, vector<int> adj[], vector<int>& vis) {
        queue<int> q;
        q.push(node);
        while (!q.empty()) {
            int d = q.front();
            vis[d] = 1;
            q.pop();
            for (int i = 0; i < adj[d].size(); i++) {
                int temp = adj[d][i];
                if (!vis[temp]) {
                    q.push(temp);
                }
            }
        }
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        for (int i = 0; i < edges.size(); i++) {
            adj[edges[i][1]].pb(edges[i][0]);
        }
        vector<vector<int>> res;
        for (int i = 0; i < n; i++) {
            vector<int> a;
            vector<int> vis(n, 0);

            bfs(i, adj, vis);

            for (int j = 0; j < n; j++) {
                if (vis[j] != 0 && j != i)
                    a.pb(j);
            }
            vis.clear();
            res.pb(a);
        }
        return res;
    }
};