class Solution {
public:
    // Function to calculate the Euclidean distance between two points
    double f(int x1, int y1, int x2, int y2) {
        long double d = sqrtl(1LL * (x1 - x2) * (x1 - x2) + 1LL * (y1 - y2) * (y1 - y2));
        return d;
    }
    
    // Depth-First Search (DFS) to traverse bombs that can be detonated
    void dfs(int node, vector<int>& vis, int& c, vector<vector<int>>& graph) {
        vis[node] = 1;
        c++; // Increment the count of detonated bombs
        
        // Traverse through all bombs connected to this bomb
        for (int i = 0; i < graph[node].size(); i++) {
            int it = graph[node][i];
            if (vis[it] == -1) {
                dfs(it, vis, c, graph);
            }
        }
    }

    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<vector<int>> graph(n); // Adjacency list to store which bombs can detonate which
        int ans = 0;
        
        // Build the graph based on the distances and the radius of each bomb
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                double d = f(bombs[i][0], bombs[i][1], bombs[j][0], bombs[j][1]);
                double d1 = bombs[i][2] * 1.0; // Bomb i's detonation radius
                double d2 = bombs[j][2] * 1.0; // Bomb j's detonation radius
                
                // Check if bomb i can detonate bomb j
                if (d <= d1)
                    graph[i].push_back(j);
                // Check if bomb j can detonate bomb i
                if (d <= d2)
                    graph[j].push_back(i);
            }
        }
        
        // Perform DFS for each bomb to find the maximum number of bombs that can be detonated
        for (int i = 0; i < n; i++) {
            int c = 0; // Counter for bombs detonated in the current path
            vector<int> vis(n, -1); // Visited array to keep track of detonated bombs
            dfs(i, vis, c, graph); // Start DFS from bomb i
            ans = max(ans, c); // Update the maximum number of detonated bombs
        }
        
        return ans;
    }
};
