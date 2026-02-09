vector<vector<int>> G, H, scc, cond;
vector<int> leave, root;
vector<bool> vis;

void dfs1(int cur)
{
	vis[cur] = 1;
	for (int next : G[cur])
		if (!vis[next]) dfs1(next);

	leave.push_back(cur);
}

void dfs2(int cur, int r)
{
	vis[cur] = 1, root[cur] = r, scc[r].push_back(cur);
	for (int next : H[cur])
		if (!vis[next]) dfs2(next, r);
}

void solve()
{
	// num of vertices, num of edges.
	int n, m;
	
	G = H = scc = cond = vector<vector<int>>(n+1);
	leave = vector<int>(), root = vector<int>(n+1);

	while (m--)
	{
		// directed edges.
		int u, v;
		G[u].push_back(v);
		H[v].push_back(u);
	}

	// sort by dfs exit time.
	vis = vector<bool>(n+1);
	for (int i = 1; i <= n; i++)
		if (!vis[i]) dfs1(i);

	// collect all reachable vertices from leave[i] in H.
	vis = vector<bool>(n+1);
	int cnt = 0;
	for (int i = n-1; i >= 0; i--)
		if (!vis[leave[i]]) dfs2(leave[i], cnt++);
	
	// condensation graph construction. (some edges may be duplicated.)
	for (int i = 0; i < cnt; i++) for (int j : scc[i]) for (int k : G[j])
		if (root[k] != i) cond[i].push_back(root[k]);
}