bool canFinish(int n, vector<pair<int, int>>& pre) {
    vector<int> degree(n, 0);
// adj<vector<vector<int>> adjency vertex for vertices
    queue<int> q;
    for (int i = 0; i < n; i++)
        if (degree[i] == 0) q.push(i);
    while (!q.empty()) {
        int curr = q.front(); q.pop(); n--;
        for (auto next: adj[curr])
            if (--degree[next] == 0) q.push(next);  //add to queue if degree is zerro
    }
    return n == 0;  //if all vertices have degree zero, all visited
}
