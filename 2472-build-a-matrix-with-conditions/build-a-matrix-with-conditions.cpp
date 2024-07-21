class Solution {
public:
    std::vector<std::vector<int>> buildMatrix(int k, std::vector<std::vector<int>>& rowConditions,
                                              std::vector<std::vector<int>>& colConditions) {
        std::vector<int> orderRows = topoSort(rowConditions, k);
        std::vector<int> orderColumns = topoSort(colConditions, k);

        if (orderRows.empty() || orderColumns.empty()) return {};

        std::vector<std::vector<int>> matrix(k, std::vector<int>(k, 0));
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                if (orderRows[i] == orderColumns[j]) {
                    matrix[i][j] = orderRows[i];
                }
            }
        }
        return matrix;
    }

private:
    std::vector<int> topoSort(std::vector<std::vector<int>>& edges, int n) {
        std::vector<std::vector<int>> adj(n + 1);
        std::vector<int> order;
        std::vector<int> visited(n + 1, 0);
        bool hasCycle = false;

        for (auto& x : edges) {
            adj[x[0]].push_back(x[1]);
        }

        for (int i = 1; i <= n; i++) {
            if (visited[i] == 0) {
                dfs(i, adj, visited, order, hasCycle);
                if (hasCycle) return {};
            }
        }
        std::reverse(order.begin(), order.end());
        return order;
    }

    void dfs(int node, std::vector<std::vector<int>>& adj, std::vector<int>& visited,
             std::vector<int>& order, bool& hasCycle) {
        visited[node] = 1;
        for (int neighbor : adj[node]) {
            if (visited[neighbor] == 0) {
                dfs(neighbor, adj, visited, order, hasCycle);
                if (hasCycle) return;
            } else if (visited[neighbor] == 1) {
                hasCycle = true;
                return;
            }
        }
        visited[node] = 2;
        order.push_back(node);
    }
};