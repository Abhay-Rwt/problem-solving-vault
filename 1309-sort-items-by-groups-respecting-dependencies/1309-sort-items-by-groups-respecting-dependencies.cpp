class Solution {
public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        // Step 1: assign new group IDs to ungrouped items
        for (int i = 0; i < n; i++)
            if (group[i] == -1)
                group[i] = m++;

        // Step 2: build graphs
        vector<vector<int>> itemGraph(n), groupGraph(m);
        vector<int> itemIndegree(n, 0), groupIndegree(m, 0);

        for (int i = 0; i < n; i++) {
            for (int prev : beforeItems[i]) {
                itemGraph[prev].push_back(i);
                itemIndegree[i]++;
                if (group[prev] != group[i]) {
                    groupGraph[group[prev]].push_back(group[i]);
                    groupIndegree[group[i]]++;
                }
            }
        }

        // Step 3: topo sort for items and groups
        auto topoSort = [&](vector<vector<int>>& adj, vector<int>& indegree) {
            queue<int> q;
            for (int i = 0; i < indegree.size(); i++)
                if (indegree[i] == 0)
                    q.push(i);

            vector<int> order;
            while (!q.empty()) {
                int u = q.front(); q.pop();
                order.push_back(u);
                for (int v : adj[u]) {
                    if (--indegree[v] == 0)
                        q.push(v);
                }
            }
            return order;
        };

        vector<int> itemOrder = topoSort(itemGraph, itemIndegree);
        vector<int> groupOrder = topoSort(groupGraph, groupIndegree);

        // If any cycle found (not all processed)
        if (itemOrder.size() != n || groupOrder.size() != m)
            return {};

        // Step 4: bucket items by group
        vector<vector<int>> groupedItems(m);
        for (int item : itemOrder)
            groupedItems[group[item]].push_back(item);

        // Step 5: merge by topological group order
        vector<int> result;
        for (int g : groupOrder)
            for (int item : groupedItems[g])
                result.push_back(item);

        return result;
    }
};
